#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e16
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
    ll n,m;
    cin>>n>>m;

    vector<vector<vl>> adj(n + 1);
    vector<vector<vl>> radj(n + 1);

    for(ll i=0;i<m;i++)
    {
        ll u,v,b,c;
        cin>>u>>v>>b>>c;

        adj[u].pb({v,b,c});
        radj[v].pb({u,b,c});
    }

    double s = 0;
    double e = (double)(1e10);

    double ans = s;

    double dif = 1e-10;
    // dbg(dif);

    while(e - s >= dif)
    {
        double mid = (s + e)/2;

        vector<double> dp(n + 1,(double)(-1e10));

        dp[1] = 0;

        // weight of an edge is b - cx
        for(int i= 1;i<=n;i++)
        {
            for(auto it : radj[i])
            {
                if(dp[it[0]] != (double)(-1e10))
                    dp[i] = max(dp[i],dp[it[0]] + it[1] - mid * it[2]);
            }
        }
        if(dp[n] >= 0)
        {
            ans = mid;
            s = mid + dif;
        }
        else
        {
            e = mid - dif;
        }
        // cout << mid <<" "<<dp[n]<<nl;
        // cout << s <<" "<<e <<" "<<mid<< nl;
    }

    cout << ans <<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(18);

    solve();
}