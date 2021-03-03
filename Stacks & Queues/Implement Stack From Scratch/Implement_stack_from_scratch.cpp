#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int arr[10],top;
    Stack(int size)
    {
        int brr[size];
        brr=arr;
        top=0;
    }
    void push(int key);
    void pop();
    void isEmpty(int key);
    void isFull(int key);
};

void push()
{

}

int main()
{
    Stack stack=new Stack(100);
    stack.push(10);
}