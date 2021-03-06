
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


bool comp(paii a, paii b)
{
    if(a.fr < b.fr)
    {
        return true;
    }
    else if(a.fr == b.fr)
    {
        return a.sc > b.sc;
    }
    else
    {
        return false;
    }
}

int main()
{
	int n;
	paii ara[10];
	cin>>n;
	int backup[10];

	loop(i, 9)
	{
	    cin>>ara[i].fr;
	    backup[i] = ara[i].fr;
	    ara[i].sc = i;
	}

	sort(ara, ara+9, comp);

	int cnt = n / ara[0].fr;
	int rem = n % ara[0].fr;

	vector<int>v;

	while(cnt)
	{
	    int t = ara[0].fr + rem;
	    int j;
	    for(j=8; j>ara[0].sc; j--)
	    {
	        if(t >= backup[j])
	        {
	            //dump(j);

	            v.pb(j);
	            rem = t - backup[j];
	            cnt--;
	            break;
	        }
	    }
	    if(j == ara[0].sc)
	    {

	        while(cnt--)
	        {
	            v.pb(ara[0].sc);
	        }
	        break;
	    }
	}

	loop(i, SZ(v))
	{
	    cout<<v[i]+1;
	}
	if(SZ(v) == 0)
	{
	    cout<<-1;
	}
	cout<<endl;








}
