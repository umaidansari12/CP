class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ans = max(ans, min(height[i], height[j]) * (j - i));
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0;
        while (left < right) {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return ans;
    }
};