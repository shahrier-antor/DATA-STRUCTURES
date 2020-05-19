#include<bits/stdc++.h>
#define mx 100001
using namespace std;

int arr[mx];
int bit[mx+1];
void update(int idx,int val,int s)
{
    while(idx<=s+1)
    {
        bit[idx]+=val;
        idx+=(idx&-idx);
    }
}
//count sum from start top idx
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=bit[idx];
        idx-=(idx&-idx);

    }
    return sum;
}
void createtree(int n)
{
    for(int i=1;i<=n;i++)
    {
        update(arr[i-1],i,n);
    }
}
int main()
{
    int n;
    cin>> n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    createtree(n);
    int idx;
    cin>> idx;
    cout<< read(idx)<< endl;

}
