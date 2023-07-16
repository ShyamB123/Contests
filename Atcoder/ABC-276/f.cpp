#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 998244353
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
            tree[i] = (tree[2 * i] +  tree[2 * i + 1])%mod;
        }
    }

    void update(ll index, ll value)
    {
        index = index + n;
        tree[index] += value;
        tree[index]%=mod;

        index /= 2;

        while (index >= 1)
        {
            tree[index] =  (tree[2 * index] + tree[2 * index + 1])%mod;
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

        return  (get(2 * indx, left, right, low, mid) +  get(2 * indx + 1, left, right, mid + 1, high))%mod;
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

ll binexp1(ll a,ll b, ll m){
    ll result = 1;
    while(b){
        if(b&1){
            result = (result*a)%m;
        }
        a = (a*a)%m;
        b>>=1;
    }
    return result;
}

ll divmod (ll a,ll b, ll m){
    ll inv = binexp1(b,m-2,m);
    ll ans = ((a%m)*(inv%m))%m;
    return ans;
}

void solve()
{
    ll n;
    cin>>n;

    vl a(n);
    set<ll>b;

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        b.insert(a[i]);
    }

    // sort(all(b));


    map<ll,ll> indx;
    map<ll,ll> nodetoval;

    ll cur =0 ;

    for(auto it : b)
    {
        nodetoval[cur] = it;
        indx[it] = cur++;
    }

    vl temp(cur,0);

    segtree sg(cur),sum(cur);


    sg.build(temp);
    sum.build(temp);

    ll nodes = sg.get_nodes();
    
    ll ans = 0;

    // dbg(sg.get_tree());
    // dbg(sum.get_tree());

    for(ll i=0;i<n;i++)
    {
        ll num = a[i];
        ll ind = indx[num];
        

        ll x = sum.get(1,ind + 1,nodes -1,0,nodes -1);
        ll y = sg.get(1,0,ind,0,nodes - 1);

        
        sg.update(ind,1);
        sum.update(ind,num);

        ans =(ans + ( (2 * x)%mod + (num * 2 * y)%mod  + num) % mod) % mod;
        cout << divmod(ans%mod,((i + 1) * (i +1))%mod ,mod)<<nl;

        // dbg(ans);

        // dbg(sg.get_tree());
        // dbg(sum.get_tree());
    }
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}