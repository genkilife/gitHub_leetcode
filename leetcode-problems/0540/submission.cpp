class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        map<int, int> arr;
        for(int i=0; i<nums.size(); i++){
            arr[nums[i]]++;
        }
        
        
        map<int, int>::iterator iter;
        for(iter = arr.begin(); iter != arr.end(); iter++){
            if(iter->second == 1){
                return iter->first;
            }
        }
        
        
    }
};
