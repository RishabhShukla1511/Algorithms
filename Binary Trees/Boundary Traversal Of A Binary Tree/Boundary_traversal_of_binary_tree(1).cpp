#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> printBoundary(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void leafNodes(Node *root,vector<int>&boundtrav)
{
    if(root)
    {
        if(root->left==NULL && root->right==NULL)
            boundtrav.push_back(root->data);
        leafNodes(root->left,boundtrav);
        leafNodes(root->right,boundtrav);
    }
}

vector <int> printBoundary(Node *root)
{
    //Your code here
    vector<int>boundtrav;
    if(root==NULL)
        return boundtrav;
    boundtrav.push_back(root->data);
    Node *temp=root->left;
    //if(temp)
    //{
        while(temp)
        {
            if(temp->left || temp->right)
                boundtrav.push_back(temp->data);
            if(temp->left)
                temp=temp->left;
            else if(temp->right)
                temp=temp->right;
            else
                break;
        }
    //}
    temp=root;
    leafNodes(temp,boundtrav);
    temp=root->right;
    vector<int>rightnodes;
    //if(temp)
    //{
        while(temp)
        {
            if(temp->left || temp->right)
                rightnodes.push_back(temp->data);
            if(temp->right)
                temp=temp->right;
            else if(temp->left)
                temp=temp->left;
            else
                break;
        }
    //}
    for(int i=rightnodes.size()-1;i>=0;i--)
        boundtrav.push_back(rightnodes[i]);
    return boundtrav;
}