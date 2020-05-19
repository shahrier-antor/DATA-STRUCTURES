#include<bits/stdc++.h>
using  namespace std;
int parent[100];
int rank[100];
void makeset(int n)
{
    for (int i=0;i<n;i++)
    {
        parent[i]=i;
        //rank[i]=0;
    }
}
/*int findparent(int x)
{
    if(x!=parent[x])findparent(parent[x]);
    else
        return x;
}
/*void unionset(int x,int y)
{
    int px=findparent(x);
    int py=findparent(y);
    if(px==py)return;
    if(rank[px]>rank[py])parent[py]=px;
    else if(rank[px]<rank[py]) parent[px]=py;
    else  parent[py]=px;
    rank[px]++;
}*/
int findparent (int x)
{
    if(parent[x]==x)return x;
     parent[x]=findparent(parent[x]);
     rank[x]++;
     return parent[x];

}
void unionset(int a,int b)
{
    parent[findparent(b)]=findparent(a);
}
void printset(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<< "node "<< i<< "parent "<< parent[i];//<< "rank "<< rank[i]<< endl;
    }
}
int main()
{
    int n;
    cin>> n;
    makeset(n);
    unionset(0,1);
    unionset(4,2);
    unionset(3,1);
    unionset(0,3);
    printset(n);

}
//#include<bits/stdc++.h>
//#define m 10000
//#define sqrsize 100
//using namespace std;

/*int arr[m];
int block[sqrsize];
int blk_size;
void update(int idx,int val)
{
    block[idx/blk_size]+=val-arr[idx];
    arr[idx]=val;
}
int query(int l,int r)
{
  int sum=0;
  while(l<r && l%blk_size!=0 && l!=0)
  {
      sum+= arr[l];
      l++;
  }
  while(l+blk_size<=r)
  {
      sum+=block[l/blk_size];
      l+=blk_size;
  }
  while(l<=r)
  {
      sum+=arr[l];
      l++;
  }
  return sum;
}
void preprocess(int a[],int n)
{
    int blk_idx  =0;
    blk_size=sqrt(n);
    for(int i=0;i<n;i++)
    {
         arr[i]=a[i];
        if(i%blk_size==0)
        {
            blk_idx++;
        }
            block[blk_idx]+=arr[i];
    }
}

int main()
{
    int n;
    int a[n+1];
    cin>>n;
    for(int i=0;i<n;i++)
    {
     cin>> a[i];

    }

   // preprocess(a,n);
    int l,r;
    cin>> l>> r;
    //query(l,r);
}

