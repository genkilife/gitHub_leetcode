bool verify(string & word){
    int i=0;
    int j = word.length()-1;
    while(i<=j){
        if(word[i] != word[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++ ){
                int len = j-i+1;
                string sub = s.substr(i, len);
                if(verify(sub)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
