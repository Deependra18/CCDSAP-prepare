/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() 
{ 
	  fastio;
	 int t;
	 cin>>t;
	 while(t--)
	 {
	 	lld a,b,c,n;
	 	cin>>a>>b>>c>>n;
	 	lld F[n+1];
	 	F[1]=1;
	 	priority_queue<int,vector<int>,greater<int>>pqmin;
	 	priority_queue<int,vector<int>,less<int>>pqmax;
	 	pqmax.push(1);
	 	for(int i=2;i<=n;i++)
	 	{
	 		   	  lld m=pqmax.top();
	 		   	  F[i]=(a*m+b*i+c)%mod;
                 if(F[i]<pqmax.top())
	 		   	  {
	 		   	  	pqmin.push(pqmax.top());
	 		   	  	pqmax.pop();
	 		   	   pqmax.push(F[i]);
	 		   	  }
	 		   	  else 
	 		   	  	pqmin.push(F[i]);

	 		   	  if(pqmin.size()>pqmax.size())
	 		   	  {
	 		   	  	pqmax.push(pqmin.top());
	 		   	  	pqmin.pop();
	 		   	  }
	 		   	
	 		}
	 		lld sum=0;
	 		for(int i=1;i<=n;i++)
	 			sum+=F[i];
	 		cout<<sum<<"\n";

	 	}

 	return 0;
}
