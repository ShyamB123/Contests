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
ll n,x,k;

ll checkleft(ll src,ll dist)
{
    // dbg(src);
    if(src > n)
    {
        return -1;
    }
    if(dist == 0)
    {
        return src;
    }
    // ll a
    if(n/src < 2)
    {
        return -1;
    }
    return checkleft(2 * src,dist - 1);


}
ll checkright(ll src,ll dist)
{
    // dbg(src);
    if(src > n)
    {
        return -1;
    }
    if(dist == 0)
    {
        return src;
    }


    if((n - 1)/src < 2)
    {
        return -1;
    }
    return checkright(2 * src + 1,dist -1);
       
    // return check(2 * src,dist - 1) + check(2 * src + 1,dist - 1);


}


void solve()
{
    cin>>n>>x>>k;

    // check down
    ll curdist = k;
    ll l = checkleft(x,k);
    ll r = checkright(x,k);

    ll ans = 0;

    if(l != -1)
    {
        if(r == -1)
        {
            ans += n - l + 1;
        }
        else
        {
            ans += r - l + 1;
        }
    }

    while(x/2 > 0)
    {
        curdist--;
        if(curdist == 0)
        {
            ans++;
            break;
        }
        // go one level up

        ll up = x/2;
        
        if(x%2 == 0)
        {
            //check right
            // ans += check(2 * up + 1,curdist-1);
            ll left = checkleft(2 * up + 1,curdist-1);
            ll right = checkright(2 * up + 1,curdist-1);
            
            if(left != -1)
            {
                if(right == -1)
                {
                    ans += n - left + 1;
                }
                else
                {
                    ans += right - left + 1;
                }
            }
        }
        else
        {
            // check left
            // ans += check(2 * up ,curdist-1);

             ll left = checkleft(2 * up ,curdist-1);
            ll right = checkright(2 * up ,curdist-1);
            
            if(left != -1)
            {
                if(right == -1)
                {
                    ans += n - left + 1;
                }
                else
                {
                    ans += right - left + 1;
                }
            }
        }

        x = up;
    }

    cout << ans <<nl;
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