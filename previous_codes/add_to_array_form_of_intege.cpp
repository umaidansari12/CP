class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        int i=0;
        for(i=num.size()-1;i>=0;i--)
        {
            int sum = num[i]+carry+(k%10);
            k/=10;
            carry=sum<10?0:1;
            sum=sum%10;
            num[i]=sum;
        }
        while(k)
        {
            int sum=carry+(k%10);
            k/=10;
            carry=sum<10?0:1;
            sum=sum%10;
            num.insert(num.begin(),sum);
        }
        if(carry)
        num.insert(num.begin(),carry);
        return num;
        
    }
};