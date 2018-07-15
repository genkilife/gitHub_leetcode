class Solution {
public:
    bool isMatch(string s, string p) {

        if(p.length()==0){
            if(s.length()==0){
                return true;
            } else{
                return false;
            }
        }
        
        // merge following with not '*' case
        if(p.length()==1 || p[1]!='*'){
            if(s.length()==0){
                return false;
            }
            else if(s[0] == p[0] || p[0] =='.'){
                return isMatch(s.substr(1, s.length()-1), p.substr(1, p.length()-1));
            } else{
                return false;
            }
        }

        
        if(p[1] == '*'){
            string sub_s = s;
            while(sub_s.length()!=0 && (sub_s[0] == p[0] || p[0] == '.')){
                sub_s = sub_s.substr(1, sub_s.length()-1); 
                
                if(isMatch(sub_s, p.substr(2, p.length()-2))){
                    return true;
                }
            }
            
            return isMatch(s, p.substr(2, p.length()-2));
        } 
        
        
    }
};
