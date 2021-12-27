#include<bits/stdc++.h>

using namespace std;
int n,e,k;
struct node
{
	int to,nex,v,pre;
}edge[20005];
int head[20005];
int cnt;
void add(int a,int b,int c)
{
	edge[++cnt].to=b;
	edge[cnt].pre=a;
	edge[cnt].v=c;
	edge[cnt].nex=head[a];
	head[a]=cnt;
}
struct cmpp
{
	int a,b,c;
	int de;
}x[20005];
bool cmp(cmpp a,cmpp b)
{
	if(a.a<b.a)return true;
	else if(a.a>b.a)return false;
	else if(a.a==b.a)
	{
		if(a.b>b.b)return true;
		else return false;
	}
}
map<pair<int,int>,int>q;
int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>x[i].a>>x[i].b>>x[i].c;
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		q[{a,b}]=1;
	}
	sort(x+1,x+1+e,cmp);
	for(int i=1;i<=e;i++)
	{
		if(!q[{x[i].a,x[i].b}])add(x[i].a,x[i].b,x[i].c);
	}
	for(int i=0;i<n;i++)
	{
		if(head[i]!=0)
		{
			cout<<i<<":";
			for(int j=head[i];j;j=edge[j].nex)
			{
				cout<<"("<<i<<","<<edge[j].to<<","<<edge[j].v<<")";
			}
			cout<<endl;
		}
	}
	return 0;
}
