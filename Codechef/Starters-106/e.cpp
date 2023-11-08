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



void solve()
{
    ll n,m;
    cin>>n>>m;

    vector<vi> adj(n + 1);

    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<vector<bool>> visited(n + 1,vector<bool>(2,false));
    vector<vl> dp(n + 1,vl(2,inf));
    queue<pair<ll,ll>> q;

    q.push({1,0});
    visited[1][0] = true;
    dp[1][0] = 0;
    while(!q.empty())
    {
        auto el = q.front();
        q.pop();

        ll src = el.F;
        ll par = el.S;


        for(auto it : adj[src])
        {
            if(visited[it][1 - par] == false)
            {
                dp[it][1 - par] = dp[src][par] + 1;
                visited[it][1 - par] = true;
                q.push({it,1 - par});
            }
        }
    }

    bool caneven = true;
    ll evenmax = 0;

    bool canodd = true;
    ll oddmax = 0;

    // dbg(dp);


    for(ll i = 1;i<=n;i++)
    {
        if(dp[i][0] == inf)
        {
            caneven = false;
        }
        if(dp[i][1] == inf)
        {
            canodd = false;
        }

        evenmax = max(evenmax,dp[i][0]);

        oddmax = max(oddmax,dp[i][1]);
    }

    ll ans = inf;

    if(caneven)
    {
        ans = min(ans,evenmax);
    }
    if(canodd)
    {
        ans = min(ans,oddmax);
    }

    if(ans == inf)
    {
        cout << -1 <<nl;
    }
    else
    {
        cout << ans <<nl;
    }

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