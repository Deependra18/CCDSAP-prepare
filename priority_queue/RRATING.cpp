/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() 
{ 
	  fastio;
	 lld t;
	 cin>>t;
	 int m=0;
	 priority_queue<lld,vector<lld>,greater<lld>>pqm;
	 priority_queue<lld,vector<lld>,less<lld>>pq;
	 while(t--)
	 {
	 	lld a;
	 	cin>>a;
	 	if(a==1)
	 		{ 
               m++;
	 		  lld x;
	 			cin>>x;
	 		   pq.push(x);
	 		 if(m/3>pqm.size())
	 		 	{
	 		 	                                         
                        pqm.push(pq.top());
                        pq.pop();
	 		 	}
	 		 	else
	 		 	{
                   if(!pqm.empty()&&pqm.top()<pq.top())
                   {
                   	pqm.push(pq.top());
                   	pq.pop();
                   	pq.push(pqm.top());
                   	pqm.pop();}
	 		 	}
	 	    }
	 	    else
	 	    {
               
               if(!pqm.size())
               	cout<<"No reviews yet\n";
               else
               {
               cout<<pqm.top()<<"\n";
               }
                     
	 	    }

	 }
	

 	return 0;
}
