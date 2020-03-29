#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
// reference = https://www.codechef.com/JAN17/problems/CHEFCIRC/ 
// https://www.codechef.com/viewsolution/12554906
using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 600, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double PRECISION = 1e-6;
const double EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

int n;
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
    inline void read() {
        scanf("%lf%lf", &x, &y);
    }
    inline Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
    inline Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    inline Point operator*(const double& k) const {
        return Point(k * x, k * y);
    }
    inline double operator*(const Point& p) const {
        return x * p.x + y * p.y;
    }
    inline double operator^(const Point& p) const {
        return x * p.y - y * p.x;
    }
    inline Point rotate(double rad) {
        return Point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    }
    inline double length() {
        return sqrt(x * x + y * y);
    }
    inline double angle() {
        return atan2(y, x);
    }
    inline void norm() {
        double l = length();
        x /= l, y /= l;
    }
    void see() {
        printf("%.4f %.4f\n", x, y);
    }
} ps[N];

typedef Point Vector;
pair<double, int> angles[N];
double arr_length[N][N];
double arr_angle[N][N];

int max_points(int n , double r) {

    int ans = 1;
    for(int i = 1; i <= n; ++i) {
        int m = 0;
        for(int j = 1; j <= n; ++j) {
            if(i == j) continue;
            double c = arr_length[i][j];
            //cout<<c<<" "<<(double)2*r<<endl;
            if(sgn(c - (double)2*r) > 0) continue;
            double angle = arr_angle[i][j];
            double delta = acos(c / ((double)2*r));
            angles[m++] = make_pair(angle - delta - EPS, 1);
            angles[m++] = make_pair(angle + delta + EPS, -1);
        }
        sort(angles, angles + m);

        int cnt = 1;
        for(int j = 0; j < m; ++j) {
            //cout<<angles[j].first<<" "<<angles[j].second<<endl;
            cnt += angles[j].second;
            ans = max(ans, cnt);
        }
        //cout<<endl<<endl;
    }
    return ans;
}

int main() {
  #ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
  #endif
    int n,m;
    cin>>n;
    m = n;
    for(int i=1 ; i<=n ; i++)
    {
        ps[i].read();
    }

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if(i==j) continue;
            Vector AB = ps[j] - ps[i];
            arr_length[i][j] = AB.length();
            arr_angle[i][j] = AB.angle();
        }
    }

    double low=0.0,high=1500.0;
    while(high-low > PRECISION)
    {
        double mid = (high+low)/2;
        int x = max_points(n,mid);
        if(x>=m)
        {
            high=mid;
        }
        else
        {
            low=mid;
        }
    }
    cout<<fixed << setprecision(8) << (low+high)/2<<endl;
    return 0;
}