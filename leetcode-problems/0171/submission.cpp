class Solution {
public:
    int titleToNumber(string s) {
        int num =0;
        while(s.length()!=0){
            char c = s[0];
            s.erase(0, 1);
            
            num = num * 26 + c- 64;
        }
        
        return num;
        
    }
};
