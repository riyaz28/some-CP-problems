#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define setp(n) cout<<fixed<<setprecision(n)
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define op(x) cout<<x
#define ip(x) cin>>x
#define ipl(s) getline(cin,s)
#define nl cout<<endl
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORE(i, a, b) for (int i=a; i<=(b); i++)

ll n,t;
vector<ll>a;



bool f(ll mid)
{
 ll sum=0;
 FORE(i,0,n-1)
 {
     sum+=(mid/a[i]);
     if(sum>=t)return true;  //important deal with overflow
 }

return sum>=t;

}
int32_t main()
{
cin>>n>>t;
ll in;
FORE(i,0,n-1)
{
    cin>>in;
    a.pb(in);
}

    ll lo=0,hi=1e18;
	for (hi ++; lo < hi; ) {
		ll mid = lo+(hi-lo)/2;
		if (f(mid)) hi = mid;
		else lo = mid+1;
	}
	cout<<lo;

return 0;
}