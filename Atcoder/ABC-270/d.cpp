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



void solve()
{
    ll n,k;
    cin>>n>>k;

    ll a[k];
    for(ll i=0;i<k;i++)
    {
        cin>>a[i];
    }

    vector<vl> dp(n + 1,vl(2,-inf));
    dp[0][0] = dp[0][1] = 0;

    for(ll i =1;i<=n;i++)
    {
        for(ll turn = 0;turn<2;turn++)
        {
            if(turn == 0)
            {
                dp[i][turn] = -inf;
            }
            else
            {
                dp[i][turn] = inf;
            }
            for(ll j =0;j<k;j++)
            {

                if(i - a[j] >= 0 && dp[i-a[j]][1-turn] != inf && turn == 0)
                {
    
                    dp[i][turn] = max(dp[i][turn],a[j] + dp[i-a[j]][1-turn]);
                    
                }
                if(i - a[j] >= 0 && dp[i-a[j]][1-turn] != -inf && turn == 1)
                {
                        dp[i][turn] = min(dp[i][turn], dp[i-a[j]][1-turn]);
                }
            }
        }
    }

    // dbg(dp);

    cout << dp[n][0]<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}