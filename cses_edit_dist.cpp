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
    string a,b; cin>>a>>b;
    n=a.size(); m=b.size();
    int dp[n+1][m+1];
    memset(dp,max(n,m),sizeof(dp));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=0;
            }
            else if(i==0  || j==0)
            {
                dp[i][j]=  i==0? j :i;
            }
            else
            {
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=1+dp[i-1][j-1]; //replace
                    dp[i][j]=min(dp[i][j],1+dp[i-1][j]);
                    dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
                }
            }
        }
    }
    cout<<dp[n][m];
     
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