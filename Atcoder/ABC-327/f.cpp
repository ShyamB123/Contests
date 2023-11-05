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
    vector<int> tree;
    vector<int> lazy;
    int n;

    public:
    lazysegtree(int length)
    {
        this->n = length;
    }

    void build(vi &a)
    {
        while (__builtin_popcount(n) > 1)
        {
            n++;
            a.pb(0);
        }

        tree.resize(2 * n);
        lazy.resize(2 * n);

        for (int i = n; i < 2 * n; i++)
        {
            tree[i] = a[i - n];
        }

        // update middle nodes

        for (int i = n - 1; i >= 1; i--)
        {
            tree[i] = max(tree[2 * i] , tree[2 * i + 1]);
        }
    }

    

    void push(int indx,int val)
    {

        lazy[indx * 2] += val;
        lazy[indx * 2 + 1] += val;
    }

    void rangeupdate(int indx,int left,int right,int low,int high,int value)
    {
        if(lazy[indx] != 0)
        {
            tree[indx] +=  lazy[indx];

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
            tree[indx] +=  value;

            if(low != high)
                push(indx,value);
        }
        else
        {
            int mid = (low + high)/2;
            rangeupdate(2 * indx,left,right,low,mid,value);
            rangeupdate(2 * indx + 1,left,right,mid + 1,high,value);

            tree[indx] = max(tree[indx * 2],tree[indx * 2 + 1]);
        }
    }

    int rangeget(int indx, int left, int right, int low, int high)
    {
        if(lazy[indx] != 0)
        {
            tree[indx] += lazy[indx];

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

        int mid = (low + high) / 2;

        return max(rangeget(2 * indx, left, right, low, mid),rangeget(2 * indx + 1, left, right, mid + 1, high));
    }
    vi get_tree()
    {
        return tree;
    }
    vi get_lazy()
    {
        return lazy;
    }
    int get_nodes()
    {
        return n;
    }
};

void solve()
{
    int n,d,w;
    cin>>n>>d>>w;

    vii a;

    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;

        a.pb({u,v});
    }

    sort(all(a));


    const int N = 4e5 + 10; 

    lazysegtree lz(N);

    vi temp(N,0);
    lz.build(temp);

    int nodes = lz.get_nodes();
    int j = 0;
    int ans = 0;

    // dbg(a);
    for(int i = 0;i<n;i++)
    {
        // dbg("here1");
        lz.rangeupdate(1,a[i].S,a[i].S + w-1,0,nodes - 1,1);
        // dbg("here2");

        while(j < i && a[j].F + d <= a[i].F)
        {
            lz.rangeupdate(1,a[j].S,a[j].S + w-1,0,nodes - 1,-1);
            j++;
        }
        // dbg("here3");


        int curans = lz.rangeget(1,a[i].S,a[i].S + w-1,0,nodes -1);
        // dbg("here4");

        ans = max(ans,curans);
        // dbg(curans);

        // for(int i=0;i<=15;i++)
        // {
        //     cout << lz.rangeget(1,i,i,0,nodes-1)<< " ";
        // }
        // cout <<nl;

    }
    cout << ans <<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}