#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
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
    int n;
    cin>>n;

    int m;
    cin>>m;

    dsu d(n);

    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        d.union_set(u,v);
    }

    map<pair<int,int>,int> tarvert;

    int k;
    cin>>k;

    for(int i =0;i<k;i++)
    {
        int u,v;
        cin>>u>>v;

        int x = d.find_parent(u);
        int y = d.find_parent(v);
        tarvert[{x,y}]++;
        tarvert[{y,x}]++;
    }
    int Q;
    cin>>Q;
    for(int i =0;i<Q;i++)
    {
        int p,q;
        cin>>p>>q;

        int u = d.find_parent(p);
        int v = d.find_parent(q);
        if(tarvert.find({u,v}) != tarvert.end())
        {
            cout << "No"<<nl;
        }
        else
        {
            cout <<"Yes"<<nl;
        }
    }
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}