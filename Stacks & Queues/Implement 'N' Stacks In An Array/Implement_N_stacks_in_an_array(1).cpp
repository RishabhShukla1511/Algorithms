#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cout << "Enter the size of array\n";
    cin >> n;
    cout << "Enter the number of stacks\n";
    cin >> k;
    int arr[n],start[k],end[k],curr[k],pos=0;
    for(int i=0;i<k;i++)
    {
        start[i]=pos;
        curr[i]=pos-1;
        pos+=n/k;
        end[i]=pos-1;
    }
    end[k-1]=n-1;
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
            {
                if(curr[stack_number]<end[stack_number])
                    arr[++curr[stack_number]]=val;
                else
                    cout << stack_number << " Stack Overflow\n";
            }
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
                if(curr[stack_number]>=start[stack_number])
                {
                    cout << "Popped element from stack is " << arr[curr[stack_number]] << '\n';
                    curr[stack_number]--;
                }
                else
                    cout << "Empty Stack\n";
            }
        }
    }
}