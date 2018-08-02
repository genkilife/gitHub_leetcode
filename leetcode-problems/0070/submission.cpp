class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        } else if (n==2){
            return 2;
        }
        
        vector<int> sum(n+1, 0);
        
        sum[0] = 0;
        sum[1] = 1;
        sum[2] = 2;
        
        for(int i=3; i<=n; i++){
            sum[i] = sum[i-1] + sum[i-2];
        }
        return sum[n];
        
    }
};
