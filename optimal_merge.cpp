#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// optimal merge pattern

// we will use min heap here.
int optimalMerge(vector<int> &files)
{
    // build minHeap
    // ABOUT PRIORITY QUEUE
    /*priority_queue is present in queue file
    - it is by default maxHeap. we will make it minHeap here
    pq(type, container, comparator);
    */

    priority_queue<int, vector<int>, greater<int>> minheap(files.begin(), files.end());

    int totalcost = 0;
    // take cost
    while (minheap.size() > 1)
    {
        int f1 = minheap.top();
        minheap.pop();
        int f2 = minheap.top();
        minheap.pop();

        int cost = f1 + f2;
        totalcost += cost;
        minheap.push(cost);
    }

    return totalcost;
}
int main()
{
    vector<int> files = {20, 30, 10, 5};
    int result = optimalMerge(files);
    cout << "minimum cost: " << result << endl;
    return 0;
}