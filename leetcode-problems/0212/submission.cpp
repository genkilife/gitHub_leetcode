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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

class Solution {
public:
    bool BFS(vector<vector<char>>& board, vector<vector<bool>>& bitmap, string word, int m, int n){
        if(SL(word) == 0){
            //cout<<board[m][n]<< " m: "<<m<<" n: "<<n<<endl;
            return true;
        }
        
        FOR(i, 0, 4){
            int m_nxt = m+dx[i];
            int n_nxt = n+dy[i];
            if(m_nxt>=0 && m_nxt < SZ(board)){
                if(n_nxt >=0 && n_nxt < SZ(board[0])){
                    if(bitmap[m_nxt][n_nxt] == false && board[m_nxt][n_nxt] == word[0]){
                        bitmap[m_nxt][n_nxt] = true;
                        if(BFS(board, bitmap, word.substr(1, SL(word)-1), m_nxt, n_nxt)){
                            //cout<<board[m][n]<< " m: "<<m<<" n: "<<n<<endl;
                            bitmap[m_nxt][n_nxt] = false;
                            return true;
                        }
                        bitmap[m_nxt][n_nxt] = false;
                    }
                }
            }
        }
        return false;
        
    }    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string> ans;
        if(SZ(board) == 0){
            return ans;
        } else if(SZ(board[0]) == 0){
            return ans;
        } else if (SZ(words) ==0){
            return ans;
        }
        int m = SZ(board);
        int n = SZ(board[0]);
        
        vector<bool> init_i(n, false);
        vector<vector<bool>> bitmap(m, init_i);

        FOR(i, 0, m){
            FOR(j, 0, n){
                FOR(k, 0, SZ(words)){
                    string word = words[k];
                    if(board[i][j] == word[0]){
                        bitmap[i][j] = true;
                        if(BFS(board, bitmap, word.substr(1, SL(word)-1), i, j)){
                            int h;
                            for(h=0; h< SZ(ans); h++){
                                if(ans[h] == word){
                                    break;
                                }
                            }
                            if(h == SZ(ans)){
                                ans.PB(word);
                                words.erase(words.begin()+k);
                                k--;
                            }
                        }
                        bitmap[i][j] = false;
                    }
                }         
            }
        }
        return ans;
    }
};
