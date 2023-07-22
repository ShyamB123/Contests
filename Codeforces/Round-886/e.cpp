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
    ull n,c;
    cin>>n>>c;

    ull a[n];

    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }



    ull s =1;
    ull e = 1e9;

    ull lim = 1e18 + 1;

    while(s<=e)
    {
        ull mid = (s + e)/2;
        if(mid > lim/mid)
        {
            e = mid-1;
            continue;
        }

        ull cur =0;
        bool ok = false;
        for(int i=0;i<n;i++)
        {
            if(a[i] > lim -(2*mid))
            {

                ok = true;
                break;
            }
             if((a[i] + 2*mid) > lim /(a[i] + 2*mid))
            {

                ok = true;
                break;
            }
             if((a[i] + 2*mid)*(a[i] + 2*mid) > lim - cur)
            {
                ok = true;
                break;
            }
            cur += (a[i] + 2*mid)*(a[i] + 2*mid);
        }

        if(ok)
        {
            e = mid-1;
            continue;
        }

        if(cur > c)
        {
            e = mid-1;
        }
        else if(cur <c)
        {
            s = mid + 1;
        }
        else
        {
            cout << mid<<nl;
            return;
        }
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