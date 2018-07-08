class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans =0;
        int m = board.size();
        if(m==0){
            return 0;
        }
        int n = board[0].size();
        if(n==0){
            return 0;
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'X'){
                    ans++;
                    board[i][j] = '.';
                    if(i < (m-1)){
                        if(board[i+1][j] == 'X'){
                            for(int k= i+1; k < m; k++){
                                if(board[k][j] == '.'){
                                    break;
                                } else{
                                    board[k][j] = '.';
                                }
                            }
                        }
                    }
                    if(j < (n-1)){
                        if(board[i][j+1] == 'X'){
                            for(int k= j+1; k < n; k++){
                                if(board[i][k] == '.'){
                                    break;
                                } else{
                                    board[i][k] = '.';
                                }
                            }
                        }
                    }
                }
            }
        }
        
        
        return ans;
    }
};
