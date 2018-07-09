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
    void swap(int& a, int&b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
        return;
    }
    
    void nextPermutation(vector<int>& nums) {
        if(SZ(nums) == 1){
            return;
        } else if (SZ(nums) == 2){
            swap(nums[0], nums[1]);
            return;
        }
        
        int exist = false;
        for(int i = SZ(nums)-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                exist = true;
                //swap(nums[i-1], nums[i]);
                
                int index_min = i;
                int min = nums[i];
                for(int j=i; j<SZ(nums); j++){
                    if(nums[j] < min && nums[j] > nums[i-1]){
                        min = nums[j];
                        index_min = j;
                    }
                }
                swap(nums[i-1], nums[index_min]);
                
                sort(nums.begin() + i, nums.end()); 
                break;
            }
        }
        if(exist == false){
            SORT(nums);
        }
        return;
        
    }
};
