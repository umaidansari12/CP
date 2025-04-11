int solution(vector<int> fish, vector<int> baits) {
    int m = baits.size(), n = fish.size(), max_fish = 0;
    sort(baits.begin(), baits.end(), greater<int>());
    
    vector<bool> fish_caught(n, false);
    
    for(int i=0;i<m;i++){
        int bait_used = 0;
        for(int j=0;j<n;j++){
            if(bait_used < 3 and fish_caught[j] == false and baits[i]<fish[j]){
                bait_used++;
                fish_caught[j] = true;
                max_fish++;
            }
        }
    }
    return max_fish;
}

