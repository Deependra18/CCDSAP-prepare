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
struct tree
{
	lld o,c,b;
};
 
tree merge(tree s1,tree s2)
{
   tree ans;
   lld p=min(s1.o,s2.c);
      ans.o=s1.o+s2.o-p;
      ans.c=s1.c+s2.c-p;
      ans.b=s1.b+s2.b+p;
      return ans;
}
 
void build(tree t[],string &s,lld l,lld r,lld v)
{
	if(r==l)
	{
		if(s[l]==')')
			{t[v].c=1;
			 t[v].o=0;
			}
		else
			{  t[v].c=0;
			t[v].o=1;
		   }
		   t[v].b=0;
		return;
	}
	else
	{
   lld mid=(l+r)/2;
   build(t,s,l,mid,2*v+1);
   build(t,s,mid+1,r,2*v+2);
   t[v]=merge(t[2*v+1],t[2*v+2]);
	}
}
 
 
tree query(tree t[],lld l,lld r,lld rl,lld rr,lld v)
{
	
       if(rl<=l && rr>=r)
		return t[v];
	   else if(rl>r||rr<l)
	   {
	   	tree p;
	   	p.o=p.c=p.b=0;
	   	return p;}
	else
	{
		lld m=(l +r)/2;
		return merge(query(t,l,m,rl,rr,2*v+1),query(t,m+1,r,rl,rr,2*v+2));
	}
 
 
}
 
int main() 
{  deepu();
	fastio;
	string s;
	cin>>s;
	lld n=s.size();
   lld l=4*n;
	tree t[l];
    build(t,s,0,n-1,0);
    lld m;
    cin>>m;
    lld tl,tr;
  for(lld i=0;i<m;i++)
  {
      cin>>tl>>tr;
      tl--,tr--;
      cout<<2*(query(t,0ll,n-1,tl,tr,0ll).b)<<"\n";
  }
 	return 0;
}
 
 