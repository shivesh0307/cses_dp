//shivesh
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define PRIME 1000000009
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define ll  long long
#define ull  unsigned int
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define sz(c) c.size()
#define r(i,a,b)    for(i=a;i<b;i++)
#define ra(i,a,b)   for(i=a;i<=b;i++)
#define vi vector<int>
#define vil vector<ll>
void solve()
{
    int n,m ; 
    cin>>n;
    ll dp[n+1][3];
    memset(dp,0,sizeof(dp));
    dp[1][2]=1; dp[1][1]=1;
    
    for(int i=2;i<n+1;i++)
    {
        dp[i][1]= 4*dp[i-1][1]+dp[i-1][2];
        dp[i][2]= dp[i-1][1]+dp[i-1][2]*2;
        dp[i][1]%=mod;
        dp[i][2]%=mod;
        
    }
    cout<<(dp[n][1]+dp[n][2])%mod<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    cin>>t; 
    while(t--)
    {
        solve();
    }
    return 0;
}