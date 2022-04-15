#include<bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    string s1=s.substr(8,2);
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
	string s;
	cin>>s;
	
}

/*
int main() {
    string s;
    cin >> s;

    int n = s.length();
    int hh, mm, ss;
    hh = (s[0] - '0') * 10 + (s[1] - '0');
    mm = (s[3] - '0') * 10 + (s[4] - '0');
    ss = (s[6] - '0') * 10 + (s[7] - '0');

    if (hh < 12 && s[8] == 'P') hh += 12;
    if (hh == 12 && s[8] == 'A') hh = 0;

    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}
*/
