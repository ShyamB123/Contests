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
    ll n,m,k;
    cin>>n>>m>>k;

    vector<vector<ll>> dp(n + 1,vl(k + 1,0));

    dp[0][0] = 1;

    // for(int i =0;i<=n;i++)
    // {
    //     cout << dp[i][0]<<" ";
    // }
    // cout <<nl;

    for(ll mv = 1;mv<=k;mv++)
    {
        for(ll i= 1;i<=n;i++)
        {
            ll ans =0;
            ll div =0;
            for(ll j = 1;j<=m;j++)
            {
                if(i - j>=0 )
                {
                    ans = (ans + dp[i-j][mv-1])%mod;
    
                }
                if(((2 * n - i - j) != (i - j)) && j > n - i && (2 * n - i - j) >= 0 )
                {
                    ans = (ans + dp[2 * n - i - j][mv-1])%mod;
                }
            }
            ans = divmod(ans,m,mod);
            dp[i][mv] = ans;
            
        }

        // cout << mv <<" : ";

        // for(int i =0;i<=n;i++)
        // {
        //     cout << dp[i][mv]<<" ";
        // }
        // cout <<nl;
    }

    

    ll ans =0;

    for(ll i=0;i<=k;i++)
    {
        
            ans = (ans + dp[n][i])%mod;
        
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