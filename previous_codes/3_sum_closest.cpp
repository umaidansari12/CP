/*As stated in the earlier hint, the naive approach is to have 3 loops of i,j,k over the array. We then just track S[i]+S[j]+S[k] for the case when (S[i]+S[j]+S[k]-target) is minimum.
The code for the same looks something like the following :


  IF number of elements in S < 3
    THEN return -1; // Invalid case
  minDifference = abs(S[0] + S[1] + S[2] - target);
  bestTillNow = S[0] + S[1] + S[2];
  FOR i = 0 to size of S
    FOR j = i + 1 to size of S
      FOR k = j + 1 to size of S
        newDiff = abs(S[i] + S[j] + S[k] - target)
        IF newDiff < minDifference
          minDifference = newDiff
          bestTillNow = S[i] + S[j] + S[k]
        END IF
      END FOR
    END FOR
  END FOR

  bestTillNow is my answer.

However, as stated earlier this approach is O(N^3). Lets see if we can do better.

Lets sort the array.
When the array is sorted, try to fix the least integer by looping over it.
Lets say the least integer in the solution is arr[i].

Now we need to find a pair of integers j and k, such that arr[j] + arr[k] is closest to (target - arr[i]).
To do that, let us try the 2 pointer approach.
If we fix the two pointers at the end ( that is, i+1 and end of array ), we look at the sum.

If the sum is smaller than the sum we need to get to, we increase the first pointer.
If the sum is bigger, we decrease the end pointer to reduce the sum.

The naive approach obviously is exloring all combinations of 3 integers using 3 loops.

Now, to look into improving, does it help if we sort the array?


*/

int threeSumClosest(vector<int> arr, int target) {
    // Your code goes here
    int n = arr.size(), minDiff = INT_MAX, ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int sum = arr[i] + arr[j] + arr[k];
                int diff = abs(sum - target);
                if (diff < minDiff)
                {
                    minDiff = diff;
                    ans = sum;
                }
            }
        }
    }
    return ans;


}
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INT_MAX, n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                int diff = (sum - target);
                if (abs(target - sum) < abs(target - ans))
                    ans = sum;
                else if (abs(target - sum) == abs(target - ans))
                {
                    if (sum > ans)
                        ans = sum;
                }
                if (sum == target)
                    return sum;
                else if (sum < target)
                    l++;
                else
                    r--;
            }
        }
        return ans;

    }
};

int threeSumClosest(vector<int> arr, int target) {
    // Your code goes here
    int n = arr.size(), minDiff = INT_MAX, ans = arr[0] + arr[1] + arr[2];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = arr[i] + arr[l] + arr[r];
            if (abs(1ll * target - sum) < abs(1ll * target - ans))
                ans = sum;
            else if (abs(1ll * target - sum) == abs(1ll * target - ans)) // condition jab difference same hoga similar to example 2
            {
                if (sum > ans)
                    ans = sum;
            }
            if (sum == target)
                return sum;
            else if (sum < target)
                l++;
            else
                r--;
        }
    }
    return ans;


}


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int bestSum = 1000000000, sum = 0;
        // Fix the smallest number in the three integers
        for (int i = 0; i < num.size() - 2; i++) {
            // Now num[i] is the smallest number in the three integers in the solution
            int ptr1 = i + 1, ptr2 = num.size() - 1;
            while (ptr1 < ptr2) {
                sum = num[i] + num[ptr1] + num[ptr2];
                if (abs(target - sum) < abs(target - bestSum)) {
                    bestSum = sum;
                }
                if (sum > target) {
                    ptr2--;
                } else {
                    ptr1++;
                }
            }
        }
        return bestSum;
    }
};

int Solution::threeSumClosest(vector<int> &A, int B) {

    if (A.size() < 3) {
        return 0;
    }

    sort(A.begin(), A.end());

    int i = 0;
    int sum, minDiff = INT_MAX;

    while (i < A.size() - 2) {
        int left = i + 1;
        int right = A.size() - 1;
        while (right > left) {
            int temp = A[i] + A[left] + A[right];
            int diff = abs(temp - B);
            if (diff == 0) {
                return B;
            }
            if (diff < minDiff) {
                minDiff = diff;
                sum = temp;
            }
            if (temp < B) {
                left++;
            }
            else {
                right--;
            }
        }
        i++;
    }

    return sum;
}
