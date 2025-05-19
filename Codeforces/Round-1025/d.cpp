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

const int N = 2e5 + 1;
vector<vl> adj(N);
vector<vl> dp(N,vl(2,-1));

void bfs()
{
    // if(dp[src][dist % 2]  == -1)
    // {
    //     return;
    // }

    // for(auto it : adj[src])
    // {

    // }

    queue<pair<ll,ll>> q;

    q.push({0,0});
    dp[0][0] = 0;

    while(!q.empty())
    {
        auto el = q.front();
        q.pop();

        int src = el.F;
        int dist = el.S;

        for(auto it : adj[src])
        {
            int ndist = dist + 1;
            if(dp[it][ndist % 2] == -1)
            {
                dp[it][ndist % 2] = ndist;
                q.push({it,ndist});
            }
        }
    }
}

void solve()
{
    ll n,m,l;
    cin>>n>>m>>l;

    vector<ll> a(l);
    ll evens = 0;
    ll evensum = 0;
    ll odds = 0;
    ll oddsum =0 ;
    ll oddmin = inf;
    for(int i = 0;i<l;i++)
    {
        cin>>a[i];
        if(a[i] % 2 == 0)
        {
            evens++;
            evensum += a[i];
        }
        else
        {
            odds++;
            oddsum += a[i];
            oddmin = min(oddmin,a[i]);
        }
    }

    for(int i =0;i<n;i++)
    {
        adj[i].clear();
        dp[i][0] = dp[i][1] = -1;
    }

    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;


        adj[u].pb(v);
        adj[v].pb(u);
    }

    vl ans(n,0);
    bfs();
    if(evens == l)
    {
    // dbg(dp);
        for(int i =0;i<n;i++)
        {
            if(dp[i][0] != -1 && dp[i][0] <= evensum)
            {
                ans[i] = 1;
            }
        }
    }
    else
    {
        for(int i =0;i<n;i++)
        {
            if(dp[i][0] != -1 && dp[i][0] <= evensum + oddsum - oddmin)
            {
                ans[i] = 1;
            }
            if(dp[i][1] != -1 && dp[i][1] <= evensum + oddsum - oddmin)
            {
                ans[i] = 1;
            }
        }

        if(odds % 2 == 0)
        {
            for(int i =0;i<n;i++)
            {
                if(dp[i][0] != -1 && dp[i][0] <= evensum + oddsum)
                {
                    ans[i] = 1;
                }
            }
        }
        else
        {
            for(int i =0;i<n;i++)
            {
                if(dp[i][1] != -1 && dp[i][1] <= evensum + oddsum)
                {
                    ans[i] = 1;
                }
            }
        }
    }


    for(auto it : ans)
        cout << it;
    
    cout << nl;
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