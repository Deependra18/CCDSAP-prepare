
/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 1000000000000000000
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() 
{ 
	  fastio;
	 string s;
	 cin>>s;
	lld n=s.size();
	vector<lld> adj[10];
	for(lld i=0;i<n;i++)
	 adj[s[i]-'0'].push_back(i);
      
      vector<lld>dis(n,-1);
      queue<lld>q;
      q.push(0);
      dis[0]=0;
      while(!q.empty())
      {
      	lld u=q.front();
      	if(u==n-1)
      		break;
      	q.pop();
      	if(u-1>=0)
      	{
      		if(dis[u-1]==-1)
      		{
      			dis[u-1]=dis[u]+1;
      			q.push(u-1);
      		}
      	}
      	if(u+1<=n-1)
      	{
          if(dis[u+1]==-1)
          {
          	dis[u+1]=dis[u]+1;
          	q.push(u+1);
          }
      	}
      	lld p=s[u]-'0';
      	for(auto it:adj[p])
      	{
      		  if(dis[it]==-1)
      		  {
      		  	dis[it]=dis[u]+1;
      		  	q.push(it);
      		  }
      	}
      	adj[p].clear();

      }
      cout<<dis[n-1];
    
 	return 0;
}
