class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> sample(10);
        sample[2]="abc";
        sample[3]="def";
        sample[4]="ghi";
        sample[5]="jkl";
        sample[6]="mno";
        sample[7]="pqrs";
        sample[8]="tuv";
        sample[9]="wxyz";
        
        for(int i=0; i<digits.length(); i++){
            if(i == 0 ){
                //cout<<"len: "<<sample[digits[0]-48].length()<<endl;
                for(int j=0; j<sample[digits[0]-48].length(); j++){
                    string x(1, sample[digits[0]-48][j]);
                    ans.push_back(x);
                    //cout <<"x: "<<x<<endl;
                }
            } else{
                vector<string> tmp;
                for(int j=0; j<ans.size(); j++){
                    string raw = ans[j];
                    
                    for(int k=0; k<sample[digits[i]-48].length(); k++){
                        string a = raw + sample[digits[i]-48][k];
                        tmp.push_back(a);
                        //cout <<"a: "<<a<<endl;
                    }
                }
                ans = tmp;
            }
        }
        return ans;
        
    }
};
