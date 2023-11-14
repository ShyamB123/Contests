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
bool rev[N] = {false};


class dsu
{
public:

    ll V;
    vector<ll> rank;
    vector<ll> parent;
    vector<ll> dist;

    dsu(ll vertices)
    {
        this->V = vertices;
        rank = vector<ll>(vertices + 1, 1);
        parent = vector<ll>(vertices + 1, 0);
        dist = vector<ll>(vertices + 1,0);

        for (ll i = 1; i <= vertices; i++)
        {
            parent[i] = i;
        }
    }

    pair<ll,ll> find_parent(ll node)
    {
        if (node == parent[node])
            return {node,0};
        auto par = find_parent(parent[node]);
        parent[node] = par.F;
        dist[node] += par.S;

        return {parent[node],dist[node]};
    }

    
    void union_set(ll a, ll b,ll wt)
    {
        ll u = find_parent(a).F;
        ll v = find_parent(b).F;

        if (u != v)
        {
            if (rank[u] < rank[v])
            {
                parent[u] = v;
                dist[u] += -wt;
                rank[v] += rank[u];

            }
            else
            {
                parent[v] = u;
                dist[v] += wt;
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
};


void solve()
{
    ll n,q;
    cin>>n>>q;


    dsu d(n);

    vi ans;
    for(ll i =0;i<q;i++)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;
        u--;
        v--;

        ll upar = d.find_parent(u).F;
        ll vpar = d.find_parent(v).F;
        ll udist = d.find_parent(u).S;
        ll vdist = d.find_parent(v).S;

        
        if(upar == vpar)
        {
            // cout << udist<<" "<<vdist<<nl;
            if(udist - vdist == wt)
            {   
                ans.pb(i + 1);
            }
        }
        else
        {
            // z + wt + vdist = u
            ll z = udist - vdist - wt;
            d.union_set(upar,vpar,z);
            ans.pb(i + 1);
        }
    }
    for(auto it : ans)
    {
        cout << it << " ";
    }
    cout <<nl;


}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}