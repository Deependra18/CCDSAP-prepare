
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

void build(lld t[],lld a[],lld l,lld r,lld v)
{
	if(l==r)
	{t[v]=a[l];
    return;}
	lld m=(l+r)/2;
	build(t,a,l,m,2*v+1);
	build(t,a,m+1,r,2*v+2);
	t[v]=min(t[2*v+1],t[2*v+2]);
}

void update(lld t[],lld lazy[],lld start,lld end,lld l,lld r,lld v,lld val)
{
	
   if(lazy[v]!=0)
   {
   	t[v]+=lazy[v];
   	if(start!=end)
   	{
   		lazy[2*v+1]+=lazy[v];
   		lazy[2*v+2]+=lazy[v];
   	}
   	lazy[v]=0;
   }
   //partial overlap
   if(start>r||end<l)
   	return;
   //full overlap
   if(l<=start && end<=r)
   {
   	  t[v]+=val;
   	  if(start!=end)
   	  {
   	  	lazy[2*v+1]+=val;
   	  	lazy[2*v+2]+=val;
   	  }
   	  return;
   }
   else
   {
    lld m=(start+end)/2;
    update(t,lazy,start,m,l,r,2*v+1,val);
    update(t,lazy,m+1,end,l,r,2*v+2,val);
    t[v]=min(t[2*v+1],t[2*v+2]);
   }

}

lld range(lld t[],lld lazy[],lld start,lld end,lld l, lld r, lld v)
{

	if(lazy[v]!=0)
	{
		t[v]+=lazy[v];
		if(start!=end)
		{
			lazy[2*v+1]+=lazy[v];
			lazy[2*v+2]+=lazy[v];
		}
		lazy[v]=0;
	}
	if(l>end||start>r)
		return INT_MAX;
	if(l<=start&&end<=r)
      return t[v];
    else
    {
    	lld m=(start+end)/2;
    	return min(range(t,lazy,start,m,l,r,2*v+1),range(t,lazy,m+1,end,l,r,2*v+2));
    //	t[v]=min(t[2*v+1],t[2*v+2]);
    }

}



int main() 
{ 
	  fastio;
	 deepu();

	 lld n;
	 cin>>n;
	 lld a[n];
    for(lld i=0;i<n;i++)
    	cin>>a[i];
    lld t[4*n];
    lld lazy[4*n]={0};
    build(t,a,0,n-1,0);
    lld q;
    cin>>q;
    cin.ignore();
    while(q--)
    {
	 string s;
	 getline(cin,s);
	 stringstream ss(s);
	 lld l,r,val;
	 ss>>l;
	 ss>>r;
	 if(ss>>val)
	 {
	 	if(l<=r)
	    update(t,lazy,0,n-1,l,r,0,val);
	    else
	    {
	     update(t,lazy,0,n-1,l,n-1,0,val);
	     update(t,lazy,0,n-1,0,r,0,val);
	    }	
	 }
	 else
	 {
	 	if(l<=r)
	     cout<<range(t,lazy,0,n-1,l,r,0);
	    else
	    {
	    	lld m=min(range(t,lazy,0,n-1,l,n-1,0),range(t,lazy,0,n-1,0,r,0));
             cout<<m;
	    }
	    cout<<"\n";
	 }
	 ss.clear();
	}
	
 	return 0;
}
