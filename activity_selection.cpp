#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for an activity
struct Activity
{
    int start, finish;
};

// Comparison function to sort by finish time
bool activityCompare(Activity a, Activity b)
{
    return a.finish < b.finish;
}

// Function to perform Activity Selection
void activitySelection(vector<Activity> &activities)
{
    int n = activities.size();

    // Step 1: Sort activities by finish time
    sort(activities.begin(), activities.end(), activityCompare);

    cout << "Selected Activities: " << endl;

    // Step 2: Select the first activity
    int lastSelected = 0;
    cout << "(" << activities[lastSelected].start
         << ", " << activities[lastSelected].finish << ")" << endl;

    // Step 3: Go through remaining activities
    for (int i = 1; i < n; i++)
    {
        if (activities[i].start >= activities[lastSelected].finish)
        {
            cout << "(" << activities[i].start
                 << ", " << activities[i].finish << ")" << endl;
            lastSelected = i;
        }
    }
}

int main()
{
    vector<Activity> activities = {
        {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};

    activitySelection(activities);

    return 0;
}
