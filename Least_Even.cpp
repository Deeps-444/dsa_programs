#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    vector<int> arr;
    while (n >= 0)
    {
        cout << "enter number: ";
        cin >> n;
        if (n >= 0)
            arr.push_back(n);
    }
    int size = arr.size();
    // DISPLAY ARRAY
    int result;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            result = arr[i];
            break;
        }
    }
    cout << result << "\n";
}
