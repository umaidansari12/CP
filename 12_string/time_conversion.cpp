#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int hour = stoi(s.substr(0, 2));
    int min = stoi(s.substr(3, 2));
    int seconds = stoi(s.substr(6, 2));
    string timeStamp = s.substr(8, 2);
    if (timeStamp.compare("AM") == 0)
    {
        if (hour == 12)
            hour = 0;
    }
    else if (timeStamp.compare("PM") == 0)
    {
        if (hour != 12)
            hour += 12;
    }
    string timeResult = "";
    if (hour >= 0 and hour <= 9)
    {
        timeResult += "0" + to_string(hour) + ":";
    }
    else
    {
        timeResult += to_string(hour) + ":";
    }
    if (min >= 0 and min <= 9)
    {
        timeResult += "0" + to_string(min) + ":";
    }
    else
    {
        timeResult += to_string(min) + ":";
    }
    if (seconds >= 0 and seconds <= 9)
    {
        timeResult += "0" + to_string(seconds);
    }
    else
    {
        timeResult += to_string(seconds);
    }
    return timeResult;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
