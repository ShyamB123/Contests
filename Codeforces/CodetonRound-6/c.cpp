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


class maxsegtree
{
    vector<int> tree;
    int n;

public:
    maxsegtree(int length)
    {
        this->n = length;
    }

    void build(vi &a)
    {
        while (__builtin_popcount(n) > 1)
        {
            n++;
            a.pb(-1);
        }

        tree.resize(2 * n);

        for (int i = n; i < 2 * n; i++)
        {
            tree[i] = a[i - n];
        }

        // update middle nodes

        for (int i = n - 1; i >= 1; i--)
        {
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(int index, int value)
    {
        index = index + n;
        if(tree[index] == value)
            tree[index] = -1;

        index /= 2;

        while (index >= 1)
        {
            tree[index] = max(tree[2 * index], tree[2 * index + 1]);
            index /= 2;
        }
    }

    int get(int indx, int left, int right, int low, int high)
    {
        if (left <= low && high <= right)
        {
            return tree[indx];
        }
        if (left > high || right < low)
        {
            return -1;
        }

        int mid = (low + high) / 2;

        return max(get(2 * indx, left, right, low, mid), get(2 * indx + 1, left, right, mid + 1, high));
    }
    vi get_tree()
    {
        return tree;
    }
    int get_nodes()
    {
        return n;
    }
};

class minsegtree
{
    vector<int> tree;
    int n;

public:
    minsegtree(int length)
    {
        this->n = length;
    }

    void build(vi &a)
    {
        while (__builtin_popcount(n) > 1)
        {
            n++;
            a.pb(INT_MAX);
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

    void update(int index, int value)
    {
        index = index + n;
        if(tree[index] == INT_MAX)
            tree[index] = value;

        index /= 2;

        while (index >= 1)
        {
            tree[index] = min( tree[2 * index], tree[2 * index + 1]);
            index /= 2;
        }
    }

    int get(int indx, int left, int right, int low, int high)
    {
        if (left <= low && high <= right)
        {
            return tree[indx];
        }
        if (left > high || right < low)
        {
            return INT_MAX;
        }

        int mid = (low + high) / 2;

        return min( get(2 * indx, left, right, low, mid), get(2 * indx + 1, left, right, mid + 1, high));
    }
    vi get_tree()
    {
        return tree;
    }
    int get_nodes()
    {
        return n;
    }
};


void solve()
{
    ll n,k;
    cin>>n>>k;

    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    // ll left[k + 1] = {n + 1};
    vi left(k + 1,INT_MAX);
    vi right(k + 1,0);

    minsegtree l(k + 1);

    vi temp(k + 1,INT_MAX);
    l.build(temp);

    int nodes = l.get_nodes();

    maxsegtree r(k + 1);

    vi temp2(k + 1,0);

    for(int i =0;i<n;i++)
    {
        temp2[a[i]] = i;
    }
    r.build(temp2);


    for(int i =0;i<n;i++)
    {
        int num = a[i];

        int lr = l.get(1,num,nodes -1,0,nodes - 1);
        int rh = r.get(1,num,nodes - 1,0,nodes -1);

        if(lr == INT_MAX)
        {
            left[num] =i;
        }
        if(rh == -1)
        {
            right[num] = i ;
        }

        left[num] = min(left[num],lr);
        right[num] = max(right[num],rh);

        l.update(num,i);
        r.update(num,0);

        // dbg(lr);
        // dbg(rh);

        // dbg(l.get_tree());
        // dbg(r.get_tree());
    }

    // dbg(left);
    // dbg(right);

    for(ll i = 1;i<=k;i++)
    {
        if(left[i] == INT_MAX)
        {
            cout << 0 <<' ';
        }
        else
            cout << 2 * (right[i] - left[i] + 1)<< " ";
    }
    cout <<nl;
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