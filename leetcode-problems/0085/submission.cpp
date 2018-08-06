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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return 0;
        }
        
        vector<int> init(matrix[0].size()+1, 0);
        vector<vector<int>> acc(matrix.size()+1, init);
        
        FOR(i, 1, acc.size()){
            FOR(j, 1, acc[0].size()){
                acc[i][j] = matrix[i-1][j-1]-48 + acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1];
            }
        }
        /*
        FOR(i, 1, acc.size()){
            FOR(j, 1, acc[0].size()){
                cout<<acc[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
        int max = 0;
        FOR(i, 0, acc.size()){
            FOR(j, 0, acc[0].size()){
                FOR(k, i+1, acc.size()){
                    FOR(m, j+1, acc[0].size()){
                        int sum = acc[k][m] - acc[i][m] - acc[k][j] + acc[i][j];
                        //cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<" m: "<<m<<" sum: "<<sum<<endl;
                        if(sum != (k-i)*(m-j)){
                            break;
                        }
                        else if(sum > max){
                            max = sum;
                        }
                    }
                }
            }
        }
        return max;
        
        
    }
};
