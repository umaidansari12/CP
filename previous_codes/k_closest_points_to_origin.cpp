class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <vector<int>, vector<vector<int>>, compare> q(points.begin(), points.begin() + k);
        for (int i = k; i < points.size(); i++)
        {
            vector<int> point = q.top();
            if (((point[0]*point[0]) + (point[1]*point[1])) > ((points[i][0]*points[i][0]) + (points[i][1]*points[i][1])))
            {
                q.pop();
                q.push(points[i]);
            }
        }
        vector<vector<int>> output;
        while (!q.empty())
        {
            output.push_back(q.top());
            q.pop();
        }
        return output;
    }
private:
    struct compare {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return (a[0] * a[0]) + (a[1] * a[1]) < (b[0] * b[0]) + (b[1] * b[1]);
        }
    };
};