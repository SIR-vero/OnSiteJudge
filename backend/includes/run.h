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
