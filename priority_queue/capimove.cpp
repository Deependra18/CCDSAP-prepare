/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() 
{ 
	  fastio;
	 int t;
	 cin>>t;
	 while(t--)
	 {
	 	lld n;
	 	cin>>n;
	 	set<int>st;
	 	map<int,int>mp;
	 	int x[n+1];
	 	for(int i=1;i<=n;i++)
	 	{
            cin>>x[i];
            mp.insert({x[i],i});
            st.insert(x[i]);
            
	 	}
	 	
	    vector<int> adj[n+1];
	    int u,v;
	    for(int i=1;i<n;i++)
	    {
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
	    }
	    for(int j=1;j<=n;j++)
	    {
	    	auto it2=st.find(x[j]);
	    	st.erase(it2);
	    	for(auto a:adj[j])
	    	{
	    		auto it1=st.find(x[a]);
                 st.erase(it1);
	    	}
            
            auto it=st.rbegin();
            auto it3=mp.find(*it);
            cout<<it3->second<<" ";
           st.insert(x[j]);
           for(auto a:adj[j])
	    	{
	    		st.insert(x[a]);
	    	}
	    }
	    for(int i=0;i<=n;i++)
	    adj[i].clear();



	 }
	 

 	return 0;
}
