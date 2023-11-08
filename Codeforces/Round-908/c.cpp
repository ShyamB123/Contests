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
vector<vi> adj(N);
vector<vi> radj(N);

bool visited[N];
set<int> zero;
bool ok = false;

void cyclecheck1(int src)
{
    visited[src] = true;

    for(auto it : adj[src])
    {
        if(visited[it] == true)
            ok = true;
        else if(visited[it] == false)
            cyclecheck1(it);
    }
}

void cyclecheck2(int src)
{
    visited[src] = true;

    for(auto it : radj[src])
    {
        if(visited[it] == true)
            ok = true;
        else if(visited[it] == false)
            cyclecheck2(it);
    }
}

int dp[N];
int tar = 0;

int dfs(int src)
{
    if(dp[src] != -1)
        return dp[src];
    visited[src] = true;
    int ans =0;

    for(auto it : radj[src])
    {
        ans = max(ans,dfs(it));
    }
    return dp[src] = ans + 1;
}


void solve()
{
    ll n;
    cin>>n;

    ll k;
    cin>>k;

    ll a[n];
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<=n;i++)
    {
        adj[i].clear();
        radj[i].clear();

        visited[i] = false;
        dp[i] = -1;
    }
    zero.clear();

    int indeg[n] = {0};

    for(int i=0;i<n;i++)
    {
        if(a[i] <= n)
        {
            int topl = 0;
            if(a[i] > i + 1)
            {
                topl += i + 1;
                topl += n - a[i];
            }
            else
            {
                topl = i + 1 - a[i];
            }
            // dbg(topl);

            int next = (topl + a[i])%n;
            adj[topl].pb(next);
            radj[next].pb(topl);
            indeg[next]++;
        }
    }

    for(int i= 0;i<n;i++)
    {
        visited[i] = false;
    }


    // check for cycle

    ok = false;

    cyclecheck2(0);

    

    if(ok == true)
    {
        cout <<"Yes"<<nl;
        return;
    }


    for(int i = 0;i<n;i++)
    {
        visited[i] = false;
    }

    int finalans =0;
    finalans = dfs(0);


    if(finalans - 1 >= k)
    {
        cout <<"Yes"<<nl;
    }
    else
    {
        cout <<"No"<<nl;
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