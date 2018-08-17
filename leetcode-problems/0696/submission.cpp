class Solution {
public:
    int countBinarySubstrings(string s) {
        int state = -1;
        int cnt_0 = 0;
        int cnt_1 = 0;
        
        // fill 2 bin
        if(s[0] == '0'){
            state = 1;
        } else{
            state = 2;
        }
        int ans=0;
        for(int i=0; i<s.length(); i++){
            //change state
            if(state == 1 && s[i] == '1'){
                state = 2;
                ans += min(cnt_0, cnt_1);
                cnt_1 = 0;
            }
            else if (state == 2 && s[i] == '0'){
                state =1;
                ans+= min(cnt_0, cnt_1);
                cnt_0 = 0;
            }
            
            if(s[i] == '0'){
                cnt_0++;
            } else if (s[i] == '1'){
                cnt_1++;
            }
        }
        ans += min(cnt_0, cnt_1);
        return ans;
    }
};
