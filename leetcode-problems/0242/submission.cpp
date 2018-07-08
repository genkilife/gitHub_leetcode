class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        
        int arr_s[26]={0};
        int arr_t[26]={0};
        
        for(int i=0; i<s.length(); i++){
            arr_s[s[i]-97]++;
            arr_t[t[i]-97]++;
        }
        for(int i=0; i<26; i++){
            if(arr_s[i] != arr_t[i]){
                return false;
            }
        }
        return true;
        
    }
};
