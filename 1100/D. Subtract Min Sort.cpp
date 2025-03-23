#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long cur = a[0];
    for (int i = 1; i < n; i++)
    {
        if (cur > a[i])
        {
            cout << "NO" << "\n";
            return;
        }
        cur = a[i] - cur;
    }
    cout << "YES" << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
