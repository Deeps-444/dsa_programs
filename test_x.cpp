#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    queue<int> q;
    cout << "enter number: ";
    cin >> n;
    q.push(n);
    cout << q.front();
    return 0;
}