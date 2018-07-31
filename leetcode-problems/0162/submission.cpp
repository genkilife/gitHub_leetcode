class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        nums.insert(nums.end(), INT_MIN);
        
        for(int i=1; i < (nums.size()-1); i++){
            if(nums[i] > nums[i-1] || (i==1 && nums[i]==-2147483648)){
               if(nums[i] > nums[i+1] || (i==(nums.size()-2) && nums[i]==-2147483648)){
                   return i-1;
               }
            }
        }
        return -1;
    }
};
