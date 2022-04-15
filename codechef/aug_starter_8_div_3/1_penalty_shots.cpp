#include <iostream>

using namespace std;

int solve()
{
    int a[11], one = 0, two = 0;
    for (int i = 1; i <= 10; i++)
    {
        cin >> a[i];
        if (i % 2 == 0)
        {
            two += a[i];
        }
        else
        {
            one += a[i];
        }
    }
    if (two == one)
        return 0;
    else if (one > two)
        return 1;
    return 2;
}

int main() {
    // your code goes here
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << '\n';
    }
    return 0;
}
