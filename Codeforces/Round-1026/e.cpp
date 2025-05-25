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
ll n;
vll ans;
map<pair<ll,ll>,ll> indx;

void check(int cur,bool ok,map<ll,set<ll>> &ladj,map<ll,set<ll>> &radj)
{
    if(ok == true)
    {
        while(ladj[cur].size() > 0)
        {
            int nr = *ladj[cur].begin();
            ladj[cur].erase(nr);
            radj[nr].erase(cur);
            
            check(nr,!ok,ladj,radj);
            ans.pb({cur,nr});
        }
    }
    else
    {
        while(radj[cur].size() > 0)
        {
            int nr = *radj[cur].begin();
            radj[cur].erase(nr);
            ladj[nr].erase(cur);
            
            check(nr,!ok,ladj,radj);
            ans.pb({nr,cur});
        }
    }
}

void solve()
{
    // alternate btw vol and pitch

    cin>>n;

    vll a(n);

    indx.clear();
    ans.clear();

    map<ll,set<ll>> ladj;
    map<ll,set<ll>> radj;
    map<ll,ll> cnt;
    for(int i =0;i<n;i++)
    {
        cin>>a[i].F>>a[i].S;
        cnt[a[i].F]++;
        cnt[a[i].S]++;

        ladj[a[i].F].insert(a[i].S);
        radj[a[i].S].insert(a[i].F);

        indx[{a[i].F,a[i].S}] = i;
    }

    // int odd = 0;
    // vl odds;
    // for(auto [it,freq] : cnt)
    // {
    //     if(freq % 2 == 1)
    //     {
    //         odd++;
    //         odds.pb(it);
    //     }
    // }

    map<ll,ll> hcnt,lcnt;
    for(int i =0;i<n;i++)
    {
        hcnt[a[i].F]++;
        lcnt[a[i].S]++;
    }
    // ll tar;
    ll odds = 0;
    for(auto [it,freq] : hcnt)
    {
        if(freq % 2 == 1)
        {
            odds++;
        }
    }

    for(auto [it,freq] : lcnt)
    {
        if(freq % 2 == 1)
        {
            odds++;
        }
    }

    if(odds == 1 || odds > 2)
    {
        cout << "NO" << nl;
        return;
    }
    
    auto ogladj = ladj;
    auto ogradj = radj;
    
    if(odds == 0)
    {
        check(a[0].F,true,ladj,radj);
    }
    else
    {   
        bool ok = false;
        for(int i =0;i<n;i++)
        {
            if(hcnt[a[i].F] % 2 == 1)
            {
                check(a[i].F,true,ladj,radj);
                ok = true;
                break;
            }
        }
        if(!ok)
        {
            for(int i =0;i<n;i++)
            {
                if(lcnt[a[i].S] % 2 == 1)
                {
                    check(a[i].S,false,ladj,radj);
                    ok = true;
                    break;
                }
            }     
        }
    }
    if(ans.size() != n)
    {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    for(auto it : ans)
    {
        cout << indx[it] + 1 << " ";
    }
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