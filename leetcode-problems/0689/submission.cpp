class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> acc(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++){
            acc[i+1] = acc[i] + nums[i];
        }
        vector<int> diff(nums.size()-(k-1), 0);
        for(int i=0; i<diff.size(); i++){
            diff[i] = acc[i+k] - acc[i];
        }
        
        
        vector<int> init_v(3,0);
        vector<vector<int>> dp(diff.size(), init_v);
        
        for(int level = 1; level <=3; level++){
            //cout<<level<<endl;
            for(int i=diff.size()-1; i>=0; i--){
                int min0 = 0;
                if(i+k < diff.size()){
                    // select
                    min0 = diff[i] + dp[i+k][level-1];
                }
                
                // can't select
                int min1=0;
                if(i+1 >= diff.size()){
                    min1 = diff[i];
                } else{
                    min1 = max(diff[i], dp[i+1][level]);
                }
                
                dp[i][level] = max(min0, min1);
                //cout<<dp[i][level]<<" ";
            }
            //cout<<endl;
        }
        //cout<<"max: "<<dp[0][3]<<endl;
        vector<int> ans;
        int level=3;
        for(int i=0; i<diff.size(); i++){
            //cout<<i<<" "<<dp[i][level] <<" "<<diff[i]<<" "<<dp[i+k][level-1]<<endl;
            if(i+k < diff.size()){
                if(dp[i][level] - diff[i] == dp[i+k][level-1]){
                    ans.push_back(i);
                    //cout<<i<<" ";
                    i += (k-1);
                    level--;
                }
            } else{
                if(dp[i][level] == diff[i]){
                    ans.push_back(i);
                    break;
                }
            }
            
        }
        //cout<<endl;
        
        return ans;
    }
};
