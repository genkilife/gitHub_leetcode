class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0){
            return false;
        } 
        while(n != 0){
            int t = n%3;
            if(t !=0){
                return false;
            } else{
                n /=3;
            }
            //cout<<"N: "<<n<<endl;
        }
        return true;
        
    }
};
