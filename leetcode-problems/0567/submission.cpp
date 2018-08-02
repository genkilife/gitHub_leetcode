class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        
        map<char, int> s1_map;
        for(int i=0; i<s1.length(); i++){
            s1_map[s1[i]]++;
        }
        map<char, int> run_map = s1_map;
        map<char, int>::iterator iter;
        for(int i=0; i<s1.length(); i++){
            run_map[s2[i]]--;
        }
        int level = 0;
        for(iter=run_map.begin(); iter!=run_map.end(); iter++){
            if(iter->second == 0){
                level++;
            }
        }
        if(level == s1_map.size()){
            return true;
        }
        
        for(int i=s1.length(); i<s2.length(); i++){

            if(s2[i] != s2[i-s1.length()]){
                if((run_map[s2[i]]-1) == 0 && s1_map.find(s2[i]) != s1_map.end()){
                    level++;
                } else if (run_map[s2[i]] == 0 && s1_map.find(s2[i]) != s1_map.end()){
                    level--;
                }
                run_map[s2[i]]--;
                
                if((run_map[s2[i-s1.length()]]+1) == 0 && s1_map.find(s2[i-s1.length()]) != s1_map.end()){
                    level++;
                } else if(run_map[s2[i-s1.length()]] == 0 && s1_map.find(s2[i-s1.length()]) != s1_map.end()){
                    level--;
                }
                run_map[s2[i-s1.length()]]++;
            }
            if(level == s1_map.size()){
                return true;
            }
        }
        
        
        return false;
    }
};
