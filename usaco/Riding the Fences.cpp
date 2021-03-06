/*
ID: himuhas1
TASK: fence
LANG: C++
*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args
#define debug(args...) asdfg,args; cout<<endl
struct ASDF{
    ASDF& operator,(int &a) {
        sf("%d", &a);
        return *this;
    }
    ASDF& operator,(long int &a){
        sf("%ld", &a);
        return *this;
    }
    ASDF& operator,(long long int &a){
        sf("%lld", &a);
        return *this;
    }
    ASDF& operator,(char &c){
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(double &d){
        sf("%lf", &d);
        return *this;
    }

    template<typename T>
    ASDF& operator,(T &a){
        cin>>a;
        return *this;
    }
}asdf;
struct ASDFG{
    template<typename T>
    ASDFG& operator,(vector<T> &v){
        pf("[");
        cout<<v[0];
        FOR(i, 1, SZ(v)){
            cout<<", "<<v[i];
        }
        pf("]");
        return *this;
    }

    template<typename T>
    ASDFG& operator,(T x) {
        cout<<x<<" ";
        return *this;
    }


}asdfg;



//Header ends here

#define MAXX 502


int cntNodes;
vector<int>graph[MAXX];
int isConnected[MAXX][MAXX];
vector<int>path;

int degree[MAXX];

void eular_travarse(int node)
{
    path.pb(node);
    int v;
    loop(i, SZ(graph[node]))
    {
        v = graph[node][i];
        if(isConnected[node][v])
        {
            isConnected[node][v]--;
            isConnected[v][node]--;
            eular_travarse(v);
        }
    }

}


int main()
{
    #ifndef hasibpc
        read("fence.in");
        write("fence.out");
    #endif
    take(cntNodes);
    int u, v;

    set<int>allNodes;

    loop(i, cntNodes)
    {
        take(u, v);
        graph[u].pb(v);
        graph[v].pb(u);
        isConnected[u][v]++;
        isConnected[v][u]++;
        allNodes.insert(u); allNodes.insert(v);
        degree[u]++;
        degree[v]++;
    }



    for(set<int>::iterator it=allNodes.begin(); it != allNodes.end(); it++)
    {
        sort(all(graph[*it]));
    }


    int st = *allNodes.begin();

    for(set<int>::iterator it = allNodes.begin(); it != allNodes.end(); it++)
    {
        if( degree[ *it ] & 1 )
        {
            st = *it;
            break;
        }
    }

    eular_travarse(st);

    //reverse(all(path));

    loop(i, SZ(path))
    {
        pf("%d\n", path[i]);
    }






}
