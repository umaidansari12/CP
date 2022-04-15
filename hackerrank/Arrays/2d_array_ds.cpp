#include <bits/stdc++.h>

using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int sum=0,m=-63;
    for(int i=0;i<arr.size()-2;i++)
    {
        for(int j=0;j<arr[0].size()-2;j++)
        {
            sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            m=max(m,sum);
            sum=0;
        }
    }

return m;
}

int main()
{
	vector <vector <int>> arr(6,vector<int> (6,0));
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	cout<<hourglassSum(arr);
}
