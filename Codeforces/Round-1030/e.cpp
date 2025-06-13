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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int N = 2e5 + 1;
vector<vector<int>> dp(N,vector<int>(2,-1));
vl l(N,-1);
vl r(N,-1);
map<ll,vl> adj;
map<ll,ll> m;

ll n,k;

int dfs(int indx,int dir)
{
    // good
    if(indx == -1)
    {
        return 1;
    }
    // if(dir == 0 && r[indx] == -1)
    // {
    //     return 1;
    // }
    // if(dir == 1 && l[indx] == -1)
    // {
    //     return 1;
    // }

    if(dp[indx][dir] != -1)
    {
        return dp[indx][dir];
    }
    dp[indx][dir] = 0;
    
    if(dir == 1)
    {
        // we change to 1 - dir
        dp[indx][dir] = dfs(l[indx],1 - dir);
    }
    else
    {
        dp[indx][dir] = dfs(r[indx],1 - dir);
    }

    return dp[indx][dir];
}

void solve()
{
    cin>>n>>k;

    adj.clear();
    // for(int i =0;i<k;i++)
    // {
    //     adj[i].clear();
    // }

    vl a(n);
    vl d(n);

    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(int i =0;i<n;i++)
    {
        cin>>d[i];
    }

    for(int i =0;i<n;i++)
    {
        l[i] = -1;
        r[i] = -1;
        for(int j =0;j<2;j++)
        {
            dp[i][j] = -1;
        }
    }


    // {
    m.clear();
        for(int i =0;i<n;i++)
        {
            ll here = (a[i] + d[i]) % k;
            if(m.find(here) != m.end())
            {
                l[i] = m[here];
            }
            m[here] = i;
        }
    // }
    // {
        // map<ll,ll> m;
    m.clear();
        for(int i =n - 1;i>=0;i--)
        {
            ll here = (d[i] % k - (a[i] % k) + k) % k;
            if(m.find(here) != m.end())
            {
                r[i] = m[here];
            }
            m[here] = i;
        }
    // }

    for(int i =0;i<n;i++)
    {
        ll here = ((a[i] % k) - (d[i] % k) + k) % k;
        
        adj[here].pb(i);
    }

    // dbg(l)
    // dbg(r)


    for(int i =0;i<n;i++)
    {
        if(dp[i][1] == -1)
        {
            dfs(i,1);
        }
    }

    // for(int i =0;i<n;i++)
    // {
    //     dbg(dp[i]);
    // }
    ll q;
    cin>>q;

    // dbg(adj)
    for(int qr =0 ;qr < q;qr++)
    {
        ll curloc;
        cin>>curloc;

        if(a[n - 1] < curloc)
        {
            cout << "YES" << nl;
            continue;
        }
        ll indx = lower_bound(all(a),curloc) - a.begin();


        // dbg(indx)

        ll here = curloc % k;
        if(adj[here].size() == 0)
        {
            cout << "YES" << nl;
            continue;
        }
        ll pntindx = lower_bound(all(adj[here]),indx) - adj[here].begin();
        
        // dbg(here)
        // dbg(pntindx)
        if(pntindx == (int)adj[here].size())
        {
            cout << "YES" << nl;
            continue;
        }
        ll pnt = adj[here][pntindx];
        // dbg(pnt)
        
        if(dp[pnt][1] == 1)
        {
            cout << "YES" << nl;
        }
        else
        {
            cout << "NO" << nl;
        }
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