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
    int n,m,a,b ; cin>>a>>b;
    int dp[a+1][b+1]; memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<a+1;i++)
    {
        for(int j=1;j<b+1;j++)
        {
            dp[i][j]=i*j;
            if(i==j) dp[i][j]=0;
            for(int k =1; k<max(i,j);k++)
            {
                if(k<i)
                dp[i][j]=min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
                if(k<j)
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout<<dp[a][b];
     
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