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
int n,m,e;
int ans = 0;
class dsu
{
    public:
    int V;
    vector<int> rank;
    vector<int> parent;


    dsu(int vertices)
    {
        this->V = vertices;
        rank = vector<int>(vertices + 1, 0);
        parent = vector<int>(vertices + 1, 0);

        for (int i = 1; i <= vertices; i++)
        {
            parent[i] = i;
        }
        for(int i = 1;i<=n;i++)
        {
            rank[i] = 1;
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
    
    cin>>n>>m>>e;

    vii edge;

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;

        edge.pb({u,v});
    }

    int qr;
    cin>>qr;
    vi query;
    set<int> s;

    for(int i=0;i<qr;i++)
    {
        int x;
        cin>>x;
        x--;
        s.insert(x);
        query.pb(x);
    }

    // vector<vi> adj(n + m + 1,0);
    dsu d(n + m);

    bool iselec[n + m + 1] = {false};
    for(int i = n + 1;i<=n + m;i++)
    {
        iselec[i] = true;
    }

    

    for(int i=0;i<e;i++)
    {
        if(s.find(i) == s.end())
        {
            int u = d.find_parent(edge[i].F);
            int v = d.find_parent(edge[i].S);
            if(iselec[v] == true || iselec[u] == true)
            {
                if(iselec[u] == false)
                {
                    ans += d.rank[u];
                }
                if(iselec[v] == false)
                {
                    ans += d.rank[v];
                }
                iselec[v] = true;
                iselec[u] = true;
            }
            d.union_set(u,v);
            // dbg(d.rank);
            // for(int i = 0;i<=n + m;i++)
            // {
            //     cout << (iselec[i] == true ? 1 : 0)<<" ";
            // }
            // cout <<endl;
            bool useless = true;
        }
    }

    vi op;
    for(int i = qr - 1;i>=0;i--)
    {
        op.pb(ans);
        int x = query[i];
        int u = d.find_parent(edge[x].F);
        int v = d.find_parent(edge[x].S);
        if(iselec[v] == true || iselec[u] == true)
        {
            if(iselec[u] == false)
            {
                ans += d.rank[u];
            }
            if(iselec[v] == false)
            {
                ans += d.rank[v];
            }
            iselec[v] = true;
            iselec[u] = true;
        }
        d.union_set(u,v);
        
    }

    reverse(all(op));

    for(auto it : op)
    {
        cout << it <<nl;
    }
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}