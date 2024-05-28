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
 
void solve() {
    int n, m; 
    cin >> n;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    ll dp[n][n][2];
    memset(dp,0ll,sizeof(dp));
    
    for(int i = 0; i < n; i++) {
        dp[i][i][0] = nums[i];
        dp[i][i][1] = 0;
    }
    
    for(int l = 2; l <= n; l++) {
        for(int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            if(l == 2) {
                dp[i][j][0] = max(nums[i], nums[j]);
                dp[i][j][1] = min(nums[i], nums[j]);
            } else {
                dp[i][j][0] = max(nums[i] + dp[i + 1][j][1], nums[j] + dp[i][j - 1][1]);
                dp[i][j][1] = min(dp[i + 1][j][0], dp[i][j - 1][0]);
            }
        }
    }
    cout << dp[0][n - 1][0] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t = 1;
    //cin >> t; 
    while(t--) {
        solve();
    }
    return 0;
}