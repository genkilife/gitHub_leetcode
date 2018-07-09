class Solution {
public:
    int trap(vector<int>& height) {
        
        int max=0;
        int max_id=-1;
        for(int i=0; i<height.size(); i++){
            if(max < height[i]){
                max = height[i];
                max_id = i;
            }
        }
        //cout<<"max id: "<<max_id <<" max: "<<max<<endl;
        int sum = 0;
        
        int rightmax_id = max_id;
        while((rightmax_id+1) < height.size()){
            int right2ndmax_id;
            int right2ndmax = 0;
            for(int id = rightmax_id+1; id<height.size(); id++){
                if(right2ndmax < height[id]){
                    right2ndmax = height[id];
                    right2ndmax_id = id;
                }
            }
            if(right2ndmax == 0){
                break;
            }
            
            for(int id = rightmax_id+1; id<=right2ndmax_id; id++){
                sum += (right2ndmax- height[id]);
            }
            //cout<<"rmax id: "<<rightmax_id <<" rmax2nd id: "<<right2ndmax_id<<endl;
            
            rightmax_id = right2ndmax_id;
        }
        int leftmax_id = max_id;
        while((leftmax_id-1) >= 0){
            int left2ndmax_id;
            int left2ndmax = 0;
            for(int id = leftmax_id-1; id>=0; id--){
                if(left2ndmax < height[id]){
                    left2ndmax = height[id];
                    left2ndmax_id = id;
                }
            }
            if(left2ndmax == 0){
                break;
            }
            
            for(int id = leftmax_id-1; id>=left2ndmax_id; id--){
                sum += (left2ndmax- height[id]);
            }
            //cout<<"lmax id: "<<leftmax_id <<" lmax2nd id: "<<left2ndmax_id<<endl;
            
            leftmax_id = left2ndmax_id;
        }
        return sum;
        
    }
};
