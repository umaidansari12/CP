vector<int> solution(vector<vector<int>> symbolPairs) {
    unordered_set<int> s;
    int _size = symbolPairs.size();
    for(int i=0;i<_size;i++){
        s.insert(symbolPairs[i][0]);
        s.insert(symbolPairs[i][1]);
    }
    vector<int> ans;
    for(auto e: s){
        ans.push_back(e);
    }
    // sort(ans.begin(), ans.end());
    return ans;
}

