#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Node{
public:
    vector<vector<int>> mat;
    int cost;
    int level;
    int city;
    vector<int> path;

    bool operator>(const Node &other) const{
        return cost > other.cost;
    }
};

class TSP{
private:
    int n;
    vector<vector<int>> dist;
    int bestCost;
    vector<int> bestPath;

public:
    TSP(int n,vector<vector<int>> dist){
        this->n=n;
        this->dist=dist;
        bestCost=INF;
    }

    int reduceMatrix(vector<vector<int>> &mat){
        int reduction=0;

        // Row reduction
        for(int i=0;i<n;i++){
            int mn=INF;

            for(int j=0;j<n;j++){
                mn=min(mn,mat[i][j]);
            }

            if(mn!=INF && mn!=0){
                reduction+=mn;

                for(int j=0;j<n;j++){
                    if(mat[i][j]!=INF){
                        mat[i][j]-=mn;
                    }
                }
            }
        }

        // Column reduction
        for(int j=0;j<n;j++){
            int mn=INF;

            for(int i=0;i<n;i++){
                mn=min(mn,mat[i][j]);
            }

            if(mn!=INF && mn!=0){
                reduction+=mn;

                for(int i=0;i<n;i++){
                    if(mat[i][j]!=INF){
                        mat[i][j]-=mn;
                    }
                }
            }
        }

        return reduction;
    }

    void solve(){
        priority_queue<Node,vector<Node>,greater<Node>> pq;

        Node root;

        root.mat=dist;
        root.level=0;
        root.city=0;
        root.path.push_back(0);

        root.cost=reduceMatrix(root.mat);

        pq.push(root);

        while(!pq.empty()){
            Node curr=pq.top();
            pq.pop();

            if(curr.cost>=bestCost){
                continue;
            }

            // All cities visited
            if(curr.level==n-1){
                if(curr.mat[curr.city][0]!=INF){

                    int total=
                        curr.cost+
                        curr.mat[curr.city][0];

                    if(total<bestCost){
                        bestCost=total;

                        bestPath=curr.path;
                        bestPath.push_back(0);
                    }
                }

                continue;
            }

            // Generate children
            for(int next=0;next<n;next++){

                if(curr.mat[curr.city][next]==INF){
                    continue;
                }

                bool visited=false;

                for(int p:curr.path){
                    if(p==next){
                        visited=true;
                        break;
                    }
                }

                if(visited){
                    continue;
                }

                Node child;

                child.mat=curr.mat;
                child.level=curr.level+1;
                child.city=next;

                child.path=curr.path;
                child.path.push_back(next);

                int edgeCost=
                    curr.mat[curr.city][next];

                // Remove row and column
                for(int k=0;k<n;k++){
                    child.mat[curr.city][k]=INF;
                    child.mat[k][next]=INF;
                }

                int reduction=
                    reduceMatrix(child.mat);

                child.cost=
                    curr.cost+
                    edgeCost+
                    reduction;

                if(child.cost<bestCost){
                    pq.push(child);
                }
            }
        }
    }

    void printResult(){
        if(bestCost==INF){
            cout<<"No solution\n";
        }
        else{
            cout<<"\nOptimal Cost: "<<bestCost<<endl;

            cout<<"Path: ";

            for(int i=0;i<bestPath.size();i++){
                cout<<bestPath[i];

                if(i+1<bestPath.size()){
                    cout<<" -> ";
                }
            }

            cout<<endl;
        }
    }
};

int main(){
    int n;

    cout<<"Enter number of cities: ";
    cin>>n;

    vector<vector<int>> dist(
        n,
        vector<int>(n)
    );

    cout<<"Enter distance matrix:\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            int x;
            cin>>x;

            if(i==j){
                dist[i][j]=INF;
            }
            else if(x==-1){
                dist[i][j]=INF;
            }
            else{
                dist[i][j]=x;
            }
        }
    }

    TSP tsp(n,dist);

    tsp.solve();

    tsp.printResult();

    return 0;
}