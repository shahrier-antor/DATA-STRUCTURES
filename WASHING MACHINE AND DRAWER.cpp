
#include<bits/stdc++.h>
#define mx 100
using namespace std;
typedef pair<int ,int > PII;
vector<PII>v;

bool cmp(PII a,PII b)
{
    // i am going to sort according to this condition

    return a.first+max(a.second,b.first)+b.second<=b.first+max(b.second,a.first)+a.second;
}


void mintimewashing()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int wash,dry;
        cin>> wash>> dry;
        v.push_back(PII(wash,dry));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
        cout<< v[i].first<<" "<< v[i].second<< endl;
    }

}
int main()
{
    mintimewashing();

}
