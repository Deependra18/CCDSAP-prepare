 
/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 1000000000000000000
typedef pair<lld,lld> pl;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<pl> adj[10001];
 
lld dijiktra(lld s,lld d,lld n)
{
  
   priority_queue<pl,vector<pl>,greater<pl>>pq;
   pq.push({0,s});
    vector<lld>dist(n+1,inf);
 
   dist[s]=0;
   while(!pq.empty())
   {
   lld u=pq.top().second;
   pq.pop();
   for(auto it:adj[u])
   {
   	  lld v=it.first;
   	  lld w=it.second;
   	  if(dist[v]>dist[u]+w)
   	  {
   	  	dist[v]=dist[u]+w;
   	  	pq.push({dist[v],v});
   	  }
   }
 
}
 
return dist[d];
 
}
 
int main() 
{ 
	  fastio;
	  int t;
	  cin>>t;
    while(t--)
    {
    lld n;
    cin>>n;
    
    unordered_map<string,lld>mp;
    for(lld i=1;i<=n;i++)
    {
     string s;
     cin>>s;
     mp[s]=i;
     lld p;
     cin>>p;
      while(p--)
      {
      	lld v,w;
     cin>>v>>w;
     adj[i].push_back({v,w});
      }
 
    }
    lld q;
    cin>>q;
    while(q--)
    {
    string s1,s2;
    cin>>s1>>s2;
    cout<<dijiktra(mp[s1],mp[s2],n)<<"\n";
   }
      for(lld i=0;i<10001;i++)
      	adj[i].clear();

}
 	return 0;
}
 