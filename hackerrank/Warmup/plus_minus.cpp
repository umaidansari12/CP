#include<bits/stdc++.h>

using namespace std;

void plusMinus(vector <int> arr)
{
	int n=0,s=arr.size(),p=0,z=0;
	for(int i=0;i<s;i++)
	{
		if(arr[i]<0)
		{
			n++;
		}
		else if(arr[i]>0)
		{
			p++;
		}
		else
		{
			z++;
		}         
	}

	cout<<fixed << setprecision(6)<<p/float(s)<<endl<<n/float(s)<<endl<<z/float(s);
	
}
int main()
{
	int n;
	cin>>n;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	plusMinus(arr);
}
/*#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    float pl = 0, mn = 0, zr = 0;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        zr += (val == 0);
        pl += (val > 0);
        mn += (val < 0);
    }
    
    zr = zr / (double)n;
    pl = pl / (double)n;
    mn = mn / (double)n;
    
    printf("%0.06lf\n%0.06lf\n%0.06lf\n", pl, mn, zr);
    return 0;
}*/
