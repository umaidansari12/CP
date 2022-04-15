#include <bits/stdc++.h>

using namespace std;

// idea is to use segmented sieve

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

bool isPrime(long n)
{
    if (n == 1 or n == 0)
        return false;
    for (long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isDigitsPrime(long n)
{
    while (n)
    {
        long digit = n % 10;
        n /= 10;
        if (!isPrime(digit))
            return false;
    }
    return true;
}

bool ismega(long long int n)
{
    bool flag = false;
    int temp;
    while (n != 0)
    {
        temp = n % 10;
        if (temp == 1)
        {
            flag = true;
            break;
        }
        n = n / 10;
        for (int j = 2; j <= (temp / 2); j++)
        {
            if (temp % j == 0)
            {
                flag = true;
                break;
            }

        }
        if (flag)
        {
            break;
        }
    }
    if (flag)
    {
        return false;
    }
    else
    {
        return true;
    }

}


int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    long first = stol(first_multiple_input[0]);

    long last = stol(first_multiple_input[1]);

    // long cnt = 0;
    // bool flag = false;


    // if (first == 1)
    //     first = 2;
    // for (int i = first; i <= last; i++)
    // {
    //     for (int j = 2; j <= (i / 2); j++)
    //     {
    //         if (i % j == 0)
    //         {
    //             flag = true;
    //             break;
    //         }

    //     }

    //     if (!flag)
    //     {
    //         if (ismega(i))
    //         {
    //             cnt += i;
    //             //cout << i << " ";
    //         }
    //     }
    //     flag = false;
    // }

    // Write your code here
    // for (long number = first; number <= last; number++)
    // {
    //     if (number == 1 or number == 0)
    //         continue;
    //     if (isPrime(number) and isDigitsPrime(number))
    //     {
    //         cnt++;
    //     }
    // }
    cout << cnt << '\n';

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
