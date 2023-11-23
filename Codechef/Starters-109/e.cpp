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

const ll N = 3e5 + 1;

vector<vi> adj(N);
vl subtree(N,0);
vl dist1(N,0);
vl dist2(N,0);

    ll n;

void cal_subtree(ll src,ll par)
{
    ll ans = 1;

    for(auto it : adj[src])
    {
        if(it != par)
        {
            cal_subtree(it,src);
            ans +=subtree[it];
        }
    }

    subtree[src] = ans;
    return;

}


ll caldist(ll src,ll par)
{
    ll ans = 0;

    for(auto it : adj[src])
    {
        if(it != par)
        {
            ans += caldist(it,src);
            ans += subtree[it];
        }

        // ans += caldist[it];
    }

    // cout << src <<" "<<ans<<nl;

    // ans += subtree[src];

    return dist2[src] = ans;
}


void rotate(ll src,ll par,ll pardist,ll childdist)
{
    
    // dbg(pardist);dbg(childdist);
    dist1[src] = (pardist + childdist);

    for(auto it : adj[src])
    {
        if(it != par)
        {
            ll othernodes = (n - subtree[it]) + (dist2[src] - (dist2[it] + subtree[it]));

        
            rotate(it,src,(pardist + othernodes),dist2[it]);
        }
    }
}

ll binexp1(ll a,ll b, ll m){
    ll result = 1;
    while(b){
        if(b&1){
            result = (result*a)%m;
        }
        a = (a*a)%m;
        b>>=1;
    }
    return result;
}

ll divmod (ll a,ll b, ll m){
    ll inv = binexp1(b,m-2,m);
    ll ans = ((a%m)*(inv%m))%m;
    return ans;
}
void solve()
{
    cin>>n;

    for(ll i =0;i<=n;i++)
    {
        adj[i].clear();
        
        subtree[i] = 0;
        dist1[i] = 0;
        dist2[i] = 0;
    }
    // subtree.clear();
    // dist1.clear();
    // dist2.clear();

    vl d;

    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        d.pb(x);
    }

    for(ll i=0;i<n - 1;i++)
    {
        ll u,v;
        cin>>u>>v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    cal_subtree(1,1);

    dist1[1] = caldist(1,1);

    // for(ll i = 1;i<=n;i++)
    // {
    //     cout << subtree[i]<<" ";
    // }
    // cout <<nl;

   

    rotate(1,1,0,dist1[1]);

    // for(ll i=1;i<=n;i++)
    // {
    //     cout << dist1[i]<<" ";
    // }
    // cout <<nl;
    // for(ll i=1;i<=n;i++)
    // {
    //     cout << dist2[i]<<" ";
    // }
    // cout <<nl;

    vl v;
    for(ll i=1;i<=n;i++)
    {
        v.pb(dist1[i]);
    }

    sort(all(v));
    // reverse(all(v));

    sort(all(d));

    ll ans =0;

    for(ll i=0;i<n;i++)
    {
        ans += ((d[i]%mod) * ((((n * n)%mod) - (v[i]%mod) + mod)%mod))%mod;
        // cout << d[i]<<" "<<n * n - v[i]<<
        ans %= mod;
    }

    // cout << ans <<nl;

    ans = divmod(ans,(n * n)%mod,mod);

    cout << ans <<nl;


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