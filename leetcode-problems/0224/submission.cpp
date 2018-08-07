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
    int calculate(string s) {
        int sum = 0;
        char op = NULL;
        //cout<<"sub str: "<<s<<endl;
        FOR(i, 0, SL(s)){
            if(s[i] >= 48 && s[i] <= 57){
                int j = i;
                while(s[j] >= 48 && s[j] <= 57){
                    j++;
                }
                //cout<<"to int: "<<s.substr(i, j-i)<<endl;
                int a = stoi(s.substr(i, j-i));
                if(op == '+'){
                    sum += a;
                } else if (op == '-'){
                    sum -= a;
                } else{
                    sum = a;
                }
                i = j-1;
            }
            else if(s[i] == '+' || s[i] == '-'){
                op = s[i];
            } else if (s[i] == '('){
                int a = calculate(s.substr(i+1, SL(s) - (i+1) ));
                
                if(op == '+'){
                    sum += a;
                } else if (op == '-'){
                    sum -= a;
                } else {
                    sum = a;
                }
                
                int j = i+1;
                int cnt = 1;
                while(cnt > 0){
                    if(s[j] == ')'){
                        cnt--;
                    } else if (s[j] == '('){
                        cnt++;
                    }
                    j++;
                }
                i = j-1;
                
            } else if (s[i] == ')'){
                return sum;
            }
        }
        return sum;
        
    }
};
