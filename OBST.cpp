#include<bits/stdc++.h>
using namespace std;

class OBST{
	public:
		int w,c,r;
};

void printobst(OBST dp[100][100],int i,int j,int parent,bool isLeft){
	if(i==j){
		return;
	}
	int root = dp[i][j].r;
	if(parent == -1){
		cout<<"k"<<root<<"is root";
	}else{
		if(isLeft){
			cout<<"\nk"<<root<<"is left child of k"<<parent;
		}else{
			cout<<"\nk"<<root<<"is right child of k"<<parent;
	}
  }
  printobst(dp,i,root-1,root,true);
  printobst(dp,root,j,root,false);	
}

void constructobst(int p[],int q[],int n){
	OBST dp[100][100];
	
	for(int len=0;len<=n;len++){
		for(int i=0;i<=n-len;i++){
			int j = i+len;
			if(i==j){
				dp[i][j].w = q[i];
				dp[i][j].c = 0;
				dp[i][j].r = 0;
			}else{
				dp[i][j].w = dp[i][j-1].w + p[j] + q[j];
				
				int minCost = INT_MAX;
				
				for(int k=i+1;k<=j;k++){
					int cost = dp[i][k-1].c+dp[k][j].c;
					
					if(cost<minCost){
						minCost = cost;
						dp[i][j].r = k;
					}
				}
				
				dp[i][j].c = minCost + dp[i][j].w;
			}
		}
	}
	cout<<"\nDP Table:\n\n";
    for(int i=0;i<=n;i++){
        cout<<"\t"<<i<<"\t\t";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<i<<"\t";
        for(int j=0;j<=n;j++){
            if(j<i){
                cout<<"-\t\t";
            }else{
                cout<<"(w="
                <<dp[i][j].w
                <<",c="
                <<dp[i][j].c
                <<",r="
                <<dp[i][j].r
                <<")\t";
            }
        }
        cout<<endl;
    }
    cout<<"\nOptimal Binary Search Tree:\n";
    printobst(dp,0,n,-1,false);
    cout<<endl;
}

int main(){

    int n;
    cout<<"Enter number of keys: ";
    cin>>n;
    int p[n+1];
    int q[n+1];
    cout<<"Enter successful probabilities:\n";
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    cout<<"Enter unsuccessful probabilities:\n";
    for(int i=0;i<=n;i++){
        cin>>q[i];
    }
    constructobst(p,q,n);
    return 0;
}
