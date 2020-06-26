#ifndef VALIDATOR_H
#define VALIDATOR_H


int DifferenceValidator (int Run_id, int Ques_id)
{

    std::string answerFile = "../answerFiles/" + to_string(Ques_id) + ".txt";
    std::string codeOutFile = "../codeOut/" + to_string(Run_id) + ".txt";
    const char *Afile = answerFile.c_str();
    const char *Cfile = codeOutFile.c_str();

    ifstream fp1(Afile);
    ifstream fp2(Cfile);

    char ch1 = getc(fp1);
    char ch2 = getc(fp2);

    bool wrongAns = false;
    while (ch1 != EOF && ch2 != EOF)
    {
        pos++;

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
