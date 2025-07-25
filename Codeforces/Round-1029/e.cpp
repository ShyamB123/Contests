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
    vl b(n);

    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i =0;i<n;i++)
    {
        cin>>b[i];
    }
    map<ll,ll> aeven,aodd,beven,bodd;

    for(int i = 1;i<=n;i++)
    {
        aeven[i] = -1;
        aodd[i] = -1;
        beven[i] = -1;
        bodd[i] = -1;
    }

    for(ll i =n - 1;i>=0;i--)
    {
        bool ok = false;
        if(a[i] == b[i])    
            ok = true;

        // dbg(aeven)
        // dbg(aodd)
        // dbg(beven)
        // dbg(bodd)
        if(i % 2 == 0)
        {
            // if(aeven.find(b[i]) != aeven.end())
            //     ok = true;
            // if(beven.find(a[i]) != beven.end())
            //     ok = true;
            // if(bodd.find(b[i]) != bodd.end())
            //     ok = true;
            // if(aodd.find(a[i]) != aodd.end())
            //     ok = true;
            
            if(aeven[b[i]] > 0)
                ok = true;
            if(beven[a[i]] > 0)
                ok = true;
            if(bodd[b[i]] > 0)
                ok = true;
            if(aodd[a[i]] > 0)
                ok = true;
        }
        else
        {
            if(aodd[b[i]] > 0)
                ok = true;
            if(bodd[a[i]] > 0)
                ok = true;
            if(beven[b[i]] > 0)
                ok = true;
            if(aeven[a[i]] > 0)
                ok = true;            
        }

        if(max({aeven[a[i]],aodd[a[i]],beven[a[i]],bodd[a[i]]}) > i + 1)
            ok = true;
        if(max({aeven[b[i]],aodd[b[i]],beven[b[i]],bodd[b[i]]}) > i + 1)
            ok = true;   

        if(i % 2 == 0)
        {
            aeven[a[i]] = max(aeven[a[i]],i);
            beven[b[i]] = max(beven[b[i]],i);
        }
        else
        {
            aodd[a[i]] = max(aodd[a[i]],i);
            bodd[b[i]] = max(bodd[b[i]],i);
        }

        if(ok)
        {
            cout << i + 1 << nl;
            return;
        }
    }
    cout << 0 << nl;
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