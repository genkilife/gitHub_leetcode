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
    int comp(string a, string b){
        int cnt = 0;
        FOR(i, 0, SL(a)){
            if(a[i]!=b[i]){
                cnt++;
            }
        }
        return cnt;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size()==0){
            return 0;
        }
        int i;
        for(i=0; i< SZ(wordList) ; i++){
            if(wordList[i] == endWord){
                break;
            }
        }
        if(i == SZ(wordList)){
            return 0;
        }
        
        
        wordList.insert(wordList.begin(), beginWord);
        
        VI graph(SZ(wordList), INT_MAX);
        
        queue<int> node;
        
        graph[0] = 1;
        node.push(0);
        
      
        while(node.size()!=0){
            int index = node.front();
            node.pop();
            FOR(i, 0, SZ(wordList)){
                if(i != index && comp(wordList[i], wordList[index]) == 1){
                    if((graph[index] + 1) < graph[i]){
                        graph[i] = graph[index] + 1;
                        node.push(i);
                    }
                }
            }
        }
        
        FOR(i, 0, SZ(wordList)){
            if(wordList[i] == endWord){
                if (graph[i] > SZ(wordList)){
                    return 0;
                } else{
                    return graph[i];
                }
            }
        }
    }
};
