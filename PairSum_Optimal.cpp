#include <iostream>
#include <vector>
using namespace std;

// function
vector<int> pairSum(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    int ps = 0;
    vector<int> ans;
    while (low < high)
    {
        ps = arr[low] + arr[high];
        if (ps > target)
        {
            high--;
        }
        else if (ps < target)
        {
            low++;
        }
        else
        {
            ans.push_back(arr[low]);
            ans.push_back(arr[high]);
            return ans;
        }
    }
}

int main()
{
    int arr[4] = {2, 7, 11, 15};
    int n = 4;
    int target = 26;

    vector<int> result = pairSum(arr, n, target);
    cout << "pairs are: " << result[0] << " and " << result[1];
    return 0;
}