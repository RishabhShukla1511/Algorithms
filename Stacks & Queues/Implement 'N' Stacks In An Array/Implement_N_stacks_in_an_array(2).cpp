#include<bits/stdc++.h>
using namespace std;

struct kstacks{
    int *arr,*top,*next,free=0;
    kstacks(int n,int k)
    {
        arr=new int[n];
        next=new int[n];
        top=new int[k];
        for(int i=0;i<k;i++)
            top[i]=-1;
        for(int i=0;i<n;i++)
            next[i]=i+1;
        next[n-1]=-1;
    }
    bool isFull(){return free==-1;};
    bool isEmpty(int stack_number){return top[stack_number]==-1;};
    void push(int stack_number,int val);
    int pop(int stack_number);
};

void kstacks::push(int stack_number,int val)
{
    if(isFull())
        cout << "Stack Overflow\n";
    else
    {
        int pos=free;
        free=next[pos];
        next[pos]=top[stack_number];
        top[stack_number]=pos;
        arr[pos]=val;
    }
}

int kstacks::pop(int stack_number)
{
    if(isEmpty(stack_number))
    {
        cout << "Stack Underflow\n";
        return INT_MAX;
    }
    else
    {
        int pos=top[stack_number];
        top[stack_number]=next[pos];
        next[pos]=free;
        free=pos;
        return arr[pos];
    }
}

int main()
{
    int n,k;
    cout << "Enter the size of array\n";
    cin >> n;
    cout << "Enter the number of stacks\n";
    cin >> k;
    kstacks *stack=new kstacks(n,k);
    while(1)
    {
        cout << "1) Enter 1 to push\n2) 2 to pop\n3) -1 to exit\n";
        cout << "Enter your choice\n";
        int choice;
        cin >> choice;
        if(choice==-1)
            break;
        if(choice==1)
        {
            cout << "Enter stack number and value\n";
            int stack_number,val;
            cin >> stack_number >> val;
            if(stack_number==-1)
                break;
            if(stack_number<0 || stack_number>=k)
                cout << "Invalid Stack Number should be between [0," << k-1 << "]\n";
            else
                stack->push(stack_number,val);
        }
        else if(choice==2)
        {
            cout << "Enter stack number\n";
            int stack_number;
            cin >> stack_number;
            if(stack_number<0 || stack_number>=k)
                cout << "Invalid Stack Number should be between [0," << k-1 << "]\n";
            else
            {
                int a=stack->pop(stack_number);
                if(a!=INT_MAX)
                    cout << "Popped element is " << a << '\n';
            }
        }
    }
}