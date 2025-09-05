#include <iostream>
using namespace std;
// brute force method==>
int main()
{
    int arr[5] = {2, 4, 7, 11, 5};
    int n = 5;
    int target = 9;
    // vector<int> pair;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << "pair is: " << arr[i] << " and " << arr[j] << endl;
            }
        }
    }
}