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
        tree[index] += value;

        index /= 2;

        while (index >= 1)
        {
            tree[index] =  tree[2 * index]+  tree[2 * index + 1];
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
    ll n,r;
    cin>>n>>r;

    vll a;

    set<ll> s;
    vector<ll> ones;
    vector<ll> ms;
    for(ll i =0;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        a.pb({u,v});
        s.insert(u);
        s.insert(v);

        if(u == 1)
        {
            ones.pb(v);
        }
        if(v == r)
        {
            ms.pb(u);
        }
    }

    sort(all(ones));
    sort(all(ms));


    map<ll,ll> m;

    ll cur =0;
    for(auto it : s)
    {
        m[it] = cur++;
    }

   

    segtree sg(cur);

    vl temp(cur,0);
    sg.build(temp);

    ll nodes = sg.get_nodes();

    sort(all(a),compare);
    // dbg(m);
        // dbg(a);
    for(ll i=0;i<n;i++)
    {
        // dbg(m[a[i].F]);
        // dbg(a[i].F);
        sg.update(m[a[i].F],1);
    }

    // dbg(sg.get_tree());

    ll ans =0;
    for(ll i =0;i<n;i++)
    {
        

        ll overlap = sg.get(1,0,m[a[i].S],0,nodes - 1);
        // dbg(overlap);
        sg.update(m[a[i].F],-1);

        ll takeones = lower_bound(all(ones),a[i].S) - ones.begin();

        takeones = ones.size() - takeones;

        ll takems = upper_bound(all(ms),a[i].S) - ms.begin();


        ll curans = overlap - min(takems,takeones);

        ans = max(ans,curans);
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