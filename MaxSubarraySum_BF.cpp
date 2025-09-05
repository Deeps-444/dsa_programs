#include <iostream>
#include <algorithm>

using namespace std;
// brute force: O(n^2);
int main()
{
    // taking an array:
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    int maxSum = INT8_MIN;
    // traversing
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += arr[j];
            maxSum = max(currSum, maxSum);
        }
    }
    cout << "Maximum Sub array sum: " << maxSum;
    return 0;
}
