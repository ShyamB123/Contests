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
const int N = 2e5 + 1;
vector<vl> adj(N);
vector<ll> depth(N);
ll pnt = 0;
ll pntpar = 0;

void dfs(int src,int par,ll lvl)
{
    ll child = 0;
    depth[src] = lvl;

    for(auto it : adj[src])
    {
        if(it != par)
        {
            dfs(it,src,lvl + 1);
            child++;
        }
    }

    if(child == 2)
    {
        pnt = src;
        pntpar = par;
    }
}

void solve()
{
    ll n;
    cin>>n;
    
    for(int i =0;i<n;i++)
    {
        adj[i].clear();
    }
    vl deg(n,0);
    for(int i =0;i<n - 1;i++)
    {
        int u,v;
        cin>>u>>v;

        u--;
        v--;

        adj[u].pb(v);
        adj[v].pb(u);

        deg[u]++;
        deg[v]++;
    }

    vl leaf;
    for(int i = 1;i<n;i++)
    {
        if(deg[i] == 1)
        {
            leaf.pb(i);
        }
    }

    if((int)leaf.size() > 2)
    {
        cout << 0 << nl;
        return;
    }
    else if((int)leaf.size() == 1)
    {
        cout << binexp(2,n) << nl;
        return;
    }

    // we have 2 leaves
    // find the break point

    dfs(0,0,0);

    ll ans = binexp(2,depth[pnt] + 1);

    ll x = depth[leaf[0]] - depth[pnt];
    ll y = depth[leaf[1]] - depth[pnt];
    ll add =0 ;

    if(x > y)
        swap(x,y);

    // take x as 1

    if(x == y)
    {
        add = 2;
    }
    else
    {
        add += binexp(2,y - x);
        add += binexp(2,y - x - 1);
        add %= mod;
    }

    ans *= add;

    ans %= mod;
    
    cout << ans << nl;


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