#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
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

    ll a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<vector<vector<ll>>> dp (n + 1,vector<vector<ll>>(m + 1,vector<ll>(2,inf)));

    // dp[0][0][0] = i;
    dp[0][0][1] = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j =0 ;j<=m;j++)
        {
            if(dp[i-1][j][0] != inf)
            {
                dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][0]);
            }
            if(dp[i-1][j][1] != inf)
            {
                dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][1] + 1);
            }

            if(j - a[i -1] >=0 && dp[i-1][j- a[i -1]][1] != inf)
            {
                dp[i][j][1] = min(dp[i][j][1],dp[i-1][j-a[i-1]][1]);
            }

            if(j - a[i -1] >= 0 && dp[i-1][j - a[i -1]][0] != inf)
            {
                dp[i][j][1] = min(dp[i][j][1],dp[i-1][j-a[i-1]][0]);
            }
        }
        //  dbg(dp[i]);
    }

   
    for(int j = 1;j<=m;j++)
    {
        int ans = min(dp[n][j][0],dp[n][j][1]);

        if(ans == inf)
        {
            cout << -1<<nl;
        }
        else
        {
            cout << ans<<nl;
        }
    }
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}