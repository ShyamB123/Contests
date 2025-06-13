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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve()
{
    ll n,k;
    cin>>n>>k;

    vl a(n);
    vl d(n);

    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(int i =0;i<n;i++)
    {
        cin>>d[i];
    }

    ll q;
    cin>>q;

    vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(k,vector<bool>(2,false)));

    for(int qr =0 ;qr < q;qr++)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<k;j++)
            {
                for(int l =0;l<2;l++)
                {
                    dp[i][j][l] = false;
                }
            }
        }

        ll curloc;
        cin>>curloc;
        ll curtime = 0;

        bool ok = true;
        // true means right, false is left
        ll indx = n;
        for(int i =0;i<n;i++)
        {
            if(a[i] >= curloc)
            {
                indx = i;
                break;
            }
        }

        if(indx == n)
        {
            cout << "YES" << nl;
            continue;
        }

        curtime = (a[indx] - curloc) % k;
        curloc = a[indx];

        while(indx >= 0 && indx < n && dp[indx][curtime][ok] == false)
        {
            dp[indx][curtime][ok] = true;

            if(ok)
            {
                // right
                if(curtime == d[indx])
                {
                    // turn 
                    ok = false;
                    if(indx - 1 >= 0)
                        curtime += abs(a[indx - 1] - a[indx]);
                    curtime %= k;
                    cout << "going from " << indx << " to " << indx - 1 << nl; 
                    indx--;

               }
                else
                {
                    if(indx + 1 < n)
                        curtime += abs(a[indx + 1] - a[indx]);
                    curtime %= k;
                    cout << "going from " << indx << " to " << indx + 1 << nl; 
                    indx++;     
                }
            }
            else
            {
                if(curtime == d[indx])
                {
                    // turn 
                    ok = true;

                    if(indx + 1 < n)
                        curtime += abs(a[indx + 1] - a[indx]);
                    curtime %= k;
                    cout << "going from " << indx << " to " << indx + 1 << nl; 
                    indx++;  
                }
                else
                {
                    if(indx - 1 >= 0)
                        curtime += abs(a[indx - 1] - a[indx]);
                    curtime %= k;
                    cout << "going from " << indx << " to " << indx - 1 << nl; 
                    indx--;    
                }
            }
        }

        // for(int i = 0;i<n;i++)
        // {
        //     for(int j =0;j<k;j++)
        //     {
        //         for(int l =0;l<2;l++)
        //         {
        //             cout << i << " " << j << " " << l << " " << (dp[i][j][l] ? 1 : 0) << nl;
        //         }
        //     }
        // }

        if(indx < 0 || indx >= n)
        {
            cout << "YES" << nl;
        }
        else
        {
            cout << "NO" << nl;
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