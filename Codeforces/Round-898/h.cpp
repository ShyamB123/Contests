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
1
18 17 15
10 13
3 4
11 18
17 16
15 12
9 3
12 10
17 13
8 18
5 17
11 8
13 3
7 9
1 12
14 10
2 18
18 17
13 6
*/

const ll N = 2e5 + 1;
vector<bool> visited(N,false);
vector<vl>adj(N);
set<ll> cyclevert;
vector<ll> par(N);

    ll n,a,b;
vector<ll> tempdist(N,inf);


void bfs(ll src)
{

    for(ll i=0;i<=n;i++)
    {
        visited[i] = false;
        tempdist[i] = inf;
    }

    queue<ll> q;

    q.push(src);
    tempdist[src] = 0;
    visited[src] = true;
    while(!q.empty())
    {
        ll el = q.front();
        q.pop();


        for(auto it :adj[el])
        {
            if(visited[it] == false)
            {
                tempdist[it] = tempdist[el] + 1;
                q.push(it);
                visited[it] = true;
            }
        }
    }

    for(ll i=0;i<=n;i++)
    {
        visited[i] = false;
    }

}


void dfs(ll src)
{
    visited[src] = true;
    for(auto it : adj[src])
    {
        if(visited[it] == true && it != par[src] && cyclevert.size() == 0)
        {
            ll x = src;
            while(x != it && x != par[x])
            {
                cyclevert.insert(x);
                // dbg(par[x]);
                x = par[x];
                bool check = true;
            }
            cyclevert.insert(x);
        }
        else if(visited[it] == false)
        {
            par[it] = src;
            dfs(it);
        }
    }
}

void solve()
{
    cin>>n>>a>>b;

    cyclevert.clear();
    for(ll i =0;i<=n;i++)
    {
        // adist[i] = 0;/
        // bdist[i] = 0;
        par[i] = i;
        adj[i].clear();
        visited[i] = false;
    }



    for(ll i=0;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    // dbg(cyclevert);


    vector<ll> adist(n + 1,inf);
    vector<ll> bdist(n + 1,inf);
    bfs(a);
    // adist = tempdist;
    for(ll i= 1;i<=n;i++)
    {
        adist[i] = tempdist[i];
        // cout << adist[i]<<" ";
    }
    // cout <<nl;
    bfs(b);
    for(ll i= 1;i<=n;i++)
    {
        bdist[i] = tempdist[i];
        // cout << bdist[i]<<" ";
    }
    // cout <<nl;
    // bdist = tempdist;

    bool ok = false;

    for(auto it : cyclevert)
    {
        // dbg(bdist[it]);
        // dbg(adist[it]);
        if(bdist[it] < adist[it])
        {
            // dbg(it);
            ok = true;
        }
    }

    if(ok == true)
    {
        cout <<"YES"<<nl;
    }
    else
    {
        cout <<"NO"<<nl;
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