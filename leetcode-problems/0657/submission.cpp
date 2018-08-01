class Solution {
public:
    bool judgeCircle(string moves) {
        
        if(moves.length()==0){
            return true;
        }
        
        vector<int> cnt(4,0);
        
        for(int i=0; i<moves.length(); i++){
            switch(moves[i]){
                case 'U':
                    cnt[0]++;break;
                case 'D':
                    cnt[1]++;break;
                case 'L':
                    cnt[2]++;break;
                case 'R':
                    cnt[3]++;break;
            }
        }
        
        if(cnt[0] == cnt[1] && cnt[2] == cnt[3]){
            return true;
        }
        return false;
        
    }
};
