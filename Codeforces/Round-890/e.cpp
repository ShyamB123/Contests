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
const int N = 5001;
vector<vi> adj(N);
vl sz(N,0);


ll cal_subtree(int src)
{
    ll ans = 1;

    for(auto it : adj[src])
    {
        ans += cal_subtree(it);
    }

    return sz[src] = ans;
}

ll dfs(int src)
{
    vl v;
    for(auto it : adj[src])
    {
        v.pb(sz[it]);
    }

    vl pre(v.size() + 1,0);


    for(int i= 0;i<v.size();i++)
    {
        pre[i + 1] = pre[i] + v[i];
    }

    ll lim = pre[pre.size() - 1] + 1;
    vector<bool> dp(lim,false);
    dp[0] = true;
    ll sum = lim - 1;

    
    for(ll i =0;i<v.size();i++)
    {
        for(ll j = lim - 1;j >= 0;j--)
        {
            if(j - v[i] >= 0 && dp[j - v[i]] == true)
            {
                dp[j] = true;
            }
        }
    }
    ll ans = 0;

    for(int j = 0;j<lim;j++)
    {
        if(dp[j] == true)
        {
            ans = max(ans,j * (sum - j));
        }
    }

    for(auto it : adj[src])
    {
        ans += dfs(it);
    }
    // dbg(src);
    // dbg(v);
    // dbg(pre);

    return ans;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].pb(i);
    }

    ll useless = cal_subtree(1);

    ll ans = dfs(1);
    cout << ans << nl;


    
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}