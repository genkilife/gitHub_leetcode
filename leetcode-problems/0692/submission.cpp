bool myfunc(pair<string, int> a, pair<string, int> b){
    
    if(a.second > b.second){
        return true;
    } else if(a.second == b.second && a.first < b.first){
        return true;
    } else{
        return false;
    }
    return false;
}


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> cont;
        for(int i=0; i<words.size(); i++){
            cont[words[i]]++;
        }
        
        vector< pair<string, int> >test;
        map<string, int>::iterator iter;
        for(iter = cont.begin(); iter != cont.end(); iter++){
            test.push_back(*iter);
        }
        
        
        sort(test.begin(), test.end(), myfunc);
        
        
        vector<string>ans;
        vector< pair<string, int> >::iterator iter2 =test.begin() ;
        for(int i =0; i < k; i++){
            ans.push_back(iter2->first);
            iter2++;
        }
        return ans;
    }
};
