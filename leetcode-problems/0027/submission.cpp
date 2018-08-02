class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int length=n-1;
        
        vector<int>index;
        for(int i=0;i<n;i++){
            if(nums[i] == val){
                index.push_back(i);
            }
        }
        int len = n-index.size();
        
        while(index.size()!=0){
            while(nums[length] == val){
                length--;
            }
            nums[index.front()] = nums[length];
            index.erase(index.begin());
            length--;
        }
        
        return len;
    
    }
};
