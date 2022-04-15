class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        for (int i = 1; i < triangle.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0)
                {
                    sum = triangle[i][j] + triangle[i - 1][j];
                }
                else if (j == triangle[i].size() - 1)
                {
                    sum = triangle[i][j] + triangle[i - 1][triangle[i - 1].size() - 1];
                }
                else
                {
                    int mi = min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                    sum = mi + triangle[i][j];
                }
                triangle[i][j] = sum;
            }
        }
        return *min_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());

    }
};