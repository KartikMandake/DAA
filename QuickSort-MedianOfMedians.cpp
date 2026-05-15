#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;

int partition(vector<int> &arr,int left,int right,int pivot){
	int i;
	for(i=left;i<=right;i++){
		if(arr[i]==pivot) break;
	}
	swap(arr[i],arr[right]);
	i = left-1;
	for(int j=left;j<right;j++){
		if(arr[j]<pivot){
			swap(arr[++i],arr[j]);
		}
	}
	swap(arr[i+1],arr[right]);
	return i+1;
}

int findMedian(vector<int> &arr,int left,int n){
	sort(arr.begin()+left,arr.begin()+left+n);
	return arr[left+n/2];
}

int medianOfMedians(vector<int> &arr,int left,int right)
{
    int n = right-left+1;

    vector<int> medians;

    int i;

    for(i=0;i<n/5;i++)
    {
        medians.push_back(
            findMedian(arr,left+i*5,5)
        );
    }

    if(i*5 < n)
    {
        medians.push_back(
            findMedian(arr,left+i*5,n%5)
        );
    }

    if(medians.size()==1)
    {
        return medians[0];
    }

    return medianOfMedians(medians,0,medians.size()-1);
}

void quickSortMedian(vector<int> &arr, int left, int right)
{
    if(left < right)
    {
        int pivot = medianOfMedians(arr, left, right);
        int pi = partition(arr, left, right, pivot);
        quickSortMedian(arr, left, pi - 1);
        quickSortMedian(arr, pi + 1, right);
    }
}

// ---------- Middle Pivot Quick Sort ----------

int partitionMiddle(vector<int> &arr, int low, int high)
{
    int mid = (low + high) / 2;
    int pivot = arr[mid];
    swap(arr[mid], arr[high]);
    int i = low;
    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSortMiddle(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int pi = partitionMiddle(arr, low, high);

        quickSortMiddle(arr, low, pi - 1);
        quickSortMiddle(arr, pi + 1, high);
    }
}

// ---------- Main ----------

int main()
{
    int n = 50000;
    vector<int> arr1(n), arr2(n);
    srand(time(0));
    for(int i = 0; i < n; i++)
        arr1[i] = rand() % 100000;
    arr2 = arr1;

    // ----- Median of Medians Timing -----
    
    auto start1 = high_resolution_clock::now();
    quickSortMedian(arr1, 0, n-1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);

    // ----- Middle Pivot Timing -----

    auto start2 = high_resolution_clock::now();
    quickSortMiddle(arr2, 0, n-1);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2);

    cout << "Time using Median of Medians Pivot: "
         << duration1.count() << " ms" << endl;

    cout << "Time using Middle Pivot: "
         << duration2.count() << " ms" << endl;

    return 0;
}