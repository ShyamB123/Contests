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
    if(p1.F != p2.F)
    {
        return p1.F < p2.F;
    }
    return p1.second > p2.second;
}

/*
1
5 5 10
1 2 2 3 9
1 2
1 3
2 4
3 4
5 3
*/

const int N = 2e5 + 1;
vector<set<ll>> adj(N);
vector<set<ll>> radj(N);
map<pair<ll,ll>,ll> wt;
vl dp(N,-1);


ll dfs(int src)
{
    if(dp[src] != -1)
    {
        return dp[src];
    }

    ll ans =0;

    for(auto it : adj[src])
    {
        ans = max(ans,wt[{src,it}] + dfs(it));
    }

    return dp[src] = ans;
}

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;

    ll h[n + 1];

    for(ll i =1;i<=n;i++)
    {
        cin>>h[i];
    }

    


    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;

        ll weight = (h[v] - h[u] + k)%k;

        wt[{u,v}] = weight;
        adj[u].insert(v);
        radj[v].insert(u);
    }



    // dp.assign(-1);
    for(int i=0;i<=n;i++)
    {
        dp[i] = -1; 
    }
    vl start;
    for(ll i = 1;i<=n;i++)
    {
        if(radj[i].size() == 0)
        {
            start.pb(i);
            dfs(i);
        }
    }

    

    // dbg(comp);

    vector<pair<ll,ll>> v;
    multiset<ll> ms;
    map<ll,vll> compvert;

    for(auto it : start)
    {
        v.pb({h[it],dp[it] + h[it]});
        ms.insert(dp[it] + h[it]);
    }
    // dbg(compvert);
    // dbg(v);
    sort(all(v));

    ll ans = inf;
    ll low = -1;
    for(ll i=0;i<v.size();i++)
    {
        // starting from this node
        ll curans = 0;
        ll st = v[i].F;
        ll end = *ms.rbegin();
        if(low != -1)
        {
            end = max(end,low + k);
        }

        ans = min(ans,end - st);

        ms.erase(ms.find(v[i].S));
        low = max(low,v[i].S);
    }
    
    cout << ans <<nl;

    for(int i = 0;i<=n;i++)
    {
        adj[i].clear();
        radj[i].clear();
    }
    wt.clear();

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