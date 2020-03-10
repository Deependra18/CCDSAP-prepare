
/* Deependra Kumar */
#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define mod 1000000007
#define inf 1000000000000000000
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void deepu()
{
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt","w",stderr);
	#endif
}

void build(lld t[],string& s,lld l,lld r,lld v)
{
	if(l==r)
	{
		t[v]=1<<(s[l]-'a');
	//pow(2,s[l]-'a')
		return ;
	}
	lld m=(l+r)/2;
	build(t,s,l,m,2*v+1);
	build(t,s,m+1,r,2*v+2);
	t[v]=t[2*v+1]|t[2*v+2];
	//checking set bit
}
void update(lld t[],lld l,lld r,lld pos,char val,lld v)
{
	if(l==r)
	{
		t[v]=1<<(val-'a');
		return ;
	}
	else
	{
	lld m=(l+r)/2;
	if(m>=pos)
	update(t,l,m,pos,val,2*v+1);
    else
    update(t,m+1,r,pos,val,2*v+2);
    t[v]=t[2*v+1]|t[2*v+2];
   }
}

 lld query(lld t[],lld l,lld r,lld rl,lld rr,lld v)
 {
 	if(rl>r || rr<l)
 		return 0;
 	if(rl<=l && rr>=r)
 		return t[v];
 	lld m=(l+r)/2;
 	return query(t,l,m,rl,rr,2*v+1)|query(t,m+1,r,rl,rr,2*v+2);
 }

int main() 
{ 
	  fastio;
	 deepu();
	 string s;
	 cin>>s;
	 lld n=s.size();
	 lld t[4*n];
	 build(t,s,0ll,n-1,0ll);
	 lld q;
	 cin>>q;
	 lld l,r,pos,check;
	 char c;
	for(lld i=0;i<q;i++)
	{
     cin>>check;
     if(check==1)
     {
     	cin>>pos>>c;
     	pos--;
     	update(t,0ll,n-1,pos,c,0ll);
     }
     else
     {
     	cin>>l>>r;
     	l--,r--;
     	cout<<__builtin_popcount(query(t,0,n-1,l,r,0))<<"\n";
     	//__builtin_popcount(n) = counts no. of set bits in n
     }
	}

    



 	return 0;
}
