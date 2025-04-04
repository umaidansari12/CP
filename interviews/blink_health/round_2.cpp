#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.



// Example 1:

// Input: nums = [1,2,3,4,5]
// Output: true
// Explanation: Any triplet where i < j < k is valid.
// Example 2:

// Input: nums = [5,4,3,2,1]
// Output: false
// Explanation: No triplet exists.
// Example 3:

// Input: nums = [2,1,5,0,4,6]
// Output: true
// Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

// approach - 1

// total of 2 loops
// approach - 2
// stack to store the last element being pushed
// current element which is being traversed, is greater than element stored on top of stack

// stack = [2,5,6]

// first_min = 1e9
// second_min = 1e9

// first_min = min(first_min, arr[i]);

// we've found first_min, -- flag should be there to check if we've found first_
// if(first_min < second_min){
//  second_min = min(second_min, arr[i]);
//}

// if we've found



// To execute C++, please define "int main()"
int main() {
  // auto words = { "Hello, ", "World!", "\n" };
  // for (const char* const& word : words) {
  // cout << word;
  // }
  // vector<int> a = {1,2,3,4,5};
  // vector<int> a = {5,4,3,2,1};

  // vector<int> a = {6,2,1,5,0,4,6};

  // 0, 4, 6

  // 2,5,6
  // 0,4,6

  // find minimum and second_minimum and third in second go or in same scan
// find first 2 numbers in increasing order and find last numbers which will be bigger than 2 numbers

// first_2 numbers can be updated while scanning
//




// i = 0
  // ith_element = 2
  // jth_found = false, true
  // jth_element_pos = -1, 2
  // kth_found = false
  // j = 1,2,3,4, 5
  // _size = 5

  // int _size = a.size();

  // bool jth_found = false, kth_found = false;

  // int jth_element_pos = -1;

  // for(int i=0;i<_size;i++){
  //   for(int j=i+1;j<_size;j++){
  //     if(!jth_found and a[j] > a[i]){
  //       jth_found = true;
  //       jth_element_pos = j;
  //     }
  //     if(jth_found and jth_element_pos !=-1 and a[j]>a[jth_element_pos]){
  //       kth_found = true;
  //     }
  //   }
  // }

  // cout << kth_found << endl;

  // vector<int> a = {5, 6, 7};
  // vector<int> a = {4, -2, 5,8};

  // vector<int> a = {1, 2, 1};
  vector<int> a = {1, 2, 3, 4, 3};



  vector<int> answer;

  int _size = a.size();

  for (int i = 0; i < _size; i++) {
    bool next_greater_found = false;
    for (int j = (i + 1) % _size; j != i; j = (j + 1) % _size) {
      if (!next_greater_found and a[j] > a[i]) {
        answer.push_back(a[j]);
        next_greater_found = true;
        break;
      }
    }
    if (!next_greater_found)
      answer.push_back(-1);
  }
  for (auto ele : answer)
    cout << ele << ",";
  cout << endl;
  return 0;
}


// Your previous Plain Text content is preserved below:

// This is just a simple shared plaintext pad, with no execution capabilities.

// When you know what language you'd like to use for your interview,
// simply choose it from the dots menu on the tab, or add a new language
// tab using the Languages button on the left.

// You can also change the default language your pads are created with
// in your account settings: https://app.coderpad.io/settings

// Enjoy your interview!

// Given a circular array arr[] of N integers such that the last element of the given array is adjacent to the first element of the array, the task is to print the Next Greater Element in this circular array. Elements for which no greater element exist, consider the next greater element as “-1”

// we should start from 0th index and move to last index and we need to find next greater element for that element and push into an answer array
// base case to make it circular is we should stop at the same index from where we started off
// increment condition => j = (j+1)%n;
// stopping condition => j!=i (we've to store i in a variable)
// starting condition => j = (j+1)%n;
// store ith element and position
// take an answer array


// Input: arr[] = {5, 6, 7}
// Output: {6, 7, -1}
// Explanation:
// Next Greater Element for 5 is 6, for 6 is 7, and for 7 is -1 as we don’t have any element greater than itself so its -1.

// Input: arr[] = {4, -2, 5, 8}
// Output: {5, 5, 8, -1}
// Explanation:
// Next Greater Element for 4 is 5, for -2 its 5, for 5 is 8, and for 8 is -1 as we don’t have any element greater than itself so its -1, and for 3 its 4.


// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2;
// The number 2 can't find next greater number.
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]