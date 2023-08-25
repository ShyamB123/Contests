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
    ll n,m,d;
    cin>>n>>m>>d;

    multiset<ll> big,small;

    vl a;
    for(ll i =0;i<n;i++)
    {
        ll x;
        cin>>x;

        a.pb(x);
    }

    ll ans = 0;
    ll sum = 0;

    for(ll i =0;i<n;i++)
    {
        // ending at this value
        
        // dbg(small);
        // dbg(big);
        // dbg(sum);
        ll rmv = d * (i + 1);
        ll curans = sum + a[i] - rmv;
        ans = max(ans,curans);

        small.insert(a[i]);

        while(small.size() > 0 && *small.rbegin() >= 0 && big.size() < m - 1)
        {
            ll sval = *small.rbegin();
            big.insert(sval);
            small.erase(small.find(sval));
            sum += sval;
        }

        while(small.size() >0 && big.size() > 0 && big.size() == m-1 && *small.rbegin() > *big.begin())
        {
            ll sval = *small.rbegin();
            ll bval = *big.begin();
            big.insert(sval);
            small.insert(bval);
            big.erase(big.find(bval));
            small.erase(small.find(sval));
            sum += sval - bval;
        }
    }

    cout << ans <<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    ll t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}