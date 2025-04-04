class Solution {
public:
    //Function to count the frequency of all elements from 1 to N in the array.
    // vector<int> count(1e7,0);
    void frequencyCount(vector<int>& arr, int N, int P)
    {
        // code here
        // vector<int> count(P+2,0);
        // for(int i=0;i<N;i++){
        //     count[arr[i]]++;
        // }
        // for(int i=1;i<=N;i++){
        //     arr[i-1] = count[i];
        // }
        unordered_map<int, int>map;

        for (int i = 0; i < N; i++) {
            map[arr[i]]++;
        }
        arr.clear();
        for (int i = 1; i <= N; i++) {
            arr.push_back(map[i]);
        }

    }
};