class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> mask(nums.size()+1, 1);
        
        for(int i=0; i<nums.size(); i++){
            mask[ nums[i] ] = 0;
        }
        vector<int> ans;
        for(int i=1; i<mask.size();i++){
            if(mask[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
