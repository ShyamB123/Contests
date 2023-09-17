#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e18
#define F first
#define S second
#define pb push_back
#define mp make_pair

#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int, int>>
#define vll vector<pair<ll, ll>>
#define all(a) a.begin(), a.end()
#define nl '\n'

using namespace std;

//----------------------DEBUGGER----------------------------------------------------------
#define dbg(x) cout << #x <<" "; _print(x); cout << endl;
 
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(ld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

 
template <class T> void _print(vector<vector<T>> v) {for(int j =0;j<v.size();j++){cout <<nl<<"[ "; for (T i : v[j]){_print(i); cout << " ";} cout << "]";};}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.F); cout << ","; _print(p.S); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T>void _print(vector<vector<vector<T>>> v){for(int k =0;k<v.size();k++){_print(v[k]);}}
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/



void solve()
{
    ll n,h;
    cin>>n>>h;

    ll a[n];

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    map<ll,pair<ll,ll>>m;


    for(ll i =0;i<n-1;i++)
    {
        ll p,c;
        cin>>p>>c;
        m[i] = {p,c};
    }

    ll finalans = inf;


    vector<vl> dp(h + 1,vl(h + 1,inf));

    // dp[h][rtnfl] = 0;

    //  for(ll j = 0;j<=h;j++)
    //     {
    for(ll k = 0;k<=h;k++)
    {
        dp[k][k] = 0;
    }
        // }

    auto ndp = dp;


    for(ll i =n-2;i>=-1;i--)
    {
        for(ll j = 0;j<=h;j++)
        {
            for(ll k = 0;k<=h;k++)
            {
                ndp[j][k] = inf;
            }
        }
        ll l = 0;
        ll r = 0;
        if(i>=0)
            l = a[i];
        r = a[i + 1];

        ll dist = r - l;
        ll fuel = m[i].S;
        ll cost = m[i].F;
        // dont refuel

        for(ll j = 0;j<=h;j++)
        {
            for(ll k = 0;k<=h;k++)
            {
                if(j - dist >=0 && k + dist <= h && dp[j - dist][k + dist] != inf)
                {
                    ndp[j][k] = min(ndp[j][k],dp[j - dist][k + dist]);
                }
            }
        }

        // refuel 1

        for(ll j = 0;j<=h;j++)
        {
            for(ll k = 0;k<=h;k++)
            {
                if(min(h,j + fuel) - dist >=0 && k + dist <= h && dp[min(h,j + fuel) - dist][k + dist] != inf)
                {
                    ndp[j][k] = min(ndp[j][k],dp[min(h,j + fuel) - dist][k + dist] + cost);
                }
            }
        }

        // refuel 2

        for(ll j = 0;j<=h;j++)
        {
            for(ll k = 0;k<=h;k++)
            {
                if(j - dist >=0 && k + dist <= h && dp[j - dist][k + dist] != inf)
                {
                    ndp[j][min(h,k + fuel)] = min(ndp[j][min(h,k + fuel)],dp[j - dist][k + dist] + cost);
                }
            }
        }

        // swap(dp,ndp);
        // for(ll j =0 ;j<=h;j++)
        // {
        //     for(ll k =0;k<=h;k++)
        //     {
        //         if(ndp[j][k] != inf)
        //         {
        //             cout << j <<" "<<k<<nl;
        //         }
        //     }
        // }
        // cout << nl;
        dp = ndp;
        // dbg(dp);
        bool check = true;
    }

    ll finaldist = a[n - 1];
    if(n > 1)
    {
        finaldist -= a[n - 2];
    }

    // dbg(dp);

    for(ll i = 0;i<=h;i++)
    {
        for(ll j =0;j<=h;j++)
        {
            finalans = min(finalans,dp[i][j]);
        }
    }
    // dbg(finalans);
    

    if(finalans == inf)
    {
        cout << -1 <<nl;
    }
    else
        cout << finalans<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}