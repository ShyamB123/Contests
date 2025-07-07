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
    ll n;
    cin>>n;

    vl a(n);

    ll maxel = 0;
    ll sum =0 ;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
        maxel = max(maxel,a[i]);
        sum += a[i];
    }

    if(sum % 2 == 1)
    {
        cout << -1 << nl;
        return;
    }

    if(maxel > sum - maxel)
    {
        cout << -1 << nl;
        return;
    }

    {
        ll here = 0;
        for(int i =0;i<n - 1;i++)
        {
            here += a[i];
            if(here == sum - here)
            {
                cout << 1 << nl;
                for(auto it : a)
                {
                    cout << it << " ";
                }
                cout << nl;
                return;
            }
        }
    }

    int indx;
    ll pre = 0;
    for(int i =0;i<n - 1;i++)
    {
        pre += a[i];
        if((pre * 2 <= sum) && (2 * pre + 2 * a[i + 1] >= sum))
        {
            indx = i + 1;
            break;
        }
    }
    ll x = pre;
    ll z = a[indx];
    ll y = sum - x - z;

    // dbg(indx)
    // dbg(x)
    // dbg(y)
    // dbg(z)

    vector<vl> ans;
    if(y >= x)
    {
        // {
        vl b(n);
        ll dif = ((z + y) - x) / 2;

        for(int i = indx + 1;i<n;i++)
        {
            ll rmv = min(a[i],dif);
            b[i] = rmv;
            b[indx] += rmv;
            // dbg(rmv)

            dif -= rmv;
        }
        ans.pb(b);
        for(int i = 0;i<n;i++)
        {
            a[i] -= b[i];
        }

        ans.pb(a);
        // }
    }
    else
    {
        vl b(n);
        ll dif = ((z + x) - y) / 2;

        for(int i = 0;i<indx;i++)
        {
            ll rmv = min(a[i],dif);
            b[i] = rmv;
            b[indx] += rmv;

            dif -= rmv;
        }
        ans.pb(b);
        for(int i = 0;i<n;i++)
        {
            a[i] -= b[i];
        }

        ans.pb(a);
    }


    cout << 2 << nl;

    for(auto it : ans)
    {
        for(auto i : it)
        {
            cout << i << " ";
        }
        cout << nl;
    }
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