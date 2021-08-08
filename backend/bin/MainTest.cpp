#include <bits/stdc++.h>
#include <chrono>
#include<thread>
#include<windows.h>
using namespace std;
using namespace std::chrono;


#ifndef DEFINE_H
#define DEFINE_H

#define C_LANG 1
#define CPP_LANG 2
#define JAVA_LANG 3
#define PYTHON3_LANG 4
#define AC 1
#define WA 2
#define CE 3
#define RE 4
#define TLE 5
#define SUCCESS 1024



#endif


int Run_id, Ques_id, Time_limit, Lang;
ofstream commandFileHandle;

#ifndef COMPILE_H
#define COMPILE_H


bool IsEmpty(const char *fileName)              //Return true if empty
{
    std::ifstream pFile(fileName);
    return pFile.peek() == std::ifstream::traits_type::eof();
}

bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

int CompileCode()   //Returns 0 if file not found, SUCCESS if compiles successfully
                                                    //CE if compilation error occurs
{
    std::string FilePathString = "../submissions/";

    if (Lang == C_LANG)
    {
        FilePathString += to_string(Run_id) + ".c" ;
    }
    else if (Lang == CPP_LANG)
    {
        FilePathString += to_string(Run_id) + ".cpp" ;
    }
    else if (Lang == JAVA_LANG)
    {
        FilePathString += to_string(Run_id) + ".java" ;
    }
    else if (Lang == PYTHON3_LANG)
    {
        FilePathString += to_string(Run_id) + ".py" ;
    }

    const char *FilePath = FilePathString.c_str();
    if (is_file_exist(FilePath))
    {
        if (Lang == C_LANG)
        {
            std::string comm = "Compile_C.bat " + to_string(Run_id);     //Compile_C.bat compiles Run_id.c file
            const char *command = comm.c_str();
            system(command);
        }
        else if (Lang == CPP_LANG)
        {
            std::string comm = "Compile_CPP.bat " + to_string(Run_id);
            const char *command = comm.c_str();
            system(command);
        }
        else if (Lang == JAVA_LANG)
        {
            std::string comm = "Compile_JAVA.bat " + to_string(Run_id);
            const char *command = comm.c_str();
            system(command);
        }
        else if (Lang == PYTHON3_LANG)
        {
            std::string comm = "Compile_PYTHON3.bat " + to_string(Run_id);
            const char *command = comm.c_str();
            system(command);
        }

        std::string compilationLogFilePath = "../compilationLog/" + to_string(Run_id) + ".log";
        if (IsEmpty(compilationLogFilePath.c_str()))
        {
            if (Lang == PYTHON3_LANG)
            {
                std::string co = "Copy_PY.bat " + to_string(Run_id);
                system(co.c_str());
            }
            return SUCCESS;
        }

        else
            return CE;

    }

    else
        return 0;                                           //denoting file not exist.
}

#endif


#ifndef RUN_H
#define RUN_H

static bool stillAlive;
static bool killed = 0;

void kill_c_cpp(){
	Sleep(Time_limit*1000);
	if(stillAlive){
        //taskkill /F /IM %2.exe /T > ../tleLog/%2n.log 2> ../tleLog/%2.log
        std::string comm = "taskkill /F /IM " + to_string(Run_id) + ".exe " + "/T " + "> ../tleLog/" + to_string(Run_id)+"n.log 2> ../tleLog/"+to_string(Run_id)+".log";
        const char *command = comm.c_str();
		system(command);
		killed = 1;
	}
}

void kill_java(){
	Sleep(Time_limit*1000);
	if(stillAlive){
        //taskkill /F /IM java.exe /T > ../tleLog/%2n.log 2> ../tleLog/%2.log
        std::string comm = "taskkill /F /IM java.exe /T > ../tleLog/" + to_string(Run_id)+"n.log 2> ../tleLog/"+to_string(Run_id)+".log";
        const char *command = comm.c_str();
		system(command);
		killed = 1;
	}
}

void kill_py(){
	Sleep(Time_limit*1000);
	if(stillAlive){
        //taskkill /F /IM python.exe /T > ../tleLog/%2n.log 2> ../tleLog/%2.log
        std::string comm = "taskkill /F /IM python.exe /T > ../tleLog/" + to_string(Run_id)+"n.log 2> ../tleLog/"+to_string(Run_id)+".log";
        const char *command = comm.c_str();
		system(command);
		killed = 1;
	}
}

int RunCode()
{
   if (Lang == C_LANG || Lang == CPP_LANG)
   {
        //%1 < ../testCases/%2.txt > ../codeOut/%1.txt
        std::string comm ="cd ../submissionsExec && " + to_string(Run_id) + ".exe < ../testCases/" + to_string(Ques_id) + ".txt > ../codeOut/" + to_string(Run_id) + ".txt";
        commandFileHandle << comm << "\n";
        const char *command = comm.c_str();
        //system(command);
        std::thread t1(kill_c_cpp);
        auto start = high_resolution_clock::now();
        stillAlive = 1;
        int retval = system(command);
        stillAlive = 0;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        t1.join();

        if(killed)
            return TLE;
        else{
            if (retval != 0)
                return RE;
			ofstream execTimeFileHandle;
			string execTimeFilePath = "./executionTimeLog/" + to_string(Run_id) + ".txt";
			execTimeFileHandle.open(execTimeFilePath);
            execTimeFileHandle << duration << endl;
            return SUCCESS;
        }
   }
   if (Lang == JAVA_LANG)
   {
        std::string comm = "Run_JAVA.bat " + to_string(Run_id) + " " + to_string(Ques_id) + " " + to_string(Time_limit);
        const char *command = comm.c_str();
        //system(command);
        std::thread t1(kill_java);
        auto start = high_resolution_clock::now();
        stillAlive = 1;
        int retval = system(command);
        stillAlive = 0;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        t1.join();

        if(killed)
            return TLE;
        else{
//            if (retval != 0)
//                return RE;
            std::string RElogfile =  "../runtimeLog/" + to_string(Run_id) + ".log";
            if (!IsEmpty(RElogfile.c_str()))
                return RE;
            return SUCCESS;
        }
   }
   if (Lang == PYTHON3_LANG)
   {
        std::string comm = "Run_PYTHON3.bat " + to_string(Run_id) + " " + to_string(Ques_id) + " " + to_string(Time_limit);
        const char *command = comm.c_str();
        //system(command);
        std::thread t1(kill_py);
        auto start = high_resolution_clock::now();
        stillAlive = 1;
        int retval = system(command);
        stillAlive = 0;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        t1.join();

        if(killed)
            return TLE;
        else{
//            if (retval != 0)
//                return RE;
            std::string RElogfile =  "../runtimeLog/" + to_string(Run_id) + ".log";
            if (!IsEmpty(RElogfile.c_str()))
                return RE;
            return SUCCESS;
        }
   }
}




#endif


#ifndef VALIDATOR_H
#define VALIDATOR_H


int DifferenceValidator ()
{

    std::string answerFile = "../answerFiles/" + to_string(Ques_id) + ".txt";
    std::string codeOutFile = "../codeOut/" + to_string(Run_id) + ".txt";
    const char *Afile = answerFile.c_str();
    const char *Cfile = codeOutFile.c_str();

    FILE *fp1 = fopen(Afile, "r");
    FILE *fp2 = fopen(Cfile, "r");

    char ch1 = getc(fp1);
    char ch2 = getc(fp2);

    bool wrongAns = false;
    while (ch1 != EOF && ch2 != EOF)
    {

        if (ch1 != ch2)
        {
            wrongAns = true;
            break;
        }

        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }
    if (ch1 == EOF && ch2 == EOF && !wrongAns)
        return AC;

    else
        return WA;

}


#endif


int main(int argc, char *args[])
{

    commandFileHandle.open("../commandLog/command.txt", ios::app);
    Run_id = atoi(args[1]);
    Ques_id = atoi(args[2]);
    Time_limit = atoi(args[3]);
    Lang = atoi(args[4]);

    int response;
    response = CompileCode();
    if (response != SUCCESS)
    {
        cout << response << endl;
        exit(0);
    }
    else if (response == SUCCESS)
    {
        response = RunCode();
        if (response != SUCCESS)
        {
            cout << response << endl;
            exit(0);
        }
        else if (response == SUCCESS)
        {
            response = DifferenceValidator();
            cout << response << endl;
        }
    }
}


