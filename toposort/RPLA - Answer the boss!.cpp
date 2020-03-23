/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 1000000000000000000
typedef pair<lld,lld> pl;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<lld>adj[1001];

void toposort(vector<lld>& indg,lld n)
{
   priority_queue<lld,vector<lld>,greater<lld>>pq;
   vector<lld> path[n+1];
   vector<lld>lev(n,0);
      for(lld i=0;i<n;i++)
      {
      	if(!indg[i])
      		{ 
      		lev[i]=0;
      		pq.push(i);
      		path[0].emplace_back(i);
         	}

      }
      int c=0;
      while(!pq.empty())
      {
      	lld u=pq.top();
      	pq.pop();
      	for(auto i:adj[u])
      	{
      		
      		if(--indg[i]==0)
      			{
      			pq.push(i);
      			lev[i]=lev[u]+1;
      			path[lev[i]].emplace_back(i);
      			}
      	}
      }

     for(lld i=0;i<n;i++)
     {
     	   sort(path[i].begin(),path[i].end());
     	   for(auto j:path[i])
     	   {
     	   	cout<<(i+1)<<" "<<j<<"\n";
     	   }
           
     }
}

int main() 
{ 
	  fastio;
	 lld t;
	 cin>>t;
    lld k=0;
	 while(k<t)
	 {
    lld n,m;
    cin>>n>>m;
    lld u,v;
    vector<lld>indg(n,0);
  for(lld i=0;i<m;i++)
  {
  	cin>>u>>v;
  	indg[u]++;
  	adj[v].emplace_back(u);
  } 
  k++;

   cout<<"Scenario #"<<k<<":\n";
  	toposort(indg,n);
   for(lld i=0;i<1001;i++)
   	adj[i].clear();
    indg.clear();
  }

 	return 0;
}
