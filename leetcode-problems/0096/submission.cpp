class Solution {
public:
    int numTrees(int n) {
        if(n==0 || n==1){
            return 1;
        }
        vector<int> ans(n+1,0);
        ans[0] = 1;
        ans[1] = 1;
        
        for(int i=2; i<=n; i++){
            int sum = 0;
            for(int left=0; left<=(i-1); left++){
                int right = (i-1)-left;
                sum += ans[left] * ans[right];
            }
            ans[i] = sum;
        }
        return ans[n];
    }
};
