#include <bits/stdc++.h>

using namespace std;

string isBalanced(string s)
{
    /*stack <char> st;
    for(auto c: s)
    {
        
        if(c=='(' || c=='{' || c=='[')
        {
            st.push(c);
        }
        else if(c==')' || c=='}' || c==']')
        {
            if(c==')' && (st.empty() ||st.top()!='('))
            {
                return "NO";
            }
            if(c=='}' && (st.empty() ||st.top()!='{'))
            {
                return "NO";
            } 
            if(c==']' && (st.empty() ||st.top()!='['))
            {
                return "NO";
            }
            else
            {
                st.pop();
            }
        } 
    }
    return st.empty()?"YES":"NO";
    */
    stack<char> st;  
    
    for (auto c: s) {
        switch (c) {
            case '{':
            case '(':
            case '[':
                st.push(c);
                break;
            case '}':
                if (st.empty() || (st.top() != '{')) {
                    return "NO";
                }
                st.pop();
                break;
            case ')':
                if (st.empty() || (st.top() != '(')) {
                    return "NO";
                }
                st.pop();
                break;
            case ']':
                if (st.empty() || (st.top() != '[')) {
                    return "NO";
                }
                st.pop();
                break;
        }
    }
    
    return st.empty() ? "YES" : "NO";
}
void showstack(stack <char> a) 
{ 
    while (!a.empty()) 
    { 
        cout << '\t' << a.top(); 
        a.pop(); 
    } 
    cout << '\n'; 
} 

int main()
{
    stack<char> s;
    string sm;
    cin >> sm;
    char c;
    for(int i=0; i < sm.length(); i++)
    {
        if (sm[i]=='(' || sm[i]=='{' || sm[i]=='[')
        {
            c=sm[i];
            s.push(c);
        }
        else if(sm[i]==')' || sm[i]=='}' || sm[i]==']')
        {
           if(sm[i]==')' && s.top()=='(')
           {
               s.pop();
           }
           else if(sm[i]==']' && s.top()=='[')
           {
               s.pop();
           }
           else if(sm[i]=='}' && s.top()=='{')
           {
               s.pop();
           }
           else
           {
               c=sm[i];
               s.push(c);
           }
                
        }
        
    }
    if(s.empty())
    {
        cout<<"true"<<endl;
    }
    else
    {
          cout<<"false"<<endl;
    }
    

}