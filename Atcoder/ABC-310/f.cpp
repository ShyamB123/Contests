#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 998244353
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

    ll a[n];

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll tar = 10;

    vector<vector<ll>> dp(n + 1,vl((1<<(tar + 1)),0));

    // for(int i=0;i<=n;i++)
    // {
    //     dp[i][1] = 1;
    // }
    dp[0][1] = 1;

    for(ll i=0;i<n;i++)
    {
        for(ll k = 0;k<(1<<(tar + 1));k++)
        {
            ll num = k;
            for(ll j = 1;j<=min(tar,a[i]);j++)
            {
                int newnum = num;
                for(ll bt =0 ;bt<tar;bt++)
                {
                    if(((num & (1<<bt)) > 0) && (j + bt <= tar))
                    {   
                        newnum = (newnum | (1 << (j + bt)));
                        
                    }
                }
                dp[i + 1][newnum] += divmod(dp[i][num],a[i],mod);
                dp[i + 1][newnum] %= mod;
            }
            if(a[i] > tar)
            {
                dp[i + 1][num] += divmod((dp[i][num] * (a[i] - 10))%mod,a[i],mod);
                dp[i + 1][num] %= mod;
            }
        }
    }

    // dbg(dp);
    // cout << dp[n][(1<<11)]<<nl;

    ll ans =0;
    for(ll i =0;i<(1<<(tar + 1));i++)
    {
        if((i & (1<<tar)) > 0)
        {
            // cout << dp[n][i]<<" ";
            ans += dp[n][i];
            ans %= mod;
        }   
        // cout <<nl;
    }
    cout << ans<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}