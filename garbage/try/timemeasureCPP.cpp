#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main(){
	auto start = high_resolution_clock::now();
	system("a < in.txt > out.txt");
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\n\nTime taken by function: "
         << duration.count() << " microseconds\n\n";
}