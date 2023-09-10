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


ll d = 840;
const ll N = 1e5 + 1;
vector<vl> dp(N + 1,vl(842,0));
void solve()
{
    ll n;
    cin>>n;

    ll x,y;
    cin>>x>>y;

    vll a;
    for(ll i=0 ;i<n - 1;i++)
    {
        ll u,v;
        cin>>u>>v;
        a.pb({u,v});
    }



    for(ll i = 0;i<d;i++)
    {
        dp[n - 1][i] = y;
    }

    for(ll i = n - 2;i>=0;i--)
    {
        for(ll j = 0;j<d;j++)
        {
            ll rem = (a[i].F - (j % a[i].F)) % a[i].F;

            ll newj = (j + rem + a[i].S)%d;

            dp[i][j] = dp[i + 1][newj] + a[i].S + rem;
        }
    }

    // dbg(dp);
    ll qr;
    cin>>qr;

    for(int i = 0;i<qr;i++) 
    {
        ll q;
        cin>>q;

        cout << q + x +  dp[0][(q + x)%d]<<nl;
//  (a[0].F - (q + x) % a[0].F)%a[0].F


    }

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}