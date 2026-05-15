#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;

long long karatsuba(long long x, long long y){
	if(x<10 || y<10) return x*y;
	
	int n = max(to_string(x).size(),to_string(y).size());
	int m = n/2;
	
	long long p = pow(10,m);
	long long a = x/p;
	long long b = x%p;
	long long c = y/p;
	long long d = y%p;
	
	long long ac = karatsuba(a,c);
	long long bd = karatsuba(b,d);
	
	long long adbc = karatsuba(a+b,c+d) - ac - bd;
	
	return ac*pow(10,2*m) + adbc*pow(10,m) + bd;
}

int main(){
	srand(time(0));
	long long x = rand() % 1000000;
	long long y = rand() % 1000000;
	
	auto start = high_resolution_clock::now();
	long long res = karatsuba(x,y);
	auto end = high_resolution_clock::now();
	
	cout<<"The multiplication of "<<x<<" and "<<y<<" is "<<res<<endl;
	cout<<"Time required to do multiplication is "
	<<duration_cast<microseconds>(end-start).count();
	
	return 0;
}