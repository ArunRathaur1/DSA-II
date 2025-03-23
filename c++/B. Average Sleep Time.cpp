#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> val(n, -1);
    ll p = 1;
    for (int i = 0; i < k; i++)
    {
        val[i] = i + 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (p > k)
            break;
        if (val[i] == -1)
            val[i] = p++;
        else
        {
            val[i] = min(val[i], p);
            p++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (val[i] == -1)
            ans += a[i] * k;
        else if(val[i]>n-k+1)
        {
            ans+=a[i]*(n-k+1);
        }
        else
            ans += a[i] * val[i];
        
    }

    double res = (double)(ans) / (double)(n - k + 1);
    cout << fixed << setprecision(10) << res << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

// int main(){
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt", "w", stderr);
//     #endif
//     fastio();
//     ll t = 1;
//     // cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }