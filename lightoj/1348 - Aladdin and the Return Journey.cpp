/***********Template Starts Here***********/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <climits>
#include <iomanip>
#include <cassert>
//#include <unordered_map>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(int i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(int i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((int)(x).size())
#define NORM(x) if(x>=mod)x-=mod;

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<pii> vii;
typedef vector<int> vi;

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp printf("Execution Time: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    if ( x < 0 ) x += m; //modInv is never negative
    return x;
}

inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

/***********Template Ends Here***********/

/*********** Hasib Templates Starts Here**********/

#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<(n); i++)
#define sf scanf
#define pf printf
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) (v).begin(), (v).end()
#define PI acos(-1.0)
#define mem(ara, val) memset(ara, val, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define vdump(x) cerr<<#x<<" = "<<x<<endl;
#define dump(args...) cerr,args; cerr<<endl

template<typename T>
ostream& operator<<(ostream& out, vector<T> v)
{
    out<<"[ ";

    loop(i, SZ(v))
    {
        if(i) out<<", ";
        out<<v[i];
    }

    out<<" ]";
    return out;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &out, pair<T1, T2> p)
{
    out<<"( "<<p.fr<<", "<<p.sc<<")";
    return out;
}

template<typename T>
ostream& operator,(ostream &out, T x)
{
    out<<x<<" ";
    return out;
}


/**********Hasib Templates Ends Here**************/

/**
 *  WARTNING for me:
 *     Never use    FOR
 *     Never use    pii, pll, vi, vi
 *     Never use    ff, ss, phl, sp, nl
 */

#define MAXX 30007 
int N;
int ara[MAXX];
vector<int>graph[MAXX];




int chainId, chainHead[MAXX], depth[MAXX], whichChain[MAXX], subsize[MAXX], parent[MAXX];
int baseArray[MAXX], posInBaseArray[MAXX], ptr;
int sum[4*MAXX];

void HLD(int cur, int prev)
{
        if(chainHead[chainId] == -1)
        {
                chainHead[chainId] = cur;
        }

        whichChain[cur] = chainId;

        baseArray[ptr] = ara[cur];
        posInBaseArray[cur] = ptr;
        ptr++;


        int idx = -1, mxVal = -1;

        int v;

        loop(i, SZ(graph[cur]))
        {
                v = graph[cur][i];

                if(v == prev) continue;

                if(subsize[v] > mxVal)
                {
                        mxVal = subsize[v];
                        idx = i;
                }
        }

        if(idx != -1)
        {
                HLD(graph[cur][idx], cur);


                loop(i, SZ(graph[cur]))
                {
                        v = graph[cur][i];

                        if(i != idx && v != prev)
                        {
                                chainId++;
                                HLD(v, cur);
                        }
                }
        }
}



void buildSegTree(int idx, int st, int ed)
{
        //debug(st, ed);
        if(st == ed)
        {
                sum[idx] = baseArray[st];
                return;
        }

        int lft = idx*2;
        int rgt = lft + 1;
        int mid = (st + ed)/2;

        buildSegTree(lft, st, mid);
        buildSegTree(rgt, mid+1, ed);

        sum[idx] = sum[lft] + sum[rgt];
}


void update(int idx, int st, int ed, int pos, int val)
{
        if(st == ed)
        {
                sum[idx] = val;
                return;
        }

        int lft = idx*2;
        int rgt = lft + 1;
        int mid = (st + ed)/2;

        if(pos <= mid)
        {
                update(lft, st, mid, pos, val);
        }
        else
        {
                update(rgt, mid+1, ed, pos, val);
        }

        sum[idx] = sum[lft] + sum[rgt];
}


int query(int idx, int st, int ed, int a, int b)
{
        if(st == a && ed == b)
        {
                return sum[idx];
        }

        int lft = idx*2;
        int rgt = lft + 1;
        int mid = ( st + ed)/2;

        if(b <= mid)
        {
                return query(lft, st, mid, a, b);
        }
        else if(mid < a)
        {
                return query(rgt, mid+1, ed, a, b);
        }
        else
        {
                return query(lft, st, mid, a, mid) + query(rgt, mid+1, ed, mid+1, b);
        }
}


int LCA(int u, int v)
{
        if(whichChain[u] == whichChain[v])
        {
                return depth[u] < depth[v] ? u : v;
        }

        if( depth[ chainHead[ whichChain[ u ] ] ] < depth[ chainHead[ whichChain[v] ] ]  )
        {
                //cerr<<"v changed"<<endl;
                v = parent[ chainHead[ whichChain[v] ] ];
        }
        else
        {
                //cerr<<"uuuu changed"<<endl;
                u = parent[ chainHead[ whichChain[u] ] ];
        }


        //debug(u, v);
        return LCA(u, v);
}




int query_up(int u, int lca)
{
        if( whichChain[u] == whichChain[lca] )
        {
                return query(1, 0, N-1, posInBaseArray[lca], posInBaseArray[u]);
        }

        int uHead = chainHead[ whichChain[u] ];

        return query(1, 0, N-1, posInBaseArray[ uHead ], posInBaseArray[u]) + query_up(parent[ uHead ], lca);
}

int getResult(int u, int v)
{
        int lca = LCA(u, v);

        return query_up(u, lca) + query_up(v, lca) - query_up(lca, lca);
}






void dfs(int u, int _depth)
{
        depth[u] = _depth;
        subsize[u] = 1;

        int v;

        loop(i, SZ(graph[u]))
        {
                v = graph[u][i];

                if(depth[v] == -1)
                {
                        parent[v] = u;
                        
                        dfs(v, _depth+1);

                        subsize[u] += subsize[v];
                }
        }
}





void init()
{
        chainId = 0;
        mem(chainHead, -1);

        ptr = 0;

        mem(depth, -1);

        dfs(0, 0);

        //cerr<<"DFS done\n";

        HLD(0, 0);


        //cerr<<"HLD done\n";

        //vdump(N);

        buildSegTree(1, 0, N-1);


        //cerr<<"SEGTREE done\n";

}














void clearEverything()
{
        loop(i, MAXX)
        {
                graph[i].clear();
        }
}

int main ()
{
    #ifdef hasibpc
        read("input.txt");
        //write("myoutput.txt");
    #endif // hasibpc

    int kases, kaseno = 0;
    int u, v;
    int q, qtype;

    sf("%d", &kases);


    while(kases--)
    {
            sf("%d", &N);

            clearEverything();

            loop(i, N)
            {
                    sf("%d", &ara[i]);
            }

            for(int i=1; i<N; i++)
            {
                    sf("%d %d", &u, &v);
                    graph[u].pb(v);
                    graph[v].pb(u);
            }


            init();

            sf("%d", &q);

            pf("Case %d:\n", ++kaseno);

            while(q--)
            {
                    sf("%d %d %d", &qtype, &u, &v);

                    if(qtype == 0)
                    {
                            pf("%d\n", getResult(u, v));
                    }
                    else
                    {
                            update(1, 0, N-1, posInBaseArray[u], v);
                    }
            }

    }



    return 0;
}
