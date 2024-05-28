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
    vector<ll> sum(x+1,0),coins(n);
    for(int i=0;i<n;i++) 
    {
        cin>>coins[i];
    
       // cout<<coins[i];
    }
    sum[0]=1;
    for(int i=1;i<=x;i++)
    {
        for(int k=0;k<n;k++)
        {
            if(i-coins[k]>=0)
            {
                sum[i]+=sum[i-coins[k]];
                sum[i]=sum[i]%mod;
            }
        }
    }
    if(sum[x])
    cout<<sum[x];
    else 
    cout<<0;
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