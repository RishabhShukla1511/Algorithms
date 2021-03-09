#include<bits/stdc++.h>
using namespace std;

bool isStackPermutataions(queue<int>input,queue<int>output)
{
    stack<int>s;
    while(!input.empty())
    {
        s.push(input.front());
        while(!s.empty() && s.top()==output.front())
        {
            output.pop();
            s.pop();
        }
        input.pop();
    }
    while(!s.empty() && s.top()==output.front())
    {
        output.pop();
        s.pop();
    }
    return (s.empty() && output.empty());    
}

int main()
{
    int n;
    cout << "Enter the length of input queue\n";
    cin >> n;
    queue<int>input;
    cout << "Enter the input queue\n";
    for(int i=0;i<n;i++)
    {
        int val;
        cin >> val;
        input.push(val);
    }
    int m;
    cout << "Enter the length of output queue\n";
    cin >> m;
    queue<int>output;
    cout << "Enter the output queue\n";
    for(int i=0;i<n;i++)
    {
        int val;
        cin >> val;
        output.push(val);
    }
    if(isStackPermutataions(input,output))
        cout << "Yes, output queue is a stack permutation of input queue";
    else
        cout << "No, output queue is not a stack permutation of input queue";
}