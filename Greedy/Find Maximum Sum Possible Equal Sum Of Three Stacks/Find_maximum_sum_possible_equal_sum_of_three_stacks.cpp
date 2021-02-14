#include<bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{
    return min(a,min(b,c));
}

int findMaxsum(int stack1[],int stack2[],int stack3[],int s1,int s2,int s3)
{
    int sum1=0,sum2=0,sum3=0;
    for(int i=0;i<s1;i++)
        sum1+=stack1[i];
    for(int i=0;i<s2;i++)
        sum2+=stack2[i];
    for(int i=0;i<s3;i++)
        sum3+=stack3[i];
    int i=0,j=0,k=0;
    while(sum1!=sum2 || sum2!=sum3)
    {
        int minsum=min(sum1,sum2,sum3);
        while(sum1>minsum && i<s1)
        {
            sum1-=stack1[i];
            i++;
        }
        while(sum2>minsum && j<s2)
        {
            sum2-=stack2[j];
            j++;
        }
        while(sum3>minsum && k<s3)
        {
            sum3-=stack3[k];
            k++;
        }
        if(i>=s1 || j>=s2 || k>=s3)
            break;
    }
    if(sum1==sum2 && sum2==sum3)
        return sum1;
    return 0;
}

int main()
{
    int s1;
    cout << "Enter the size of stack1\n";
    cin >> s1;
    int stack1[s1];
    cout << "Enter the elements of stack1\n";
    for(int i=0;i<s1;i++)
        cin >> stack1[i];
    int s2;
    cout << "Enter the size of stack2\n";
    cin >> s2;
    int stack2[s2];
    cout << "Enter the elements of stack2\n";
    for(int i=0;i<s2;i++)
        cin >> stack2[i];
    int s3;
    cout << "Enter the size of stack3\n";
    cin >> s3;
    int stack3[s3];
    cout << "Enter the elements of stack3\n";
    for(int i=0;i<s3;i++)
        cin >> stack3[i];
    cout << "Maximum sum possible is " << findMaxsum(stack1,stack2,stack3,s1,s2,s3);
}