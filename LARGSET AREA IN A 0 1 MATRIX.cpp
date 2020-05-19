#include<bits/stdc++.h>
using namespace std;
int marea(int hist[],int n)
{
    int tp;
    stack<int>s;
    int i=0;
    int maxarea=0;
    int area;
    while(i<n)
    {
        if(s.empty()||hist[s.top()]<=hist[i])
        {
            s.push(i++);
        }
        else
        {
            tp=s.top();
            s.pop();
            area=hist[tp]*(s.empty()?i:(i-s.top()-1));
            if(area>maxarea)
            maxarea=area;
        }

    }
    while(s.empty()==false)
    {
        tp=s.top();
        s.pop();
        area= hist[tp]*(s.empty()?i:(i-s.top()-1));
        if(area>maxarea)
            maxarea=area;
    }
    return maxarea;

}




int main()
{
    int n,o;
    cin>>n>>o;
    int m[o][n];
    for(int i=0;i<o;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>> m[i][j];
        }

    }
    int temp[n];
    int area=0;
    int maxarea=0;
    for(int i=0;i<o;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(m[i][j]==0)
                temp[j]=0;
            else
                temp[j]+=m[i][j];

        }
        area=marea(temp,n);
       if(area>maxarea)
       {
           maxarea=area;
       }
    }
   cout<< maxarea<< endl;
}
