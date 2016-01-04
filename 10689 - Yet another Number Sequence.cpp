#include <iostream>
#include <cmath>

using namespace std;

void calc( int repeat, int a, int b, int n, int m )
{
    n = n % repeat;
    int *serieFibo = new int[ n + 2 ];
    serieFibo[0] = a;
    serieFibo[1] = b;
    int i = 2;
    m = pow( 10, m );
    for(; i < n + 1; i++ )
        serieFibo[i] = (serieFibo[i-1] + serieFibo[i-2]) % m;
    cout << serieFibo[ n ] % m << endl;
}

int main()
{
    int t, a, b, n, m;
    cin >> t;
    while( t-- )
    {
        cin  >> a >> b >> n >> m;
        switch( m )
        {
            case 1:
                calc( 60, a, b, n, m);
                break;
            case 2:
                calc( 300, a, b, n, m);
                break;
            case 3:
                calc( 1500, a, b, n, m);
                break;
            case 4:
                calc( 15000, a, b, n, m);
                break;
        }
    }
    return 0;
}
