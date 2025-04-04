// Brute

// tc - O(nlogx) + O(mlogy) + O(n+m) insertion of arr1 into set and insertion of arr2 into set
// sc - O(n+m) + O(n+m) set + result

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    //Your code here
    //return vector with correct order of elements
    set<int> answer;
    for (int i = 0; i < n; i++) {
        answer.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        answer.insert(arr2[i]);
    }
    vector<int> result;
    for (auto it : answer)
        result.push_back(it);
    return result;
}

// tc - O(n+m)
// sc - O(n+m) - result array

vector < int > sortedArray(vector < int > arr1, vector < int > arr2) {
    int n = arr1.size();
    int m = arr2.size();
    // Write your code here
    int first = 0, second = 0;
    vector<int> _union;
    while (first < n and second < m) {
        if (arr1[first] <= arr2[second]) {
            if (_union.size() == 0 or _union.back() != arr1[first])
                _union.push_back(arr1[first]);
            first++;
        }
        else {
            if (_union.size() == 0 or _union.back() != arr2[second])
                _union.push_back(arr2[second]);
            second++;
        }
    }

    while (first < n) {
        if (_union.back() != arr1[first])
            _union.push_back(arr1[first]);
        first++;
    }
    while (second < m) {
        if (_union.back() != arr2[second])
            _union.push_back(arr2[second]);
        second++;
    }
    return _union;
}