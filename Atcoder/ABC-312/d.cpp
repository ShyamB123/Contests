#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 998244353
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



void solve()
{
    string s;
    cin>>s;

    if(s.size()%2 == 1)
    {
        cout << 0 <<nl;
        return;
    }

    ll tar = s.size()/2;

    vector<vector<ll>> dp(s.size()/2 + 2,vl(s.size()/2 + 2,0));
    // vl dp(tar + 2,0);
    
    dp[0][0] = 1;
    auto ndp = dp;

    for(int i=0;i<s.size();i++)
    {
        if(s[i] == ')')
        {
            for(int j =1;j<=tar;j++)
            {
                int left = i - j + 1;
                if(left <= tar && left >= j && left >= 0)
                {
                    ndp[left][j] += dp[left][j - 1];
                    ndp[left][j] %= mod;
                }
            }
        }
        else if(s[i] == '(')
        {
            for(int j =1;j<=tar;j++)
            {
                int right = i - j + 1;
                if(right <= tar && j >= right && right >=0)
                {
                    ndp[j][right] += dp[j - 1][right];
                    ndp[j][right] %= mod;
                }
            }
        }
        else
        {
            // let it be a right
            for(int j =1;j<=tar;j++)
            {
                int left = i - j + 1;
                if(left <= tar && left >= j && left >= 0)
                {
                    ndp[left][j] += dp[left][j - 1];
                    // dbg(dp[left][j-1]);
                    ndp[left][j] %= mod;
                }
            }

            // let it be a left
            for(int j =1;j<=tar;j++)
            {
                int right = i - j + 1;
                if(right <= tar && j >= right && right >=0)
                {
                    ndp[j][right] += dp[j - 1][right];
                    ndp[j][right] %= mod;
                }
            }
        }
        // dp = ndp;
        swap(dp,ndp);
    }
    // dbg(dp);
    cout << dp[tar][tar]<<nl;

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}