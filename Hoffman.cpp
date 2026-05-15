#include<bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left,*right;

    Node(char c,int f){
        ch=c;
        freq=f;
        left=NULL;
        right=NULL;
    }
};

struct Compare{
    bool operator()(Node* a,Node* b){
        return a->freq>b->freq;
    }
};

void encode(Node* root,string code,vector<string>& codes){

    if(root==NULL){
        return;
    }

    if(root->left==NULL && root->right==NULL){
        codes[root->ch]=code;
    }

    encode(root->left,code+"0",codes);
    encode(root->right,code+"1",codes);
}

void huffman(string text){

    vector<int> freq(256,0);

    for(char c:text){
        freq[c]++;
    }

    priority_queue<Node*,vector<Node*>,Compare> pq;

    for(int i=0;i<256;i++){
        if(freq[i]>0){
            pq.push(new Node((char)i,freq[i]));
        }
    }

    while(pq.size()>1){

        Node* left=pq.top();
        pq.pop();

        Node* right=pq.top();
        pq.pop();

        Node* parent=new Node('#',left->freq+right->freq);

        parent->left=left;
        parent->right=right;

        pq.push(parent);
    }

    vector<string> codes(256);

    encode(pq.top(),"",codes);

    cout<<"Character Codes:"<<endl;

    for(int i=0;i<256;i++){
        if(codes[i]!=""){
            cout<<(char)i<<" : "<<codes[i]<<endl;
        }
    }

    cout<<"Encoded : ";

    for(char c:text){
        cout<<codes[c];
    }

    cout<<endl;
}

int main(){

    string text;

    cout<<"Enter text : ";
    cin>>text;

    huffman(text);

    return 0;
}