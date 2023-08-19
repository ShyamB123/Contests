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

ll n;

ll dp[101][101][(101 * 101)];
ll sum;

ll check(ll l,ll pre,int zeros,string &s)
{
    // dbg(pre + suf);
    ll suf = sum - pre;

    if(l>=n)
    {
        if(pre == suf)
            return 0;
        return inf;
    }
    if(dp[l][zeros][pre] != -1)
    {
        return dp[l][zeros][pre];
    }
    ll ans = inf;
    for(ll i = l;i<n;i++)
    {
        swap(s[i],s[l]);
        ll newzeros = 0;
        ll newones = 0;
        ll newpre = 0;
        ll newsuf = 0;
        for(ll j=0;j<n;j++)
        {
            if(s[j] == '0')
            {
                newzeros++;
                newpre += newones;
            }
            else
            {
                newones++;
                newsuf += newzeros;
            }
        }
        ll ok = (i == l?0:1);

        ans = min(ans,ok + check(l + 1,newpre,newzeros,s));

        swap(s[i],s[l]);
    }

    return dp[l][zeros][pre] = ans;

}

void solve()
{
    string s;
    cin>>s;
    cout << s.size()<<endl;

    memset(dp,-1,sizeof(dp));

    n = s.size();
    ll zeros = 0;
    ll ones = 0;
    ll pre = 0;
    ll suf = 0;
    for(ll i=0;i<n;i++)
    {
        if(s[i] == '0')
        {
            zeros++;
            pre += ones;
        }
        else
        {
            ones++;
            suf += zeros;
        }
    }
    sum = pre + suf;
    ll ans = check(0,pre,zeros,s);
    cout << ans <<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

  
    solve();
}