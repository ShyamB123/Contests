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
    ll n;
    cin>>n;

    set<ll> s;

    vll a;
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;

        a.pb({x,y});
        s.insert(x);
        s.insert(y);
    }

    sort(all(a));
    int nodetoval[s.size()];
    map<int,int> m;

    if(*s.begin() != 1)
    {
        cout << 1 << nl;
        return;
    }

    int cur = 0;

    for(auto it : s)
    {
        m[it] = cur;
        nodetoval[cur] = it;
        cur++;
    }

    vector<vi> adj(cur + 1);
    for(int i =0;i<n;i++)
    {
        int u = m[a[i].F];
        int v = m[a[i].S];
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = 1;

    queue<int> q;

    q.push(0);


    bool visited[cur + 1] = {false};
    while(!q.empty())
    {
        int el = q.front();
        q.pop();

        ans = max(ans,nodetoval[el]);

        for(auto it : adj[el])
        {
            if(visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
            }
        } 
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