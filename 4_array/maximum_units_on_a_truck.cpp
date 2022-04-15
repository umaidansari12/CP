class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b) {
            return a[1] >= b[1];
        });

        int answer = 0;
        for (auto box : boxTypes) {
            if (box[0] <= truckSize) {
                truckSize -= box[0];
                answer += (box[0] * box[1]);
            }
            else {
                answer += (truckSize * box[1]);
                break;
            }
        }
        return answer;

    }
};

class Solution {
public:
    static bool comp(const vector<int> a, const vector<int> b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int ans = 0;
        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (truckSize >= boxTypes[i][0])
            {
                truckSize -= boxTypes[i][0];
                ans += (boxTypes[i][0] * boxTypes[i][1]);
            }
            else
            {
                ans += (truckSize * boxTypes[i][1]);
                truckSize = 0;
            }
        }
        return ans;

    }
};