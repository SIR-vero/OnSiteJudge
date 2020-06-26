#include<bits/stdc++.h>

bool IsEmpty(const char *fileName)
{
    std::ifstream pFile(fileName);
    return pFile.peek() == std::ifstream::traits_type::eof();
}

bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

int CompileCode(const int Run_id, const int Lang)   //Returns 0 if file not found 1 if compiles successfully
                                                    //3 if compilation error occurs
{
    std::string FilePathString = "../submissions/";

    if (Lang == C_LANG)
    {
        FilePath += to_string(Run_id) + ".c" ;
    }
    else if (Lang == CPP_LANG)
    {
        FilePath += to_string(Run_id) + ".cpp" ;
    }
    else if (Lang == JAVA_LANG)
    {
        FilePath += to_string(Run_id) + ".java" ;
    }
    else if (Lang == PYTHON3_LANG)
    {
        FilePath += to_string(Run_id) + ".py" ;
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

            }
            return 1;
        }

        else
            return CE;

    }

    else
        return 0;                                           //denoting file not exist.
}


int main()
{

}
