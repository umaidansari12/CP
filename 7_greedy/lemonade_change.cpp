class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // int current_amount = 0, _size = bills.size();
        // for(int i=0;i<_size;i++){
        //     int return_amount = bills[i] - 5;
        //     cout<<i<<"-"<<current_amount<<":"<<return_amount<<endl;
        //     if(current_amount<return_amount){
        //         return false;
        //     }
        //     current_amount-=return_amount;
        //     current_amount+=5;
        // }
        int five = 0, ten = 0, twenty = 0, _size = bills.size();
        for (int i = 0; i < _size; i++) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                if (five >= 1)
                    five--, ten++;
                else
                    return false;
            }
            else if (bills[i] == 20) {
                twenty++;
                if (ten >= 1 and five >= 1) {
                    ten--, five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};