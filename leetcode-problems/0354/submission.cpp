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

bool mycomp(PII a, PII b){
    if(a.first < b.first || (a.first == b.first && a.second < b.second)){
        return true;
    }
    return false;
}

class Solution {
public:
    
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {

        sort(ALL((envelopes)), mycomp);
        
        
        VI ans(SZ(envelopes) + 1, 0);
        
        PII head(INT_MIN, INT_MIN);
        envelopes.insert(envelopes.begin(), head);
        

        
        int max = 0;
        FOR(i, 1, SZ(envelopes)){
            FOR(j, 0, i){
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second){
                    if((ans[j] + 1) > ans[i]){
                        ans[i] = ans[j] + 1;
                        
                        if(ans[i] > max){
                            max = ans[i];
                        }
                    }
                }
            }
        }

        
        return max;
        
    }
};
