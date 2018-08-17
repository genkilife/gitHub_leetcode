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

bool check_pala(string a){
    int i=0;
    if(a.length()==0){
        return false;
    }
    for(i=0; i<=a.length()/2; i++){
        if(a[i] != a[a.length()-1-i]){
            break;
        }
    }
    
    if(i>a.length()/2){
        return true;
    }
    return false;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<string> rwords;
        FOR(i, 0, SZ(words)){
            string item (words[i].rbegin(), words[i].rend());
            rwords.PB(item);
        }
        vector<vector<int>>ans;
        FOR(i, 0, SZ(words)){
            FOR(j, i+1, SZ(rwords)){
                if(words[i].find(rwords[j]) != string::npos || rwords[j].find(words[i]) != string::npos){ 
                    string a = words[i] + words[j];
                    if(check_pala(a)){
                        ans.PB({i,j});
                    }
                    a = words[j] + words[i];
                    if(check_pala(a)){
                        ans.PB({j,i});
                    }
                }
            }
        }
        return ans;
    }
};
