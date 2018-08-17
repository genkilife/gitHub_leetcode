class Solution {
public:
    bool validPalindrome(string s) {
        string rev(s.rbegin(), s.rend());
        string sub1, sub2;
        bool flag = false;
        for(int i=0; i<s.length(); i++){
            if(s[i] != rev[i]){
                // remove s[i]
                string s1 = s;
                s1.erase(s1.begin()+i);
                string r1 = rev;
                r1.erase(r1.begin() + r1.length()-1-i);
                if(s1 == r1){
                    return true;
                }
                
                r1 = rev;
                r1.erase(r1.begin()+i);
                s1 = s;
                s1.erase(s1.begin() + s1.length() -1 -i);
                if(s1 == r1){
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};
