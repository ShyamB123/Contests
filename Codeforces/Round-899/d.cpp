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
#define vull vector<ull>


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

const ll N = 2e5 + 10;
vector<vl> adj(N);
vector<ll> a(N + 1);
vector<ll> dp(N,0);
vl subtree(N,0);
vl ans(N,0);
ll n;

ll calsubtree(ll src,ll par)
{
    ll cur =1;

    for(auto it : adj[src])
    {
        if(it != par)
        {
            cur += calsubtree(it,src);
        }
    }

    return subtree[src] = cur;
}

void dfs(ll src,ll par)
{
    ll tar = a[src];

    ll ans =0 ;

    for(auto it : adj[src])
    {
        if(it != par)
        {
            dfs(it,src);
            ans += (tar ^ (a[it])) * subtree[it] + dp[it];
        }
    }

    dp[src] = ans;
}

void dfs2(ll src,ll par)
{
    ans[src] = dp[src];
    // for(int i = 1;i<=n;i++)
    // {
    //     cout << dp[i]<<" ";
    // }
    // cout <<nl;
    for(auto it : adj[src])
    {
        if(it != par)
        {
            ll parsize = subtree[src];
            ll childsize = subtree[it];

            ll oldpar = dp[src];
            ll oldchild = dp[it];

            dp[it] += (a[it] ^ a[src]) * (parsize - childsize) + (oldpar - oldchild - (a[it] ^ a[src]) * (childsize));
            dp[src] -= oldchild + (a[it] ^ a[src]) * (childsize);

            subtree[it] += parsize - childsize;
            subtree[src] -= childsize;

            dfs2(it,src);

            dp[it] = oldchild;
            dp[src] = oldpar;

            subtree[src] = parsize;
            subtree[it] = childsize;
        }
    }
}


void solve()
{

    cin>>n;

    for(ll i =0;i<=n;i++)
    {
        adj[i].clear();
        ans[i] = 0;
    }

    dp.clear();
    ans.clear();
    subtree.clear();
    a.clear();


    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }


    calsubtree(1,1);

    dfs(1,1);

    

    dfs2(1,1);


    for(ll i = 1;i<=n;i++)
    {
        cout << ans[i]<<" ";
    }
    cout <<nl;
    

// for(ll i =0;i<=n;i++)
//     {
//         adj[i].clear();
//         dp[i].clear();
//     }

//     ans.clear();
//     subtree.clear();
//     a.clear();


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