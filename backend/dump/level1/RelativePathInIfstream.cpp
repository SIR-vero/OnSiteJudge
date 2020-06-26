#include <bits/stdc++.h>
using namespace std;

bool IsEmpty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

int main()
{
    if (is_file_exist("../testing.log")){
        ifstream file("../testing.log");
        if (IsEmpty(file))
            cout << "empty\n";
        else
            cout << "not empty\n";}
    else
        cout << "file does'nt exist \a";
}
