#include<bits/stdc++.h>
#include<chrono>
#include<ctime>
using namespace std;
using namespace chrono;

int linearSearch(vector<int> &arr,int n,int target){
	for(int i=0;i<n;i++){
		if(arr[i]==target){
			return 1;
		}
	}
	return 0;
}
//Iterative Binary Search
int binarySearch(vector<int> &arr,int n,int target){
	int low = 0, high = n-1;
	while(low<=high){
	int mid = (high-low)/2 + low;
	if(arr[mid]==target){
		return 1;
	}else if(target>arr[mid]){
		low = mid+1;
	}else{
		high = mid-1;
	 }	
	}
	return 0;
}

// Recursive Binary Search
int recursiveBinarySearch(vector<int> &arr,int n,int low,int high,int target){
	if(low>high) return 0;
	int mid = (high - low)/2 + low;
	if(arr[mid] == target){
		return 1;
	}else if(target>arr[mid]){
		return recursiveBinarySearch(arr,n,mid+1,high,target);
	}else{
		return recursiveBinarySearch(arr,n,low,mid-1,target);
	}
}

int main(){
	const int n = 10000000;
	vector<int> arr(10000000);
	
	srand(time(0));
	
	for(int i=0;i<n;i++){
		arr[i] = rand() % 100000;
	}
	
	int key = -1;
	
	cout<<"Array size : "<<n<<endl;
	cout<<"Searching element : "<<key<<"\n\n\n";
	
	auto start1 = chrono::high_resolution_clock::now();
	int found = linearSearch(arr,n,key);
	auto end1 = chrono::high_resolution_clock::now();
	
	cout<<"Linear Search : "
	<<(found ? "FOUND" : "NOT FOUND")<<endl;
	cout<<"Time : "
	<<duration_cast<milliseconds>(end1-start1).count()
	<<"milliseconds\n\n";
	
	sort(arr.begin(),arr.end());     //For Binary Search
	
	auto start2 = chrono::high_resolution_clock::now();
	for(int i=0;i<10000000;i++){
    found = binarySearch(arr,n,key);
}
	auto end2 = chrono::high_resolution_clock::now();
	
	cout<<"Binary iterative Search : "
	<<(found ? "FOUND" : "NOT FOUND")<<endl;
	cout<<"Time : "
	<<duration_cast<nanoseconds>(end2-start2).count()
	<<"nanoseconds\n\n";
	
	auto start3 = high_resolution_clock::now();
	for(int i=0;i<100000;i++){
    found = recursiveBinarySearch(arr,n,0,n-1,key);
}
	auto end3 = high_resolution_clock::now();
	
	cout<<"Recursive Binary Search : "
	<<(found ? "FOUND" : "NOT FOUND")<<endl;
	cout<<"Time : "
	<<duration_cast<nanoseconds>(end3-start3).count()
	<<"nanoseconds\n\n";
	
	return 0;
	
}

