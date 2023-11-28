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
    ll n,k;
    cin>>n>>k;

    vll a(n);
    vl x(n);
    vl y(n);

    for(int i =0;i<n;i++)
    {
        cin>>a[i].F>>a[i].S;
        x[i] = a[i].F;
        y[i] = a[i].S;
    }

    sort(all(x));
    sort(all(y));
    vl prex(n + 1,0);
    vl prey(n + 1,0);


    for(int i=0;i<n;i++)
    {
        prex[i + 1] = prex[i] + x[i];
        prey[i + 1] = prey[i] + y[i];
    }

    ll N_LIM = 1e9 + 1;
    ll sn = 0;
    ll en = N_LIM;
    ll ansn = en;

    while(sn <= en)
    {
        ll midn = (en + sn)/2;

        // choose the best point

        ll POINT_LIM = 1e9 + 1;
        ll sx = 0;
        ll ex = POINT_LIM;
        ll ansx = inf;
        ll valx = inf;

        while(sx <= ex)
        {
            ll midx = (sx + ex)/2;


            // left point
            ll left = midx;
            ll right = midx + midn;
            ll curval1 = 0;
            ll curval2 = 0;

            {
                ll indx1 = lower_bound(all(x),left) - x.begin();

                curval1 += indx1 * left - prex[indx1];

                ll indx2 = upper_bound(all(x),right) - x.begin();

                if(indx2 != n)
                {
                    curval1 += prex[n] - prex[indx2 ] - (n - indx2) * right;
                }
            }
            {
                ll indx1 = lower_bound(all(x),left + 1) - x.begin();

                curval2 += indx1 * (left + 1) - prex[indx1];

                ll indx2 = upper_bound(all(x),right + 1) - x.begin();

                if(indx2 != n)
                {
                    curval2 += prex[n] - prex[indx2 ] - (n - indx2) * (right + 1);
                }
            }

            valx = min({valx,curval1,curval2});
            if(curval1 > curval2)
            {
                sx = midx + 1;
            }
            else
            {
                ex= midx - 1;
            }
        }   
        ll sy = 0;
        ll ey = POINT_LIM;
        ll ansy = inf;
        ll valy = inf;
        while(sy <= ey)
        {
            ll midy = (sy + ey)/2;


            // left point
            ll left = midy;
            ll right = midy + midn;
            ll curval1 = 0;
            ll curval2 = 0;

            {
                ll indx1 = lower_bound(all(y),left) - y.begin();

                curval1 += indx1 * left - prey[indx1];

                ll indx2 = upper_bound(all(y),right) - y.begin();

                if(indx2 != n)
                {
                    curval1 += prey[n] - prey[indx2]- (n - indx2) * right;
                }
            }
            {
                ll indx1 = lower_bound(all(y),left + 1) - y.begin();

                curval2 += indx1 * (left + 1) - prey[indx1];

                ll indx2 = upper_bound(all(y),right + 1) - y.begin();

                if(indx2 != n)
                {
                    curval2 += prey[n] - prey[indx2 ]- (n - indx2) * (right + 1);
                }
            }

            valy = min({valy,curval1,curval2});
            if(curval1 > curval2)
            {
                sy = midy + 1;
            }
            else
            {
                ey = midy - 1;
            }
        } 

        if(valy + valx <= k)
        {
            ansn = midn;
            en = midn - 1;
            // dbg(valy);
            // dbg(valx);
        }
        else{
            sn = midn + 1;
        }
    }

    cout << ansn <<nl;

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}