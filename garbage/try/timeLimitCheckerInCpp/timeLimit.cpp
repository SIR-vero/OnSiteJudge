#include<bits/stdc++.h>
#include <chrono>
#include<thread>
#include<windows.h>
using namespace std;
using namespace std::chrono;

static bool stillAlive;
static bool killed = 0;

void kill(){
	int milliSec = 1000;
	Sleep(milliSec);
	if(stillAlive){
		system("taskkill /F /IM a.exe /T");
		killed = 1;
	}
}

int main(){
    system("cd");
	auto start = high_resolution_clock::now();
	std::thread t1(kill);
	stillAlive = 1;
	system("a.exe < in.txt > out.txt");
	stillAlive = 0;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\n\nTime taken by function: "
         << duration.count() << " microseconds\n\n";
	t1.join();
	if(killed)
		cout << "\n\nTLE\n\n";
	else
		cout << "\n\nAC\n\n";
	int n;
	//cin >> n;
}
