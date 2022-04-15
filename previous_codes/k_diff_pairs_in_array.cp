class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		int n = nums.size(), count = 0;
		set<pair<int, int>> s;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (abs(nums[i] - nums[j]) == k)
				{
					if (s.find({nums[i], nums[j]}) == s.end() && s.find({nums[j], nums[i]}) == s.end())
						count++;
					s.insert({nums[i], nums[j]});
				}

			}
		}
		return count;
	}
};

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size(),count=0;
        set<pair<int,int>> s;
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        while(i<n && j<n)
        {
            if(i!=j && abs(nums[j]-nums[i])==k && s.find({nums[i],nums[j]})==s.end())
            {
                    s.insert({nums[i],nums[j]});
                    count++;
            }
            if(abs(nums[j]-nums[i])>k)
                i++;
            else
                j++;
        }
        return count;
    }
};