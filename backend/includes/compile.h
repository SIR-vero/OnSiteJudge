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
                ifstream fs;
                ofstream ft;
                fs.open(FilePath);
                std::string TargetFilePath = "../submissionsExec/" + to_string(Run_id) + ".py";
                ft.open(TargetFilePath);
                char ch;
                while(fs.eof()==0)
                {
                    fs>>ch;
                    ft<<ch;
                }
                fs.close();
                ft.close();
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
