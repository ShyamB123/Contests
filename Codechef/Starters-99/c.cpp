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

 template <class T>
    void _print(vector<vector<vector<T>>> v)
    {
        for(int k =0;k<v.size();k++)
        {
            cout <<endl<< k <<" : "<<endl;
            for (int j = 0; j < v[0].size(); j++)
            {
                cout  << "[ ";
                for (T i : v[k][j])
                {
                    _print(i);
                    cout << " ";
                }
                cout << "]"<< " ";
            }
        };
    }

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
1
5
1 2 4 3 1

*/



void solve()
{
    ll n;
    cin>>n;

    ll a[n];

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vector<vector<vector<ll>>> dp(n + 1,vector<vector<ll>>(3,vector<ll>(3,0)));

    ll tempnum = a[2];
    ll sum = a[0] + a[1] + a[2];

    ll rem = a[2]%3;

    ll x,y;
    x = a[1]%3;
    y = a[2]%3;
    for(ll h =0;h<3;h++)
    {
        for(ll j =0;j<3;j++)
        {
            ll k = abs(6 - j - h)%3;
            int z = (k - a[0]%3 + 3)%3;
            dp[2][j][h] = (j - x + 3)%3 + (h-y + 3)%3 + z;
            bool ok = true;
        }
    }


    for(ll i = 3;i<n;i++)
    {
        ll rem = a[i]%3;
        
        for(ll h =0;h<3;h++)
        {
            for(ll j =0;j<3;j++)
            {
                ll k = abs(6 - j - h)%3;
                dp[i][j][h] = (h-rem + 3)%3 + dp[i-1][k][j];
            }
        }
    }
    // dbg(dp);

    ll ans = 1e9;

    for(ll i=0;i<3;i++)
    {
        for(ll j =0;j<3;j++)    
        {
            ans = min(ans,dp[n-1][i][j]);
        }
    }
    cout << ans<<nl;

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