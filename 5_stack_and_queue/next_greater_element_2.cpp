class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> s;
        //for circular array just assuming that the array is doubled up and using moduloperator to get the things done down the line
        for (int i = (2 * n) - 1; i >= 0; i--) {
            //start iterating from back and checking if the element that is being placed at the top of the stack is less than or equal to the current element then we remove the current element from the stack as it is of no use for us as stack is maintaining the elements in increasing order from top to bottom and we discard elements smaller than the current element efficiently
            while (!s.empty() and s.top() <= nums[i % n]) {
                s.pop();
            }
            //now when we got the element that is greater than the current element and the stack is not empty then we make this top of the stack as the nge of the current element
            if (i < n) {

                if (!s.empty()) nge[i] = s.top();
            }
            //now push the current element into the stack
            s.push(nums[i % n]);
        }
        return nge;

    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> s;
        //for circular array just assuming that the array is doubled up and using moduloperator to get the things done down the line
        for (int i = 0; i < 2 * n; i++) {
            //start iterating from front and checking if the element that is being placed at the top of the stack is less than or equal to the current element then we remove the current element from the stack as it is of no use for us as stack is maintaining the elements in increasing order from top to bottom and we discard elements smaller than the current element efficiently
            while (!s.empty() and nums[s.top()] < nums[i % n]) {
                nge[s.top()] = nums[i % n];
                s.pop();
            }
            //now when we got the element that is greater than the current element and the stack is not empty then we make this top of the stack as the nge of the current element
            //now push the current element into the stack
            s.push(i % n);
        }
        return nge;

    }
};