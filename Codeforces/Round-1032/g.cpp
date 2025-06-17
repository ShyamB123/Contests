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

    string s;
    cin>>s;

    vl a;
    for(ll i =0;i<n;i++)
    {
        if(s[i] == '0')
        {
            a.pb(-1);
        }
        else
        {
            a.pb(1);
        }
    }

    set<ll> st;
    st.insert(0);
    vl pre(n + 1,0);

    for(ll i =0;i<n;i++)
    {
        pre[i + 1] = pre[i] + a[i];
        st.insert(pre[i + 1]);
    }

    map<ll,ll> m;
    ll cur = 0;

    for(auto it : st)
    {
        m[it] = cur;
        cur++;
    }

    ll ans =0 ;

    {
        // this is when one is maximum
        segtree sg1(cur);
        segtree sg2(cur);

        vl temp1(cur,0);
        vl temp2(cur,0);
        sg1.build(temp1);
        sg2.build(temp2);

        sg1.update(m[0],1);
        sg2.update(m[0],-1);

        ll nodes = sg1.get_nodes();

        for(ll i =0;i<n;i++)
        {
            ll here = pre[i + 1];

            // we need it to be smaller 
            // so from 0 -> m[here]

            ll elem = sg1.get(1,0,m[here],0,nodes - 1);
            ll val = sg2.get(1,0,m[here],0,nodes - 1);



            ll hereans = elem * (here + i) - val;
            // dbg(i)
            // dbg(elem)
            // dbg(val)
            // dbg(hereans)

            ans += hereans/2;

            sg1.update(m[pre[i + 1]],1);
            sg2.update(m[pre[i + 1]],pre[i + 1] + i);
        }
    }

    {
        // this is when zero is maximum
        segtree sg1(cur);
        segtree sg2(cur);

        vl temp1(cur,0);
        vl temp2(cur,0);
        sg1.build(temp1);
        sg2.build(temp2);

        sg1.update(m[0],1);
        sg2.update(m[0],1);

        ll nodes = sg1.get_nodes();

        for(ll i =0;i<n;i++)
        {
            ll here = pre[i + 1];

            // we need it to be bigger 
            // so from m[here] + 1
            
            if(m[here] + 1 <= cur - 1)
            {
                ll elem = sg1.get(1,m[here] + 1,cur - 1,0,nodes - 1);
                ll val = sg2.get(1,m[here] + 1,cur - 1,0,nodes - 1);

                ll hereans = val - elem * (here - i);
                ans += hereans/2;
            }
            sg1.update(m[pre[i + 1]],1);
            sg2.update(m[pre[i + 1]],pre[i + 1] - i);
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