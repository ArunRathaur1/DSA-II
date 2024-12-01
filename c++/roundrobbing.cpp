// Apurv Shekhar 23115013
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr)
{
    for (int i : arr)
        cout << i << ' ';
    cout << endl;
}

void calculateFinishTime(int n, vector<int> &finishTime, vector<int> arrivalTime, vector<int> burstTime, int quanta)
{
    // vector<int> burstTime = burstTime;
    int start = 0, count = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (arrivalTime[i] <= start)
        {
            arrivalTime[i] = -1;
            // startTime[i] = start;
            q.push(i);
        }
    }
    while (!q.empty() || count < n)
    {
        if (!q.empty())
        {
            int idx = q.front();
            q.pop();
            if (burstTime[idx] <= quanta)
            {
                start += burstTime[idx];
                finishTime[idx] = start;
                burstTime[idx] = 0;
                count++;
            }
            else
            {
                start += quanta;
                burstTime[idx] -= quanta;
                for (int i = 0; i < n; i++)
                {
                    if (arrivalTime[i] >= 0 && arrivalTime[i] <= start)
                    {
                        // startTime[i] = start;
                        arrivalTime[i] = -1;
                        q.push(i);
                    }
                }
                q.push(idx);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (arrivalTime[i] >= 0 && arrivalTime[i] <= start)
                {
                    arrivalTime[i] = -1;
                    // startTime[i] = start;
                    q.push(i);
                }
            }
        }
    }
}

// Apurv Shekhar 23115013
void calculateWaitTime(vector<int> &waitTime, vector<int> &TaTime, vector<int> &burstTime)
{
    for (int i = 0; i < waitTime.size(); i++)
        waitTime[i] = TaTime[i] - burstTime[i];
}

void calculateTATime(vector<int> &TaTime, vector<int> &finishTime, vector<int> &arrivalTime)
{
    for (int i = 0; i < TaTime.size(); i++)
        TaTime[i] = finishTime[i] - arrivalTime[i];
}
double calculateAvgWaitTime(vector<int> waitTime, int n)
{
    return accumulate(waitTime.begin(), waitTime.end(), 0.0) / n;
}
double calculateAvgTATime(vector<int> TaTime, int n)
{
    return accumulate(TaTime.begin(), TaTime.end(), 0.0) / n;
}

int main()
{
    int n = 5;
    int quanta = 2;
    // cin >> n;
    vector<int> arrivalTime = {0, 2, 4, 6, 8};
    vector<int> burstTime = {3, 6, 4, 5, 2};
    vector<int> startTime(n, 0);
    vector<int> finishTime(n, 0);
    vector<int> waitTime(n, 0);
    vector<int> TaTime(n, 0);
    cout << "Arrival Time\n";
    // for (int i = 0; i < n; i++)
    // cin >> arrivalTime[i];
    cout << "Burst Time\n";
    // for (int i = 0; i < n; i++)
    // cin >> burstTime[i];
    // cout << "Burst Time:\n"; for (int i : burstTime) cin >> i;
    calculateFinishTime(n, finishTime, arrivalTime, burstTime, quanta);
    calculateTATime(TaTime, finishTime, arrivalTime);
    calculateWaitTime(waitTime, TaTime, burstTime);
    cout << "Finish Time:\n";
    print(finishTime);
    cout << "Wait Time: \n";
    print(waitTime);
    cout << "Turnaround Time: \n";
    print(TaTime);
    cout << "Avg Wait Time: " << calculateAvgWaitTime(waitTime, n) << "\nAvg Turnaround Time: " << calculateAvgTATime(TaTime, n);
    return 0;
}