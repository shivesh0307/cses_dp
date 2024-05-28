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
    vector<ll> nums(n);
    for(int i=0;i<n;i++) 
    {
        cin>>nums[i];
       // cout<<nums[i]<<endl;
    }
    
   vector<ll> dp; 
   dp.push_back(nums[0]);
   for(int i=1;i<n;i++)
   {
    auto lower = upper_bound(dp.begin(), dp.end(), nums[i]);
    //cout<<lower-dp.begin()<<" "<<dp[0] <<endl;
  
    if(lower==dp.end() && dp[dp.size()-1]!=nums[i])
    {
        dp.push_back(nums[i]);
    }
    else
    {
        int j = lower-dp.begin(); 
        if(j==0 ||(j>0 && dp[j-1]!=nums[i]))
        {
            dp[j]=nums[i];
        }
    }
    
   }
   cout<<dp.size();
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