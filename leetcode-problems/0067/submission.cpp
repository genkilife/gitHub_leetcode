class Solution {
public:
    string addBinary(string a, string b) {
        string min;
        string max;
        if(a.length()>b.length()){
            max = a;
            min = b;
        } else{
            max = b;
            min = a;
        }
        int diff = max.length() - min.length();
        
        min.insert(0, diff, '0');
        
        string ans;
        int carry = 0;
        for(int i=min.length()-1; i>=0; i--){
            char c = min[i]-48 + max[i]-48 + carry;
            if(c > 1){
                carry = 1;
                c -= 2;
            } else{
                carry = 0;
            }
            ans.insert(0, 1, c+48);
        }
        
        if(carry > 0){
            ans.insert(0, 1, '1');
        }

        return ans;
        
        
    }
};
