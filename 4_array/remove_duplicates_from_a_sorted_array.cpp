class Solution {
public:
    // brute
    // insert elements in set
    // traverse the set and modify the array
    // tc - o(nlogn) + o(n) as logn is insertion in set
    // sc - o(n)
    int remove_duplicate(int a[], int n) {
        // code here
        set<int> unique_elements;
        for (int i = 0; i < n; i++) {
            unique_elements.insert(a[i]);
        }
        int index = 0;
        for (auto element : unique_elements) {
            a[index++] = element;
        }
        return index;
    }
};


// this approach uses two pointers , as single will always be sorted and at its correct position we will need to find next element that will come to its side
// initialize two pointers i and j both pointing at 0,
//now increment j until we are getting same element at i and j,
// as soon as we get unequal element that means now we have found a unique elemnent and its time to place it at its correct location
// which is just beside where ith element is residing
// we want to do it until j exhausts its boundary
// test case - all unique elements, all duplicates, single element, mix element
// TC - O(N) - j is travelling till n
// SC - O(1)



class Solution {
public:
    int remove_duplicate(int a[], int n) {
        // code here
        int first_ptr = 0, second_ptr = 0;
        while (second_ptr < n) {
            while (second_ptr < n and a[first_ptr] == a[second_ptr]) {
                second_ptr++;
            }
            a[++first_ptr] = a[second_ptr];
        }
        return first_ptr;
    }
};

class Solution {
public:
    int remove_duplicate(int a[], int n) {
        // code here
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (a[i] != a[j]) {
                a[i + 1] = a[j];
                i++;
            }
        }
        return i + 1;
    }
};