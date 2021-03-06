/**
   __      __            ______             _________     __     ______
  |  |    |  |          /  __  \           /   _____ \   |  |   |   __  \
  |  |    |  |         /  /  \  \          |  |     \/   |  |   |  |  \  \
  |  |    |  |        /  /    \  \         |  |          |  |   |  |   \  \
  |  |____|  |       /  /######\  \        |  |______    |  |   |  |___*  /
  |   ____   |      /              \       |______   |   |  |   |   ___  X
  |  |    |  |     /  /##########\  \             |  |   |  |   |  |   *  \
  |  |    |  |    /  /            \  \            |  |   |  |   |  |   /  /
  |  |    |  |   /  /              \  \   /\______|  |   |  |   |  |__/  /
  |__|    |__|   \_/                \_/   \__________|   |__|   |_______/


**/



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

#define MAX18 1000000000000000007LL


#define MMAX 1000007 //(10^6)

#define MAX 10007 // (10^4)

#define MOD 1000000007LL //(10^9 + 7)


vector<ll>pows[62];


void preCalc()
{
    for(ll i=1; i<MMAX; i++)
    {
        for(ll j=i*i*i, p=3; p < 62 ;p++, j*=i)
        {
            pows[p].pb(j);
            if(j > MAX18/i) //here is the real trick. checking if i*j > MAX18.
            {
                break;
            }

        }
    }
}

ll root(int i, ll x)
{
    if(i == 1) return x;
    if(i==2) return sqrt(x);

    vector<ll> &v = pows[i];



    int low = 0, high = SZ(v)-1;
    //dump(v[0]);
    //debug(low, high);

    while(low <= high)
    {
        int mid = (low+high)/2;

        if(v[mid] <= x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    //debug(low, high);

    return low; // = high+1
}


int N, Q;
ll ara[MAX];
ll comu[MAX];



int main()
{
    //ios_base::sync_with_stdio(0);
    preCalc();


    //cerr<<root(12, 1000000000000000000);



    int kases;

    sf("%d", &kases);

    while(kases--)
    {
        sf("%d %d", &N, &Q);

        for(int i=1; i<=N; i++)
        {
            sf("%lld", &ara[i]);
            //if(ara[i] < 0) ara[i] = ara[i] + MOD;
        }

        comu[N+1] = 0;
        comu[61] = 0;

        for(int i=N; i>0; i--)
        {
            comu[i] = (comu[i+1] + ara[i] ) % MOD;
        }

        loop(q, Q)
        {
            ll sum = 0;
            ll x;

            sf("%lld", &x);

            int till = min(60, N);
            ll r;

            for(int i=1; i<=till; i++)
            {
                r = root(i, x)%MOD;
                sum += ( r*ara[i] )%MOD;

                sum = sum%MOD;
            }

            sum = (sum + comu[61])%MOD;

            sum = (sum + MOD)%MOD;

            if(q) pf(" ");
            pf("%lld", sum);
        }

        pf("\n");
    }
}
