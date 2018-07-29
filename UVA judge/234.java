import java.util.*;
import java.math.*;

public class Main
{
	public static void main( String[] args )
	{
		Scanner is = new Scanner( System.in );

		ArrayList<Integer> sequence = new ArrayList<>();
		ArrayList<Integer> possible = new ArrayList<>();
		TreeMap<Integer,TreeSet<Integer>> container = new TreeMap<>();
		int timeMiss, aux, sum;
		int p, q;
		for( int c = 1; ( p = is.nextInt() ) != 0; c++ )
		{
			for( int i = 0; i < p; i++ ) {
				sequence.add( is.nextInt() );
				possible.add( 0 );
			}

			q = is.nextInt();
			for( int i = 0; i < q; i++ ) {
				aux = is.nextInt();
				if( !container.containsKey( aux ) )
					container.put( aux, new TreeSet<>() );
				container.get( aux ).add( is.nextInt() );
			}
			Collections.sort( sequence );

			timeMiss = Integer.MAX_VALUE;
			do {

				sum = q = 0;
				for( int a: container.keySet() )
					for( int b: container.get(a) )
					{
						sum = 0;
						aux = Integer.MAX_VALUE;
						for( int d: sequence )
						{
							sum += d;
							aux = Math.min( aux, Math.abs( sum - b ) );
						}
						q += aux;
					}

				if( q < timeMiss ) {
					timeMiss = q;
					Collections.copy( possible, sequence );
				}
			}while( next_permutation( sequence ) );

			System.out.println( "Data set " + c );
			System.out.print( "Order:" );
			for( int i: possible )
				System.out.print( " " + i );
			System.out.println( "\nError: " + timeMiss );

			possible.clear();
			container.clear();
			sequence.clear();
		}
	}

	static boolean next_permutation( ArrayList<Integer> ele )
	{
		for( int k = ele.size() - 2; k >= 0; k-- )
		{
			if( ele.get(k) < ele.get(k + 1) )
				for( int l = ele.size() - 1; l >= 0; l-- )
					if( ele.get(k) < ele.get(l) )
					{
						Collections.swap( ele, k, l );
						k++;
						for( l = ele.size() - 1; k < l; k++, l-- )
							Collections.swap( ele, k, l );
						return true;
					}
		}
		return false;
	}

}
