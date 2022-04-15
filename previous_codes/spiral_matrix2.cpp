class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int direction = 0, top = 0, down = n - 1, left = 0, right = n - 1, j = 1;
        while (left <= right && top <= down)
        {
            if (direction == 0)
            {
                for (int i = left; i <= right; i++)
                    res[top][i] = j++;
                top++;
            }
            else if (direction == 1)
            {
                for (int i = top; i <= down; i++)
                    res[i][right] = j++;
                right--;
            }
            else if (direction == 2)
            {
                for (int i = right; i >= left; i--)
                    res[down][i] = j++;
                down--;
            }
            else if (direction == 3)
            {
                for (int i = down; i >= top; i--)
                    res[i][left] = j++;
                left++;
            }
            direction = (direction + 1) % 4;
        }
        return res;

    }
};