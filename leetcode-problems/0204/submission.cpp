class Solution {
public:
    int countPrimes(int n) {
        if(n<3){
            return 0;
        }
        if(n==3){
            return 1;
        }
        if(n==4){
            return 2;
        }
        

        
        int cnt =2;
        
        for(int i=4; i<n; i++){
            int j;
            for(j=2; j*j<=i; j++){
                if(i%j == 0){
                    break;
                }
            }
            if(j*j > i){
                cnt++;
            }
            //cout<<j<<" "<<i<<endl;
        }
        return cnt;
    }
};
