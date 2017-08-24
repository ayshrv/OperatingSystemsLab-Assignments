/*input
abcdef
*/
#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x);
#define slld(x) scanf("%lld",&x);
#define ss(x) scanf("%s",x);
#define sc(x) scanf("%c",&x);
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define pc1(x) cout<<x<<" ";
#define pc2(x,y) cout<<x<<" "<<y<<" "<<endl;
#define pc3(x,y,z) cout<<x<<" "<<y<<" "<<z<<" "<<endl;
#define pc4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<" "<<endl;
#define pce(x) cout<<x<<endl;
#define ps0() cout<<endl;
#define ps1(x) cout<<#x<<" ";
#define ps2(x,y) cout<<#x<<" "<<y<<" "<<endl;
#define ps3(x,y,z) cout<<#x<<" "<<y<<" "<<z<<" "<<endl;
#define ps4(w,x,y,z) cout<<#w<<" "<<x<<" "#y<<" "<<z<<" "<<endl;
#define pse(x) cout<<#x<<endl;
#define GET_MACRO(_0, _1, _2, _3, _4, NAME, ...) NAME
#define GET_MACRO1(_1, _2, _3, _4, NAME, ...) NAME
#define ps(...) \
		do{if (DEBUG) GET_MACRO(_0, ##__VA_ARGS__, ps4, ps3, ps2, ps1, ps0)(__VA_ARGS__)} while(0);
#define pc(...) \
 		do{if (DEBUG) GET_MACRO1(__VA_ARGS__, pc4, pc3, pc2, pc1)(__VA_ARGS__)} while(0);
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI; 

#define MOD 1000000007
#define DEBUG 1

int main()
{

    char s[100];
    scanf("%s",s);
    pc(strlen(s))

}