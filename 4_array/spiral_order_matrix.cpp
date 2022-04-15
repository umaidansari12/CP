vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int top = 0 , left = 0 , right = A[0].size() - 1, bottom = A.size() - 1, direction = 0;
    vector<int> res;
    while (left <= right and top <= bottom)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; i++)
            {
                res.push_back(A[top][i]);
            }
            top++;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(A[i][right]);
            }
            right--;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; i--)
            {
                res.push_back(A[bottom][i]);
            }
            bottom--;
        }
        else if (direction == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(A[i][left]);
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
    return res;
}
