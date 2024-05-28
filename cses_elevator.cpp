#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int full_mask = 1 << n;
    vector<int> subset_weights(full_mask, 0);
    vector<int> dp(full_mask, INT_MAX);

    // Precompute the sum of weights for all subsets
    for (int mask = 0; mask < full_mask; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += weights[i];
            }
        }
        subset_weights[mask] = sum;
    }

    dp[0] = 0; // No people need 0 rides

    // Iterate over all subsets
    for (int mask = 1; mask < full_mask; mask++) {
        // Iterate over all submasks of the current mask
        for (int submask = mask; submask; submask = (submask - 1) & mask) {
            if (subset_weights[submask] <= x) {
                dp[mask] = min(dp[mask], dp[mask ^ submask] + 1);
            }
        }
    }

    cout << dp[full_mask - 1] << endl; // Minimum number of rides for all people
    return 0;
}
