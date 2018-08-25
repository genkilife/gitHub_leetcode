class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        if(numRows == 1){
            return s;
        }
        
        for(int i=0; i<s.length(); i++){
            int index = i %((numRows-1)*2);
            
            if(index < (numRows-1)){
                ans[index] += s[i];
            } else{
                ans[numRows-1 - (index - (numRows-1))] += s[i];
            }
            
            
        }
        string out;
        for(int i=0; i<ans.size(); i++){
            out += ans[i];
        }
        return out;
    }
};
