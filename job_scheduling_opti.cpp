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

// to find parent
int findParent(vector<int> &parent, int x)
{
    if (x == parent[x])
        return x;

    return parent[x] = findParent(parent, parent[x]); // path compression
}

void unionSets(vector<int> &parent, int u, int v)
{
    parent[u] = v; // merge u into v
}
void jobScheduling(job jobs[], int n)
{
    // sort in decreasing
    sort(jobs, jobs + n, compare);

    // find max deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // initialize disjoint sets
    vector<int> parent(maxDeadline + 1);
    for (int i = 0; i < maxDeadline; i++)
    {
        parent[i] = i; // array is used and not linked list beacause ll will have extra memory overhead
    }

    // slot array to keep track of deadline
    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0, countJobs = 0;

    for (int i = 0; i < n; i++)
    {
        int availaibleSlot = findParent(parent, jobs[i].deadline);

        if (availaibleSlot > 0)
        {
            slot[availaibleSlot] = jobs[i].id;
            totalProfit += jobs[i].profit;
            countJobs++;

            unionSets(parent, availaibleSlot, availaibleSlot - 1);
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
