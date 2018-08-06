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
    
    int compute(int a, int b, char op){
        switch(op){
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
        }
    }
    
    vector<int> rec(string input){
        vector<int> ans;
        if(input.length()==0){
            return ans;
        }
        // check whether has +-*
        int i=0;

        for(i=0; i<input.length();i++){
            char c = input[i];
            if(c=='+' || c=='-' || c=='*'){
                vector<int> left_set;
                vector<int> right_set;
                left_set = rec(input.substr(0, i));
                right_set = rec(input.substr(i+1, input.length()-(i+1)));
                vector<int>::iterator iter_l;
                vector<int>::iterator iter_r;
                
                for(iter_l = left_set.begin(); iter_l != left_set.end(); iter_l++){
                    for(iter_r = right_set.begin(); iter_r != right_set.end(); iter_r++){
                        ans.push_back(compute(*iter_l, *iter_r, c));
                    }
                }
            }
        }
        
        if(ans.size()==0){
            int x = stoi(input);
            ans.push_back(x);
        } 
        return ans; 
    }
    
    
    vector<int> diffWaysToCompute(string input) {
        
        vector<int> ans;
        for(int i=0; i<input.length(); i++){
            char c = input[i];
            if(c=='+' || c=='-' || c=='*'){
                // split up left and right
                vector<int> left_set;
                vector<int> right_set;
        
                left_set = rec(input.substr(0, i));
                right_set = rec(input.substr(i+1, input.length()-(i+1)));
                
                
                vector<int>::iterator iter_l;
                vector<int>::iterator iter_r;
                
                for(iter_l = left_set.begin(); iter_l != left_set.end(); iter_l++){
                    for(iter_r = right_set.begin(); iter_r != right_set.end(); iter_r++){
                        ans.push_back(compute(*iter_l, *iter_r, c));
                    }
                }
            }
        }
        
        if(SZ(ans)==0){
            ans.push_back(stoi(input));
        }
        
        SORT(ans);
        return ans;
        
    }
};
