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
    
    bool valid(int col, int row, vector<int>& col_occupied){
        
        FOR(i, 0, col_occupied.size()){
            if(col == col_occupied[i] || i == row || (abs(i-row) == abs(col - col_occupied[i]))){
                return false;
            }
        }
        return true;
    }
    
    void find_all(int n, int rowidx, vector<int>& col_occupied, vector< vector<string> >& ans){
        if(rowidx== n){
            // add solution
            vector<string> solution(n, string(n,'.'));
            FOR(i, 0, n){
                solution[i][col_occupied[i]] = 'Q';
            }
            ans.PB(solution);
            
        }
        
        FOR(i, 0, n){
            if(valid(i, rowidx, col_occupied)){
                // find next
                col_occupied.PB(i);
                find_all(n, rowidx+1, col_occupied, ans);
                col_occupied.pop_back();
            }
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector< vector<string> > ans;
        
        vector< int > col_occupied;
        
        find_all(n, 0 , col_occupied, ans);
        
        return ans;
        
        
    }
};
