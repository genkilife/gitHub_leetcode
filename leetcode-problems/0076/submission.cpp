class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mymap;
    
        
        for(int i=0; i<t.length(); i++){
            mymap[t[i]] = mymap[t[i]] -1;
            //cout<<t[i]<<" "<<mymap[t[i]]<<endl;
        }
        int n = mymap.size();
        /*
        map<char, int>::iterator iter;
        for(iter = mymap.begin(); iter != mymap.end(); iter++){
            cout<<iter->first<<" "<<iter->second<<endl;
        }
        */
        
        
        int cnt=0;
        string ans = "";
        string stack;
        for(int i=0; i<s.length(); i++){
            mymap[s[i]]++;

            if(mymap[s[i]] == 0){
                cnt++;
            }
            
                
            int ptr = -1;
            int j=0;
            while(stack.length()!=0){
                if(mymap[stack[0]] > 0){
                    //ptr = j;
                    mymap[stack[0]]--;
                    stack.erase(0, 1);
                } else{
                    break;
                }
            }

            

            stack.append(1, s[i]);
            //cout<<mymap[s[i]]<<" "<<cnt<<" "<<stack<<endl;
            if(cnt >= n){
                if(ans == "" || ans.length() > stack.length()){
                    ans = stack;
                }
            }
        }
        return ans;
    }
};
