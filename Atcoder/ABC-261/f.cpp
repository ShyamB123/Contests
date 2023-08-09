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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

class segtree
{
    vector<ll> tree;
    ll n;

public:
    segtree(ll length)
    {
        this->n = length;
    }

    void build(vl &a)
    {
        while (__builtin_popcount(n) > 1)
        {
            n++;
            a.pb(0);
        }

        tree.resize(2 * n);

        for (ll i = n; i < 2 * n; i++)
        {
            tree[i] = a[i - n];
        }

        // update middle nodes

        for (ll i = n - 1; i >= 1; i--)
        {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    void update(ll index, ll value)
    {
        index = index + n;
        tree[index] = value;

        index /= 2;

        while (index >= 1)
        {
            tree[index] = tree[2 * index] + tree[2 * index + 1];
            index /= 2;
        }
    }

    ll get(ll indx, ll left, ll right, ll low, ll high)
    {
        if (left <= low && high <= right)
        {
            return tree[indx];
        }
        if (left > high || right < low)
        {
            return 0;
        }

        ll mid = (low + high) / 2;

        return get(2 * indx, left, right, low, mid) + get(2 * indx + 1, left, right, mid + 1, high);
    }
    vl get_tree()
    {
        return tree;
    }
    ll get_nodes()
    {
        return n;
    }
};


void solve()
{
    ll n;
    cin>>n;

    vector<vl> a(n);
    ll c[n];
    ll x[n];

    vl order;
    for(ll i =0;i<n;i++)
    {
        cin>>c[i];
    }

    for(ll i = 0;i<n;i++)
    {
        cin>>x[i];
        order.pb(x[i]);
    }
    vector<ordered_set> adj(n + 1);
    priority_queue<vl> pq;
    for(ll i =0;i<n;i++)
    {
        a[i] = {c[i],x[i],i};
        adj[c[i]].insert(i);
        vl temp = {x[i],i,c[i]};
        pq.push(temp);
    }

    ll op = 0;
    ll sz = n;

    segtree sg(n);

    vl temp(n,1);

    sg.build(temp);

    ll nodes = sg.get_nodes();

    while(!pq.empty())
    {
        auto el = pq.top();
        pq.pop();
        ll col = el[2];
        ll val = el[0];
        ll indx = el[1];

        ll cansave = adj[col].size() - adj[col].order_of_key(indx + 1);
        ll rightel = sg.get(1,indx + 1,nodes - 1,0,nodes - 1);

        op += ((ll)(rightel)) - cansave;

        adj[col].erase(indx);
        sg.update(indx,0);    
    }

    cout << op <<nl;
}


int main()
{   
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}