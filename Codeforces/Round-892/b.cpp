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
8 5 3
1 2 3 4 5 
*/



void solve()
{
    ll n,m,d;
    cin>>n>>m>>d;

    vl a;
    

    for(ll i =0;i<m;i++)
    {
        ll x;
        cin>>x;
        a.pb(x);
    }

    ll total = 0;

    for(ll i = 0;i<m;i++)
    {
        if(i == 0 && a[i] == 1)
        {
            continue;
        }
        
        if(i == 0)
        {
            total += (a[i] - 1+ d - 1)/d;
        }
        else
            total += (a[i] -a[i -1] + d - 1)/d;
    }
    if(n == a[m - 1])
    {
        total++;
    }
    else
    {
        total += (n - a[m-1] + d - 1)/d;
        if((n - a[m-1])%d == 0)
            total++;
    }

    ll maxdiff = INT_MIN;
    ll indx = 0;

    int ans = 0;
    for(ll i = 0;i<m;i++)
    {
        ll l = i > 0 ? a[i -1] : 1;
        ll r = i < m - 1 ? a[i + 1] : n;
        ll cur = a[i];

    
        // if we remove
        ll rmv = (r - l + d -1)/d;
        if(i == m -1 && (n - l)%d == 0)
        {
            rmv++;
        }

        // if we dont remove;
        ll x = (cur - l + d -1)/d;
        ll y = (r - cur + d-1 )/d;
        
        if(i == m-1 && cur == n)
        {
            x++;
        }
        if(i == m - 1 && cur < n && (n - cur)%d == 0)
        {
            y++;
        }

        ll op = x + y ;


        if(op - rmv >= maxdiff)
        {
            if(op - rmv == maxdiff)
            {
                ans++;
            }
            else
            {
                maxdiff = op - rmv;
                ans = 1;
            }
        }
    }

    cout << total - maxdiff<<" "<<ans<<nl;
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