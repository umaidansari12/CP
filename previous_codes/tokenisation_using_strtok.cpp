#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char input[1000];
	cin.getline(input, 1000, '\n');
	char *token = strtok(input, " ");
	while (token != NULL)
	{
		cout << token << ",";
		token = strtok(NULL, " ");
	}


	return 0;
}