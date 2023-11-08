#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fibonacci(int n)
{
    int a = 0, b = 1, next = 0;

    cout << a << " " << b << " ";

    for (int i = 3; i <= n; i++)
    {
        next = a + b;
        cout << next << " ";

        a = b;
        b = next;
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    fibonacci(n);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)