#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e16
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
3 4 4
1 2 2
2 3 2
1 3 3
1 3 1
4 2 1 2
*/



void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;

    vector<vl> a;

    for(ll i=0;i<m;i++)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;

        vl temp;
        temp.pb(u);
        temp.pb(v);
        temp.pb(wt);
        a.pb(temp);
    }

    vl edge(k);

    for(ll i =0;i<k;i++)
    {
        cin>>edge[i];
        edge[i]--;
    }
    // dbg(edge);

    vl dp(n + 1,inf);

    dp[1] = 0;

    for(ll i=0;i<k;i++)
    {
        ll u = a[edge[i]][0];
        ll v = a[edge[i]][1];
        ll wt = a[edge[i]][2];

        if(dp[u] != inf)
        {
            dp[v] = min(dp[v],dp[u] + wt);
        }
        //   dbg(dp);

    }
  
    cout << (dp[n] == inf ? -1 : dp[n])<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}