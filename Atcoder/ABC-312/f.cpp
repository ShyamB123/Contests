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
4 3
0 10
0 11
1 12
2 3
*/



void solve()
{
    ll n,m;
    cin>>n>>m;

    multiset<ll> ms,cur;
    multiset<ll> twos;


    vl zero,one;
    for(ll i=0;i<n;i++)
    {
        ll t,x;
        cin>>t>>x;

        if(t == 2)
        {
            twos.insert(x);
        }
        else
        {
            if(t == 0)
            {
                zero.pb(x);
            }
            else
            {
                one.pb(x);
            }
        }
    }

    sort(all(zero));
    reverse(all(zero));
    
    ll ans = 0;
    ll sum = 0;
    for(ll i =0;i<zero.size();i++)
    {
        if(cur.size() == m)
        {
            // ms.insert({0,zero[i]});
            break;
        }
        else
        {
            cur.insert(zero[i]);
            sum += zero[i];
        }
    }

    for(auto it : one)
    {
        ms.insert(it);
    }

    ans = sum;


    ll turns =  0;
    // if(twos.size() > 0)
    // {
    //     turns = *twos.rbegin();
    //     twos.erase(twos.find(turns));
    //     m--;
    // }
    
    // while(cur.size()>m)
    // {
    //     sum -=*cur.begin();
    //     cur.erase(cur.find(*cur.begin()));
    // }

    while(m > 0 && ms.size() > 0)
    {
        if(turns == 0)
        {
            if(twos.size() > 0)
            {
                turns += *twos.rbegin();
                twos.erase(twos.find(turns));
                m--;
                // cur.erase(cur.find(*cur.begin()));
            }
            else
            {
                break;
            }
        }

        while(cur.size()>m)
        {
            sum -=*cur.begin();
            cur.erase(cur.find(*cur.begin()));
            
        }
        if(cur.size() == m)
        {
            if (( *ms.rbegin()) < (*cur.begin()))
            {
                // cout << ( *ms.rbegin()).S <<" "<<(*cur.begin()).S<<nl;
                break;
            }
            auto elsmall = *ms.rbegin();
            auto elbig = *cur.begin();
            ll small = elsmall;
            ll big = elbig;
            
            cur.erase(cur.find(elbig));
            cur.insert(elsmall);
            ms.erase(ms.find(elsmall));
            sum += small - big;    
            turns--;
        }
        else
        {
            auto elsmall = *ms.rbegin();
            ll small = elsmall;
            cur.insert(elsmall);
            ms.erase(ms.find(elsmall));
            sum += small;
            turns--;
        }
        ans = max(ans,sum);
    }

    cout << ans<<nl;





}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}