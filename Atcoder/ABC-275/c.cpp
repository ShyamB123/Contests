#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
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
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*
##.......
##.......
.........
.......#.
.....#...
......###
......##.
.........
.........

*/



void solve()
{
    ll n = 9;

    char a[n][n];

    for(ll i =0;i<n;i++)
    {
        for(ll j =0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    set<vll> s;
    ll count =0;
    for(ll tlx = 0;tlx<n;tlx++)
    {
        for(ll tly = 0;tly<n;tly++)
        {
            if(a[tlx][tly] == '#')
            {
                // top left poll is tlx tly
                for(ll trx = 0;trx<n;trx++)
                {
                    for(ll try_ = 0;try_<n;try_++)
                    {
                        // top right poll is tlx tly
                        if(a[trx][try_] == '#' && (trx != tlx || try_!= tly) )
                        {
                            ll brx,bry,blx,bly;

                            ll xdiff = abs(tlx - trx);
                            ll ydiff = abs(tly - try_);
                            
                            brx = tlx + ydiff;
                            bry = tly + xdiff;

                            blx = trx + ydiff;
                            bly = try_ + xdiff;
                             vll p;
                            p.pb({tlx,tly});
                            p.pb({trx,try_});
                            p.pb({brx,bry});
                            p.pb({blx,bly});
                            sort(all(p));



                            if(brx >= 0 && brx <n && blx >= 0 && blx <n && (brx != blx || bry!= bly) && (brx != tlx || bry!= tly) && (brx != trx || bry!= try_)&& (blx != tlx || bly!= tly) && (blx != trx || bly!= try_))
                            {
                                if(a[brx][bry] == '#' && a[blx][bly] == '#')
                                {
                                    if(s.find(p) == s.end())
                                    {
                                        count++;
                                       
                                    }
                                    s.insert(p);
                                    // dbg(p);
                                }
                                 
                            }
                        }
                    }
                }

            }
        }
    }

    // dbg(s);

    cout <<count<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}