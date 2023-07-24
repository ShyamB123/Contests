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
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/
const int N = 2e5  + 10;
vl fib;

void cal_fib(int n)
{
    fib.pb(1);
    fib.pb(1);

    for(int i =2;i<n;i++)
    {
        ll x = fib[fib.size()-1] + fib[fib.size() - 2];
        fib.pb(x);
    }
}

void solve()
{
    ll n,k;
    cin>>n>>k;

    if(k>N-5)
    {
        cout << 0<<nl;
        return;
    }

    ll x = fib[k - 2 ];
    ll y = fib[k - 3 ];

    // cout << x<<" "<<y<<nl;

    ll ans =0;
    for(ll f2 = 0;f2<=n;f2++)
    {
        if((n - x * f2)>=0 && (n - x * f2)%y == 0 && (f2 >= (n - x*f2)/y))
        {
            // cout << f2 <<" "<<(n - x*f2)/y<<nl;
            ans++;
        }
    }

    cout << ans<<nl;
    
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    cal_fib(N);

    ll t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}