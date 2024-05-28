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
ll count(string str)
{
    ll n =str.size();
    ll dp[n][10];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<10;i++)
    {
        int j = str[0]-'0';
        dp[0][i]= (i<=j) ? 1 : 0;
    }
    ll flag=-1;
    for(int i=1 ; i<n;i++)
    {
        for(int j =0 ;j<10;j++)
        {
            dp[i][j]=j==0 ? 1:0;
            for(int k =0;k<10;k++)
            {
                if(j==k) continue; 
                
                dp[i][j]+=dp[i-1][k];
                if(j>(str[i]-'0') && dp[i-1][k] && k==(str[i-1]-'0') )
                dp[i][j]+=flag;
            }
        }
        //cout<<i<<" flag "<<flag<<endl;
        if(str[i]==str[i-1]) flag=0;
    }
    ll ans =0; 
    for(int i=0;i<10;i++) 
    {
        ans+=dp[n-1][i];
    }
    return ans ;
}
void solve()
{
    int n,m ; 
    ll a, b; cin>>a>>b;
    
    ll cnt1 = a==0 ? 0 : count(to_string(a-1));
    ll cnt2 = count(to_string(b));
    //cout<<cnt1 <<" "<<cnt2<<endl;
    cout<<cnt2-cnt1;
    
    
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