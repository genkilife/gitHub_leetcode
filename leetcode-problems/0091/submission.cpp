class Solution {
public:
    int numDecodings(string s) {
        
        vector<int> sums(s.length()+1, 0);
        
        sums[s.length()] = 1;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] == '1'){
                if(i == s.length()-1){
                    sums[i] = sums[i+1];
                } else{
                    sums[i] = sums[i+1] + sums[i+2];
                }
                
            }
            else if (s[i] =='2'){
                if((i == s.length()-1) || (s[i+1]-48)>6 ){
                    sums[i] = sums[i+1];
                } else{
                    sums[i] = sums[i+1] + sums[i+2];
                }
            }
            else if ((s[i] -48) >2 && (s[i] -48) <= 9){
                sums[i] = sums[i+1];
            } else{
                sums[i] = 0;
            }
            
        }
        return sums[0];
    }
};
