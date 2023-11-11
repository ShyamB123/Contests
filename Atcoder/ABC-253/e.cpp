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



void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll> dp(m + 1,0);

    if(k == 0)
    {
        ll ans = 1;
        for(int i = 0;i<n;i++)
        {
            ans *= m;
            ans %= mod;
        }
        cout << ans <<nl;
        return;
    }

    // dp[0] = 1;
    for(int j =1;j<=m;j++)
    {
        dp[j] = 1;
    }

    for(int i =1;i<n;i++)
    {
        // do prefixs of dp
        // auto ndp = dp;
        vector<ll> ndp(m + 1,0);

        for(int j = 1;j<=m;j++)
        {
            dp[j] += dp[j - 1];
            dp[j] %= mod;
        }

        for(int j = 1;j<=m;j++)
        {
            if(j - k >= 0)
            {
                ndp[j] += dp[j - k];
                ndp[j] %= mod;
            }


            if(j + k <= m)
            {
                ndp[j] += ((dp[m] - dp[j + k - 1] + mod)%mod);
                ndp[j] %= mod;  
            }
        }

        dp = ndp;
        // dbg(dp);
    }

    ll ans =0;

    for(int i= 1;i<=m;i++)
    {
        ans += dp[i];
        ans %= mod;
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