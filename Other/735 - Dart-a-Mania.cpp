#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


inline int ca( int a, int b )
{
    return a == 50 ? 50 : a * b;
}

int main()
{
    ios_base::sync_with_stdio( false );
    int n, p, c;
    string line = string( 70, '*' );
    set< tuple<int,int,int> > combination, permutation;
    vector<int> auxSort( 3, 0 );
    cin >> n;
    while( true )
    {
        permutation.clear();
        combination.clear();
        for( int i = 0; i <= 21; i++ ) {
            if( i == 21 ) i = 50;
            for( int j = 0; j <= 21; j++ ) {
                if( j == 21 ) j = 50;
                for( int k = 0; k <= 21; k++ ) {
                    if( k == 21 ) k = 50;
                    for( int a = 1; a < 4; a++ )
                        for( int b = 1; b < 4; b++ )
                            for( int c = 1; c < 4; c++ )
                                if( ca( i, a ) + ca( j, b )+ ca( k, c ) == n )
                                {
                                    permutation.insert( make_tuple( ca( i, a ), ca( j, b ), ca( k, c ) ) );
                                    auxSort[ 0 ] = ca( i, a );
                                    auxSort[ 1 ] = ca( j, b );
                                    auxSort[ 2 ] = ca( k, c );
                                    sort( auxSort.begin(), auxSort.end() );
                                    combination.insert( make_tuple( auxSort[0], auxSort[1], auxSort[2] ) );
                                }
                }
            }
        }


        if( permutation.empty() )
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
        else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combination.size() << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << permutation.size() << ".\n";
        }

        cout << line << endl;
        cin >> n;
        if( n < 1 )
        {
            cout << "END OF OUTPUT" << endl;
            break;
        }
    }

    return 0;
}
