#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

void extendedEuclides( ll a, ll b, ll &x, ll &y, ll &d )
{
    if( b == 0 ) { x = 1; y = 0; d = a; return; }
    extendedEuclides( b, a % b, x, y, d );
    long x1 = y;
    long y1 = x - ( a / b ) * y;
    x = x1;
    y = y1;
}

int main()
{
    ios_base::sync_with_stdio( false );
    short t;
    int x1, k;
    ll a, b, x, y, d;
    for( cin >> t; t > 0; t-- )
    {
        cin >> x1 >> k;
        a = floor( x1 / (double)k );
        b = ceil( x1 / (double)k );
        extendedEuclides( a, b, x, y, d );
        x1 /= d;
        cout << ( x * x1 ) << " " << ( y * x1 ) << endl;
    }
    return 0;
}
