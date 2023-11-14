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

const ll N = 9;
vector<vl> adj(N);
vector<bool> visited(N,false);


int curlen =0;
void dfs(int src)
{
    curlen++;
    visited[src] = true;
    for(auto it : adj[src])
    {
        if(visited[it] == false)
        {
            dfs(it);
        }
    }
}

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;

    vector<vl> edge;
    for(ll i =0;i<m;i++)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;

        edge.pb({u,v,wt});

        // adj[u].pb({v,wt});
        // adj[v].pb({u,wt});
    }

    ll ans = inf;
    for(ll i =0;i<(1 << m);i++)
    {
        if(__builtin_popcount(i) == n - 1)
        {
            ll num = i;
            unordered_set<ll> s;
            ll cur = 0;
            for(int i =1;i<=n;i++)
            {
                adj[i].clear();
            }
            for(ll j = 0;j < m;j++)
            {
                if((num & (1 << j)) > 0)
                {
                    // s.insert(edge[j][0]);
                    // s.insert(edge[j][1]);
                    adj[edge[j][0]].pb(edge[j][1]);
                    adj[edge[j][1]].pb(edge[j][0]);
                    cur += edge[j][2];
                    cur %=k;
                }
            }

            curlen = 0;
            dfs(1);
            
            for(int i=1;i<=n;i++)
            {
                visited[i] = false;
                adj[i].clear();
            }

            
            // if(cur == 8648083103)
            // {
            //     ll c = 0;
            //     for(ll j = 0;j < m;j++)
            //     {
            //         if((num & (1 << j)) > 0)
            //         {
            //             // s.insert(edge[j][0]);
            //             // s.insert(edge[j][1]);
            //             dbg(edge[j]);
            //             // c += edge[j][2];
            //         }
            //     }
            // }
            if(curlen == n && ans > cur)
            {
                // cout << cur <<nl;
                // ans = min(ans,cur);
                ans = cur;
                // dbg(ans);
            }
        }
    }

    cout << ans <<nl;


    
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}