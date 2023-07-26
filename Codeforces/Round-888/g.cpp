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

class dsu
{
    int V;
    vector<int> rank;
    vector<int> parent;

public:
    dsu(int vertices)
    {
        this->V = vertices;
        rank = vector<int>(vertices + 1, 1);
        parent = vector<int>(vertices + 1, 0);

        for (int i = 1; i <= vertices; i++)
        {
            parent[i] = i;
        }
    }

    int find_parent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find_parent(parent[node]);
    }
    void union_set(int a, int b)
    {
        int u = find_parent(a);
        int v = find_parent(b);

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

    vector<int> get_parent()
    {
        return parent;
    }
    vector<int> get_rank()
    {
        return rank;
    }
};

void solve()
{
    ll n,m;
    cin>>n>>m;

    vll h(n);
    for(ll i=0;i<n;i++)
    {
        cin>>h[i].F;
        h[i].S = i;
    }

    vii edges;
    vector<vi> adj(n);
    // map<


    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;

        adj[x].pb(y);
        adj[y].pb(x);
        edges.pb({x,y});
    }

    vector<vl> query;

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        vl v;

        ll maxh = h[a].F + c;
        v.pb(maxh);
        v.pb(a);
        v.pb(b);
        v.pb(c);
        v.pb(i);
        query.pb(v);
    }

    sort(all(h));
    sort(all(query));

    
    bool vertices[n] = {false};
    dsu d(n);   

    int j =0;

    vector<bool> ans(q);

    for(int i=0;i<q;i++)
    {
        set<int>newvertices;
        vl v = query[i];
        ll maxh = v[0];
        ll a = v[1];
        ll b = v[2];
        ll e = v[3];
        ll indx = v[4];

        while(j < n && h[j].F <= maxh)
        {
            newvertices.insert(h[j].S);
            // vertices.insert(h[j].S);
            vertices[h[j].S] = true;
            j++;
        }

        for(auto it : newvertices)
        {
            for(auto k : adj[it])
            {
                if(vertices[k] == true)
                {
                    int u = d.find_parent(k);
                    int v = d.find_parent(it);

                    if(u != v)
                    {
                        d.union_set(u,v);
                    }
                }
            }
        }

        if(d.find_parent(a) == d.find_parent(b))
        {
            ans[indx] = true;
        }
        else
        {
            ans[indx] = false;
        }
    }

    for(int i =0;i<q;i++)
    {
        if(ans[i])
        {
            cout <<"YES"<<nl;
        }
        else
        {
            cout <<"NO"<<nl;
        }
    }
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