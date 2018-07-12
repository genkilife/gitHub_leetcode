class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> acc(nums.size()+1, 0);
        
        for(int i=0; i<nums.size(); i++){
            acc[i+1] = acc[i] + nums[i];
        }
        
        int maxdata = acc[1];

        int mindata = acc[0];
        int minindex = 0;
        for(int i=1; i<acc.size(); i++){
            if(maxdata < (acc[i] - mindata)){
                maxdata = acc[i] - mindata;
            }
            if(mindata > acc[i]){
                mindata = acc[i];
                minindex = i;
            }
        }
        
        return maxdata;
        
        
        
    }
};
