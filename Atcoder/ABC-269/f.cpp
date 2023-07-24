#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 998244353
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
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*
3 3
4
1 3 2 3
1 3 1 1
1 2 2 3
2 3 1 3

3 3
1
2 3 1 3

4 4
1
2 4 2 4

8 2
1
1 8 1 1

*/
ull n,m;

ull cal_value(ull a,ull b,ull c,ull d)
{
    ull w = d - c + 1;
    ull h = b - a + 1;

    ull t = (h + 1)/2;
    ull y = (w + 1)/2 - 1;
    // ull x = (a - 1) * m + c;
    ull x = ((a - 1)*m+ c)%mod;

    ull finalans =0;
    
    // ull ans =  t * (y + 1) * (x + y);
    ull ans = ((((t%mod) * ((y + 1)%mod))%mod) * ((x + y)%mod))%mod;

    // ull add = (t -1) * (t) * m * (y + 1);   
    // ull add = ((((((binexp(2,t)%mod) - 2 + mod)%mod) * m)%mod) * (y + 1))%mod ;
    ull add = ((((((t - 1) * t)%mod) * m)%mod) * ((y + 1)%mod))%mod;

    finalans += ans;
    finalans %= mod;
    finalans += add;
    finalans %= mod;

    return finalans;
}

void solve()
{
    
    cin>>n>>m;

    ull q;
    cin>>q;

    for(ull i=0;i<q;i++)
    {
        ull a,b,c,d;
        cin>>a>>b>>c>>d;
        ull finalans =0;
        // columns where the first row is filled
        // first col is white
        if((a + c) % 2 == 0)
        {
            {
                finalans += cal_value(a,b,c,d);
                finalans %= mod;
            }
            {
                if(a != b && c != d )
                {
                    a++;
                    c++;
                    finalans += cal_value(a,b,c,d);
                    finalans %= mod;
                }
                
            }
        }
        else
        {
            ull newa = a+1;
            ull newc = c;
            ull oga,ogb,ogc,ogd;
            oga = a;
            ogb = b;
            ogc = c;
            ogd = d;
            if(ogd - ogc >= 1)
            {
                a = oga;
                b = ogb;
                c = ogc + 1;
                d = ogd;
                {
                    finalans += cal_value(a,b,c,d);
                    finalans %= mod;
                }
                {
                    if(a != b && c != d )
                    {
                        a++;
                        c++;
                        finalans += cal_value(a,b,c,d);
                        finalans %= mod;
                    }
                    
                }
            }
            if(ogb - oga >=1)
            {
                a = oga + 1;
                b = ogb;
                c = ogc;
                d = ogc;
                {   
                    finalans += cal_value(a,b,c,d);
                    finalans %= mod;
                }
                {
                    if(a != b && c != d )
                    {
                        a++;
                        c++;
                        finalans += cal_value(a,b,c,d);
                        finalans %= mod;
                    }
                }
            }
        }
        cout << finalans<<nl;
    }
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}