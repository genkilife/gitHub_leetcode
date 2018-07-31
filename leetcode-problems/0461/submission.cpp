class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int ans = x ^ y;
        
        int cnt =0;
        while(ans != 0){
            cnt += ans %2;
            ans /=2;
        }
        return cnt;
    }
};
