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
    vector<int> tree;
    int n;

public:
    segtree(int length)
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
            tree[i] = min(tree[2 * i],tree[2 * i + 1]);
        }
    }

    void update(int index, int value)
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

        return min(get(2 * indx, left, right, low, mid), get(2 * indx + 1, left, right, mid + 1, high));
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
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
    }

    vector<vector<int>> dp(n + 1,vector<int>(2,INT_MAX));

    dp[0][0] = 1;
    dp[0][1] = 1;
    


    segtree sga(n);
    segtree sgb(n);

    vi temp(n,INT_MAX);

    sga.build(temp);
    sgb.build(temp);

    int nodes = sga.get_nodes();

    sga.update(a[0],1);
    sgb.update(a[0],1);

    for(int i=1 ;i<n;i++)
    {
        // if its alices turn 
        // dbg(sgb.get_tree());
        int vala = sgb.get(1,0,a[i] - 1,0,nodes-1);
        if(vala == 1)
        {
            dp[i][0] = 0;
        }
        else if(vala == INT_MAX)
        {
            dp[i][0] = 1;
        }
        else
        {
            dp[i][0] = 1;
        }

        sga.update(a[i],dp[i][0]);
        // dbg(sga.get_tree());


        // bobs turn
        int valb = sga.get(1,0,a[i] - 1,0,nodes-1);
        if(valb == 1)
        {
            dp[i][1] = 0;
        }
        else if(valb == INT_MAX)
        {
            dp[i][1] = 1;
        }
        else
        {
            dp[i][1] = 1;
        }
        sgb.update(a[i],dp[i][1]);
        // dbg(sgb.get_tree());

    }
    int ans =0;
    for(int i=1;i<n;i++)
    {
        if(dp[i][1] == 0)
        {
            ans++;
        }
    }
    cout << ans<<nl;
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