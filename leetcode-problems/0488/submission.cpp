using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
typedef vector<string> VS;

#define SL(a) int((a).length())
#define SZ(a) int((a).size())
#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple

#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second

#define DUMP(x) cout<<#x<<":"<<(x)<<endl

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

class Solution {
public:
    int pass(string board, map<char, int> hand){
        /*
        cout<<"board: "<< board<<" ";
        map<char, int>::iterator ii;
        for(ii=hand.begin(); ii!=hand.end(); ii++){
            cout<< ii->first <<" "<<ii->second<<" ";
        }
        cout<<endl;
        */

        
        // reduce board
        int i=0;
        while( i < (SL(board)-2)){
            if(board[i] == board[i+1] && board[i+1] == board[i+2]){
                int j = i+3;
                while(j < SL(board) && board[j-1] == board[j]){
                    j++;
                }
                board.erase(i, j-i);
                i=0;
            } else{
                i++;
            }
        }
        if(SL(board) == 0){
            return 0;
        }
        if(SZ(hand) == 0 && SL(board) !=0){
            return -1;   
        }
        
        
        int local_cnt = -1;
        FOR(i, 0, SL(board)){
            if(i != (SL(board)-1) && board[i] == board[i+1]){
                if(hand.find(board[i]) != hand.end()){
                    string n_board = board;
                    map<char, int> n_hand = hand;
                    n_hand[board[i]]--;
                    if(n_hand[board[i]] == 0){
                        n_hand.erase(board[i]);
                    }
                    
                    int cnt = pass(n_board.erase(i, 2), n_hand);
                    if(cnt >=0){
                        cnt++;
                        if(local_cnt == -1){
                            local_cnt = cnt;
                        } else if(cnt < local_cnt){
                            local_cnt = cnt;
                        }
                    }
                }
                i++;
            }
            else if(hand.find(board[i]) != hand.end()){
                
                string n_board = board;
                map<char, int>  n_hand = hand;
                n_hand[board[i]]--;
                if(n_hand[board[i]] == 0){
                    n_hand.erase(board[i]);
                }
                
                int cnt = pass(n_board.insert(i, 1, board[i]), n_hand);
                if(cnt >=0){
                    cnt++;
                    if(local_cnt == -1){
                        local_cnt = cnt;
                    } else if(cnt < local_cnt){
                        local_cnt = cnt;
                    }
                }
            }
        }
        
        return local_cnt;
        
    }
    
    int findMinStep(string board, string hand) {

        map<char, int> m_hand;
        
        FOR(i, 0, SL(hand)){
            m_hand[hand[i]]++; 
        }
        
        return pass(board, m_hand);

    }
};
