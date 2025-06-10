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

class dsu
{
public:
    ll V;
    vector<ll> rank;
    vector<ll> parent;
    vector<ll> minel;

    dsu(ll vertices)
    {
        this->V = vertices;
        rank = vector<ll>(vertices + 1, 1);
        parent = vector<ll>(vertices + 1, 0);
        minel = vector<ll>(vertices + 1, 0);

        for (ll i = 0; i <= vertices; i++)
        {
            parent[i] = i;
            minel[i] = inf;
        }
    }

    ll find_parent(ll node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find_parent(parent[node]);
    }
    void union_set(ll a, ll b,ll wt)
    {
        ll u = find_parent(a);
        ll v = find_parent(b);
        // dbg(wt)

        if (u != v)
        {
            if (rank[u] < rank[v])
            {
                parent[u] = v;
                rank[v] += rank[u];
                minel[v] = min({minel[v],minel[u],wt});
            }
            else
            {
                parent[v] = u;
                rank[u] += rank[v];
                minel[u] = min({minel[v],minel[u],wt});
            }
        }
    }

    vector<ll> get_parent()
    {
        return parent;
    }
    vector<ll> get_rank()
    {
        return rank;
    }
};

void solve()
{
    ll n,m;
    cin>>n>>m;

    vector<vl> edges;
    for(int i =0;i<m;i++)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;
        u--;
        v--;

        edges.pb({wt,u,v});
    }
    sort(all(edges));
    // reverse(all(edges));

    dsu d(n);
    ll ans = inf;
    // dbg(edges)
    for(int i =0;i<m;i++)
    {
        ll wt = edges[i][0];
        ll u = edges[i][1];
        ll v = edges[i][2];
        d.union_set(u,v,wt);

        // for(int j =0;j<n;j++)
        // {
        //     dbg(j)
        //     dbg(d.find_parent(j))
        //     // dbg(d.minel[d.find_parent(j)])
        // }
        // dbg(d.minel)

        if(d.find_parent(0) == d.find_parent(n - 1))
        {
            // they are in the same component

            ll here = d.minel[d.find_parent(0)];
            // dbg(here)
            ans = min(ans,wt + here);
        }

    }

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