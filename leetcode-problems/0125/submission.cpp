class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        while(left <= right){
            //cout<<"head: "<<s[left]<<" "<<s[right]<<endl;
            while(isalpha(s[left]) == 0 && isdigit(s[left]) == 0){
                left++;
            }
            while(isalpha(s[right])==0 && isdigit(s[right]) == 0){
                right--;
            }
            if(left>right){
                break;
            }
            //cout<<"mid: <"<<s[left]<<"> <"<<s[right]<<">"<<endl;
            if(isalpha(s[left])){
                s[left] = tolower(s[left]);
            }
            if(isalpha(s[right])){
                s[right] = tolower(s[right]);
            }
            
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
        
    }
};
