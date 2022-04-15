int Solution::braces(string A) {
    stack<char> s;
    for(auto ch:A)
    {
        if(ch=='(' or ch =='+' or ch=='-' or ch == '*' or ch == '/')
        s.push(ch);
        else if(ch==')')
        {
            if(s.top()=='(')
            return true;
            else
            {
                while(!s.empty() and s.top()!='(')
                    s.pop();
                s.pop();
            }
        } 
    }
    return false;
}
