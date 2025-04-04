class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        return (b[1] > a[1]);
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        priority_queue<vector<int>> pq;

        int i = 0;

        vector<vector<int>> data;

        for (i = 0; i < n; i++)
        {
            data.push_back({profits[i], capital[i]});
        }

        sort(data.begin(), data.end(), comp);

        i = 0;
        while (k--)
        {
            while (i < n && w >= data[i][1])
            {
                pq.push(data[i]);
                i++;
            }

            if (pq.empty()) break;

            w += (pq.top())[0];
            pq.pop();
        }

        return w;

    }
};