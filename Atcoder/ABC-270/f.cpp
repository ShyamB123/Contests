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


bool compare(vl p1, vl p2)
{
    return p1[2] < p2[2];
}

/*
4 2
1 3 1 1
3 2 1 2
1 2 2
3 4 1
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

    ll x[n + 1];
    ll y[n + 1];

    vector<vl> edge;

    ll minair = inf;
    ll minwater = inf;

    for(ll i =1;i<=n;i++)
    {
        cin>>x[i];
        vl v;
        v.pb(i);
        v.pb(n + 1);
        v.pb(x[i]);
        edge.pb(v);
        minair = min(minair,x[i]);
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>y[i];
        vl v;
        v.pb(i);
        v.pb(n + 2);
        v.pb(y[i]);
        edge.pb(v);
        minwater = min(minwater,y[i]);
    }

    n+= 2;
    for(ll i=0;i<m;i++)
    {
        ll u,t,wt;
        cin>>u>>t>>wt;
        vl v;
        v.pb(u);
        v.pb(t);
        v.pb(wt);
        edge.pb(v);
    }

    sort(all(edge),compare);

    
    ll ans =inf;

    ll air =0;
    ll water = 0;

    for(ll i =0;i<4;i++)
    {
        dsu d(n);
        ll curans =0;
        for(auto it : edge)
        {
            vl s = it;
            

            ll elu = s[0];
            ll elv = s[1];
            ll u = d.find_parent(s[0]);
            ll v = d.find_parent(s[1]);
            ll wt = s[2];
            if(i == 0 && elv == n-1)
            {
                continue;
            }
            
            if(i == 1 && elv == n)
            {
                continue;
            }
            if(i == 2 && (elv == n-1 || elv == n))
            {
                continue;
            }

            if(u != v)
            {
                d.union_set(u,v);
                curans += wt;
            }
        }
        vi temp = d.get_rank();
        if(i == 0 && temp[d.find_parent(1)]<n-1)
        {
            continue;
        }
        else if(i == 1 && temp[d.find_parent(1)]<n-1)
        {
            continue;
        }
        else if(i == 2 && temp[d.find_parent(1)] < n-2)
        {
            continue;
        }
        else
        {
            ans = min(curans,ans);
        }
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