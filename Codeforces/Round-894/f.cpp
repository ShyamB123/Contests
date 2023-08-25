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


const int N = 1e6 + 1;
int dp[N];

void solve()
{
    ll f,w;
    cin>>f>>w;

    if(f > w)
    {
        swap(f,w);
    }

    ll n;
    cin>>n;

    ll a[n];

    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }

    ll s = 1;
    ll e = 1e6 + 1;
    ll ans = e;
    while(s <= e)
    {
        ll mid = (s + e)/2;
        ll fire = mid * f;
        ll water = mid * w;

        if(water >= sum)
        {
            ans = min(ans,mid);
            e = mid - 1;
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0] = 1;

        for(int i = 0;i<n;i++)
        {
            for(int j = fire;j >= 0;j--)
            {
                if(j - a[i] >= 0 && dp[j - a[i]] == 1)
                {
                    dp[j] = 1;
                }
            }
        }

        ll firemax = 0;
        for(int j = fire;j>=0;j--)
        {
            if(dp[j] == 1)
            {
                firemax = j;
                break;
            }
        }

        ll rest = sum - firemax;
        if(water >= rest)
        {
            ans = min(ans,mid);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

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