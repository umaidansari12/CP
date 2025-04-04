class Solution {
public:
    double average(vector<int>& salary) {
        int _max = *max_element(salary.begin(), salary.end());
        int _min = *min_element(salary.begin(), salary.end());
        long long int sum = accumulate(salary.begin(), salary.end(), 0);

        sum -= (_max + _min);
        return sum / ((double)salary.size() - 2);
        // can be done with sorting too.
    }
};