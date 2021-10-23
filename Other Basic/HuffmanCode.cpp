#include<bits/stdc++.h>
using namespace std;
struct MinHeapNode{
    char data;
    unsigned freq;
    MinHeapNode *left,*right;
    MinHeapNode(char data,unsigned freq){
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
};
struct compare{
    bool operator()(MinHeapNode *l,MinHeapNode *r){
        return (l->freq > r->freq);
    }
};
void printCode(struct MinHeapNode *top,string str){
    if(top==NULL) return;
    if(top->data!='$')
        cout << top->data <<":" << str << endl;
    printCode(top->left,str+"0");
    printCode(top->right,str+"1");
}
void HuffmanCode(char dataA[],int freqA[],int n){
    struct MinHeapNode *left;
    struct MinHeapNode *right;
    struct MinHeapNode *top;
    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> mh;
    for(int i=0;i<n;i++)
        mh.push(new MinHeapNode(dataA[i],freqA[i]));
    while(mh.size()!=1){
        left=mh.top();
        mh.pop();
        right=mh.top();
        mh.pop();

        top = new MinHeapNode('$',left->freq+right->freq);

        top->left=left;
        top->right=right;

        mh.push(top);
    }
    printCode(mh.top(),"");
}
int main(){
    char arr[]={'a','b','c','d','e','f'};
    int freq[]={5, 9, 12, 13, 16, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    HuffmanCode(arr,freq,n);
    return 0;
}