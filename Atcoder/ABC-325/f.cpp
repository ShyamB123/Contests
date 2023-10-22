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

const int N = 1e5 + 1;
    ll n;

vl d(N);
vector<vl> s;

ll dp[101][1001][1001];

ll check(ll i,ll a1,ll a2)
{
    if(i >= n)
        return 0;
    if(dp[i][a1][a2] != -1)
    {
        return dp[i][a1][a2];
    }

    ll ans = inf;
    ll start = min((d[i] + s[0][0] - 1)/s[0][0],a1);
    // ll start = a1;
    for(ll x = start;x>=0;x--)
    {
        ll rem = d[i] - x * s[0][0];
        ll y = 0;
        if(rem > 0)
            y = ((rem + s[1][0] - 1) / s[1][0]);
        if(y <= a2)
        {
            ll curans = x * s[0][1] + y * s[1][1] + check(i + 1,a1 - x,a2 - y);
            ans = min(curans,ans);
        }
    }

    return dp[i][a1][a2] = ans;
}


void solve()
{

    cin>>n;

    memset(dp,-1,sizeof(dp));

    for(ll i=0;i<n;i++)
    {
        cin>>d[i];
    }

    for(ll i =0;i<2;i++)
    {
        ll l,c,k;
        cin>>l>>c>>k;
        s.pb({l,c,k});
    }

    ll ans = check(0,s[0][2],s[1][2]);

    if(ans == inf)
    {
        cout << -1 <<nl;
        return;
    }
    cout << ans <<nl;

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}