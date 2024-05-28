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
    int n,m ; cin>>n>>m;
    vector<int> num(n);
    for(int i=0;i<n;i++) cin>>num[i];
     ll dp[n+1][m+1];
     memset(dp,0ll,sizeof(dp));
     for(int j=0;j<m+1;j++)
     {
         dp[0][j]=1;
     }
     for(int i=1;i<n+1;i++)
     {
         for(int j=1;j<m+1;j++)
         {
             if(num[i-1]==0)
             {
                dp[i][j]=dp[i-1][j];
             if(j-1>=0) dp[i][j]+=dp[i-1][j-1];
             if(j+1<=m) dp[i][j]+=dp[i-1][j+1];
             dp[i][j]=dp[i][j]%mod;
             }
             else if(j==num[i-1])
             {
             dp[i][j]=dp[i-1][j];
             if(j-1>=0) dp[i][j]+=dp[i-1][j-1];
             if(j+1<=m) dp[i][j]+=dp[i-1][j+1];
             dp[i][j]=dp[i][j]%mod;
             }
             if(i==1)
             {
                 dp[i][j]=min(dp[i][j],1ll);
             }
         }
     }
     ll ans=0;
     for(int i=0;i<n+1;i++){
     for(int j=0;j<m+1;j++)
     {
         if(i==n)
        ans+=dp[n][j];
        //cout<<i << " "<<j <<" "<<dp[i][j]<<endl;
        ans=ans%mod;
     }
     }
     cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    //cin>>t; 
    while(t--)
    {
        solve();
    }
    return 0;
}