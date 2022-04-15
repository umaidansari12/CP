#include<string>
using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    string t;
    int h=minutes/60;
    string hour;
    hour+=(to_string(h));
    minutes%=60;
    string min;
    if(minutes<=9)
    min+=("0"+to_string(minutes));
    else
    min+=(to_string(minutes));
    
    return hour+":"+min;
    
}