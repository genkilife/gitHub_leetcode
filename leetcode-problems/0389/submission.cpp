class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> ss;
        map<char, int> st;
        
        for(int i=0; i<s.length(); i++){
            ss[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            st[t[i]]++;
        }
        
        map<char, int>::iterator iter;
        for(iter=st.begin(); iter != st.end(); iter++){
            if( ss.find(iter->first) == ss.end() || ss[iter->first] != iter->second ){
                return iter->first;
            }
            
        }
    }
};
