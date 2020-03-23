/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 1000000000000000000
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<lld>path;
void toposort(vector<lld> adj[],vector<lld> &indg)
{
	priority_queue<lld,vector<lld>,greater<lld>>pq;
	   for(lld i=0;i<26;i++)
	   {
	   	  if(!indg[i])
	   	  	pq.push(i);
	   }
	   while(!pq.empty())
	   {
	   	  lld p=pq.top();
	   	  pq.pop();
	   	  path.emplace_back(p);
	   	  for(auto i:adj[p])
	   	  {
	   	  	if(--indg[i]==0)
	   	  	{
	   	  		pq.push(i);
	   	  	}
	   	  }
	   }
	   if(path.size()!=26)
	   {
	   	cout<<"Impossible";
	   }
	   else
	   {
	   	   for(auto i:path)
	   	   	cout<<(char)(i+'a');
	   }
}


int main() 
{ 
	 fastio;
	 lld n;
	 cin>>n;
	 vector<lld> adj[26];
	 vector<lld> indg(26,0);
	 string ss,s;
         cin>>ss;
      lld n1,n2,l;
	 for(lld i=1;i<n;i++)
	 {
          cin>>s;
          n1=ss.size();
          n2=s.size();
          l=min(n1,n2);
           int f=0;
          for(lld j=0;j<l;j++)
          {
            if(s[j]!=ss[j])
            { 
            	f=1;
               indg[s[j]-'a']++;
               adj[ss[j]-'a'].emplace_back(s[j]-'a');
               break;
            }

          }
          if(!f)
          {
          	if(n1>n2)
          	{
          		cout<<"Impossible";
          		return 0;
          	}
          }
          ss=s;
	 }
	 toposort(adj,indg);
 	return 0;
}