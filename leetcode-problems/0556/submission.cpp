class Solution {
public:
    int nextGreaterElement(int n) {
        string n_s = to_string(n);
        int i;
        for(i=0; i<n_s.length()-1; i++){
            if(n_s[i] < n_s[i+1]){
                break;
            }
        }
        if(i == n_s.length()-1){
            return -1;
        }
        next_permutation(n_s.begin(), n_s.end());
        
        
        long long int ans = stol(n_s);
        if(ans > INT_MAX){
            return -1;
        }
        return ans;
        
        
    }
};
