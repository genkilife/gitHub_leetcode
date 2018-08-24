bool myfunc(vector<string> a , vector<string> b){
    return a[0] < b[0];
}


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        sort(accounts.begin(), accounts.end(), myfunc);
        
        string comp = accounts[0][0];
        int left = 0;
        
        vector<vector<string>> ans;
        
        for(int right = 0; left < accounts.size() && right < accounts.size();){
            
            bool diff_flag = true;
            if(comp == accounts[right][0]){
                right++;
                if(right != accounts.size()){
                    continue;
                }
                diff_flag = false;
            }
    
            
            if(right == accounts.size() || diff_flag == true){
                string name = comp;
                // [left, right)
                vector<set<string>>name_series;
                //cout<<left<<" "<<right<<" "<<comp<<" "<<accounts.size()<<endl;
                for(int i=left; i < right; i++){
                    vector<string> one_person = accounts[i];
                    // echeck whether it is in one set
                    int index = -1;
                    //cout<<"check "<<i<<" person\n";
                    for(int k=1; k<one_person.size(); k++){
                        for(int j=0; j<name_series.size(); j++){
                            set<string>::iterator iter;
                            for(iter = name_series[j].begin(); iter != name_series[j].end(); iter++){
                                if(*iter == one_person[k]){
                                    if(index == -1){
                                        //cout<<"index: "<<index<<" k: "<<k<<" j: "<<j<<endl;
                                        index = j;
                                        for(int m=1; m<one_person.size(); m++){
                                            name_series[index].insert(one_person[m]);
                                        }
                                    } else if(index != j){
                                        int min = (index < j) ? index : j;
                                        int max = (index > j) ? index: j;
                                        index = min;
                                        
                                        set<string>::iterator iter2;
                                        for(iter2=name_series[max].begin(); iter2 != name_series[max].end(); iter2++){
                                            name_series[min].insert(*iter2);
                                        }
                                        
                                        name_series.erase(name_series.begin()+max);
                                    }
                                    break;
                                }
                            }
                        }
                    }
                    
                    if(index == -1){
                        set<string> a;
                        for(int m=1; m<one_person.size(); m++){
                            a.insert(one_person[m]);
                        }
                        name_series.push_back(a);
                    }
                    /*
                    cout<<"case:\n";
                    for(int i=0; i<name_series.size(); i++){
                        for(set<string>::iterator iter=name_series[i].begin(); iter !=name_series[i].end(); iter++ ){
                            cout<<*iter<<" ";
                        }
                        cout<<endl;
                    }
                    */
                    
                }
                
                for(int i=0; i<name_series.size(); i++){
                    vector<string> item(name_series[i].begin(), name_series[i].end());
                    item.insert(item.begin(), name);
                    ans.push_back(item);
                }
                
                left = right;
                if(left != accounts.size()){
                    comp = accounts[left][0];
                }
            }
            //cout<<"end: "<<left<<" "<<right<<" "<<comp<<" "<<accounts.size()<<endl;
        }
        
        return ans;
    }
};
