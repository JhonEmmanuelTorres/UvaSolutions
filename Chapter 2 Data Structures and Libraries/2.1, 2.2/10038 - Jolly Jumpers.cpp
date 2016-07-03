#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    short n;
    bool isjolly;
    int aux;
    while( cin >> n )
    {
        vector<int> sequence( n );
        isjolly = true;
        while( n-- )
            cin >> sequence[ n ];
        n = sequence.size();
        vector<bool> jolly( n - 1, false );
        while( --n )
        {
            aux = abs(sequence[n] - sequence[n-1] );
            if( aux >= sequence.size() || !aux )
            {
                isjolly = false;
                jolly.clear();
                break;
            }
            else
                jolly[ aux - 1 ] = true;
        }
        n = jolly.size();
        while( n-- )
            if( !jolly[n] )
            {
                isjolly = false;
                break;
            }
        if( isjolly )
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }
    return 0;
}
