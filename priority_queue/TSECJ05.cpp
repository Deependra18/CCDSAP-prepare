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
		lld k,n;
		cin>>k>>n;
		lld x;
		//min heap
		priority_queue<int,vector<int>,greater<int>>pq;
		for(int i=0;i<n;i++)
		{
           cin>>x;
           if(pq.size()<k)
          { 	
          	
          	pq.push(x);
          	if(pq.size()==k)
          		cout<<pq.top()<<" ";
          	else
          		cout<<-1<<" ";
             
           }
           else
           {
           	
           	if(pq.top()<x)
           		{ 
           		pq.pop();
           	    pq.push(x);
           	    }
           	    cout<<pq.top()<<" ";
           }
		}
		cout<<"\n";
	}

 	return 0;
}
