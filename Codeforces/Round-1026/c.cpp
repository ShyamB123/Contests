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

    vl d(n);

    for(int i =0;i<n;i++)
    {
        cin>>d[i];
    }
    vll a(n);

    for(int i =0;i<n;i++)
    {
        cin>>a[i].F>>a[i].S;
    }

    {
        ll l = 0;
        ll r = 0;
        ll prev = 0;

        for(int i =0;i<n;i++)
        {
            if(d[i] == 0)
            {
                // stays same

            }
            else if(d[i] == 1)
            {
                l++;
                r++;
            }
            else
            {
                r++;
            }

            l = max(l,a[i].F);
            r = min(r,a[i].S);

            if(l > r)
            {
                cout << -1 << nl;
                return;
            }

            // dbg(l)
            // dbg(r)
        }
    }

    // cout << "poss" << nl;
    vl ans(n,0);
    ll l = 0;
    ll r = 0;
    ll cur = 0;
    stack<ll> st;

    for(int i =0;i<n;i++)
    {
        if(d[i] == 0)
        {
            // stays same
            ans[i] = 0;
        }
        else if(d[i] == 1)
        {
            l++;
            r++;
            cur++;
            ans[i] = 1;
        }
        else
        {
            r++;
            st.push(i);
        }

        l = max(l,a[i].F);
        r = min(r,a[i].S);


        while(cur < a[i].F)
        {
            cur++;
            assert(st.size() > 0);

            ans[st.top()] = 1;
            st.pop();
        }
    }

    for(auto it : ans)
        cout << it << " ";
    
    cout << nl;

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