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


class dsu
{
    ll V;
    vector<ll> rank;
    vector<ll> parent;

public:
    dsu(ll vertices)
    {
        this->V = vertices;
        rank = vector<ll>(vertices + 1, 1);
        parent = vector<ll>(vertices + 1, 0);

        for (ll i = 1; i <= vertices; i++)
        {
            parent[i] = i;
        }
    }

    ll find_parent(ll node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find_parent(parent[node]);
    }
    void union_set(ll a, ll b)
    {
        ll u = find_parent(a);
        ll v = find_parent(b);

        if (u != v)
        {
            if (rank[u] < rank[v])
            {
                parent[u] = v;
                rank[v] += rank[u];
            }
            else
            {
                parent[v] = u;
                rank[u] += rank[v];
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
    ll get_size(ll src)
    {
        return rank[src];
    }
};

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


void solve()
{
    ll n,S;
    cin>>n>>S;

    vector<vi> edge;

    for(ll i=0;i<n-1;i++)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;

        vi temp;
        temp.pb(wt);
        temp.pb(u);
        temp.pb(v);
        edge.pb(temp);
    }

    sort(all(edge));

    dsu d(n);

    ll ans = 1;
    for(ll i=0;i<n-1;i++)
    {

        ll u = edge[i][1];
        ll v = edge[i][2];
        ll wt = edge[i][0];

        ll szu = d.get_size(d.find_parent(u));
        ll szv = d.get_size(d.find_parent(v));

        ans *= binexp(S - wt + 1,szu * szv - 1);
        ans %= mod;

        d.union_set(d.find_parent(u),d.find_parent(v));
        // dbg(binexp(S - wt + 1,szu * szv - 1))
        // dbg(szu)
        // dbg(szv)
        // dbg(ans);
    }

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