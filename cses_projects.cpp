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
    vector<vector<ll>> projects(n,vector<ll>(3));
    for(int i=0;i<n;i++) cin>>projects[i][0]>>projects[i][1]>>projects[i][2];
     sort(projects.begin(), projects.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[1] < b[1];
    });
    vector<ll> dp(n,0);
    dp[0]=projects[0][2];
    for(int i=1;i<n;i++)
    {
        ll x= projects[i][0]; 
        auto it = lower_bound(projects.begin(), projects.begin()+i, x, [](const vector<ll>& a, ll x) {
        return a[1] < x;
        });
        ll j = it - projects.begin();       //index of lower_bound on project[i][1]
        ll ans1=projects[i][2];         // do the project
        if(j-1>=0 )
        {
            ans1+=dp[j-1];
        }
        ll ans2=dp[i-1]; // don't do the project
        dp[i]=max(ans2,ans1);
        
    }
    cout<<dp[n-1];
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