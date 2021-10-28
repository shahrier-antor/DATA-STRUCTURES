#include<bits/stdc++.h>
#define mx 100
using namespace std ;
int p[mx];
  int vertex,ed;
void makeset(int n)
{
    for(int i=0;i<n;i++)
        p[i]=i;
}
struct edge{
    int u,w,v;
};
// the below function is responsible for sorting according
// to weight.
bool operator<(edge a,edge b)
{

    return a.w<b.w;
}
vector<edge>e;
int find(int x)
{
    if(p[x]==x)return  x;
    return p[x]=find(p[x]);
}
void k()
{
    sort(e.begin(),e.end());
    int ans=0;
    int sz=e.size();
    for(int i=0;i<sz;i++)
    {
        if(find(e[i].u)!=find(e[i].v))
        {
            p[p[e[i].u]]=p[e[i].v];
            ans+=e[i].w;
        }
    }
    cout<< ans<< endl ;
}
int main()
{
    freopen("input.txt","r",stdin);

    cin>> vertex>> ed;
    makeset(vertex);
    for(int i=0;i<ed;i++)
    {
        edge l;
        cin>> l.u>>l.v>>l.w;
        e.push_back(l);
    }

    k();

      for(int i=0;i<ed;i++)
    {
        cout<< e[i].u<< " "<<e[i].v<< " "<<e[i].w<< endl;
    }
}
