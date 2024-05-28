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
    int n,m ; cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++) cin>>num[i];
     ll dp[n+1][100000+1];
     memset(dp, 0 , sizeof(dp));
     for(int i=0;i<n+1;i++)
     {
         for(int j=0;j<1e5+1;j++)
         {
             if(i==0 && j==0 ){
                 dp[i][j]=1;
             }
             else if(j==0)
             {
                 dp[i][j]=1;
             }
             else if(i>0){
                
                //not using num[i-1]
                dp[i][j]|=dp[i-1][j];
                //usign num[i-1]
                if(j-num[i-1]>=0)
                dp[i][j]|=dp[i-1][j-num[i-1]];
             }
         }
     }
     ll ans=0;
     for(int j=1;j<1e5+1;j++) ans+=dp[n][j];
     cout<<ans<<endl;
     for(int j=1;j<1e5+1;j++)
     {
         if(dp[n][j]) cout<<j<<" ";
     }
     
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