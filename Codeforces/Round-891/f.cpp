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

ll sqr_root(ll tar)
{
    ll l = 0;
    ll r = 2e9 + 1;
    // ll r= 1e9;

    ll ans = 1;

    while(l<=r)
    {
        ll mid = (l+r)/2;

        if(mid*mid <= tar)
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }

    return ans;
}

void solve()
{
    ll n;
    cin>>n;

    ll a[n];
    map<ll,ll> m;

    for(ll i =0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }

    ll q;
    cin>>q;
    
    for(ll i =0;i<q;i++)
    {
        ll x,y;
        cin>>x>>y;

        ll ok = sqr_root(x * x - 4 * y);
        if(ok * ok != x * x - 4 * y)
        {
            cout << 0 <<" ";
            continue;
        }
        ll cur =0 ;

        ll tar1ai = x + ok;
        ll tar1aj;
        if(tar1ai%2 == 1)
        {
            // dont do;
        }
        else
        {
            tar1ai /= 2;
            ll tarj = y/tar1ai;
            tar1aj = tarj;
            
            if(tar1ai == tarj)
            {
                cur += m[tar1ai] * (m[tar1ai] -1 )/2;
            }
            else
            {
                cur += m[tar1ai] * m[tarj];
            }
        }

        ll tar2ai = x - ok;
        if(tar2ai%2 == 1)
        {
            // dont do;
        }
        else
        {
            tar2ai /= 2;
            ll tarj = y/tar2ai;

            if(tarj != tar1ai || tar2ai != tar1aj)
            {
                if(tar2ai != tarj)
                {
                    cur += m[tar2ai] * m[tarj];
                }
                else
                {
                    cur += m[tarj] * (m[tarj] - 1)/2;
                }
            }
        }

        cout << cur <<" ";
    }
    cout <<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    int t;
    cin>>t;
    while(t--)
        solve();
}