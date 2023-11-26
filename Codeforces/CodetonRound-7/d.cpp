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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

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
    ll n,q;
    cin>>n>>q;

    ll a[n];

    set<ll> os;
    for(ll i =0;i<n;i++)
    {
        cin>>a[i];
        if(a[i] == 1)
            os.insert(i);
    }

    for(ll qr = 0;qr < q;qr++)
    {
        ll ch;
        cin>>ch;

        if(ch == 1)
        {
            ll sum;
            cin>>sum;
            if(os.size() > 0)
            {
                ll firstone = *os.begin();

                ll len = n - firstone ;
                ll val = len + (len - os.size());

                if(val >= sum)
                {
                    cout <<"Yes"<<nl;
                }
                else
                {
                    ll lefttwos = firstone;
                    if(val + lefttwos * 2 < sum)
                    {
                        cout <<"No"<<nl;
                    }
                    else
                    {
                        if((sum - val)%2 == 0)
                        {
                            cout <<"Yes"<<nl;

                        }
                        else
                        {
                            ll lastindx = *os.rbegin();
                            ll righttwos = n - lastindx - 1;

                            ll maxtwos = max(righttwos,lefttwos);
                            val -= 2 * righttwos; 

                            if(val + maxtwos * 2 >= sum)
                            {
                                cout <<"Yes"<<nl;
                            }
                            else
                            {
                                cout <<"No"<<nl;
                            }
                        }

                    }
                }
            
            }
            else
            {
                if(sum <= 2 * n && sum%2 == 0)
                {
                    cout <<"Yes"<<nl;
                }
                else
                {
                    cout <<"No"<<nl;
                }
            }
        }
        else
        {
            ll indx,v;
            cin>>indx>>v;
            indx--;

            if(a[indx] != v)
            {
                if(v == 1)
                {
                    os.insert(indx);
                }
                else
                {
                    os.erase(indx);
                }
            }
            a[indx] = v;
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