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
    // if you get an answer you can always get it down to k - 1 elements
    // now check if its possible ig?
    
    ll n,k;
    cin>>n>>k;

    vl a(n);
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }

    if(k == 1)
    {
        cout << "YES" << nl;
        return;
    }

    vl b = a;
    sort(all(b));

    ll border = b[k - 2];

    // vl fix(n,0);
    vl v;

    for(int i =0;i<n;i++)
    {
        if(a[i] < border)
        {
            v.pb(i);
        }
    }

    // dbg(v)

    ll l = 0;
    ll r = v.size() - 1;
    ll sz = v.size();

    if(sz == 0)
    {
        cout << "YES" << nl;
        return;
    }
    for(int i =0;i<sz/2;i++)
    {
        if(a[v[i]] != a[v[sz - 1 - i]])
        {
            cout << "NO" << nl;
            return;
        }
    }
    ll canadd = 0;
    while(l <= r)
    {
        ll lhere = v[l];
        ll lprev = l - 1 >= 0 ? v[l - 1] : 0;

        ll rhere = v[r];
        ll rprev = r + 1 < sz ? v[r + 1] : n - 1;

        ll lb = 0;
        ll rb = 0;

        for(int i = lprev;i <= lhere;i++)
        {
            if(a[i] == border)
            {
                lb++;
            }
        }
        
        for(int i = rhere;i <= rprev;i++)
        {
            if(a[i] == border)
            {
                rb++;
            }
        }

        canadd += min(lb,rb) * 2;
        l++;
        r--;
    }
    // dbg(l)
    // dbg(r)
    if(sz % 2 == 0)
    {
        l--;
        r++;
        // dbg(l)
        // dbg(r)
        for(int i = v[l];i <= v[r];i++)
        {
            if(a[i] == border)
            {
                canadd++;
            }
        }
    }

    if(sz + canadd >= k - 1)
    {
        cout << "YES" << nl; 
    }
    else
    {
        cout << "NO" << nl;
    }
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