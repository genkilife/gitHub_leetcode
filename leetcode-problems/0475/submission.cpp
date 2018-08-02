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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long long g_radius = 0;
        
        SORT(houses);
        SORT(heaters);

        /*
        FOR(i, 0, SZ(houses)){
            cout<<houses[i]<<" ";
        }
        cout<<endl;
        FOR(i, 0, SZ(heaters)){
            cout<<heaters[i]<<" ";
        }
        cout<<endl;
        */
        FOR(i, 0, SZ(houses)){
            long long radius = -1;
            long long radius2 = -1;
            
            int index = GET_POS(heaters, houses[i]);
            
            if(index != SZ(heaters)){
                if(houses[i] > heaters[index]){
                    radius = houses[i] - heaters[index];
                } else{
                    radius = heaters[index] - houses[i];
                }
                //cout<<"top index: "<<index<<" house: "<<houses[i] <<" heaters: "<< heaters[index]<<" radius: "<<radius<<endl;
            }
            index--;
            while(index >=0 && heaters[index] >= houses[i]){
                index--;
            }
            
            if( (index) >=0 ){
                if(houses[i] > heaters[index]){
                    radius2 = houses[i] - heaters[index];   
                } else{
                    radius2 = heaters[index] - houses[i];
                }
                if(radius > radius2 || radius < 0){
                    //cout<<"bot index: "<<index<<" house: "<<houses[i] <<" heaters: "<< heaters[index]<<endl;
                    radius = radius2;
                }
            }
            


            if(radius > g_radius){
                g_radius = radius;
            }

            //cout<<"i: "<<i<<" house data: "<<houses[i]<<" index: "<<index<<" radius: "<<radius<<endl;
        }
        return g_radius;
    }
};
