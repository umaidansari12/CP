class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    answer[i] = prices[i] - prices[j];
                    break;
                }
            }
            if (answer[i] == -1)
                answer[i] = prices[i];
        }
        return answer;
    }
};

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result = prices;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() and prices[stk.top()] >= prices[i]) {
                result[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};