class Solution {
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
		// code here
		map<int, int> m;
		for (int i = 0; i < n; i++)
			m[pow(arr[i], 2)]++;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (m.find(pow(arr[i], 2) + pow(arr[j], 2)) != m.end())
					return true;
			}

		}
		return false;
	}
};