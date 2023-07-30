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
    int n;
    cin>>n;

    int a[n];
    int indx = -1;
    int negindx = -1;
    

    for(int i=0;i<n;i++)
    {
        cin>>a[i];

        if(a[i] > 0)
        {
            indx = i;
        }
        if(a[i] < 0)
        {
            negindx = i;
        }
    }   

    if(indx == -1 && negindx == -1)
    {
        cout << 0 <<nl;
        return;
    }

    int op = 0;
    vii ans;

    if(indx != -1)
    {
        while(a[indx] <= 40)
        {
            op++;
            ans.pb({indx,indx});
            a[indx] += a[indx];
        }
        op+=2;
        a[0] += 2 * a[indx];
        ans.pb({0,indx});
        ans.pb({0,indx});

        for(int i = 1;i<n;i++)
        {
            op+=2;
            ans.pb({i,i-1});
            ans.pb({i,i-1});
            a[i] += 2 * a[i-1];
        }
    }
    else
    {
        while(a[negindx] > -40)
        {
            op++;
            ans.pb({negindx,negindx});
            a[negindx] += a[negindx];
        }
        op+=2;
        a[n-1] += 2 * a[negindx];
        ans.pb({n-1,negindx});
         ans.pb({n-1,negindx});

        for(int i = n-2;i>=0;i--)
        {
            op+=2;
            ans.pb({i,i + 1});
            ans.pb({i,i + 1});
            a[i] += 2 * a[i+1];
        }
    }

    // for(int i =0;i<n;i++)
    // {
    //     cout << a[i]<<" ";
    // }
    // cout <<nl;

    cout << ans.size() <<nl;
    for(auto it : ans)
    {
        cout << it.F + 1<<" "<<it.S + 1<<nl;
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