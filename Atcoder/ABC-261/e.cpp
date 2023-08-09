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



void solve()
{
    int n,x;
    cin>>n>>x;

    vector<vector<vi>> dp(n + 1 ,vector<vi>(32,vi(2,0)));
    for(int i=0;i<31;i++)
    {
        dp[0][i][0] = 0;
        dp[0][i][1] = 1;
    }

    vii v;
    for(int i =0;i<n;i++)
    {
        int t,b;    
        cin>>t>>b;
        v.pb({t,b});
    }

    for(int j =0 ;j<n;j++)
    {
        int num = v[j].S;
        int op = v[j].F;
        for(int i=0;i<31;i++)
        {
            for(int k = 0;k<2;k++)
            {
                int bit = ((num & (1<<i)) > 0)?1:0;
                if(op == 1)
                {
                    dp[j + 1][i][k] = dp[j][i][k] & bit;
                }
                else if(op == 2)
                {
                    dp[j + 1][i][k] = dp[j][i][k] | bit;
                }
                else
                {
                    dp[j + 1][i][k] = dp[j][i][k] ^ bit;
                }
            }
        }
    }

    for(int j = 0;j<n;j++)
    {
        int next =0;
        for(int i =0;i<31;i++)
        {
            int bit = ((x & (1<<i)) > 0)?1:0;
            int newbit = dp[j+1][i][bit];
            next += (newbit << i);
        }
        cout << next <<nl;
        x = next;
    }
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}