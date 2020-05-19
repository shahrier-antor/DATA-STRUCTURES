
#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx];
//int tree[mx*4];
//int lazy[mx*4];
struct info{
    int prop,sum;
}tree[mx*4];

void init(int node,int b,int e)
{
    if(b==e){tree[node].sum=arr[b];return;}
    int left=2*node;
    int right=2*node+1;
    int mid =(b+e)/2;
    init (left,b,mid);
    init (right,mid+1,e);
    tree[node].sum=tree[right].sum+tree[left].sum;
    //tree[node]=max(tree[left],tree[right]);
}
//we are trying to update in a range i,j by some value............
void update(int node,int b,int e,int i,int j,int val)

{
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;

    // if out of range
    if(b>e||b>j||e<i)return;
    // fully in the range
    if(b>=i&&e<=j)
    {
        tree[node].sum+=((e-b+1)*val);
        tree[node].prop+=val;

        return;// this means we have postponed
    }
    // if not fully in the range but overlaps
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
   //then we keep recurring back by getting the values........
    tree[node].sum=tree[left].sum+tree[right].sum+((e-b+1)*tree[node].prop);
    //tree[node]=max(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j,int carry=0)
{
     int left=node<<1;
    int right=(node<<1)+1;
    int mid=(b+e)>>1;

    // if out of range
    if(b>e||b>j||e<i)return 0;
    // fully in the range
    if(b>=i&&e<=j)
    {
        return tree[node].sum+ carry*(e-b+1);
    }
     // if not fully in the range but overlaps
    int p=query(left,b,mid,i,j,carry+tree[node].prop);
    int q=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p+q;
    //return max(p,q);
}
int main()
{
    int n;
    cin>> n;
    for(int i=0;i<n;i++)cin>> arr[i];
    init(1,1,n);
    cout<<query(1,1,n,2,4)<<endl;
    int val;
    cin>> val;
    update(1,1,n,2,4,val);
    cout<<query(1,1,n,2,4)<< endl;
}




