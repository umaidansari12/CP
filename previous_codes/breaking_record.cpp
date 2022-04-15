#include<bits/stdc++.h>

using namespace std;

vector<int> breakingRecords(vector<int> scores) {
    int max=scores[0];
    int min=scores[0];
    vector <int> a(2);
    for(int i=0;i<scores.size();i++)
    {
        if(scores[i]>max)
        {
            a[0]++;
            max=scores[i];
        }
        if(scores[i]<min)
        {
            min=scores[i];
            a[1]++;
        }
    }

return a;
}

int main()
{
    vector <int> scores;

}