#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 998244353
#define inf 1e14
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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/

ll sigma(ll n)
{
    return (n * (n - 1)/2)%mod;
}


void solve()
{
    ll n,k;
    cin>>n>>k;

    vl a(n);
    vl v(k);

    for(ll i =0;i<n;i++)
    {
        cin>>a[i];
    }

    for(ll i =0;i<k;i++)
    {
        cin>>v[i];
    }

    ll ans =0 ;

    ordered_set os;

    ll cur =0;
    for(ll i =0;i<k;i++)
    {
        ll indx = os.size() - os.order_of_key(v[i]);

        cur += indx;
        cur %= mod;
        os.insert(v[i]);
    }

    ans = (n * cur)%mod;

    os.clear();
    os.insert(inf);
    for(ll i = 0;i<n;i++)
    {
        ll num = a[i];
        ll last = os.order_of_key(num);

        ll next = inf;
        ll p = 0;
        while(1)
        {
            num *= 2;
            next = os.order_of_key(num);
            if(next == os.size()) break;
            ll el = next - last;

            p++;
            
            if(p < k)
            {
                ans += ((((k * k)%mod - sigma(k - p + 1) + mod)%mod) * el)%mod;
            }
            else
            {
                ll left = os.size() - 1 - last;
                ans += (((k * k)%mod) * left)%mod;
                ans %= mod;
                break;
            }
            ans %= mod;
            last = next;

        }
        os.insert(a[i]);
    }

    os.clear();
    os.insert(inf);
    for(ll i = n - 1;i>=0;i--)
    {
        ll num = a[i];
        ll last = os.order_of_key(num);

        ll next = inf;
        ll p = 0;
        while(1)
        {
            num *= 2;
            next = os.order_of_key(num);
            if(next == os.size()) break;

            ll el = next - last;

            p++;

            if(p < k)
            {
                ans += ((sigma(k - p + 1)%mod) * el)%mod;
            }
            else
            {
                // dbg(last);
                // ll left = os.size() - 1 - last;
                // ans += (((k * k)%mod) * left)%mod;
                // ans %= mod;
                break;
            }
            ans %= mod;
            last = next;
        }
        os.insert(a[i]);
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