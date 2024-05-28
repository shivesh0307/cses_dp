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
    int n,x ; cin>>n; 
   vector<vector<char> > grid(n,vector<char>(n));
   for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
   cin>>grid[i][j];
   
   vector<vector<ll> > ans(n,vector<ll>(n,0));
   ans[0][0]= grid[0][0] =='.' ? 1 :0;
   for(int i=0;i<n;i++)
   {
       for(int j=(i==0 ?1 :0);j<n;j++)
       {
           if(grid[i][j]!='.') continue;
           if(i-1>=0) ans[i][j]+=ans[i-1][j];
           if(j-1>=0) ans[i][j]+=ans[i][j-1];
           ans[i][j]%=mod;
           
       }
   }
   cout<< ans[n-1][n-1];
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