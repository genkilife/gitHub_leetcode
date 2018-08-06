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
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    
        SORT(nums);
        int offset = INT_MAX;
        int ans = INT_MAX;
        FOR(i, 0, nums.size()-2){
            FOR(j, i+1, nums.size()-1){
                int a = nums[i];
                int b = nums[j];
                int c = target - a - b;
                
                FOR(k, j+1, nums.size()){
                    if(nums[k] < c){
                        if( (c -nums[k]) < offset){
                            offset = (c -nums[k]);
                            ans = a + b + nums[k];
                        }
                    } else{
                        if((nums[k]-c) < offset){
                            offset = (nums[k]-c);
                            ans = a + b + nums[k];
                        }
                    }
                }
                
                
            }
        }
        return ans;
        
    }
};
