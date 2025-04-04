class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int _size = s.size(), ans = 0, left = 0;
        // unordered_set<char> hash_set;
        // for(int i=0;i<_size;i++){
        //     set<char> hash_set;
        //     for(int j=i;j<_size;j++){
        //         if(hash_set.find(s[j])!=hash_set.end()){
        //             break;
        //         }
        //         ans = max(ans, j-i+1);
        //         hash_set.insert(s[j]);
        //     }
        // }
        // for(int right = 0; right < _size;right++){
        //     while(hash_set.find(s[right])!=hash_set.end()){
        //         hash_set.erase(s[left]);
        //         left++;
        //     }
        //     ans = max(ans, right - left +1);
        //     hash_set.insert(s[right]);
        // }
        // unordered_map<int, int> hash_map;
        // for(int right = 0; right < _size;right++){
        //     while(hash_map.find(s[right])!=hash_map.end() and hash_map[s[right]]>0){
        //         if(hash_map[s[left]]>0)
        //             hash_map[s[left++]]--;
        //     }
        //     ans = max(ans, right - left +1);
        //     hash_map[s[right]]++;
        // }
        // return ans;
        unordered_map<int, int> hash_map;
        for (int right = 0; right < _size; right++) {
            while (hash_map.find(s[right]) != hash_map.end() and hash_map[s[right]] >= left) {
                left = hash_map[s[right]]  + 1;
            }
            ans = max(ans, right - left + 1);
            hash_map[s[right]] = right;
        }
        return ans;
    }
};