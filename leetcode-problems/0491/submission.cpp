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
    void find_seq(int pre, vector<int>&nums, vector<int>&stack, set<vector<int>> & ans){
        if(nums.size() == 0){
            if(stack.size() > 1){
                ans.insert(stack);
            }
            return;
        }
        
        
        vector<int> tmp;
        find_seq(pre, tmp, stack, ans);
        
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= pre){
                vector<int> sub_nums(nums.begin()+i+1, nums.end());
                stack.push_back(nums[i]);
                find_seq(nums[i], sub_nums, stack, ans);
                stack.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //SORT(nums);
        set<vector<int>> ans;
        vector<int> stack;
        find_seq(-101, nums, stack, ans);
        
        
        set<vector<int>>::iterator iter;
        vector<vector<int>> out;
        for(iter = ans.begin(); iter != ans.end(); iter++){
            out.push_back(*iter);
        }
        
        return out;
    }
};
