#include<bits/stdc++.h>
using namespace std;

class Item{
	public:
		int value;
		int weight;
		
		Item(int value,int weight){
			this->value = value;
			this->weight = weight; 
		}
};

bool cmp(Item a,Item b){
	double r1 = (double)a.value/a.weight;
	double r2 = (double)b.value/b.weight;
	return r1>r2;
}

class solution{
	public:
		double fractionalKnapsack(int capacity,vector<Item> arr,int n){
			sort(arr.begin(),arr.end(),cmp);
			double res = 0.0;
			for(int i=0;i<n;i++){
				if(capacity>arr[i].weight){
					res += arr[i].value;
					capacity -= arr[i].weight;
				}else{
					res += arr[i].value * ((double)capacity/arr[i].weight);
					break;
				}
			}
			return res;
		}
};

int main(){
	int n,capacity;
	cout<<"Enter the no of items : ";
	cin>>n;
	cout<<"\n\nEnter the capacity of knapsack : ";
	cin>>capacity;
	vector<Item> arr;
	cout<<"\n\nEnter the value and weight of each item : ";
	for(int i=0;i<n;i++){
		int value,weight;
		cin>>value>>weight;
		arr.push_back(Item(value,weight));
	}
	
	solution sol;
	double maxValue = sol.fractionalKnapsack(capacity,arr,n);
	
	cout<<"Maximum Value in Knapsack : "<<maxValue<<endl;
	
	return 0;
}