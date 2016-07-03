#include <iostream>

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	string answer;
	while( t-- )
	{
		cin >> n;
		n =  (((((n*567)/9) + 7492 )*235)/47) - 498 ;
		answer = to_string( n );
		cout << answer[ answer.size() -2 ] << endl;
	}
	return 0;
}
