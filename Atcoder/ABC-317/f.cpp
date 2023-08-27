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

ll dp[64][10][10][10][2][2][2][2][2][2];
string s;
ll len;
ll a[3];


ll check(ll i,ll rema,ll remb,ll remc ,ll at,ll bt,ll ct,ll az,ll bz,ll cz)
{
    if(i >= len)
    {
        if(rema == 0 && remb == 0 && remc == 0 && az == 0 && bz == 0 && cz == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if(dp[i][rema][remb][remc][at][bt][ct][az][bz][cz] != -1)
    {
        return dp[i][rema][remb][remc][at][bt][ct][az][bz][cz];
    }
    ll ans = 0;
    ll dig = len - i - 1;

    {
        // 0 0 --> 0
        
        // ll tempans = check(i + 1,rema,remb,remc,0,0);
        int newat = 0;
        int newbt = 0;
        int newct = 0;

        if(at == 1 && s[i] == '0')
        {
            newat = 1;
        }
        if(bt == 1 && s[i] == '0')
        {
            newbt = 1;
        }
        if(ct == 1 && s[i] == '0')
        {
            newct = 1;
        }
        
        ans += check(i + 1,rema,remb,remc,newat,newbt,newct,az,bz,cz);
        // if(tempans > 0)
        ans %= mod;
    }
    if((s[i] == '1' || (bt == 0 && ct == 0)))
    {
        // 0 1 --> 1
        ll newremb = (((1ll<<dig) % a[1]) + remb)%a[1];
        ll newremc = (((1ll<<dig) % a[2]) + remc)%a[2];

        int newat = 0;
        if(at == 1 && s[i] == '0')
        {
            newat = 1;
        }
        ll newbt = (bt == 1)?1:0;
        ll newct = (ct == 1)?1:0;
        ans += check(i + 1,rema,newremb,newremc,newat,newbt,newct,az,0,0);
        ans %= mod;

    } 
    if((s[i] == '1' || (at == 0 && ct == 0)))
    {
        // 1 0 --> 1
        ll newrema = (((1ll<<dig) % a[0]) + rema)%a[0] ;
        ll newremc = (((1ll<<dig) % a[2]) + remc)%a[2];
        ll newat = (at == 1)?1:0;
        ll newct = (ct == 1)?1:0;

        int newbt = 0;

        if(s[i] == '0' && bt == 1)
        {
            newbt = 1;
        }


        ans += check(i + 1,newrema,remb,newremc,newat,newbt,newct,0,bz,0);
        ans %= mod;

    } 
    if((s[i] == '1' || (bt == 0 && at == 0)))
    {
        // 1 1 --> 0
        ll newrema = (((1ll<<dig) % a[0]) + rema)%a[0] ;
        ll newremb = (((1ll<<dig) % a[1]) + remb)%a[1];
        // ll newremc = (1ll<<dig) % a[2];
        ll newat = (at == 1)?1:0;
        ll newbt = (bt == 1)?1:0;

        int newct = 0;
        if(s[i] == '0' && ct == 1)
        {
            newct = 1;
        }
        ans += check(i + 1,newrema,newremb,remc,newat,newbt,newct,0,0,cz);
        ans %= mod;
    } 

    // dbg(ans);

    return dp[i][rema][remb][remc][at][bt][ct][az][bz][cz] = ans%mod;
    
}

void solve()
{
    ll n;
    cin>>n;


    for(ll i=0;i<3;i++)
    {
        cin>>a[i];
    }

    ll temp = n;

    while(temp > 0)
    {
        if(temp % 2 == 1)
        {
            s += '1';
        }
        else
        {
            s += '0';
        }
        temp/=2;
    }
    reverse(all(s));
    len = s.size();
    // dbg(s);
    // cout << len <<nl;
    memset(dp,-1,sizeof(dp));

    cout << check(0,0,0,0,1,1,1,1,1,1)<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}