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
    vector<double> tree;
    int n;

public:
    segtree(int length)
    {
        this->n = length;
    }

    void build(vector<double> &a)
    {
        while (__builtin_popcount(n) > 1)
        {
            n++;
            a.pb(inf);
        }

        tree.resize(2 * n);

        for (int i = n; i < 2 * n; i++)
        {
            tree[i] = a[i - n];
        }

        // update middle nodes

        for (int i = n - 1; i >= 1; i--)
        {
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(int index, double value)
    {
        index = index + n;
        tree[index] = value;

        index /= 2;

        while (index >= 1)
        {
            tree[index] = min(tree[2 * index], tree[2 * index + 1]);
            index /= 2;
        }
    }

    double get(int indx, int left, int right, int low, int high)
    {
        if (left <= low && high <= right)
        {
            return tree[indx];
        }
        if (left > high || right < low)
        {
            return inf;
        }

        int mid = (low + high) / 2;

        return min(get(2 * indx, left, right, low, mid), get(2 * indx + 1, left, right, mid + 1, high));
    }
    vector<double> get_tree()
    {
        return tree;
    }
    int get_nodes()
    {
        return n;
    }
};


double caldist(ll x1,ll x2,ll y1,ll y2)
{
    return sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
}

void solve()
{
    ll n,k;
    cin>>n>>k;

    ll sx,sy;
    cin>>sx>>sy;


    vll a;

    for(int i =0;i<n;i++){
        int u,v;
        cin>>u>>v;

        a.pb({u,v});
    }

    double totaldist = caldist(sx,a[0].F,sy,a[0].S) + caldist(sx,a[n - 1].F,sy,a[n - 1].S);

    for(int i = 1;i<n;i++)
    {
        totaldist += caldist(a[i].F,a[i - 1].F,a[i].S,a[i - 1].S);
    }

    segtree sg(n);

    vector<double> temp(n,inf);

    temp[n - 1] = 0;

    sg.build(temp);

    int nodes = sg.get_nodes();

    for(int i = n - 2;i>=0;i--)
    {
        // if u wanna build here

        double cost = caldist(sx,a[i].F,sy,a[i].S) + caldist(sx,a[i + 1].F,sy,a[i + 1].S) 
                    -caldist(a[i].F,a[i + 1].F,a[i].S,a[i + 1].S);

        // dbg(cost);
        int l = i + 1;
        int r = min(n,i + k);

        double ans =sg.get(1,l,r,0,nodes - 1) + cost;
        // dbg(ans);

        sg.update(i,ans);
    }

    // dbg(sg.get_tree());
    // dbg(totaldist);

    double finaladd = sg.get(1,0,k - 1,0,nodes - 1);
    // dbg(finaladd);

    totaldist += finaladd;

    cout << totaldist << nl;

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}