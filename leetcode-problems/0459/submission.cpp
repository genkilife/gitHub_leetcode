class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int length = s.length()/2;
        for(int i=1; i<=length; i++){
            string a = s.substr(0, i);
            
            if(s.length() % a.length() == 0){
                string comp;
                for(int j=0; j<s.length() / a.length(); j++){
                    comp += a;
                }
                if(comp == s){
                    return true;
                }
            }
        }
        return false;
    }
};
