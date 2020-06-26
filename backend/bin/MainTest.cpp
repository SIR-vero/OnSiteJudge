#include <bits/stdc++.h>
using namespace std;


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

int CompileCode(const int Run_id, const int Lang)   //Returns 0 if file not found, SUCCESS if compiles successfully
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

int RunCode(const int Run_id, const int Lang, const int Ques_id, const int Time_limit)
{
   if (Lang == C_LANG || Lang == CPP_LANG)
   {
        std::string comm = "Run_C_CPP.bat " + to_string(Run_id) + " " + to_string(Ques_id) + " " + to_string(Time_limit);
        const char *command = comm.c_str();
        system(command);
   }
   if (Lang == JAVA_LANG)
   {
        std::string comm = "Run_JAVA.bat " + to_string(Run_id) + " " + to_string(Ques_id) + " " + to_string(Time_limit);
        const char *command = comm.c_str();
        system(command);
   }
   if (Lang == PYTHON3_LANG)
   {
        std::string comm = "Run_PYTHON3.bat " + to_string(Run_id) + " " + to_string(Ques_id) + " " + to_string(Time_limit);
        const char *command = comm.c_str();
        system(command);
   }
   if (Lang != C_LANG && Lang != CPP_LANG)
   {
       std::string RElogfile =  "../runtimeLog/" + to_string(Run_id) + ".log";
       if (!IsEmpty(RElogfile.c_str()))
            return RE;
   }

   std::string TLElogfile = "../tleLog/" + to_string(Run_id) + "n" + ".log";
   if (!IsEmpty(TLElogfile.c_str()))
        return TLE;
    else
        return SUCCESS;
}




#endif


#ifndef VALIDATOR_H
#define VALIDATOR_H


int DifferenceValidator (int Run_id, int Ques_id)
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
    int runid, quesid, tl, lang;
    runid = atoi(args[1]);
    quesid = atoi(args[2]);
    tl = atoi(args[3]);
    lang = atoi(args[4]);

    int response;
    response = CompileCode(runid, lang);
    if (response != SUCCESS)
    {
        cout << response << endl;
        exit(0);
    }
    else if (response == SUCCESS)
    {
        response = RunCode(runid, lang, quesid, tl);
        if (response != SUCCESS)
        {
            cout << response << endl;
            exit(0);
        }
        else if (response == SUCCESS)
        {
            response = DifferenceValidator(runid, quesid);
            cout << response << endl;
        }
    }
}


