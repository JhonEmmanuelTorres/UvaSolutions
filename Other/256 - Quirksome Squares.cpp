#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<short,short> Pair;

int main()
{
    ll aux;
    short x, y, a, expo;

    vector<vector<Pair>> container;
    vector<ll> squares( 10000 );
    for( int i = 0; i < 10000; i++ )
        squares[ i ] = i*i;

    for( int i = 10, digits = 1; digits <= 4; i *= 10, digits++ )
    {
        container.push_back( vector<Pair>() );
        for( int j = 0; j < i; j++ )
        {
            aux = squares[j];
            x = y = 0;
            for( a = 0, expo = 1; a < digits; a++, expo *= 10 )
            {
                x += (aux%10)*expo;
                aux /= 10;
            }
            for( a = 0, expo = 1; a < digits; a++, expo *= 10 )
            {
                y += (aux%10)*expo;
                aux /= 10;
            }
            if( x + y == j )
                container[ digits - 1 ].push_back( make_pair( y, x ) );
        }
    }

    char format[] = "%05hd%05hd\n";
    while( cin >> x )
    {
        x /= 2;
        format[ 2 ] = format[ 7 ] = x-- + '0';

        for( auto i: container[x] )
            printf( format, i.first, i.second );
    }

    return 0;
}
