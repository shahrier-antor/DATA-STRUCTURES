#include<bits/stdc++.h>
using namespace std;
#define max 100
typedef pair<int,int >PII;
vector<PII>v[max];
struct node
{
    int u;
    int cost;
};
bool operator<(node a ,node b)
{
   // priority queue arrage in boro theke   choto
   return a.cost>b.cost;
}
priority_queue<node>pq;
int cost[max];
bool taken[max];
int vertex,edge;
int prim(int source)
{
    for(int i=0;i<vertex;i++)
    {
        cost[i]=INT_MAX,taken[i]=false;
    }
    cost[source]=0;
    node temp;
    temp.u=source;
    temp.cost=0;
    pq.push(temp);
    int ans=0;
    while(!pq.empty())
    {
        node current=pq.top();
        pq.pop();
        if(taken[current.u])continue;
        taken[current.u]=true;
        ans+=current.cost;
        cout<< ans<< endl;
        for(int i=0;i<v[current.u].size();i++)
        {
            if(taken[v[current.u][i].first])
            {
                continue;
            }
            if(v[current.u][i].second<cost[v[current.u][i].first])
            {
                node temp2;
                temp2.u=v[current.u][i].first;
                temp2.cost=v[current.u][i].second;
                pq.push(temp2);
                cost[v[current.u][i].first]=v[current.u][i].second;
            }
        }

    }
return ans;
}
void printg()
{
    for(int i=0;i<vertex;i++)
    {
        cout<< i<< "--";
        for(int j=0;j<v[i].size();j++)
        {
            cout<< v[i][j].first<< "-"<< v[i][j].second<< " ";
        }cout<< endl;
    }cout<< endl;
}
int main()

{
    freopen("input.txt","r",stdin);
    cin>> vertex>>edge;
    for(int i=0;i<edge;i++)
    {
        int source;
        PII p;
        cin>> source>> p.first>> p.second;
        v[source].push_back(p);
        int source2=p.first;
        p.first=source;
        v[source2].push_back(p);
    }
    printg();
    cout<< prim(0)<< endl;
}
