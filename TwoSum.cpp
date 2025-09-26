#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int left = 0;
    int n = nums.size();
    int right = n - 1;
    vector<int> ans;
    struct Numb
    {
        int value;
        int index;
    };
    // initialize the struct
    vector<Numb> org(n);
    for (int i = 0; i < n; i++)
    {
        org[i].value = nums[i];
        org[i].index = i;
    }
    sort(org.begin(), org.end(), [](const Numb &a, const Numb &b)
         { return &a.value < &b.value; });
    while (left <= right)
    {
        if (org[left].value + org[right].value == target)
        {
            ans.push_back(org[left].index);
            ans.push_back(org[right].index);
            return ans;
        }
        else if (org[left].value + org[right].value > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return {-1, -1};
}

int main()
{

    vector<int> ans, nums;
    nums = {3, 2, 4};
    ans = twoSum(nums, 6);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",t";
    }
}