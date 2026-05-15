#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;

int partition(vector<int> &arr,int left,int right){
	int i = left-1;
	int pivot = arr[right];
	for(int j=left;j<right;j++){
		if(arr[j]<pivot){
			swap(arr[++i],arr[j]);
		}
	}
	swap(arr[i+1],arr[right]);
	return i+1;
}

int randomPartition(vector<int> &arr,int left,int right){
	int randomIndex = left + rand()%(right-left+1);
	swap(arr[randomIndex],arr[right]);
	return partition(arr,left,right);
}

void randomizedQuickSort(vector<int> &arr,int left,int right){
	if(left<right){
		int p = randomPartition(arr,left,right);
		randomizedQuickSort(arr,left,p-1);
		randomizedQuickSort(arr,p+1,right);
	}
}

void printArray(vector<int> &arr){
	for(int x : arr){
		cout<<x<<" ";
	}
	cout<<endl;
}

int main(){
	srand(time(0));
	int n;
	cout<<"Enter the no of elements : ";
	cin>>n;
	cout<<"Enter the array elements : ";
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Orginal array : ";
	printArray(arr);
	
	auto start = high_resolution_clock::now();
	randomizedQuickSort(arr,0,arr.size()-1);
	auto end = high_resolution_clock::now();
	
	double duration = duration_cast<milliseconds>(end-start).count();
	
	cout<<"Sorted array :";
	printArray(arr);
	
	cout<<"Time taken : "<<duration<<endl;
	
	return 0;
	
}