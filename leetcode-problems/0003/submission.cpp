class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        
        for(int i=0; i<s.length(); i++){
            vector<bool> hash(128, false); 
            int length=0;
            for(int j=i; j<s.length(); j++){
                if(hash[s[j]] == false){
                    length++;
                    hash[s[j]] = true;
                } else{
                    break;
                }
            }
            
            if(length > max_length){
                max_length = length;
            }
            
        }
        return max_length;
    }
};
