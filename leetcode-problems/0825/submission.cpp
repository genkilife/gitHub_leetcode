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
#define GET_POS(c,x) (upper_bound(c.begin(),c.end(),x)-c.begin())

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
    int numFriendRequests(vector<int>& ages) {
        vector<float> ages_f(ages.begin(), ages.end());
        
        SORT(ages_f);
        /*
        FOR(i, 0, SZ(ages_f)){
            cout<<ages_f[i]<<" ";
        }
        cout<<endl;
        */
        int cnt=0;
        for(int i=0; i<SZ(ages_f); i++){
            //cout<<ages_f[i]<<" ";
            int pos = GET_POS(ages_f,ages_f[i]*0.5+7);
            if(pos < i){
                cnt+= (i-pos);
            }
            
            //cout<<(i-pos)<<" "<<i<<" "<<pos<<" ";  
            
            pos = GET_POS(ages_f,ages_f[i])-1;
            if(ages_f[i]*0.5+7 < ages_f[i]){
                while(ages_f[pos] > ages_f[i] && pos > i){
                    pos--;
                }
                cnt += (pos - i);
            }
            //cout<<pos<<" "<<i<<endl;   
            //cout<<(pos-i)<<" "<<cnt<<endl; 
        }
        return cnt;
    }
};
