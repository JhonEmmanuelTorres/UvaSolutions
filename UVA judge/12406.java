import java.util.*;
import java.math.*;

public class Main
{
	public static void main( String[] args )
	{
		Scanner is = new Scanner( System.in );
		int p, q;
		long min, max, aux, number, exp;
		LinkedList<Long> possible = new LinkedList<>();
		ArrayList< LinkedList<Long> > container = new ArrayList<>( 17 );

		for( int c = 0; c < 17; c++ )
		{
			container.add( new LinkedList<>() );
			for( int i = 0; i < (1 << c+1); i++ )
			{
				number = i;
				aux = 0;
				exp = 1;
				for( int j = 0; j < c+1; j++, exp *= 10, number /= 2 )
					aux += number % 2 == 0 ? 2*exp : exp;
				container.get(c).add( aux );
			}
		}

		int n = is.nextInt() + 1;
		for( int c = 1; c < n; c++ )
		{
			p = is.nextInt();
			q = 1 << is.nextInt();

			for( long i: container.get(p-1) )
				if( i % q == 0 )
					possible.add( i );

			System.out.print( "Case " + c + ":" );

			if( possible.isEmpty() )
			{
				System.out.println( " impossible" );
				continue;
			}

			min = Collections.min( possible );
			max = Collections.max( possible );

			if( min == max )
				System.out.println( " " + max );
			else
				System.out.println( " " + min + " " + max );

			possible.clear();
		}
	}
}
