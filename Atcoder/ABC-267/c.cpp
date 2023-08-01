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
9 - 4 + 18 - 20 = 

-2 + 12 - 15 + 12

. i ..... i + m - 1
pre[i]......pre[i + m]    
*/



void solve()
{
    ll n,m;
    cin>>n>>m;

    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vl pre(n + 1,0);

    for(ll i =0;i<n;i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }

    ll ans =0;

    ll cur = m;
    ll finalans = 0;
    for(ll i = n-1;i>n - 1 - m;i--)
    {
        ans += cur * a[i];
        cur--;
    }
    finalans = ans;
    
    // dbg(ans);
    for(ll i = n-1-m;i>=0;i--)
    {
        ans -= m * a[i + m];
        ans += pre[i + m] - pre[i];
        // dbg(ans);
        // ans += a[i];
        // dbg(ans);

        finalans = max(finalans,ans);
    }

    cout << finalans<<nl;
    
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}