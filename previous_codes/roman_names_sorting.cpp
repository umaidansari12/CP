// C++ program to sort an array of
// Roman Numerals in ascending order

#include <bits/stdc++.h>
using namespace std;

// Function to return the value
// of a Roman symbol
int value(char r)
{
    // I in roman is equal to
    // 1 in decimal
    if (r == 'I')
        return 1;

    // V in roman is equal to
    // 5 in decimal
    if (r == 'V')
        return 5;

    // X in roman is equal to
    // 10 in decimal
    if (r == 'X')
        return 10;

    // L in roman is equal to
    // 50 in decimal
    if (r == 'L')
        return 50;

    // C in roman is equal to
    // 100 in decimal
    if (r == 'C')
        return 100;

    // D in roman is equal to
    // 500 in decimal
    if (r == 'D')
        return 500;

    // M in roman is equal to
    // 1000 in decimal
    if (r == 'M')
        return 1000;

    return -1;
}

// Function to return the decimal value
// of a roman numaral
int romanToDecimal(string& str)
{
    // Initialize result
    int res = 0;

    // Traverse given input
    for (int i = 0; i < str.length(); i++) {

        // Getting value of symbol s[i]
        int s1 = value(str[i]);

        if (i + 1 < str.length()) {

            // Getting value of symbol s[i+1]
            int s2 = value(str[i + 1]);

            // Comparing both values
            if (s1 >= s2) {

                // Value of current symbol
                // is >= the next symbol
                res = res + s1;
            }
            else {

                // Value of current symbol
                // is < the next symbol
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
}

// Function to sort the array according to
// the increasing order
void sortArr(string arr[], int n)
{
    // Vector to store the roman to integer
    // with respective element
    vector<pair<int, string> > vp;

    // Inserting roman to integer
    // with respective elements in vector pair
    for (int i = 0; i < n; i++) {
        vp.push_back(make_pair(
                         romanToDecimal(
                             arr[i]),
                         arr[i]));
    }

    // Sort the vector, this will sort the pair
    // according to the increasing order.
    sort(vp.begin(), vp.end());

    // Print the sorted vector content
    for (int i = 0; i < vp.size(); i++)
        cout << vp[i].second << " "
             << vp[i].first << "\n";
}

// Driver code
int main()
{
    string arr[] = { "MCMIV", "MIV",
                     "MCM", "MMIV"
                   };
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArr(arr, n);

    return 0;
}