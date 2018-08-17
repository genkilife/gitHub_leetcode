class Solution {
public:
    int divide(int dividend, int divisor) {
        long dividend_l = dividend;
        long  divisor_l = divisor;
        long ans = dividend_l/divisor_l;
        if(ans > 2147483647 || ans <-2147483648){
            ans = 2147483647;
        }
        return ans;
    }
};
