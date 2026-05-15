#include<bits/stdc++.h>
using namespace std;

class Item{
	public:
		float weight,value;
		
		Item(float weight,float value){
			this->weight = weight;
			this->value = value;
		}
};

class Node{
	public:
		int level;
		float weight;
		float profit;
		float bound;
};

bool cmp(Item a,Item b){
	return (a.value/a.weight) > (b.value/b.weight);
}

float bound(Node u,int n,int w,vector<Item> arr){
	if(u.weight>w) return 0;
	
	float profitBound = u.profit;
	int j = u.level+1;
	float totalWeight = u.weight;
	
	while(j<n && totalWeight + arr[j].weight <=w){
		totalWeight += arr[j].weight;
		profitBound += arr[j].value;
		j++;
	}
	
	if(j<n){
		profitBound += arr[j].value*((float)(w-totalWeight)/arr[j].weight);
	}
	return profitBound;
}

float knapsack(float w,vector<Item> arr,int n){
	sort(arr.begin(),arr.end(),cmp);
	
	queue<Node> q;
	Node u,v;
	
	u.level = -1;
	u.profit = 0;
	u.weight = 0;
	
	q.push(u);
	
	float maxProfit = 0;
	while(!q.empty()){
		u = q.front();
		q.pop();
		
		if(u.level == n-1){
		continue;
	}
	
	v.level = u.level+1;
	v.profit = u.profit + arr[v.level].value;
	v.weight = u.weight + arr[v.level].weight;
	
	if(v.weight<=w && v.profit>maxProfit){
		maxProfit = v.profit;
	}
	v.bound = bound(v,n,w,arr);
	
	if(v.bound>maxProfit){
		q.push(v);
	}
	
	v.weight = u.weight;
	v.profit = u.profit;
	
	v.bound = bound(v,n,w,arr);
	
	if(v.bound>maxProfit){
		q.push(v);
	  }
	}
	
	return maxProfit;	 
}

int main() {
    int n;
    float W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> arr;

    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        float w, v;
        cin >> w >> v;
        arr.push_back(Item(w, v));
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    float maxProfit = knapsack(W, arr, n);

    cout << "Maximum possible profit = " << maxProfit << endl;

    return 0;
}