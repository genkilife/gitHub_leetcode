class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==0){
            return false;
        }
        vector<int> acc(nums.size()+1, 0);
        for(int i=1; i<acc.size(); i++){
            acc[i] = acc[i-1] + nums[i-1];
        }
        
        for(int i=0; i<acc.size(); i++){
            for(int j=i+2; j<acc.size(); j++){
                if (k == 0){
                    if((acc[j] - acc[i]) == 0){
                        return true;
                    }
                }
                else if((acc[j] - acc[i]) % k ==0){
                    return true;
                }
            }
        }
        return false;
    }
};
