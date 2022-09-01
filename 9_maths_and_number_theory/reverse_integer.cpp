#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long int revNum = 0;
        
        while(x){         
            revNum = revNum*10 + x%10;
            x/=10;
            if(revNum<INT_MIN or revNum > INT_MAX)
                return 0;
        }
        return (int)revNum;   
            
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
    	
    }
    return 0;


