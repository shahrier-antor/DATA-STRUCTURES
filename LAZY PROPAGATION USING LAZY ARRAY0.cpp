
#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx];
int tree[mx*4];
int lazy[mx*4];
void init(int node,int b,int e)
{
    if(b==e){tree[node]=arr[b];return;}
    int left=2*node;
    int right=2*node+1;
    int mid =(b+e)/2;
    init (left,b,mid);
    init (right,mid+1,e);
    tree[node]=tree[right]+tree[left];
    //tree[node]=max(tree[left],tree[right]);
}
//we are trying to update in a range i,j by some value............
void update(int node,int b,int e,int i,int j,int val)

{
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
// updating the main tree if the lazy tree is not updated
//and propagating the value to the child of the next node of the lazy tree
    if (lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(b!=e)
        {
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];

        }
        lazy[node]=0;
    }
    // if out of range
    if(b>e||b>j||e<i)return;
    // fully in the range
    if(b>=i&&e<=j)
    {
        tree[node]+=val;
        if(b!=e)
        {
            //now we are postponing the propagation by only updating the range
            // and assigning the value to the lazy tree;
            lazy[left]+=val;
            lazy[right]+=val;
        }
        return;// this means we have postponed
    }
    // if not fully in the range but overlaps
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
   //then we keep recurring back by getting the values........
    tree[node]=tree[left]+tree[right];
    //tree[node]=max(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j)
{
     int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(b!=e)
        {
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node]=0;
    }
    // if out of range
    if(b>e||b>j||e<i)return 0;
    // fully in the range
    if(b>=i&&e<=j)
    {
        return tree[node];
    }
     // if not fully in the range but overlaps
    int p=query(left,b,mid,i,j);
    int q=query(right,mid+1,e,i,j);
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



