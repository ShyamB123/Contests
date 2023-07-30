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
8
1 2
2 3
2 4
1 5
2 6
2 7
2 8
*/

const int N = 2e5 + 1;
vector<vi> adj(N);
ll ans = 0;
int nodes;
ll rmv = 0;

vl sz(N,0);

ll cal_size(int src,int par)
{
    ll subsz = 1;

    for(auto it : adj[src])
    {
        if(it != par)
        {
            subsz += cal_size(it,src);
        }
    }
    return sz[src] = subsz;
}

void dfs(int src,int par)
{
    vl v;

    for(auto it : adj[src])
    {
        if(it != par){
            v.pb(sz[it]);
        }
    }
    v.pb(nodes - sz[src] );
    // rmv += nodes - sz[src];
    int n = v.size();
    if(n > 1)
    {
        vl pre(n,0);

        pre[n-1] = v[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            pre[i] = pre[i + 1] + v[i];
        }
        vl pre2(n,0);

        for(int i = n-2;i>=0;i--)
        {
            pre2[i] = v[i] * pre[i + 1];
        }
        
        for(int i = n-2;i>=0;i--)
        {
            pre2[i] += pre2[i + 1];
        }

        for(int i = 0;i<n-2;i++)
        {
            ans += v[i] * pre2[i + 1];
        }
        // dbg(src);
        // dbg(v);
        // dbg(pre);
        // dbg(pre2);
        // dbg(ans);  
    } 

    for(auto it : adj[src])
    {
        if(it != par)
        {
            dfs(it,src);
        }
    }


}

void solve()
{
    cin>>nodes;

    for(int i=0;i<nodes-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ans = 0;

    cal_size(1,1);

    dfs(1,1);

    cout << ans <<nl;




}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    ans = 0;
    solve();
}