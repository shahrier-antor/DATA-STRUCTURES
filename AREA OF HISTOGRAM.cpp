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
    int n;
    cin>> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    cout<<marea(a,n)<< endl;
}
