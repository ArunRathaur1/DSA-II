#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int x;
        ll k;
        cin >> n >> x >> k;
        string s;
        cin >> s;
        ll T = 0, C = 0;
        int p = x;
        bool f = false;
        for (int i = 0; i < n && T < k; i++)
        {
            T++;
            p += (s[i] == 'L' ? -1 : 1);
            if (p == 0)
            {
                C++;
                f = true;
                break;
            }
        }
        if (T == k)
        {
            cout << C << "\n";
            continue;
        }
        if (!f)
        {
            cout << C << "\n";
            continue;
        }
        int q = 0, r = 0, tp = 0;
        bool cyc = false;
        for (int i = 0; i < n; i++)
        {
            q++;
            tp += (s[i] == 'L' ? -1 : 1);
            if (tp == 0)
            {
                cyc = true;
                break;
            }
        }
        if (!cyc)
        {
            cout << C << "\n";
            continue;
        }
        ll L = q;
        ll R = k - T;
        ll full = R / L;
        C += full;
        ll rem = R % L;
        tp = 0;
        for (int i = 0; i < rem; i++)
        {
            tp += (s[i] == 'L' ? -1 : 1);
            if (tp == 0)
            {
                C++;
                break;
            }
        }
        cout << C << "\n";
    }
    return 0;
}
