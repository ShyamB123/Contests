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
    ll a[n];
    multiset<ll> ms;
    map<ll,ll> m;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        ms.insert(a[i]);
        m[a[i]]++;
    }

    ll k;
    cin>>k;

    ll minel = *ms.begin();
    ll i =0;
    vl ans(n, 0);
    while(i<n && k > 0)
    {
        if(a[i] == minel && m[minel] == 1)
        {
            ms.erase(ms.find(a[i]));
            if(ms.size() == 0)
            {
                ans[i] += k/a[i];
                k = 0;
            }
            else
            {
                ll nextgreat = *ms.begin();
                // find the point where you can do same operations from both indices
                ll s = 0;
                ll e = k/minel ;

                ll curans = e;

                while(s <= e)
                {
                    ll mid = (s + e)/2;

                    ll remcoins = k - minel * mid;

                    if(remcoins/minel == remcoins/nextgreat)
                    {
                        e = mid - 1;
                        curans = mid;

                    }
                    else
                    {
                        s = mid + 1;

                    }
                }

                ans[i] += curans;
                k -= minel * curans;
                minel = nextgreat;
            }
            // break;
        }
        else
        {
            m[a[i]]--;
            ms.erase(ms.find(a[i]));
        }
            i++;
    }

    // dbg(ans);

    ll cur =0;
    vl pre(n,0);
    for(int i = n - 1;i>=0;i--)
    {
        cur += ans[i];
        pre[i] += cur;
    }

    for(int i=0;i<n;i++)
    {
        cout << pre[i]<<" ";
    }
    cout <<nl;

    

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