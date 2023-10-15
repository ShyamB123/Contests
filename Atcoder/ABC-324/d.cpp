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


ll sqr_root(ll tar)
{
    ll l = 1;
    ll r = 1e9;

    ll ans = 1;

    while(l<=r)
    {
        ll mid = (l+r)/2;

        if(mid*mid <= tar)
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }

    return ans;
}
void solve()
{
    int n;
    cin>>n;

    vector<char> s(n);

    // multiset<int> ms;
    vi ms(10,0);

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        // ms.insert((int)(s[i]-'0'));
        ms[(int)(s[i]-'0')]++;
    }

    vl squares;

    for(ll i = 0;i * i < 1e14;i++)
    {
        squares.pb(i * i);
    }

    ll ans = 0;

    auto tempms = ms;
    for(ll it : squares)
    {
        ll num = it;
        tempms = ms;

        bool ok = true;
        while(num > 0)
        {
            int dig = num%10;
            num/=10;
            if(tempms[dig] == 0)
            {
                ok = false;
            }
            else
            {
                tempms[dig]--;
            }
        }

        for(int i = 1;i<=9;i++)
        {
            if(tempms[i] > 0)
            {
                ok = false;
            }
        }
        if(ok)ans++;
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