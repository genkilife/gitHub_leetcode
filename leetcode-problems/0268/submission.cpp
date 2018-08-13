class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> mask(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++){
            mask[nums[i]] = 1;
        }
        for(int i=0; i<mask.size(); i++){
            if(mask[i] == 0){
                return i;
            }
        }
    }
};
