// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long left = 1;
        long right = n;
        long mid = (left+right)/2+1;
        while(mid <= right){
            //cout<<left<<" "<<mid<<" "<<right<<endl;
            long myguess = guess(mid);
            if(myguess == 0){
                return mid;
            } else if(myguess == 1){
                left = mid+1;
                mid = (left+right)/2+1;
            } else{
                right = mid-1;
                mid =  (left+right)/2+1;
            }
        }
        return right;
        
    }
};
