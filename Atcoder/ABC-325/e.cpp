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
    ll n,a,b,c;
    cin>>n>>a>>b>>c;

    ll d[n][n];

    // vector<vector<pair<ll,ll>>> adjc(n + 1);
    // vector<vector<pair<ll,ll>>> adjt(n + 1);

    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>d[i][j];
        }
    }

     vector<ll> dpc(n,inf);
     vector<ll> dpt(n,inf);

    {
       

        dpc[0] = 0;

        priority_queue<pair<ll,ll>> pq;

        pq.push({0,0});

        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();

            ll src = el.S;
            ll dist = -el.F;

            if(dpc[src] < dist)
            {
                continue;
            }

            for(int i = 0;i<n;i++)
            {
                ll newdist = dist + d[src][i] * a;

                if(newdist < dpc[i])
                {
                    dpc[i] = newdist;
                    pq.push({-newdist,i});
                }
            }
        }

        // dbg(dpc);
    }

    {

        dpt[n-1] = 0;

        priority_queue<pair<ll,ll>> pq;

        pq.push({0,n-1});

        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();

            ll src = el.S;
            ll dist = -el.F;

            if(dpt[src] < dist)
            {
                continue;
            }

            for(int i = 0;i<n;i++)
            {
                ll newdist = dist + d[src][i] * b + c;

                if(newdist < dpt[i])
                {
                    dpt[i] = newdist;
                    pq.push({-newdist,i});
                }
            }
        }

        // dbg(dpt);
    }

    ll ans = inf;
    for(int i = 0;i<n;i++)
    {
        ans = min(ans,dpc[i] + dpt[i]);
    }

    cout << ans <<nl;







}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}