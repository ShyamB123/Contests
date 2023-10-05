#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
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
#define dbg(x)         \
    cout << #x << " "; \
    _print(x);         \
    cout << endl;

void _print(ll t)
{
    cout << t;
}
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(ld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }

template <class T>
void _print(vector<vector<T>> v)
{
    for (int j = 0; j < v.size(); j++)
    {
        cout << nl << "[ ";
        for (T i : v[j])
        {
            _print(i);
            cout << " ";
        }
        cout << "]";
    };
}
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cout << "{";
    _print(p.F);
    cout << ",";
    _print(p.S);
    cout << "}";
}
template <class T>
void _print(vector<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(set<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cout << "[ ";
    for (T i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cout << "[ ";
    for (auto i : v)
    {
        _print(i);
        cout << " ";
    }
    cout << "]";
}
template <class T>
void _print(vector<vector<vector<T>>> v)
{
    for (int k = 0; k < v.size(); k++)
    {
        _print(v[k]);
    }
}
//----------------------------------------------------------------------------------------

bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/

vector<vector<int>> a(4, vi(4, 0)), b(4, vi(4, 0)), c(4, vi(4, 0));
vi lrud(4,0);
bool poss = false;
void rotate(int x)
{
    if(x == 1)
    {
        auto temp = a;

        for(int i =0;i<4;i++)
        {
            for(int j = 0;j<4;j++)
            {
                temp[i][j] = a[j][3 - i];
            }
        }

        a = temp;

    }
    else if(x == 2)
    {
        auto temp = b;

        for(int i =0;i<4;i++)
        {
            for(int j = 0;j<4;j++)
            {
                temp[i][j] = b[j][3 - i];
            }
        }

        b = temp;
    }
    else
    {
        auto temp = c;

        for(int i =0;i<4;i++)
        {
            for(int j = 0;j<4;j++)
            {
                temp[i][j] = c[j][3 - i];
            }
        }

        c = temp;
    }
}

void findtopleft(int x)
{
    int left = 4,top = 4;
    int bottom = 0,right = 0;
    if(x == 1)
    {
 
        for(int i =0;i<4;i++)
        {
            for(int j =0;j<4;j++)
            {
                if(a[i][j] == 1)
                {
                    left = min(left,j);
                    top = min(top,i);
                    bottom = max(bottom,i);
                    right = max(right,j);
                }
            }
        }
    }
    else if(x == 2)
    {

        for(int i =0;i<4;i++)
        {
            for(int j =0;j<4;j++)
            {
                if(b[i][j] == 1)
                {
                    left = min(left,j);
                    top = min(top,i);
                    bottom = max(bottom,i);
                    right = max(right,j);
                }
            }
        }
    }
    else
    {

        for(int i =0;i<4;i++)
        {
            for(int j =0;j<4;j++)
            {
                if(c[i][j] == 1)
                {
                    left = min(left,j);
                    top = min(top,i);
                    bottom = max(bottom,i);
                    right = max(right,j);
                }
            }
        }
    }

    lrud[0] = left;
    lrud[1] = right;
    lrud[2] = top;
    lrud[3] = bottom;
}


vector<vi> tg = {{1,1,1,1},{1,1,1,1},{0,0,0,1},{0,0,0,0}};

void setC(vector<vi> &grid)
{
    // find the top left

    // dbg(tg);


        for(int rot = 0;rot<4;rot++)
        {
            findtopleft(3);
            int left = lrud[0];
            int right = lrud[1];
            int top = lrud[2];
            int bottom = lrud[3]; 

            int height = bottom - top + 1;
            int width = right - left + 1;

            // dbg(c);

            // place this top left

            for(int x = 0;x<4;x++)
            {
                for(int y = 0;y<4;y++)
                {
                    if(x + height - 1 >= 4 || y + width - 1 >= 4)
                    {
                        continue;
                    }
                    auto tempgrid = grid;
                    bool ok = true;

                    for(int i =top;i<=bottom;i++)
                    {
                        for(int j =left ;j<=right;j++)
                        {
                            if(x + i - top>= 4 || y + j - left >= 4)
                            {
                                // ok = false;
                                continue;
                            }
                            if(grid[x + i - top][y + j - left] == 1 && c[i][j] == 1)
                            {
                                ok = false;
                            }
                            else
                            {
                                tempgrid[x + i - top][y + j - left] ^= c[i][j];
                            }
                        }
                    }

                    // dbg(tempgrid);

                    if(ok)
                    {
                        // setC(tempgrid);
                        // dbg(tempgrid);
                        bool empty = false;
                        for(int h =0;h<4;h++)
                        {
                            for(int l = 0;l<4;l++)
                            {
                                if(tempgrid[h][l] == 0)
                                    empty = true;
                            }
                        }
                        if(empty == false)
                            poss = true;
                    }
                }
            }

            rotate(3);
        }
    
}

void setB(vector<vi> &grid)
{
    // find the top left

    for(int rot = 0;rot<4;rot++)
    {
        findtopleft(2);
        int left = lrud[0];
        int right = lrud[1];
        int top = lrud[2];
        int bottom = lrud[3]; 

        int height = bottom - top + 1;
        int width = right - left + 1;

        // place this top left

        for(int x = 0;x<4;x++)
        {
            for(int y = 0;y<4;y++)
            {
                if(x + height - 1 >= 4 || y + width - 1 >= 4)
                {
                    continue;
                }
                auto tempgrid = grid;
            bool ok = true;

                for(int i =top;i<=bottom;i++)
                {
                    for(int j =left ;j<=right;j++)
                    {
                        if(x + i - top>= 4 || y + j - left >= 4)
                        {
                            // ok = false;
                            continue;
                        }
                        if(grid[x + i - top][y + j - left] == 1 && b[i][j] == 1)
                        {
                            ok = false;
                        }
                        else
                        {
                            tempgrid[x + i - top][y + j - left] ^= b[i][j];
                        }
                    }
                }

                if(ok)
                {
                    setC(tempgrid);
                    // dbg(tempgrid);
                }
            }
        }

        rotate(2);
    }
}

void setA(vector<vi> &grid)
{
    // find the top left

    for(int rot = 0;rot<4;rot++)
    {
        findtopleft(1);
        int left = lrud[0];
        int right = lrud[1];
        int top = lrud[2];
        int bottom = lrud[3]; 

        int height = bottom - top + 1;
        int width = right - left + 1;

        // place this top left

        for(int x = 0;x<4;x++)
        {
            for(int y = 0;y<4;y++)
            {
                if(x + height - 1 >= 4 || y + width - 1 >= 4)
                {
                    continue;
                }
                auto tempgrid = grid;
            bool ok = true;

                for(int i =top;i<=bottom;i++)
                {
                    for(int j =left ;j<=right;j++)
                    {
                        if(x + i - top>= 4 || y + j - left >= 4)
                        {
                            // ok = false;
                            continue;
                        }
                        if(grid[x + i - top][y + j - left] == 1 && a[i][j] == 1)
                        {
                            ok = false;
                        }
                        else
                        {
                            tempgrid[x + i - top][y + j - left] ^= a[i][j];
                        }
                    }
                }

                if(ok)
                {
                    setB(tempgrid);
                    // dbg(tempgrid);
                }
            }
        }

        rotate(1);
    }
}

void solve()
{
    vector<vector<int>> grid(4, vi(4, 0));

    for (int x = 0; x < 3; x++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                char ch;
                cin >> ch;
                if (x == 0)
                {
                    if (ch == '.')
                    {
                        a[i][j] = 0;
                    }
                    else
                    {
                        a[i][j] = 1;
                    }
                }
                else if(x == 1)
                {
                    if (ch == '.')
                    {
                       b[i][j] = 0;
                    }
                    else
                    {
                        b[i][j] = 1;
                    }
                }
                else
                {
                    if (ch == '.')
                    {
                        c[i][j] = 0;
                    }
                    else
                    {
                        c[i][j] = 1;
                    }
                }
            }
        }
    }

    setA(grid);

    if(poss)
    {
        cout << "Yes"<<nl;
    }
    else
    {
        cout <<"No"<<nl;
    }


}

int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}