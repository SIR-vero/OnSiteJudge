#include<chrono>
#include<bits/stdc++.h>
#include<windows.h>

using namespace std;
 int main()
 {
     auto start = chrono::high_resolution_clock::now();

     //for (int i = 0; i < 1000000000; i++){}

     Sleep(1000);

     auto e = chrono::high_resolution_clock::now();

     chrono::duration<float> dur = e - start;

     cout << dur.count()*1000.0f << endl;
 }
