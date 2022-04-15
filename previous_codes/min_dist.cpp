/*#include<bits/stdc++.h>

using namespace std;

int minimumDistances(vector<int> a) {
    vector <int> r(100001);
    vector <int> di;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        r[a[i]]++;
    }
    for(int i=0;i<((3*n)/4);i++)
    {
        if(r[a[i]]==2 )
        {
            int j=i+1;
            for(j=i+1;j<n;j++)
            {
                if(a[j]==a[i])
                {
                    break;
                }
            }
            int d=abs(j-i);
            di.push_back(d);
           
        }
    }
if(di.size()==0)
{
    return -1;
}
int m=*min_element(di.begin(),di.end());
return m;
}

int main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int r=minimumDistances(a);
    cout<<r<<endl;
}*/
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000+1];
#define inf 1000000000
int main() {
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];

	int res = inf;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < i; j++) 
			if(a[i] == a[j]) 
            {
                res = min(res, i - j);

            }

	if(res == inf) res = -1;
	cout << res << endl;
	
	return 0;
}