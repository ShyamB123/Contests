#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 998244353
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
ll n,m;
ll a,b,c,d,e,f;
vl dx,dy;
set<pair<ll,ll>> obs;
map<pair<pair<ll,ll>,ll>,ll> dp;

ll check(ll x,ll y,ll turn)
{

    if(obs.find({x,y}) != obs.end())
    {
        return 0;
    }
    if(turn >= n)
    {
        return 1;
    }
    cout << x<<" "<<y<<" "<<turn<<endl;

    // vl v;
    // v.pb(x);
    // v.pb(y);
    // v.pb(turn);
    auto v = make_pair(make_pair(x,y),turn);
    if(dp.find(v) != dp.end())
    {
        return dp[v];
    }

    ll ans = 0;

    for(int i = 0;i<3;i++)
    {
        ans += check(x + dx[i],y + dy[i],turn+1);
        ans %= mod;
    }
    
    return dp[v] = ans;
}
void solve()
{
    
    cin>>n>>m;

    cin>>a>>b>>c>>d>>e>>f;
    dx.pb(a);
    dx.pb(c);
    dx.pb(e);

    dy.pb(b);
    dy.pb(d);
    dy.pb(f);
    for(ll i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        obs.insert({x,y});
    }

    ll ans = check(0,0,0);

    dbg(dp);

    cout << ans <<nl;
    
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}