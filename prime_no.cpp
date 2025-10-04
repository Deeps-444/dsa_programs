#include <iostream>
using namespace std;

// prime number
bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    int i = 2;
    while (i < n / 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    i++;
    return true;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    bool result = is_prime(n);
    if (result)
    {
        cout << "n is prime";
    }
    else
    {
        cout << "n is not prime";
    }
    return 0;
}
