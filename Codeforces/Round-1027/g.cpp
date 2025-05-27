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
    ll n,k;
    cin>>n>>k;

    vl a(n);

    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }

    vl b =a ;
    vl tw(n,0);

    for(int i =0;i<n;i++)
    {
        while(b[i] % 2 == 0)
        {
            b[i] /= 2;
            tw[i]++;
        }
    }

    vl pre(n);
    vl suf(n);

    for(int i =0;i<n;i++)
    {
        // assuinmg next element is present
        ll twos = tw[i];
        if(i == n - 1)
        {
            pre[i] = (1ll<<twos);
        }
        else
        {
            if(b[i] != b[i + 1])
            {
                pre[i] = (1ll<<twos);
            }
            else
            {
                if(a[i] < a[i + 1])
                {
                    pre[i] = (1ll<<twos);
                }
                else
                {
                    // you need to start at 2 * a[i + 1]
                    ll ntwos =(2 * a[i + 1]);
                    ll cnt = 0;
                    while(ntwos % 2 == 0)
                    {
                        cnt++;
                        ntwos /= 2;
                    }
                    pre[i] = (1ll<<twos)-(1ll<<cnt) + 1;
                }
            }
        }

        if(i - 1>=0)
        {
            pre[i] += pre[i - 1];
        }
    }

    for(int i =n - 1;i>=0;i--)
    {
        // assuinmg prev element is present
        ll twos = tw[i];
        if(i == 0)
        {
            suf[i] = (1ll<<twos);
        }
        else
        {
            if(b[i] != b[i - 1])
            {
                suf[i] = (1ll<<twos);
            }
            else
            {
                if(a[i] < a[i - 1])
                {
                    suf[i] = (1ll<<twos);
                }
                else
                {
                    // you need to start at 2 * a[i + 1]
                    ll ntwos = 2 * a[i - 1];
                    ll cnt = 0;
                    while(ntwos % 2 == 0)
                    {
                        cnt++;
                        ntwos /= 2;
                    }
                    suf[i] = (1ll<<twos)-(1ll<<cnt) + 1;
                }
            }
        }
        if(i + 1 < n)
        {
            suf[i] += suf[i + 1];
        }
    }

    //dbg(pre)dbg(suf)

    bool ok = false;
    for(int i =0;i<n;i++)
    {
        ll twos = tw[i];
        ll cur = (1ll<<twos);

        if(i - 1 >= 0)
        {
            cur += pre[i - 1];
        }
        if(i + 1 < n)
            cur += suf[i + 1];

        if(cur >= k)
        {
            ok = true;
        }
    }

    cout << (ok?"YES" : "NO") << nl;
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