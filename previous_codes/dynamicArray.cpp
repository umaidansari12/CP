#include <bits/stdc++.h>

using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector <int> s[n];
    vector <int> l(n);
    int lastAnswer=0;
    int index;
    l.push_back(lastAnswer);
    for(int i =0;i<queries.size();i++)
    {
            if(queries[i][0]==1)
            {
                index=((queries[i][1]^lastAnswer) % n);
                s[index].push_back(queries[i][2]);
            }
            else
            {
                index=((queries[i][1]^lastAnswer) % n);
                lastAnswer = (queries[i][2]%s[index].size());
                l.push_back(lastAnswer);   
            }
    }

return l;

}
/*vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector <vector<int>> s(n);
    vector <int> l(n);
    int lastAnswer=0;
    int index,x,y;
    for(int i =0;i<queries.size();i++)
    {
        x=queries[i][1];
            index=((x^lastAnswer) % n);
            if(queries[i][0]==1)
            {
                s[index].push_back(queries[i][2]);
            }
            else
            {
                int si=s[index].size();
                y=queries[i][2]%si;
                
                lastAnswer = s[index][y];
                l.push_back(lastAnswer);   
            }
    }

return l;

}
*/

int main()
{
    int n;
    cin >> n;
    return 0;
}