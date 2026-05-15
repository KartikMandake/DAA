#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;

int mn,mx,steps;

void minMaxSimple(vector<int> &arr){
	int n = arr.size();
	mn = arr[0];
	mx = arr[0];
	
	for(int i=0;i<n;i++){
		steps++;
		if(arr[i]<mn){
			mn = arr[i];
		}
		steps++;
		if(arr[i]>mx){
			mx = arr[i];
		}
	}
}

void minMaxDivideConquer(vector<int> &arr,int i,int j){
	if(i==j){
		mn = mx = arr[i];
		return;
	}
	if(j==i+1){
		steps++;
		if(arr[i]<arr[j]){
			mn = arr[i];
			mx = arr[j];
		}else{
			mn = arr[j];
			mx = arr[i];
		}
		return;
	}
	
	int leftmin,leftmax,rightmin,rightmax;
	
	int mid = (i+j)/2;
	
	minMaxDivideConquer(arr,i,mid);
	leftmin = mn;
	leftmax = mx;
	
	minMaxDivideConquer(arr,mid+1,j);
	rightmin = mn;
	rightmax = mx;
	
	steps++;
	mn = (leftmin < rightmin) ? leftmin : rightmin;
	
	steps++;
	mx = (leftmax > rightmax) ? leftmax : rightmax; 
}

int main(){
	srand(time(0));
//	int n;
//	cout<<"Enter the no of elements : ;
//	cin>>n;
//	
//	vector<int> arr(n);
//	for(int i=0;i<n;i++){
//		cin>>arr[i];
//	}
	
	const int n = 500;
	vector<int> arr(500);
	cout<<"Array Elements : ";
	for(int i=0;i<n;i++){
		arr[i] = rand()%10000;
		cout<<arr[i]<<" ";
	}
	
	cout<<"\n\n";
	
	auto start1 = high_resolution_clock::now();
    minMaxSimple(arr);
    auto end1 = high_resolution_clock::now();

    cout << "Simple Method:\n";
    cout << "Minimum = " << mn << endl;
    cout << "Maximum = " << mx << endl;
    cout << "Step count = " << steps << endl;
    cout << "Execution Time = "
         << duration_cast<nanoseconds>(end1 - start1).count()
         << " nanoseconds\n\n";

    // -------- Divide and Conquer --------
    steps = 0;

    auto start2 = high_resolution_clock::now();
    minMaxDivideConquer(arr, 0, n - 1);
    auto end2 = high_resolution_clock::now();

    cout << "Divide and Conquer Method:\n";
    cout << "Minimum = " << mn << endl;
    cout << "Maximum = " << mx << endl;
    cout << "Step count = " << steps << endl;
    cout << "Execution Time = "
         << duration_cast<nanoseconds>(end2 - start2).count()
         << " nanoseconds\n";

    return 0;
}