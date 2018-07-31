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

bool rec(vector<int>& nums, int target, int index){

    if(target < 0){
        return false;
    }
    if(index == nums.size()){
        return false;
    }

    for(int i=index; i<nums.size(); i++){
        if(nums[i] == target){
            return true;
        }
        else if(rec(nums, target - nums[i], i+1)){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if((sum%2) == 1){
            return false;
        } 
        int target = sum/2;
        
        RSORT(nums);
        
        if(target == nums[0]){
            return true;
        }
        return rec(nums, target-nums[0], 1);
        
        
    }
};
