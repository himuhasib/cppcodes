/****************************************************************
   ▄█    █▄       ▄████████    ▄████████  ▄█  ▀█████████▄
  ███    ███     ███    ███   ███    ███ ███    ███    ███
  ███    ███     ███    ███   ███    █▀  ███   ███    ███
 ▄███▄▄▄▄███▄▄   ███    ███   ███        ███  ▄███▄▄▄██▀
▀▀███▀▀▀▀███▀  ▀███████████ ▀███████████ ███ ▀▀███▀▀▀██▄
  ███    ███     ███    ███          ███ ███    ███    ██▄
  ███    ███     ███    ███    ▄█    ███ ███    ███    ███
  ███    █▀      ███    █▀   ▄████████▀  █▀   ▄█████████▀
****************************************************************/



#include<bits/stdc++.h>


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

#define dump(x) cerr<<#x<<" = "<<x<<endl
#define debug(args...) cerr,args; cerr<<endl;
using namespace std;


template<typename T>
ostream& operator<<(ostream& output, vector<T>&v)
{
    output<<"[ ";
    if(SZ(v))
    {
        output<<v[0];
    }
    FOR(i, 1, SZ(v))
    {
        output<<", "<<v[i];
    }
    output<<" ]";
    return output;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& output, pair<T1, T2>&p)
{
    output<<"( "<<p.fr<<", "<<p.sc<<" )";
    return output;
}




template<typename T>
ostream& operator,(ostream& output, T x)
{
    output<<x<<" ";
    return output;
}





//Header ends here

#define MAXX 200007

#define MAXCOLOR 4

int dp[MAXX][MAXCOLOR+1];

vector<int>childList[MAXX];


int rec(int pos, int parentColor)
{
    int &ret = dp[pos][parentColor];

    if(ret != -1) return ret;


    ret = INFINITY;

    for(int i=1; i<=MAXCOLOR; i++)
    {
        if(i != parentColor )
        {
            int sum = i;

            loop(j, SZ(childList[pos]))
            {
                sum += rec(childList[pos][j], i);
            }

            ret = min(sum, ret);
        }
    }

    return ret;


}

int N;


int main()
{
    read("input");
    int kases, kaseno = 0;

    int parent;

    cin>>kases;

    while(kases--)
    {
        loop(i, MAXX)
        {
            childList[i].clear();
        }


        mem(dp, -1);

        cin>>N;

        for(int i =1; i<=N; i++)
        {
            cin>>parent;
            if(parent != 0)
            {
                childList[parent].pb(i);

                //cerr<<parent<<" -> "<<i<<endl;
            }
        }

        int result = rec(1, 0);


        pf("Case #%d: %d\n", ++kaseno, result);

       // dump(dp[4][2]);
    }



}
