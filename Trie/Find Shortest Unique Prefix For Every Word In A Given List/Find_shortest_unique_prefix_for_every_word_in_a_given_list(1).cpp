#include<bits/stdc++.h>
#define alphabet_size 26
using namespace std;

struct Node
{
    Node* children[alphabet_size];
    bool isEndofWord;
    int noofEndingWords;
    Node()
    {
        for(int i=0;i<alphabet_size;i++)
            children[i]=NULL;
        isEndofWord=false;
        noofEndingWords=0;
    }
};

int getIndex(char c)
{
    return (c-'a');
}

char getChar(int val)
{
    return (val+'a');
}

void insert(Node *root,string key)
{
    Node *temp=root;
    for(int i=0;i<key.length();i++)
    {
        int index=getIndex(key[i]);
        if(!temp->children[index])
            temp->children[index]=new Node();
        temp=temp->children[index];
    }
    temp->isEndofWord=true;
    return;
}

Node *createTrie(string words[],int n)
{
    Node *root=new Node();
    for(int i=0;i<n;i++)
        insert(root,words[i]);
    return root;
}

int countChildren(Node *root)
{
    int cnt=0;
    if(root->isEndofWord)
        cnt++;
    for(int i=0;i<alphabet_size;i++)
    {
        if(root->children[i])
            cnt+=countChildren(root->children[i]);
    }
    root->noofEndingWords=cnt;
    return cnt;
}

void shortestUniquePrefix(Node *root,string prefix)
{
    if(root->noofEndingWords==1)
    {
        cout << prefix << " ";
        return;
    }
    for(int i=0;i<alphabet_size;i++)
    {
        if(root->children[i])
            shortestUniquePrefix(root->children[i],prefix+getChar(i));
    }
    return;
}

int main()
{
    int n;
    cout << "Enter the number of words\n";
    cin >> n;
    string words[n];
    cout << "Enter the words\n";
    for(int i=0;i<n;i++)
        cin >> words[i];
    Node *root=createTrie(words,n);
    root->noofEndingWords=countChildren(root);
    shortestUniquePrefix(root,"");
    return 0;
}