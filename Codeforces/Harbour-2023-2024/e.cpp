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
template <class T>void _print(vector<vector<vector<T>>> v){for(ll k =0;k<v.size();k++){_print(v[k]);}}
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/


ll check(ll i,vl &a)
{
    if(i < 0)
    {
        return (((a.size())%mod) * (a.size()))%mod;
    }

    vl zeros,ones;

    for(auto it : a)
    {
        if((it & (1<<i)) > 0)
        {
            // dbg((it & (1<<i)));
            ones.pb(it);
        }
        else
        {
            zeros.pb(it);
        }
    }

    // we can differentiate the ones and zeros now

    ll ans = 0;

    ans += (3 * zeros.size() * ones.size())%mod;
    ans%= mod;

    if(zeros.size() >= 1)
    {
        ans += check(i - 1,zeros);
        ans %= mod;
    
    }
    
    
    
    if(ones.size() >= 1)
    {
        ans += ((ones.size()) * (ones.size()))%mod ;
        ans += check(i - 1,ones);
        ans %= mod;
    }
    else if(ones.size() == 1)
    {
        ans++;
    }

    // dbg(ans);
    return ans;
}

ll binexp1(ll a,ll b, ll m){
    ll result = 1;
    while(b){
        if(b&1){
            result = (result*a)%m;
        }
        a = (a*a)%m;
        b>>=1;
    }
    return result;
}

ll divmod (ll a,ll b, ll m){
    ll inv = binexp1(b,m-2,m);
    ll ans = ((a%m)*(inv%m))%m;
    return ans;
}

void solve()
{
    ll n;
    cin>>n;

    vl a;
    ll ans = 0;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        a.pb(x);
        
        // ll curans =  __builtin_popcount(x) + 1;
        // if(curans >= 2)
        // {
        //     curans++;
        // }

    }

    // dbg(check(31,a));
    ans += check(31,a);

    ans %= mod;

    ans = divmod(ans,(n * n)%mod,mod);

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