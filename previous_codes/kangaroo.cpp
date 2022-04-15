#include <bits/stdc++.h>

using namespace std;
/*int tm=x1-x2;
    if(x1<x2 && v1 <=v2)
    {
        string s="NO";
        return s;
    }
    if(x1>=x2 && v1 < v2)
    {
        string s="YES";
        return s;
    }
    if(tm<0 && v2<v1)
    {
        string s="YES";
        return s;
    }
    if(tm<0)
    {
        string s="NO";
        return s;
    }
    if((tm)%(v2-v1)==0)
    {
        string s="YES";
        return s;
    }
    else
    {
        string s="NO";
        return s;
    }
*/

string kangaroo(int x1, int v1, int x2, int v2) {
    /*int tm=x1-x2;
    
    if(tm<0)
    {
        string s="NO";
        return s;
    }
    if((tm)%(v2-v1)==0)
    {
        string s="YES";
        return s;
    }
    else
    {
        string s="NO";
        return s;
    }*/
    while(x1!=x2)
    {
        x1+=v1;
        x2+=v2;
        if(x1>x2)
        {
            break;
        }
    }
    if(x1==x2)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }

}
int main()
{
    string s=kangaroo(0,2,5,3);
    cout << s;
}