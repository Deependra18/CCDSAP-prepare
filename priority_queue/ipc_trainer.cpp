#include<bits/stdc++.h>
using namespace std;
#define lld long long int

struct pp
{
lld first,second,third;
};

struct comp{
    bool operator()(const pp &a,const pp &b)
    {
        return a.first>b.first;
    }
    
};

struct comp1
{
    bool operator()(const pp &a,const pp &b)
    {
        return a.third<b.third;
    }
};
int main() 
{ 
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 lld t;
	 cin>>t;
	 while(t--)
	 {
	 	lld n,d;
	 	cin>>n>>d;
	priority_queue<pp,vector<pp>,comp> pq;
	priority_queue<pp,vector<pp>,comp1>pq1;
	pp c;
	for(lld i=0;i<n;i++)
	{
		cin>>c.first>>c.second>>c.third;
		pq.push(c);
	}
	lld d1=0;
	while((!pq.empty())&&d1<d)
	{
		    d1++;

	        while(!pq.empty()&&d1==pq.top().first)
	        { //cout<<d1;
	            pq1.push(pq.top());
	            pq.pop();
	        }
	        if(pq1.size())
	        {
	        pp u= pq1.top();
	              pq1.pop();
	             u.second--;
	        if(u.second!=0)
	           pq1.push(u);
	   }
	}
    lld sum=0;
   while(!pq1.empty()&&d1<d)
   {
   	        pp u= pq1.top();
	              pq1.pop();
	             u.second--;
	        if(u.second!=0)
	           pq1.push(u);
	       d1++;
   }
      // cout<<" ###";
   while(!pq1.empty())
   {
   	pp w=pq1.top();
   	  pq1.pop();
   	sum+=(w.second*w.third);
   }

    cout<<sum<<"\n";
}
 	return 0;
}

