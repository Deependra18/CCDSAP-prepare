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
	 	lld n,k1,k2,k3;
	 	cin>>n>>k1>>k2>>k3;
	 	int a[n+1]={0};
	 	for(int i=1;i<=n;i++)
	 	{
           cin>>a[i];
           a[i]+=a[i-1];
	 	}
	 	priority_queue<int,vector<int>,greater<int>>pq;
        int ans=0;
	 	for(int i=1;i<=n;i++)
	 	{
           for(int j=0;j<i;j++)
           {
              ans=a[i]-a[j];
              if(pq.size()<k3)
              	pq.push(ans);
              else
              {
              	if(ans>pq.top()) pq.pop(),pq.push(ans);
              }
           }

	 	}
	 	int c=k3,e,b,d;
	 	while(pq.size()&&c>0)
	 	{
	 		 
	 		if(c==k1)
	 			e=pq.top();
	 		else if(c==k2)
	 			b=pq.top();
	 		else if(c==k3)
	 			d=pq.top();
	 		    pq.pop();
	 		    c--;
	 	}
	 	cout<<e<<" "<<b<<" "<<d<<"\n";

	 }

 	return 0;
}
