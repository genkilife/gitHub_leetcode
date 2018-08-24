class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        if(n <=1){
            return ans;
        }
        
        
        for(int i=1; i<n; i++){
            
            string cur_str = ans;
            string nex_str = "";
            
            while(cur_str != ""){
                char c = cur_str[0];
                //string tmp = cur_str.substr(0,1);
                int len = 1;
                
                while(len<=8 && len < cur_str.length() && cur_str[len] == c){
                    len++;
                }
                cur_str.erase(0, len);
                
                nex_str += to_string(len);
                nex_str += c;
            }
            ans = nex_str;
        }
        return ans;
    }
};
