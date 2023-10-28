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

const int N = 2e5 + 1;
    ll n;

vl pre(N);
vl in(N);
vl loc(N);
bool ok;
vii ans(N,{0,0});

int dfs(int src,int s,int e,int indx)
{
    // if(indx > n)
    //     return 1;
    int i = loc[src];

    if(s == e)
        return 1;
        

    if(i > e || i < s)
        ok = false;


    // next is indx + 1;
    int cur = 0;
    
    if(s != i)
    {
        if(loc[pre[indx + 1]] < loc[src])
        {
            ans[src].F = pre[indx + 1];
            cur += dfs(pre[indx + 1],s,i -1,indx + 1);
        }
        else
        {
            ok = false;
        }
    }
    // go to right

    if(i != e)
    {
        if(loc[pre[indx + cur + 1]] > loc[src])
        {
            ans[src].S = pre[indx +cur + 1];
            // right
            cur += dfs(pre[indx + cur + 1],i + 1,e,indx + cur + 1);
        }
        else
        {
            ok = false;
        }
    }

    return 1 + cur;


}

void solve()
{
    cin>>n;    

    for(int i =1;i<=n;i++)
    {
        cin>>pre[i];
    }

    for(int i=1;i<=n;i++)
    {
        cin>> in[i];
        loc[in[i]] = i;
    }

    ok = true;
    int useless = dfs(1,1,n,1);

    if(!ok)
    {
        cout << -1 <<nl;
    }
    else
    {
        for(int i = 1;i<=n;i++)
        {
            cout << ans[i].F <<" "<<ans[i].S<<nl;
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