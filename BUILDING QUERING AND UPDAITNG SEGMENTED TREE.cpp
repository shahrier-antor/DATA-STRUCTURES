/*#include<bits/stdc++.h>

#define mx 100001

using namespace std;


int arr[mx];
int tree[mx*4];
int global;

void init(int node, int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }

    int left=2*node;
    int right=(2*node )+1;

    int mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node]=(tree[left]+tree[right]);


}

int query(int node,int b,int e,int i,int j)
{
    if(j<b || i>e) return 0;

    if(b>=i && e<=j)
    {
        return tree[node];
    }

    int left=2*node;
    int right=(2*node)+1;
    int mid=(b+e)/2;

    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);

    return p1+p2;
}

void update(int node,int b,int e,int i,int val)
{
    if(i<b || i>e) return ;

    if(b==e)
    {
        global=tree[node];

        tree[node]=val;
        return ;
    }

    int left=2*node;
    int right=(2*node)+1;
    int mid=(b+e)/2;

    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);

    tree[node]=tree[left]+tree[right];
}

void update1(int node,int b,int e,int i,int val)
{
    if(i<b || i>e) return ;

    if(b==e)
    {
        global=tree[node];

        tree[node]=global+val;
        return ;
    }

    int left=2*node;
    int right=(2*node)+1;
    int mid=(b+e)/2;

    update1(left,b,mid,i,val);
    update1(right,mid+1,e,i,val);

    tree[node]=tree[left]+tree[right];
}



int main()
{

    int t,n,q,l,r,ans,v;
    scanf("%d",&t);

   for(int ca=1;ca<=t;ca++)
   {


       scanf("%d%d",&n,&q);

       for(int i=1;i<=n;i++) scanf("%d",&arr[i]);


       init(1,1,n);



       printf("Case %d:\n",ca);

       for(int i=1;i<=q;i++)
       {
           scanf("%d",&l);

           if(l==1)
           {
               scanf("%d",&r);
               update(1,1,n,r+1,0);
                printf("%d\n",global);
           }
           else if(l==2)
           {
               scanf("%d%d",&r,&v);

               update1(1,1,n,r+1,v);

           }
           else if(l==3)
           {
               scanf("%d%d",&r,&v);
               ans=query(1,1,n,r+1,v+1);
           printf("%d\n",ans);

           }


       }


   }

}
*/



// query postion strats from 1..........................


/*#include<bits/stdc++.h>
using namespace std;
#define mx 500005
int tree[mx*4];
int n,q;
int ans=0;
int gcd(int a,int b){
     if(b==0) return a;
     return gcd(b,a%b);
}
void build(int i,int l,int r){
    if(l==r){
        scanf("%d",&tree[i]);
        return;

    }
    int mid = (l+r)/2;
    int left=2*i;
    int right= (2*i)+1;
    build(left,l,mid);
    build(right,mid+1,r);
   tree[i]=gcd(tree[left],tree[right]);
   // tree[i]=tree[left]+tree[right];

}
void update(int i,int l,int r, int pos ,int val){
    if(l==r){
        tree[i]=val;
        return;
    }
    int left=i*2;
    int right=(i*2)+1;
    int mid=(l+r)/2;
    if(pos<=mid){
        update(left,l,mid,pos,val);
    }
    else{
        update(right,mid+1,r,pos,val);
    }
    tree[i]=gcd(tree[left],tree[right]);
    //tree[i]=tree[left]+tree[right];
}
void query(int i,int l,int r,int x,int y,int g){
    if(ans==2)return ;
    if(l==r){
        if(tree[i]%g){
            ans++;
        }
        return;
    }
    int left=i*2;
    int right=(i*2)+1;
    int mid=(l+r)/2;

    if(x<=mid&&tree[left]%g){
        query(left,l,mid,x,y,g);
    }
    if(mid<y&&tree[right]%g){
        query(right,mid+1,r,x,y,g);
    }





}

int main(){


        scanf("%d",&n);
        build(1,1,n);
        scanf("%d",&q);
        for(int j=1,op,x,y,val;j<=q;j++){
            ans=0;
            scanf("%d%d%d",&op,&x,&y);
            if(op==1){
                scanf("%d",&val);
                query(1,1,n,x,y,val);
                if(ans<=1)puts("YES");
                else puts("NO");

            }
            else if(op==2)
                update(1,1,n,x,y);

        }

}*/












#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,a[N],gcd[N],q;
#define lc x<<1
#define rc x<<1|1
void build(int x,int l,int r){
	if (l==r) return void(gcd[x]=a[l]);
	int mid=(l+r)>>1;
	build(lc,l,mid);build(rc,mid+1,r);
	gcd[x]=__gcd(gcd[lc],gcd[rc]);
}
void Set(int x,int l,int r,int p,int v){
	if (l==r) return void(gcd[x]=v);
	int mid=(l+r)>>1;
	p>mid?Set(rc,mid+1,r,p,v):Set(lc,l,mid,p,v);
	gcd[x]=__gcd(gcd[lc],gcd[rc]);
}
int query(int x,int l,int r,int L,int R,int v){
	if (gcd[x]%v==0) return 0;
	if (l==r) return 1;
	int mid=(l+r)>>1,ans=0;
	if (L<=mid) ans+=query(lc,l,mid,L,R,v);
	if (R>mid&&ans<2) ans+=query(rc,mid+1,r,L,R,v);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&q);
	while (q--){
		int tp,l,r,v;
		scanf("%d%d%d",&tp,&l,&r);
		if (tp==1) scanf("%d",&v),puts(query(1,1,n,l,r,v)<2?"YES":"NO");
		else Set(1,1,n,l,r);
	}
	return 0;
}

#include<cstdio>
int n,q;
int val[500005<<2];
int cnt=0;
int Gcd(int a,int b){
	return b?Gcd(b,a%b):a;
}
void bul(int i,int l,int r){
	if(l==r){
		scanf("%d",&val[i]);
		return;
	}
	int m=(l+r)>>1;
	bul(i<<1,l,m);bul(i<<1|1,m+1,r);
	val[i]=Gcd(val[i<<1],val[i<<1|1]);
}
void upd(int i,int l,int r,int k,int x){
	if(l==r){val[i]=x;return;}
	int m=(l+r)>>1;
	if(k<=m) upd(i<<1,l,m,k,x);
	else upd(i<<1|1,m+1,r,k,x);
	val[i]=Gcd(val[i<<1],val[i<<1|1]);
}
void qur(int i,int l,int r,int ql,int qr,int x){
	if(cnt==2)return;
	if(l==r){if(val[i]%x)cnt++;return;}
	int m=(l+r)>>1;
	if(ql<=m&&val[i<<1]%x) qur(i<<1,l,m,ql,qr,x);
	if(m<qr&&val[i<<1|1]%x) qur(i<<1|1,m+1,r,ql,qr,x);
}
int main(){
	scanf("%d",&n);
	bul(1,1,n);
	scanf("%d",&q);
	for(int i=1,op,x,y,va;i<=q;i++){
		cnt=0;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			scanf("%d",&va);
			qur(1,1,n,x,y,va);
			if(cnt<=1) puts("YES");
			else puts("NO");
		}
		else upd(1,1,n,x,y);
	}
	return 0;
}



