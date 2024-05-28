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
    int sum=n*(n+1)/2;
    if(sum%2)
    {
        cout<<0;
        return;
    }
    sum/=2;
    vector<vector<ll>> dp(n+1,vector<ll>(sum+1,0));
    dp[0][0]=1;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1; j<sum+1;j++)
        {
            dp[i][j]+=dp[i-1][j];
            if(j-i>=0)
            dp[i][j]+=dp[i-1][j-i];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][sum];
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