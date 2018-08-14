class Solution {
public:
    int maximumSwap(int num) {
        vector<int> arr;
        int ans = num;
        while(num != 0){
            arr.push_back( num % 10);
            num/=10;
        }
        
        for(int i=arr.size()-1; i>=0; i--){
            int min = 0;
            int id = -1;
            for(int j = i-1; j >=0; j--){
                if(min <= arr[j]){
                    min = arr[j];
                    id = j;
                }
            }
            if(min > arr[i]){
                int tmp = arr[i];
                arr[i] = arr[id];
                arr[id] = tmp;
                
                int num = 0;
                for(i = arr.size()-1; i>=0; i--){
                    num *= 10;
                    num += arr[i];
                }
                return num;                
            }
        }
        return ans;
    }
};
