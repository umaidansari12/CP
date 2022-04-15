class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int untouched =0;
        map<int,int> m;
        for(auto i:wall)
        {
            int end=0;
            for(int j=0;j<i.size()-1;j++)
            {
                end+=i[j];
                m[end]++;
                untouched=max(untouched,m[end]);
            }
        }
        return wall.size()-untouched;
    }
};