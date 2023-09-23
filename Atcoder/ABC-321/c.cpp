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
    ll k;
    cin>>k;

    ll dp[11][10] = {0};

    for(ll i=0;i<=9;i++)
    {
        dp[1][i] = 1;
    }

    if(k <= 9)
    {
        cout << k <<nl;
        return;
    }


    ll cur = 9;
    for(ll dig = 2;dig<=10;dig++)
    {
        for(ll i = 1;i<=9;i++)
        {
            ll val = 0;
            for(ll j = 0;j<i;j++)
            {
                if(cur + dp[dig - 1][j] < k)
                {
                    cur += dp[dig - 1][j];
                    val += dp[dig - 1][j];
                }
                else
                {
                    ll now = cur;
                    string ans = "";
                    ans += (char)(i + '0');
                    ans += (char)(j + '0');
                    ll pl = dig - 2;
                    ll d = j;


                    while(ans.size() < dig)
                    {
                        ll j = 0;  
                        for(ll h = 0;h<d;h++)
                        {
                            if(now + dp[pl][h] < k)
                            {
                                now += dp[pl][h];
                            }
                            else
                            {
                                ans += (char)(h + '0');
                                d = h;
                                break;
                            }
                        } 
                        pl--;
                    }
                    cout << ans <<nl;
                    return;
                }
            }
            dp[dig][i] = val;
        }
    }
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}