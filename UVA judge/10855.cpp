#include <iostream>

using namespace std;

char **rotate( char **square, int n )
{
    char **aux = new char*[ n ];
    for( int i = 0; i < n; i++ )
        aux[i] = new char[ n ];
    int x = n-1, y;
    for( int i = 0; i < n; i++ )
    {
        y = 0;
        for( int j = 0; j < n; j++ )
            aux[ y++ ][ x ]  = square[i][j];
        x--;
    }
    return aux;
}

int main()
{
    ios_base::sync_with_stdio( false );
    char **squareBig, **squareSmall, tmp;
    int N, n, i, aux, p;
    bool isSubMax;
    while( cin >> N >> n, N || n )
    {
        squareBig = new char*[ N ];
        for( i = 0; i < N; i++ )
        {
            squareBig[i] = new char[ N ];
            cin >> squareBig[i];
        }
        squareSmall = new char*[ n ];
        for( i = 0; i < n; i++ )
        {
            squareSmall[i] = new char[ n ];
            cin >> squareSmall[i];
        }
        p = 4;
        while( p-- )
        {
            aux = 0;
            for( i = 0; i < N-n+1; i++ )
            {
                for( int j = 0; j < N-n+1; j++ )
                {
                    isSubMax = true;
                    for( int a = 0; a < n && isSubMax; a++ )
                        for( int b = 0; b < n && isSubMax; b++ )
                            if( squareSmall[a][b] != squareBig[a+i][b+j] )
                                isSubMax = false;
                    if( isSubMax )
                        aux++;
                }
            }
            if( p == 3 )
                cout << aux;
            else
                cout << " " << aux;
            if( p != 0 )
                squareSmall = rotate( squareSmall, n );
        }
        cout << "\n";
    }
    return 0;
}