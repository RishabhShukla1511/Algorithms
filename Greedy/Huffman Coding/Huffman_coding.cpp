#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    int freq;
    Node *left,*right;
    Node(char data,int freq)
    {
        this->data=data;
        this->freq=freq;
        left=right=NULL;
    }
};

void print(Node *root,string code)
{
    if(!root)
        return;
    if(root->data!='?')
        cout << root->data << " - " << code << '\n';
    print(root->left,code+"0");
    print(root->right,code+"1");
}

struct cmp
{
    bool operator()(Node* n1,Node* n2)
    {
        return n1->freq>n2->freq;
    }
};

void huffmanCoding(pair<char,int>arr[],int n)
{
    priority_queue<Node*,vector<Node*>,cmp>pq;
    for(int i=0;i<n;i++)
    {
        Node *root=new Node(arr[i].first,arr[i].second);
        pq.push(root);
    }
    while(pq.size()!=1)
    {
        Node *left=pq.top();
        pq.pop();
        Node *right=pq.top();
        pq.pop();
        Node *root=new Node('?',left->freq+right->freq);
        root->left=left;
        root->right=right;
        pq.push(root);
    }
    Node *root=pq.top();
    pq.pop();
    string code="";
    cout << "Huffman Encoding of the characters is as follows:\n";
    print(root,code);
}

int main()
{
    cout << "Implementing Huffman Coding - Min Heap - using STL Priority Queue\n";
    int n;
    cout << "Enter the number of characters\n";
    cin >> n;
    pair<char,int>arr[n];
    cout << "In the following " << n << " lines enter a character along with its freq separated by space\n";
    for(int i=0;i<n;i++)
    {
        char c;
        int freq;
        cin >> c >> freq;
        arr[i]={c,freq};
    }
    huffmanCoding(arr,n);
}