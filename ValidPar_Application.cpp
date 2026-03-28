#include <iostream>
using namespace std;

bool isValid(string s)
{
    unordered_map<char, char> mp = {
        {')', '('},
        {'}', '{'},
        {']', '['}};
    bool flag = true;
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        { // opening
            st.push(c);
        }
        else
        {
            if (st.empty() || st.top() != mp[c])
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    cout << "Enter you mathematical equation to solve: ";
    string equation;
    cin >> equation;

    if (isValid(equation))
    {
        cout << "Solving equation....";
    }
    else
    {
        cout << "Enter a valid equation. make sure u used right brackets";
    }

    return 0;
}