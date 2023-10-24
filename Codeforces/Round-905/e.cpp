#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
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
    ll n;
    cin>>n;

    ll t;
    cin>>t;

    vector<vii> adj(n + 1);
    for(int i=0;i<t;i++)
    {
        int m;
        cin>>m;

        for(int j =0;j<m;j++)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;

            adj[u].pb({v,i});
            adj[v].pb({u,i});
        }
    }


    int k;
    cin>>k;

    int a[k];
    for(int i= 0;i<k;i++)
    {
        cin>>a[i];
        a[i]--;
    }
        
    vector<vi> pos(t + 1);

    for(int i =0;i<k;i++)
    {
        pos[a[i]].pb(i);
    }

    priority_queue<pair<int,int>> pq;

    pq.push({0,0});
    vector<int> dp(n,inf);
    dp[0] = 0;

    while(!pq.empty())
    {
        auto el = pq.top();
        pq.pop();

        int dist = -el.F;
        int src = el.S;

        if(dp[src] < dist)
            continue;
        
        for(auto it : adj[src])
        {
            int v = it.F;
            int i = it.S;

            int indx = lower_bound(all(pos[i]),dist) - pos[i].begin();

            if(indx < pos[i].size() && dp[v] > pos[i][indx])
            {
                dp[v] = pos[i][indx] + 1;
                pq.push({-pos[i][indx] - 1,v});
            }
        }
    }

    if(dp[n - 1] == inf)
        cout << -1 <<nl;
    else
        cout << dp[n-1] <<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}