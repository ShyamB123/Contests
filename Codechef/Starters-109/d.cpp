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
1
5 3
-1 -1 4 4 4
-1 -1 -1 -1 -1
*/



void solve()
{
    ll n,d;
    cin>>n>>d;

    ll b[n];
    ll c[n];

    for(ll i =0;i<n;i++)
    {
        cin>>b[i];
    }

    for(ll i=0;i<n;i++)
    {
        cin>>c[i];
    }

    for(int i=1;i<n;i++)
    {
        if((b[i] < b[i - 1]) ||( c[i] > c[i - 1]))
        {
            cout <<"NO"<<nl;
            return;
        }
    }

    ll precurmax = -inf;
    ll precurmin = inf;

    vl ans(n,-inf);
    vi indices;


    for(ll i=0;i<n;i++)
    {
        if(i == 0)
        {
            if(b[i] != c[i])
            {
                cout <<"NO"<<nl;
                return;
            }
            ans[i] = b[i];
            precurmax = b[i];
            precurmin = c[i];
            indices.pb(i);
            continue;
        }

        if(precurmax != b[i] && precurmin != c[i])
        {
            cout <<"NO"<<nl;
            return;
        }
        else if(precurmax == b[i] && precurmin == c[i])
        {
            // NO change 
        }
        else if(precurmax != b[i])
        {
            if(abs(b[i] - precurmax) > d)
            {
                cout <<"NO"<<nl;
                return;
            }
            ans[i] = b[i];
            precurmax = b[i];
            indices.pb(i);
        }
        else
        {
            if(abs(c[i] - precurmin) > d)
            {
                cout <<"NO"<<nl;
                return;
            }
            ans[i] = c[i];
            precurmin = c[i];
            indices.pb(i);
        }
    }

    for(ll i = 1;i<indices.size();i++)
    {
        ll len = indices[i] - indices[i - 1];
        ll dif = abs(ans[indices[i]] - ans[indices[i - 1]]);

        if(dif > len * d)
        {
            cout <<"NO"<<nl;
            return;
        }


        if(ans[indices[i - 1]] > ans[indices[i]])
        {
            ll j = indices[i-1] + 1;
            ll cur = max(c[j],ans[indices[i-1]] - d);
            while(j < indices[i] && cur > ans[indices[i]])
            {
                ans[j] = cur;
                cur -= d;
                if(cur < c[j + 1])
                {
                    cur = c[j + 1];
                }
                j++;
            }
            
            cur = ans[indices[i]];
            while(j < indices[i])
            {
                ans[j] = cur;
                j++;
            }

            if(abs(ans[indices[i]] - ans[indices[i] - 1]) > d)
            {
                cout <<"NO"<<nl;
                return;
            }
        }
        else
        {
            ll j = indices[i-1] + 1;
            ll cur = min(b[j],ans[indices[i-1]] + d);

            while(j < indices[i] && cur < ans[indices[i]])
            {
                ans[j] = cur;
                cur += d;
                if(cur > b[j + 1])
                {
                    cur = b[j + 1];
                }
                j++;
            }
            cur = ans[indices[i]];
            while(j < indices[i])
            {
                ans[j] = cur;
                j++;
            }
            if(abs(ans[indices[i]] - ans[indices[i] - 1]) > d)
            {
                cout <<"NO"<<nl;
                return;
            }
        }
    }

    // dbg(indices);

    for(ll i = indices.back() + 1;i<n;i++)
    {
        ans[i] = ans[indices.back()];
    }

    cout <<"YES"<<nl;

    for(auto it : ans)
    {
        cout << it <<" ";
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