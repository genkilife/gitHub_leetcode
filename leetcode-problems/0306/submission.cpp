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
    bool check_str(string a, string b, string whole){
        if(SL(whole) <=0){
            return false;
        }
        long sum_i = stol(a) + stol(b);
        string sum_s = to_string(sum_i);
        
        size_t found = whole.find(sum_s, 0);
        
        if(found != string::npos){
            if(SL(sum_s) == SL(whole)){
                return true;
            }
            else{
                return check_str(b, sum_s, whole.substr(SL(sum_s), SL(whole) - SL(sum_s)));
            }
        }
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        if(SZ(num) < 3){
            return false;
        }
        
        FOR(i, 0, SZ(num)-2){
            FOR(j, i+1, SZ(num)-1){
                

                // 1st word is 0-i
                // 2nd word is i+1 - j
                string a = num.substr(0, i+1);
                string b = num.substr(i+1, j-(i+1)+1);
                
                if(a[0] == '0' && SL(a)>1){
                    continue;
                }
                if(b[0] == '0' && SL(b)>1){
                    continue;
                }
                
                string remain = num.substr(j+1, num.length()-(j+1) );
                
                if(SL(a)>SL(remain) || SL(b)>SL(remain) || SL(a)>10 || SL(b)>10 ){
                    continue;
                }
                
                if(check_str(a, b, remain )){
                    return true;
                }
            }
        }
        return false;
        
        
    }
};
