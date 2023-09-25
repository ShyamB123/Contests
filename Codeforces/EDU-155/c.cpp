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
template <class T>void _print(vector<vector<vector<T>>> v){for(int k =0;k<v.size();k++){_print(v[k]);}}
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/
ll binexp(ll a,ll b)
{
    ll result = 1;
    while(b){
        if(b&1){
            result = (result*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return result;
}

vector<ll> infact,fact;

void fill_inverse_fact_fact(ll n){
    infact.resize(n+1);
    fact.resize(n+1);
    fact[0]=1;
    fact[1] = 1;
    for(ll i = 2;i<=n;i++)
    {
        // fact[i] = mul(fact[i-1],i);
        fact[i] = (fact[i-1]*i)%mod;
    }
    infact[n] = binexp(fact[n],mod-2);
    infact[0] = 1;
    for(ll i = n-1;i>=1;i--)
    {
        // infact[i] = mul(i+1,infact[i+1]);
         infact[i] = ((i+1)*infact[i+1])%mod;
    }
}

long long ncr(ll n, ll k) {
    return fact[n] * infact[k] % mod * infact[n - k] % mod;
}


void solve()
{
    string s;
    cin>>s;

    ll ans = 1;
    ll op = 0;

    int n = s.size();
    for(int i=0 ;i<n;i++)
    {

        ll len = 1;

        int j = i;

        while(j + 1 < n && s[j + 1] == s[i])
        {
            j++;
            len++;
        }

        op += len - 1;

        if(len > 1)
        {
            ans = (ans * len)%mod;
        }

        i = j;


    }

    ans = (ans * fact[op])%mod;

    cout << op <<" "<<ans<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    fill_inverse_fact_fact(2e5 + 10);

    ll t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}