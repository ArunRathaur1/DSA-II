#include <bits/stdc++.h>
using namespace std;

bool isPossible(int bottles, vector<int> &ar, int h)
{
    vector<int> selected(ar.begin(), ar.begin() + bottles);
    sort(selected.begin(),selected.end(),greater<int>());
    int currHeight = 0;
    for (int i = 0; i +1 < selected.size(); i += 2)
    {
        currHeight += max(selected[i], selected[i + 1]);
        if (currHeight > h)
            return false;
    }
    if (selected.size() % 2 != 0)
    {
        currHeight += selected.back();
        if (currHeight > h)
            return false;
    }
    return true;
}

int main()
{
    int n, h;
    cin >> n >> h;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }


    int low = 0, high = n, result = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, ar, h))
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}