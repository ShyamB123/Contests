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
    if(p1.F != p2.F)
        return p1.F < p2.F;
    else
        return p1.S > p2.S;

}

/*

*/



void solve()
{
    ll n,m;
    cin>>n>>m;

    ll a[n];
    set<int> ms;
    map<int,int> pos;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ms.insert(a[i]);
        pos[a[i]] = i;
    }
    ms.insert(inf);
    


    ll b[m];

    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }

    sort(b,b + m);
    // dbg(ms);

    vii bpos(m);
    for(int i= 0;i<m;i++)
    {
        int val = *ms.lower_bound(b[i]);
        if(val == inf)
        {
            bpos[i].F = -1;
            bpos[i].S = b[i];
        }
        else
        {
            bpos[i].F = pos[val];
            bpos[i].S = b[i];
        }
    }

    sort(all(bpos),compare);

    // dbg(bpos);

    int j =0 ;

    vi ans;

    while(j < m && bpos[j].F == -1)
    {
        ans.pb(bpos[j].S);
        j++;
    }

    for(int i =0;i<n;i++)
    {
        ans.pb(a[i]);
        while(j < m && i == bpos[j].F)
        {
            ans.pb(bpos[j].S);
            j++;
        }
    }

    for(auto it : ans)
    {
        cout << it << " ";
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