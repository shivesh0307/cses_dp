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
    int n,x ; cin>>n>>x;
    vector<int> price(n),pages(n);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    int ans[n+1][x+1];
    memset(ans, 0, sizeof(ans));
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<x+1;j++)
        {
            ans[i][j]=max(ans[i][j],ans[i-1][j]);
            if(j-price[i-1]>=0)
            ans[i][j]=max(ans[i][j],ans[i-1][j-price[i-1]]+pages[i-1]);
        }
    }
    cout<<ans[n][x];
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