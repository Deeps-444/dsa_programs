#include <iostream>
#include <algorithm>

using namespace std;
// KADEN'S ALGORITHM
int main()
{
    // taking an array:
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    int maxSum = INT8_MIN;
    int currSum = 0;
    // traversing
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << "Maximum Sub array sum: " << maxSum;
    return 0;
}
