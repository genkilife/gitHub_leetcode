class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int N = minutesToTest / minutesToDie;
        
        int cnt = buckets ;
        int comp =1;
        int ans = 0;
        while(cnt > comp ){
            ans ++;
            comp *= (N+1);
        }
        return ans;
    }
};
