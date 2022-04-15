#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int cnt = 0;
int printSubsequence()
{
	cnt++;
	//this statement is used to check if the recursion depth doesnt go 100 times and will make recursion debugging easy allowing your program not to freezze in some infinite case
	if (cnt >= 100)
		return 0;
}

int myLogic()
{
	return -1;
}

int correctAnswerorBruteAnswer()//your brute force or someones accepted solution
{
	return -1;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//Constraints
	// 1 <= T <=10
	// 1 <= N <= 1000000
	// 1 <= A[i] <= 1000000

	// generating test case for stress testing
	// also u can change  t to some finite number like 1 to 1000 to get as much test case where your code is failing
	// int cnt=1;
	// while(cnt<=1000)
	//{
	//body to generate test case
	//cnt++;
	//}
	srand(time(NULL));//this function is used because when we  used to build our code in c++ it caches / seeds those value for rand() function and produces the same test case again and again so this function doesnt seeds the value for rand() functionn
	int t = rand() % 10 + 1; // rand()%10 produces element in the range [0,9] + 1 to get 10 values
	while (t--)
	{
		int n = rand() % 9 + 1; // small values range to get the smalller test case for debugging
		int a[n];
		for (int i = 0; i < n; i++)
			a[i] = rand() % 10 + 1;// small values range to get the smalller test case for debugging
	}

	while (t--)
	{
		int myAns = myLogic();
		int correctAns = correctAnswerorBruteAnswer();
		if (correctAns != myAns)
		{
			//cout<<"all the parameters like array and size";
			break;
		}
	}
	return 0;
}