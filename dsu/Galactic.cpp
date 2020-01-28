#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX 1000000000000000000
lld find(lld u,lld parent[])
{
	if(u==parent[u])
		return u;
	return parent[u]=find(parent[u],parent);
}
void union1(lld parent[],lld u,lld v,lld w[])
{
	u=find(u,parent);
	v=find(v,parent);
	if(u==v)
	 return;
	if(w[u]>w[v])
	 parent[u]=v;
	else if(w[v]>=w[u])
	 parent[v]=u;
}

int main() 
{ 
	 deepu();
	lld n,m;
	cin>>n>>m;
	lld a[m+1],b[m+1],w[n+1],parent[n+1];
	for(int i=1;i<=n;i++)
		parent[i]=i;
	for(int i=1;i<=m;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
	{	cin>>w[i];
	     if(w[i]<0)
	   	w[i]=LLONG_MAX;
	}
	for(int i=1;i<=m;i++)
	union1(parent,a[i],b[i],w);
    vector<lld>v;
    lld ma=LLONG_MAX,f=0;
    for(int i=1;i<=n;i++)
    {
    	if(parent[i]==i)
    	{
    		if(w[i]==LLONG_MAX)
    			f=1;
    		    v.push_back(w[i]);
    		    ma=min(ma,w[i]);
    		    
    	}
    }
    if(f&&v.size()>1)
    	cout<<"-1\n";
    else 
    {
    	lld ans=0;
    	for(int i=0;i<(int)v.size();i++)
    	{
            ans+=v[i];
    	}
    	ans+=ma*((int)v.size()-2);
    	cout<<ans<<"\n";
    }



 	return 0;
}

