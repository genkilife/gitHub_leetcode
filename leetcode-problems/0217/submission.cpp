class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> aa;
        for(int i=0; i<nums.size(); i++){
            if(aa.find(nums[i]) == aa.end()){
                aa.insert(nums[i]);
            } else{
                return true;
            }
        }
        return false;
    }
};
