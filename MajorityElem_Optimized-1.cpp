#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majElem(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end()); //==> O(nlogn)
    int freq = 1, ans = nums[0];    // initialization

    // loop
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = nums[i];
        }

        // check for condition:
        if (freq > n / 2)
        {
            return ans;
        }
    }
    return -1;
}

int main()
{
    // find majority number:
    vector<int> nums = {1, 2, 2, 1, 1, 2};
    // finding majority;
    int result = majElem(nums);
    if (result > 0)
    {
        cout << "majority number is : " << result;
    }
    else
    {
        cout << "no majority number";
    }
    return 0;
}