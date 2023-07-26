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

ll n,k;
ll x,y;
ll ans;
ll val;
void dfs(int j,vll &a)
{
    

    if(a.size() == 1)
    {
        return ;
    }
    if(j < 0)
    {
        int calans =0;
        int u = a[0].F;
        int v = a[1].F;
        int tempx = 0;
        for(int i=0;i<k;i++)
        {
            if((u & (1<<i)) == (v & (1<<i)))
            {
                calans += (1<<i);
                if((u & (1<<i)) == 0)
                {
                    tempx += (1<<i);
                }
            }
            
        }
        if(calans>ans)
        {
            x = a[0].S;
            y = a[1].S;
            ans = calans;
            val = tempx;
        }
        return;
    }
    vll zero,fir;
    for(auto it : a)
    {
        if((it.F & (1<<j)) > 0)
        {
            fir.pb(it);
        }
        else
        {
            zero.pb(it);
        }
    }

    

    if(fir.size() == 1 && zero.size() == 1)
    {
        int calans =0;
        int u = a[0].F;
        int v = a[1].F;
        int tempx = 0;
        for(int i=0;i<k;i++)
        {
            if((u & (1<<i)) == (v & (1<<i)))
            {
                calans += (1<<i);
                if((u & (1<<i)) == 0)
                {
                    tempx += (1<<i);
                }
            }
            
        }
        if(calans>ans)
        {
            x = a[0].S;
            y = a[1].S;
            ans = calans;
            val = tempx;
        }
        return;
    }
    if(fir.size() > 1)
    {
        dfs(j-1,fir);
    }
    if(zero.size() > 1)
    {
        dfs(j -1,zero);
    }
}
void solve()
{
    cin>>n>>k;
    vll a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i].F;
        a[i].S = i;
    }
    ans =0;
    val = 0;
    x = 0;
    y = 1;

    dfs(k,a);

    cout << x + 1<< " "<<y + 1<<" "<<val<<nl;
     
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