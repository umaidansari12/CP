#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>


using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 1; i <= 1000; i++)
		{
			cout << (i * i) << endl;
			int ans;
			cin >> ans;
			if (ans == 1) goto end;
		}
end:
		continue;
	}
	return 0;
}

/*int main() {
	int l = 1, r = 1000000, queries = 0;
	while (l != r) {
		int mid = (l + r + 1) / 2;
		printf("%d\n", mid);
		fflush(stdout);
		queries++;
		int response;
		scanf("%d", response);
		if (response == 1)
			break;
		else if (response == 0)
			r = mid — 1;
		else
			l = mid;
	}

	printf("%d\n", l);
	fflush(stdout);
}*/