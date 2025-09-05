#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// job scheduling

struct job
{
    int id;
    int profit;
    int deadline;
};

bool compare(job a, job b)
{
    return a.profit > b.profit;
}
void jobScheduling(job jobs[], int n)
{
    // sort in decraesing
    sort(jobs, jobs + n, compare);

    // find max deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // slot array to keep track of deadline
    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0, countJobs = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                countJobs++;
                break;
            }
        }
    }

    cout << "Jobs scheduled: ";
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (slot[i] != -1)
            cout << "J" << slot[i] << " ";
    }
    cout << endl;

    cout << "Total jobs done: " << countJobs << endl;
    cout << "Maximum Profit: " << totalProfit << endl;
}

int main()
{
    // Example
    job jobs[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobScheduling(jobs, n);

    return 0;
}
