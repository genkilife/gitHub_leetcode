int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        deque<pair<int, int>> myqueue;
        myqueue.push_back(make_pair(sr, sc));
        int orig_color = image[sr][sc];
        
        //vector<int> init(image[0].size(), 0);
        //vector<vector<int>> mask(image.size(), init);
        while(myqueue.size() != 0){
            
            int x = myqueue.front().first;
            int y = myqueue.front().second;
            myqueue.pop_front();
            image[x][y] = newColor;
            if(newColor == orig_color){
                break;
            }
            //cout<<x<<" "<<y<<endl;
            for(int i=0; i<4; i++){
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if(x_ < 0 || x_ >= image.size() || y_ < 0 || y_ >= image[0].size()){
                    continue;
                }
                
                if(image[x_][y_] == orig_color){
                    myqueue.push_back({x_, y_});
                }
            }
            
        }
        return image;
    }
};
