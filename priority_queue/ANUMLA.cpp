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
	while(t--)
	{
		lld n;
		cin>>n;
		lld p=pow(2,n);
		multiset<lld>mp;
		int u;
		for(int i=0;i<p;i++)
		{
			cin>>u;
			if(u)
			mp.insert(u);
		}

		vector<int> v,v1;
		for(int k=0;k<n;k++)
		{
			auto it=mp.begin();
			v.push_back(*it);
			mp.erase(it);
			v1.push_back(*it);
			int y=v1.size();
			for(int i=0;i<(y-1);i++)
			{    
				auto it1=mp.find(v1[i]+v[k]);
                      mp.erase(it1);
                      v1.push_back(*it1);
                   }	
		}
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";
		cout<<"\n";

		

	}

 	return 0;
}
