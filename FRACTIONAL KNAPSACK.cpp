#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int >PII;
vector<PII>v;
bool cmp(PII a,PII b)
{
    // we want to return a.price/a.weight>b.price/b.weight
    // to keep the precision we multiply by cross
    // price= second....... weight =first
    /// going to sort according to this condition
     return a.second*b.first>b.second*a.first;
}
void fractionalknapsack()
{
    int n,w;
    cin>> n;
    for(int i=0;i<n;i++)
    {
        int weight,price;
        cin>> weight>> price;
        v.push_back(PII(weight,price));
    }
    sort(v.begin(),v.end(),cmp);
    cin>> w;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int z=min(w,v[i].first);
        w-=z;
        ans+=z* v[i].second;
    }
    cout<< ans<< endl;
}
int main()
{
    fractionalknapsack();
}
