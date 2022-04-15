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


class Solution {
private:
    struct manhattan_distance {
        bool operator()(vector<int> &a, vector<int> &b) {
            return (a[0] * a[0]) + (a[1] * a[1]) > (b[0] * b[0]) + (b[1] * b[1]);
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, manhattan_distance> closestPoints;

        int _size = points.size();

        for (int i = 0; i < _size; i++) {
            closestPoints.push(points[i]);
        }

        vector<vector<int>> result;

        // while(!closestPoints.empty()){
        //    cout<<closestPoints.top()[0] << " "<<closestPoints.top()[1]<<endl;
        //    closestPoints.pop();
        // }

        while (k--) {
            result.push_back(closestPoints.top());
            closestPoints.pop();
        }


        return result;

    }
};