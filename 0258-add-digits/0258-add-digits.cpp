class Solution {
public:
    int addDigits(int num) {
        while(num/10!=0){
            int ans=0;
            string n=to_string(num);
            for(auto it:n){
                ans=ans+(it-'0');
            }
            num=ans;
        }
        return num;
    }
};