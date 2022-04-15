#include <bits/stdc++.h>

using namespace std;

int recursive_sum(long long int n)
{
    if(n==0)
        return 0;
    return n%10 + recursive_sum(n/10);
}
int super_Digit(string n, int k) {
    int x=stoi(n);
    int sum=recursive_sum(x);
    sum*=k;
    string str = to_string(sum);
    if(n.length()==1)
    {

        int a= atoi(n.c_str());
        return a;
    }
    return super_Digit(str,1);
}
int superDigit(string n, int k) {
    int sum=0;
    for(int i=0;i<n.length();i++)
    {
        char c = n[i];
        int x = c - '0';
        sum = sum + (x*k); 
    }
    if(sum % 9 == 0)
    {
        return 9;
    }
    return sum % 9;
}
string time_conversion(string s)
{
    /*
    string s1=s.substr(8,10);
    string s2=s.substr(0,2);
    string s3;
    int n;
    string s4;
    s4.copy(s);
    cout << s;
    if(s1.compare("PM")==0)
    {
        n = stoi(s2);
        n=(n + 12)%24;
        s3=to_string(n);
        cout << s3 << s.substr(2,10)<<endl;         
    }
    cout << endl;
    
    cout << s1;
    cout << s2;
    cout << n;
    */
    string s1=s.substr(8,10);
    string s2=s.substr(0,2);
    string s3;
    int n;
    string s4 = s.substr(0,8);
    if((s1.compare("PM")==0) && s2.compare("12")==0)
    {
        s3="12";
        s4= s3 + s.substr(2,6);         
    }
    else if(s1.compare("PM")==0)
    {
        n = stoi(s2);
        n=(n + 12)%24;
        s3=to_string(n);
        s4= s3 + s.substr(2,6);         
    }
    else if((s1.compare("AM")==0)&&(s2.compare("12")==0))
    {
        s3="00";
        s4= s3 + s.substr(2,6); 
    }
    return s4;
}
int main()
{
    //int x = superDigit("9875",4);
    //cout << time_conversion("01:00:45AM");
	int q, type; cin >> q; 
    map<string,int> clas; string name;
	for (int i(0), mark; i<q; ++i)
	{
		cin >> type >> name;
		if (type == 1){
			cin >> mark;
			clas[name] += mark;
		}
		else if (type == 2)
			clas.erase(name);
		else
			cout << clas[name] << "\n";
	}
	return 0;
}
/*int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    /*map<string,int>m;
    int q,y,k;
    string x;
    cin >> q;
    for(int i =0;i<q;i++)
    {
        cin >> k;
        cin >> x;
        if(k==1)
        {
            cin >> y;
            map<string,int>::iterator i = m.find(x);
            if(i == m.end())
            {
                m.insert(pair<string,int>(x,y));
            }
            else
            {
                i->second= i->second + y;
            }
        }
        else if(k==2)
        {
            m.erase(x);
        }
        else
       {
            i = m.find(x);
            if(i == m.end())
            {
                cout <<"0\n";
            }
            else
            {
                cout << i->second<<endl;
            }
       } 
        
    }  
    
    return 0;
}*/


