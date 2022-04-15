class Solution {

public:
	long long subCount(long long arr[], int N, long long K)
	{
		// Your code goes here
		long long int count = 0;
		//unordered_map<int,int> m;
		for (int i = 0; i < N; i++)
		{
			long long int sum = 0;
			for (int j = i; j < N; j++)
			{
				sum += arr[j];
				if (sum % K == 0)
					count++;
			}
		}
		return count;

	}



};

class Solution {

public:
	long long subCount(long long arr[], int N, long long k)
	{
		// Your code goes here
		long long int count = 0;
		unordered_map<int, int> m;
		int curr_sum = 0, mx = -1;
		for (int i = 0; i < N; i++)
		{
			curr_sum += arr[i];
			if (((curr_sum % k) + k) % k == 0)
				count++;

			if (m.find(((curr_sum % k) + k) % k) != m.end())
				count += m[((curr_sum % k) + k) % k];
			m[((curr_sum % k) + k) % k]++;
		}
		return count;

	}



};
