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

class lazysegtree
{
    vector<ll> tree;
    vector<ll> lazy;
    ll n;

    public:
    lazysegtree(ll length)
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
        lazy.resize(2 * n);

        for (ll i = n; i < 2 * n; i++)
        {
            tree[i] = a[i - n];
        }

        // update middle nodes

        for (ll i = n - 1; i >= 1; i--)
        {
            tree[i] = tree[2 * i] +  tree[2 * i + 1];
        }
    }

    

    void push(ll indx,ll val)
    {

        lazy[indx * 2] += val;
        lazy[indx * 2 + 1] += val;
    }

    void rangeupdate(ll indx,ll left,ll right,ll low,ll high,ll value)
    {
        if(lazy[indx] != 0)
        {
            tree[indx] += (high - low + 1) * lazy[indx];

            if(low != high)
            {
                // push down
                push(indx,lazy[indx]);
            }

            lazy[indx] = 0;
        }

        if(high < left || low > right)
        {
            return;
        }

        if(left <= low && right >= high)
        {
            // you can update here
            tree[indx] += (high - low + 1) * value;

            if(low != high)
                push(indx,value);
        }
        else
        {
            ll mid = (low + high)/2;
            rangeupdate(2 * indx,left,right,low,mid,value);
            rangeupdate(2 * indx + 1,left,right,mid + 1,high,value);

            tree[indx] = tree[indx * 2] + tree[indx * 2 + 1];
        }
    }

    ll rangeget(ll indx, ll left, ll right, ll low, ll high)
    {
        if(lazy[indx] != 0)
        {
            tree[indx] += (high - low + 1) * lazy[indx];

            if(low != high)
            {
                // push down
                push(indx,lazy[indx]);
            }

            lazy[indx] = 0;
        }
        if (left <= low && high <= right)
        {
            return tree[indx];
        }
        if (left > high || right < low)
        {
            return 0;
        }

        ll mid = (low + high) / 2;

        return rangeget(2 * indx, left, right, low, mid) + rangeget(2 * indx + 1, left, right, mid + 1, high);
    }
    vl get_tree()
    {
        return tree;
    }
    vl get_lazy()
    {
        return lazy;
    }
    ll get_nodes()
    {
        return n;
    }
};

void solve()
{
    ll n,m,q;
    cin>>n>>m>>q;

    vector<vl> a;

    vector<vll> rows(n);

    for(ll i= 0;i<n;i++)
    {
        rows[i].pb({-1,0});
    }

    map<ll,vl> thirdq;
    map<ll,ll> revthirdq;

    for(ll i =0;i<q;i++)
    {
        ll ch;
        cin>>ch;

        vl v;
        v.pb(ch);

        if(ch == 1)
        {
            ll l,r,x;
            cin>>l>>r>>x;
            l--;
            r--;
            v.pb(l);
            v.pb(r);
            v.pb(x);
        }
        else if(ch == 2)
        {
            ll row,x;
            cin>>row>>x;
            row--;
            v.pb(row);
            v.pb(x);
            rows[row].pb({i,x});
        }
        else
        {
            ll row,col;
            cin>>row>>col;
            row--;
            col--;

            v.pb(row);
            v.pb(col);

            auto p = rows[row].back();
            thirdq[p.F].pb(i);
            revthirdq[i] = p.F;
        }
        a.pb(v);
    }
    // dbg("here");

    lazysegtree lz(m);

    vl temp(m,0);
    lz.build(temp);

    ll nodes = lz.get_nodes();
    map<pair<ll,ll>,ll> store;
    vl ans;

    for(ll qr = 0;qr < q;qr++)
    {
        ll ch = a[qr][0];

        if(ch == 1)
        {
            lz.rangeupdate(1,a[qr][1],a[qr][2],0,nodes - 1,a[qr][3]);
        }
        else if(ch == 2)
        {
            for(auto it : thirdq[qr])
            {
                // get the j of this 3rd query
                store[{qr,it}] = lz.rangeget(1,a[it][2],a[it][2],0, nodes -1);
            }
        }
        else
        {
            ll curj = lz.rangeget(1,a[qr][2],a[qr][2],0, nodes -1);
            ll prev = revthirdq[qr];
            ll segj = curj - store[{prev,qr}];
            if(prev >= 0)
            {
                ans.pb(segj + a[prev][2]);
            }
            else
            {
                ans.pb(segj);
            }
            // cout << ans.back()<<endl;
        }
    }

    for(auto it : ans)
    {
        cout << it << nl;
    }
    // cout << nl;


}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}