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
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/

const int N = 2e5 +1;
vi par(N,0);
vi sz(N,0);

int find_parent(int u)
{
    if(u == par[u])
    {
        return u;
    }
    return par[u] = find_parent(par[u]);
}

void merge(int x,int y)
{
    int u = find_parent(x);
    int v = find_parent(y);

    if(u != v)
    {
        if(sz[u] < sz[v])
        {
            par[u] = v;
            sz[v] += sz[u];
        }
        else
        {
            par[v] = u;
            sz[u] += sz[v];
        }

    }

}

void solve()
{
    ll n;
    cin>>n;

    vl dp(n + 1,-inf);

    ll m;
    cin>>m;

    vector<vector<pair<ll,ll>>> adj(n + 1);
    for(ll i=0;i<m;i++)
    {
        ll x,y,wt;
        cin>>x>>y>>wt;
        adj[x].pb({y,wt});  
        adj[y].pb({x,-wt});
    }

    bool visited[n + 1] = {false};
    
    for(int i =1;i<=n;i++)
    {
        if(visited[i] == false)
        {
            queue<pair<ll,ll>>q;
            q.push({i,0});
            visited[i] = true;
            dp[i] = 0;
            while(!q.empty())
            {
                auto el = q.front();

                ll src = el.F;
                ll dist = el.S;
                q.pop();

                for(auto it : adj[src])
                {
                    if(visited[it.F] == false)
                    {
                        visited[it.F] = true;
                        dp[it.F] = dist + it.S;
                        q.push({it.F,dp[it.F]});
                    }
                    else if(visited[it.F] == true)
                    {
                        if(dp[it.F] - dp[src] != it.S)
                        {
                            cout <<"No"<<nl;
                            return;
                        }
                    }
                }
            }
        }
    }

    cout <<"Yes"<<nl;


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