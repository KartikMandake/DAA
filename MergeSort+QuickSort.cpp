#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;

void merge(vector<int> &arr,int left,int mid,int right){
	vector<int> temp;
	
	int i=left,j=mid+1;
	
	while(i<=mid && j<=right){
		if(arr[i]<=arr[j]){
			temp.push_back(arr[i++]);
		}else{
			temp.push_back(arr[j++]);
		}
	}
	while(i<=mid){
		temp.push_back(arr[i++]);
	}
	while(j<=right){
		temp.push_back(arr[j++]);
	}
	
	for(int k=0;k<temp.size();k++){
		arr[left+k] = temp[k];
	}
}

void mergeSort(vector<int> &arr,int left,int right){
	if(left>=right) return;
	int mid = (left+right)/2;
	mergeSort(arr,left,mid);
	mergeSort(arr,mid+1,right);
	merge(arr,left,mid,right);
}

int partition(vector<int> &arr,int left,int right){
		int pivot = arr[right];
		int i = left-1;
		for(int j=left;j<right;j++){
			if(arr[j]<pivot){
				swap(arr[++i],arr[j]);
			}
		}
		swap(arr[i+1],arr[right]);
		return i+1;
}

void quickSort(vector<int> &arr,int left,int right){
	if(left<right){
		int p = partition(arr,left,right);
		quickSort(arr,left,p-1);
		quickSort(arr,p+1,right);
	}
}

int main(){
	srand(time(0));
	
	vector<int> arr1(50000), arr2;

    for (int& x : arr1) x = rand()%10000;
    arr2 = arr1;
    
	auto start1 = high_resolution_clock::now();
    mergeSort(arr1, 0, arr1.size() - 1);
    auto end1 = high_resolution_clock::now();
    cout << "Merge Sort Time: "
         << duration_cast<milliseconds>(end1 - start1).count() << " ms\n";

    auto start2 = high_resolution_clock::now();
    quickSort(arr2, 0, arr2.size() - 1);
    auto end2 = high_resolution_clock::now();
    cout << "Quick Sort Time: "
         << duration_cast<milliseconds>(end2 - start2).count() << " ms\n";
}