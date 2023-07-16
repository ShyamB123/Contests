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
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/


void solve()
{

    int n,m,k;   

    cin>>n>>m>>k;
        
    vector<vii> adj(n + 1);
    vector<vector<bool>> visited(n + 1,vector<bool>(2,false));
    set<int> s;

    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].pb({v,wt});
        adj[v].pb({u,wt});
    }

    for(int i =0;i<k;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }


    for(int i = 1;i<=n;i++)
    {
        visited[i][0] = visited[i][1] = false;
    }

    queue<vi> q;
    
        vi v;
        v.pb(1);
        v.pb(0);
        v.pb(0);

        q.push(v);
        visited[1][0] = true;

        int ans = inf;
    

    while(!q.empty())
    {
        auto ve = q.front();
        q.pop();

        int src = ve[0];
        int sw = ve[1];
        int dist = ve[2];

        bool ok = false;
        if(src == n)
        {
            ans = min(ans,dist);
        }

        // int newsw = sw;
        if(s.find(src) != s.end())
        {
            ok = true;
            // sw = (sw + 1)%2;
        }

        if(!ok)
        {
            for(auto it : adj[src])
            {
                if(it.S != sw && visited[it.F][sw] == false)
                {
                    visited[it.F][sw] = true;
                    vi t;
                    t.pb(it.F);
                    t.pb(sw);
                    t.pb(dist + 1);
                    q.push(t);
                }
            }
        }
        else
        {
            for(auto it : adj[src])
            {
                if(it.S != sw && visited[it.F][sw] == false)
                {
                    visited[it.F][sw] = true;
                    vi t;
                    t.pb(it.F);
                    t.pb(sw);
                    t.pb(dist + 1);
                    q.push(t);
                }
                if(it.S == sw && visited[it.F][(sw + 1)%2] == false)
                {
                    visited[it.F][(sw + 1)%2] = true;
                    vi t;
                    t.pb(it.F);
                    t.pb((sw + 1)%2);
                    t.pb(dist + 1);
                    q.push(t);
                }
            }
        }
    }


    if(ans == inf)
    {
        cout << -1 << nl;
        return;
    }
    cout << ans<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}