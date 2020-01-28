/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lld find_p(lld u,lld parent[])
{
	if(u==parent[u])return u;
	return parent[u]=find_p(parent[u],parent);
}

void merge(lld u,lld v,lld parent[],lld w[])
{
	u=find_p(u,parent);
	v=find_p(v,parent);
	if(u!=v)
	{
		if(w[u]==w[v])
			return;
      if(w[u]<w[v])
      	swap(u,v);
      parent[v]=u;
	}
	else
		cout<<"Invalid query!\n";
}

int main() 
{ 
	  fastio;
	  lld t;
	  cin>>t;
	  while(t--)
	  {
	  	lld n;
	  	cin>>n;
	  	lld w[n+1],parent[n+1];
	  	for(lld i=1;i<=n;i++)
	  		{cin>>w[i];
	  	    parent[i]=i;}

	  	lld q;
	  	cin>>q;
	  	while(q--)
	  	{
	  		lld in;
	  		cin>>in;
	  		if(in==0)
	  		{
	  			lld u,v;
	  			cin>>u>>v;
	  			merge(u,v,parent,w);
	  		}
	  		else
	  		{
	  			lld u;
	  			cin>>u;
	  			u=find_p(u,parent);
	  			cout<<u<<"\n";
	  		}
	  	}

	  }
	

 	return 0;
}
