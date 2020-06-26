#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    string s = "something";
    s = s + '/' + to_string(a) + ".cpp" ;
    const char *f = s.c_str();
    cout << f << endl;
}
