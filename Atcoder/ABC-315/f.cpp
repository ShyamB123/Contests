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
template <class T>void _print(vector<vector<vector<T>>> v){for(int k =0;k<v.size();k++){cout << endl<<k <<" : "<<endl;_print(v[k]);}}
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/

double caldist(ll a,ll b,ll c,ll d)
{
    double ans = sqrt((a - c) * (a - c) + (d - b) * (d - b));
    return ans;
}

void solve()
{
    ll n;
    cin>>n;

    vll point;

    for(ll i=0;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        point.pb({u,v});
    }

    // double dp[n + 1][30];
    int back = 30;

    vector<vector<double>> dp(n + 1,(vector<double>(back,inf)));
    dp[0][0] = 0;


    for(int i =1;i<n;i++)
    {
        // // dont choose this checkpoint
        // for(int j = 1;j<back;j++)
        // {
        //     dp[i][j][0] = min(dp[i-1][j - 1][0],dp[i-1][j-1][1]);
        // }

        // choose it

        for(int j = i - 1;j>=max(0,i - back);j--)
        {
            int skip = i - j -1;
            double dist = caldist(point[i].F,point[i].S,point[j].F,point[j].S);
            for(int k = skip;k<back;k++)
            {
                if(dp[j][k - skip] != inf)
                {
                    dp[i][k] = min(dp[i][k],dp[j][k - skip] + dist);
                }
            }
        }
    }

    double ans = dp[n-1][0];

    // dbg(dp);

    ll p = 1;

    for(int j = 1;j<back;j++)
    {
        // if(dp[n-1][j][0] != inf)
        // {
        //     ans = min(ans,dp[n-1][j][0] + (double)p);
        // }
        if(dp[n-1][j] != inf)
        {
            ans = min(ans,dp[n-1][j] + (double)p);
        }
        p*=2;
    }

    cout << ans <<nl;




}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}