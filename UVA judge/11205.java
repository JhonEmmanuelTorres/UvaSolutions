import java.util.*;
import java.math.*;

public class Main
{
	public static void main( String[] args )
	{
		Scanner is = new Scanner( System.in );
		HashSet<String> possible = new HashSet<>();
		ArrayList< ArrayList<Integer> > repre = new ArrayList<>();
		int p, n, min;
		String[] container;
		for( int t = is.nextInt(); t > 0; t-- )
		{
			p = is.nextInt();
			n = is.nextInt();
			for( int i = 0; i < n; i++ )
			{
				repre.add( new ArrayList<>() );
				for( int j = 0; j < p; j++ )
					repre.get(i).add( is.nextInt() );
			}

			min = p;
			container = new String[ n ];

			for( int i = 0; i < (1 << p); i++ )
			{
				for( int a = 0; a < n; a++ )
					container[a] = new String();

				for( int j = 0; j < p; j++ )
					if( ( i & ( 1 << j ) ) != 0 )
						for( int a = 0; a < n; a++ )
							container[a] += repre.get(a).get( j );

				for( String o: container )
					possible.add( o );

				if( possible.size() == n )
					min = Math.min( min, Integer.bitCount( i ) );

				possible.clear();
			}
			System.out.println( min );
			repre.clear();
		}
	}
}
