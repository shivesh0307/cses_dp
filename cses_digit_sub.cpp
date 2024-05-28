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
    vector<ll> count(n+1,n+1);
    count[0]=0; count[1]=1;
    for(int i=2;i<n+1;i++)
    {
        int k = i; 
        while(k>0)
        {
            int d= k%10;
            count[i]=min(count[i],1+count[i-d]);
            k=k/10;
        }
    }
    //if(count[x]!=x+1)
    //for(int i=0;i<=x;i++)
    //cout<<i<<" "<<count[i]<<endl;
    cout<<count[n];
    //else 
    //cout<<-1;
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