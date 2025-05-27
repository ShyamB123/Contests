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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int x,y,k;
const int N = 1e6 + 1;
vector<vl> d(N);
vl dp(N,inf);

ll helper(ll n)
{
    if(n == 1)
        return 0;
    if(dp[n] != inf)
        return dp[n];

    for(auto it : d[n])
    {
        if(it <= k)
        {
            dp[n] = min(dp[n],1 + helper(n/it));
        }
    }

    return dp[n];
}

void solve()
{
    cin>>x>>y>>k;

    map<ll,ll> xcnt,ycnt;
    {
        ll num = x;
        for(ll i = 2;i * i <= num ;i++)
        {
            while(num % i == 0)
            {
                num/= i;
                xcnt[i]++;
            }
        }

        if(num > 1)
        {
            xcnt[num]++;
        }
    }

    {
        ll num = y;
        for(ll i = 2;i * i <= num ;i++)
        {
            while(num % i == 0)
            {
                num/= i;
                ycnt[i]++;
            }
        }

        if(num > 1)
        {
            ycnt[num]++;
        }
    }

    vector<ll> xs,ys;
    for(auto [it,freq] : xcnt)
    {
        if(freq > ycnt[it])
        {
            for(ll i =0;i<freq - ycnt[it];i++)
            {
                xs.pb(it);
            }
        }
    }
    for(auto [it,freq] : ycnt)
    {
        if(freq > xcnt[it])
        {
            for(ll i =0;i<freq - xcnt[it];i++)
            {
                ys.pb(it);
            }
        }
    }

    sort(all(xs));
    sort(all(ys));
    if(xs.size() > 0 && xs.back() > k)
    {
        cout << -1 << nl;
        return;
    }
    if(ys.size() > 0 && ys.back() > k)
    {
        cout << -1 << nl;
        return;
    }

    ll xn = 1;
    ll yn = 1;

    for(auto it : xs)
        xn *= it;
    for(auto it : ys)
        yn *= it;

    dp.assign(xn + 1,inf);
    ll ans = helper(xn);
    dp.assign(yn + 1,inf);
    ans += helper(yn);

    cout << ans << nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    for(int i = 2;i<N;i++)
    {
        for(int j = i;j < N;j += i)
        {   
            d[j].pb(i);
        }
    }
    

    ll t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}