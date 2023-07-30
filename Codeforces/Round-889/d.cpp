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

    vl pos;
    vl neg;
    ll posindx;
    ll negindx;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];

        if(a[i] > 0)
        {
            pos.pb(i);
            posindx = i;
        }
        else if(a[i] < 0)
        {
            neg.pb(i);
            negindx = i;
        }
    }

    vii ans;

    if(max(pos.size(),neg.size()) >=13)
    {
        if(pos.size() > neg.size())
        {  
            while(a[posindx] < 20)
            {
                a[posindx] += a[posindx];
                ans.pb({posindx,posindx});
            }

            for(auto it : neg)
            {
                a[it] += a[posindx];
                ans.pb({it,posindx});
            }

            for(ll i = 1;i<n;i++)
            {
                a[i] += a[i-1];
                ans.pb({i,i-1});
            }
        }
        else
        {
            while(a[negindx] > -20)
            {
                a[negindx] += a[negindx];
                ans.pb({negindx,negindx});
            }

            for(auto it : pos)
            {
                a[it] += a[negindx];
                ans.pb({it,negindx});
            }

            for(ll i = n-2;i>=0;i--)
            {
                a[i] += a[i+1];
                ans.pb({i,i+1});
            }
        }
    }
    else
    {
        ll maxabs = -1;
        ll maxabsindx = -1;
        bool ok = true;
        for(ll i=0;i<n;i++)
        {
            if(abs(a[i]) > maxabs)
            {
                maxabs = abs(a[i]);
                maxabsindx = i;
                if(a[i] > 0)
                {
                    ok = true;
                }
                else
                {
                    ok = false;
                }
            }
        }

        if(ok == true)
        {
            // maxabs is pos
            for(auto it : neg)
            {
                ans.pb({it,maxabsindx});
                a[it] += a[maxabsindx];
            }
            // all are pos
            for(ll i = 1;i<n;i++)
            {
                a[i] += a[i-1];
                ans.pb({i,i-1});
            }
            
        }
        else
        {
            //maxabs in neg
            for(auto it : pos)
            {
                ans.pb({it,maxabsindx});
                a[it] += a[maxabsindx];
            }
            for(ll i = n-2;i>=0;i--)
            {
                a[i] += a[i+1];
                ans.pb({i,i+1});
            }
        }
    }

    cout << ans.size()<<nl;

    for(auto it : ans)
    {
        cout << it.F + 1<<" "<<it.S + 1<<nl;
    }

    // for(int i =0;i<n;i++)
    // {
    //     cout << a[i]<<" ";
    // }
    // cout <<nl;
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