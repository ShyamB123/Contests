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

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll s = 0;
    ll e = 1e12;

    

    while(s <= e)
    {
        ll mid = (s + e)/2;

        ll curans =0;
        vl b = a;
        for(ll i=0;i<n;i++)
        {
            curans += min(b[i],mid-1);
            b[i] -= min(b[i],mid-1);
            // curans += min(max(0ll,mid-1),a[i]);
            
        }
        for(ll i =0;i<n;i++)
        {
            if(b[i] >= 1)
            {
                curans++;
                b[i]--;
            }
            if(curans == k)
            {
                for(ll j =0;j<n;j++)
                {
                    cout << b[j]<< " ";
                }
                cout <<nl;
                return;
            }
        }
        if(curans > k)
        {
            e = mid-1;
        }
        else
        {
            s = mid + 1;
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