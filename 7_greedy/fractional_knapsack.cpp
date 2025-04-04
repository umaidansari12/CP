// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr, arr + n, [](const Item & a, const Item & b) {
            double a_value = a.value / (double)a.weight;
            double b_value = b.value / (double)b.weight;
            return a_value >= b_value;
        });
        double value = 0.0;
        for (int i = 0; i < n; i++) {
            if (arr[i].weight <= w) {
                value += ((double)arr[i].value);
                w -= (arr[i].weight);
            }
            else {
                value += (arr[i].value / (double)arr[i].weight) * w;
                w = 0;
            }
            // cout << w<<endl;
        }
        return value;
    }
};