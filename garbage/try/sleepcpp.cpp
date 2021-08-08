#include<bits/stdc++.h>
#include <chrono>
#include<thread>
#include<windows.h>
using namespace std;
using namespace std::chrono;


int main(){
	auto start = high_resolution_clock::now();
	Sleep(2000);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\n\nTime taken by function: "
         << duration.count() << " microseconds\n\n";
	int n;
	cin >> n;
}