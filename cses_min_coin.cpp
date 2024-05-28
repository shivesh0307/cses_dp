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
    vector<ll> count(x+1,x+1),coins(n);
    for(int i=0;i<n;i++) 
    {
        cin>>coins[i];
    
       // cout<<coins[i];
    }
    count[0]=0;
    for(int i=1;i<=x;i++)
    {
        for(int k=0;k<n;k++)
        {
            if(i-coins[k]>=0)
            {
                count[i] = min(count[i],1+count[i-coins[k]]);
            }
        }
    }
    if(count[x]!=x+1)
    cout<<count[x];
    else 
    cout<<-1;
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