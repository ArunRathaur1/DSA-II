#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> calculateEarningsAndReviews(ll price, const vector<ll>& a, const vector<ll>& b) {
    ll earnings = 0;
    ll negativeReviews = 0;

    for (size_t i = 0; i < a.size(); ++i) {
        if (price <= a[i]) {
            earnings += price; // Positive review
        } else if (price <= b[i]) {
            earnings += price; // Negative review
            negativeReviews++;
        }
        // No purchase if price > b[i]
    }
    return {earnings, negativeReviews};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; ++i) cin >> a[i];
        for (ll i = 0; i < n; ++i) cin >> b[i];

        // Binary search for the optimal price
        ll low = 1, high = *max_element(b.begin(), b.end());
        ll maxEarnings = 0;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            // Manually unpack the pair returned by the function
            pair<ll, ll> result = calculateEarningsAndReviews(mid, a, b);
            ll earnings = result.first;
            ll negativeReviews = result.second;

            if (negativeReviews <= k) {
                // Valid price, try higher prices for potentially better earnings
                maxEarnings = max(maxEarnings, earnings);
                low = mid + 1;
            } else {
                // Too many negative reviews, try lower prices
                high = mid - 1;
            }
        }

        // Output the maximum earnings for this test case
        cout << maxEarnings << '\n';
    }

    return 0;
}
