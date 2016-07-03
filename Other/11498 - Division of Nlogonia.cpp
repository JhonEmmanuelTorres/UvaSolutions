#include <iostream>

using namespace std;

struct Point{ int x, y; };

int main()
{
	int t, n;
	Point division, tmp;
	cin >> t;
	while( t != 0  )
	{
		cin >> division.x >> division.y;
		while( t-- )
		{
			cin >> tmp.x >> tmp.y;
			if( tmp.x > division.x && tmp.y > division.y )
				cout << "NE" << endl;
			else if( tmp.x < division.x && tmp.y > division.y )
				cout << "NO" << endl;
			else if( tmp.x > division.x && tmp.y < division.y )
				cout << "SE" << endl;
			else if( tmp.x < division.x && tmp.y < division.y )
				cout << "SO" << endl;
			else
				cout << "divisa" << endl;
		}
		cin >> t;
	}
	return 0;
}
