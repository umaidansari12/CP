class Solution {
public:
    bool isValid(string s){
        stack<int> st;
        int _size = s.size();
        for (int i = 0; i < _size; i++) {
            if (s[i] == '(')
                st.push(s[i]);
            else {
                if (st.empty())
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
    int longestValidParentheses(string s) {

        int _size = s.size(), ans = 0;

        // for(int i=0;i<_size;i++){
        //     string temp = "";
        //     for(int j=i;j<_size;j++){
        //         temp += s[j];
        //         if(isValid(temp))
        //             ans = max(ans, j-i+1);
        //     }
        // }
        // return ans;
        // int _size = s.size(), counter = 0, answer = 0;
        // stack<int> stk;

        // for(int i=0;i<_size;i++){
        //     if(s[i] == '(')
        //         stk.push(s[i]);
        //     else if(s[i] == ')'){
        //         if(stk.empty()){
        //             counter = 0;
        //         }
        //         else{
        //             stk.pop();
        //             counter+=2;
        //             answer = max(answer, counter);
        //         }
        //     }
        // }
        // return answer;

        // stack<int> st;
        // st.push(-1);

        // for(int i=0;i<_size;i++){
        //     if(s[i]=='('){
        //         st.push(i);
        //     }
        //     else {
        //         st.pop();
        //         if(st.empty())
        //             st.push(i);
        //         else{
        //             ans = max(ans, i - st.top());
        //         }
        //     }
        // }
        // return ans;

        int open = 0, close = 0;
        for (int i = 0; i < _size; i++) {
            if (s[i] == '(')
                open++;
            else
                close++;
            if (open == close)
                ans = max(ans, open + close);
            else if (close > open)
                open = close = 0;
        }
        open = close = 0;
        for (int i = _size - 1; i >= 0; i--) {
            if (s[i] == '(')
                open++;
            else
                close++;
            if (open == close)
                ans = max(ans, open + close);
            else if (open > close)
                open = close = 0;
        }
        return ans;
    }
};