
/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 1000000000000000000
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lld a[1501][1501],n;
void toposort(vector<lld> &outdg)
{
	vector<lld> vis(n+1,0);;
	lld ans[n+1][n+1];
	memset(ans,0,sizeof ans);
	  priority_queue<lld>pq;
	   for(lld i=1;i<=n;i++)
	   {
	   	if(!outdg[i])
	   		pq.push(i);
	   }
	   lld c=0;
	   while(!pq.empty())
	   {
	   	  lld u=pq.top();
	   	  vis[u]=1;
	   	  pq.pop();
	   	  for(int i=1;i<=n;i++)
	   	  {
	   	  	   if(a[i][u])
	   	  	   {
	   	  	   	 if(--outdg[i]==0)
	   	  	   	 	pq.push(i);
	   	  	   }
	   	  	   else if(!vis[i])
	   	  	   {
	   	  	   	    ans[i][u]=1;
	   	  	   	    c++;
	   	  	   }
	   	  }

	   }
	   cout<<c<<"\n";
	   for(int i=1;i<=n;i++)
	   {
	   	for(int j=1;j<=n;j++)
	   	{
	   		  if(ans[i][j])
	   		  cout<<i<<" "<<j<<"\n";	 
	   	}
	   }

}


int main() 
{ 
	  fastio;
	  cin>>n;
      vector<lld> outdg(n+1,0);
	  for(lld i=0;i<n;i++)
	  { 
	  	string s;
	  	cin>>s;
	  	for(int j=0;j<n;j++)
	  	{
	  		 if(s[j]=='1')
	  		 {
	  		 	a[i+1][j+1]=1;
	  		 	outdg[i+1]++;
	  		 }
	  		 else
	  		 a[i+1][j+1]=0;
	    }
       }
	  toposort(outdg);



 	return 0;
}
