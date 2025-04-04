class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        // sort children array and cookie array and start contenting minimum size cookie to the child to satisfy his need not give him more
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int content_children = 0;
        int l = 0, r = 0, g_size = g.size(), s_size = s.size();
        while (l < g_size and r < s_size) {
            if (s[r] >= g[l]) {
                l++, r++;
            }
            else {
                r++;
            }
        }
        return l;
        // for(int i=0;i<g_size;i++){
        //     for(int j=0;j<s_size;j++){
        //         if(s[j]>=g[i] and content_children<s_size and content_children < g_size){
        //             content_children++;
        //             break;
        //         }
        //     }
        // }
        // for(int i=0;i<=min(g_size-1, s_size-1);i++){
        //     if(s[i]>=g[i])
        //         content_children++;
        // }
        // return content_children;
    }
};