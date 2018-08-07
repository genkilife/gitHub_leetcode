class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        bool flag = true;
        
        while(flag){
            flag = false;
            for(int i=1; i < asteroids.size(); i++){
                if(asteroids[i-1] > 0 && asteroids[i] < 0){
                    if(abs(asteroids[i-1]) > abs(asteroids[i])){
                        asteroids.erase(asteroids.begin() + i);
                    } else if (abs(asteroids[i-1]) < abs(asteroids[i])){
                        asteroids.erase(asteroids.begin() + i-1);
                    } else if (abs(asteroids[i-1]) == abs(asteroids[i])){
                        asteroids.erase(asteroids.begin() + i-1);
                        asteroids.erase(asteroids.begin() + i-1);
                    }
                    flag = true;
                }
            }
        }
        
        return asteroids;
        
    }
};
