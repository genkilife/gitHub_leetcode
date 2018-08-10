class Solution {
public:
    int min(int a, int b){
        return (a>b) ? b : a;
    }
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size()-1;
        int max = min(height[left],height[right]) * (height.size()-1);
        while(left < right){
            if (height[left] < height[right]){
                left ++;
            }
            else{
                right --;
            }
            int res = min(height[left], height[right]) * (right - left);
            if(res > max){
                max = res;
            }
        }
        return max;
    }
};
