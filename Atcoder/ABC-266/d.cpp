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
    int n;
    cin>>n;

    const int N = 1e5 + 1;
    vector<vl> a(N);
    
    int maxtime =0;
    for(int i=0;i<n;i++)
    {
        ll t,x,val;
        cin>>t>>x>>val;

        // vi v;
        a[t].pb(x);
        a[t].pb(val);
        maxtime = t;
    }

    vector<vector<ll>> dp(maxtime + 1,vl(5,-inf));
    dp[0][0] = 0;

    for(int i = 1;i<=maxtime;i++)
    {
        dp[i] = dp[i-1];


        if(a[i].size()>0)
        {
            ll pos = a[i][0];
            ll val = a[i][1];
            for(ll j =0;j<5;j++)
            {
                ll time = max(1ll,abs(pos - j));
                if(i - time >= 0 && dp[i - time][j] != -inf)
                {
                    dp[i][pos] = max(dp[i][pos],dp[i-time][j] + val);
                }
            }
        }
    }
    // dbg(dp);
    ll ans= 0;
    for(int j =0;j<5;j++)
    {
        ans = max(ans,dp[maxtime][j]);
    }

    cout << ans<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}