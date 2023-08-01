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
const int N = 2e5 + 1;
vector<vi> adj(N);
vector<vii> q(N);
int qr;
vi ans(N,-1);
int l,r;
vi dist(N,1e9);

vi path;

void dfs1(int src,int par)
{
    for(auto it : adj[src])
    {
        if(it != par)
        {
            dist[it] = min(dist[it],dist[src] + 1);
            dfs1(it,src);
        }
    }
}

void dfs2(int src,int par)
{
    path.pb(src);

    for(auto it : q[src])
    {
        if(it.F <= path.size() - 1)
        {
            int indx = path.size() - it.F - 1;
            ans[it.S] = path[indx];
            // dbg(path);
            // dbg(ans[it.S]);
            bool ok = false;
        }
    }

    for(auto it : adj[src])
    {
        if(it != par)
        {
            dfs2(it,src);
        }
    }
    path.pop_back();
}

void solve()
{
    int n;
    cin>>n;

    for(int i =0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    
    cin>>qr;

    for(int i =0;i<qr;i++)
    {
        int u,k;
        cin>>u>>k;

        q[u].pb({k,i});
    }

    dist[1] = 0;

    dfs1(1,1);

    int val = 0;

    for(int i=1;i<=n;i++)
    {
        // cout << dist[i] <<" ";
        if(dist[i] > val)
        {
            l = i;
            val = dist[i];
        }
    }
    // cout <<nl;

    // dist.resize(n + 1,1e9);
    for(int i=1;i<=n;i++)
    {
        dist[i] = 1e9;
    }
    dist[l] = 0;

    dfs1(l,l);

    val = 0;

    for(int i=1;i<=n;i++)
    {
        // cout << dist[i] <<" ";
        if(dist[i] > val)
        {
            r = i;
            val = dist[i];
        }
    }
    // cout <<nl;

    // dbg(l);dbg(r);

    dfs2(l,l);
    dfs2(r,r);

    for(int i=0;i<qr;i++)
    {
        cout << ans[i]<<nl;
    }
    // cout <<nl;




}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}