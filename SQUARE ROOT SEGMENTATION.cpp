#include<bits/stdc++.h>
#define m 10000
#define sqrsize 100
using namespace std;

int arr[10000];
int block[100];
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
void prepr(int a[],int n)
{
    int blk_idx  =-1;
    blk_size= sqrt(n);
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

    cin>>n;
     int a[n+1];
    for(int i=0;i<n;i++)
    {
     cin>> a[i];

    }

    prepr(a,n);
    int l,r;
    cin>> l>> r;
   cout<< query(l,r)<<
   endl;
}
