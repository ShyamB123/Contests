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


// cp algo sparse table
const int K = 20;
const int MAXN = 2e5 + 1;

ll st[K + 1][MAXN];
int lg[MAXN+1];


ll maxquery(ll l, ll r)
{
    ll i = lg[r - l + 1];
    return max(st[i][l],st[i][r - (1<<i) + 1]);
}

void solve()
{
    ll n,s,x;
    cin>>n>>s>>x;

    vl a(n);
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }

    std::copy(a.begin(), a.end(), st[0]);

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = max(st[i - 1][j],st[i - 1][j + (1 << (i - 1))]);


    map<ll,vl> adj;

    ll cur = 0;
    adj[cur].pb(-1);
    ll ans = 0;
    for(int i =0;i<n;i++)
    {
        cur += a[i];
        ll tar = cur - s;

        if(adj[tar].size() > 0)
        {
            ll right = -1;
            ll left = n;
            {
                ll st = 0;
                ll e = adj[tar].size() - 1;
                
                // first right point such that max query is x
                while(st <= e)
                {
                    ll mid = (st + e)/2;
                    ll val = maxquery(adj[tar][mid] + 1,i);
                    if(val == x)
                    {
                        right = mid;
                    }

                    if(val >= x)
                    {
                        st = mid + 1;
                    }
                    else
                    {
                        e = mid - 1;
                    }
                }
            }
            {
                ll st = 0;
                ll e = adj[tar].size() - 1;
                
                // first left point such that max query is x
                while(st <= e)
                {
                    ll mid = (st + e)/2;
                    ll val = maxquery(adj[tar][mid] + 1,i);
                    if(val == x)
                    {
                        left = mid;
                    }

                    if(val > x)
                    {
                        st = mid + 1;
                    }
                    else
                    {
                        e = mid - 1;
                    }
                }
            }

            if(right >= left)
            {
                ans += right - left + 1;
            }
        }
        adj[cur].pb(i);
    }

    cout << ans << nl;


}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i/2] + 1;

    ll t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}