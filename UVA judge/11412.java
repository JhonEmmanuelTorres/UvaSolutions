import java.util.*;
import java.math.*;

public class Main
{
	public static void main( String[] args )
	{
		Scanner is = new Scanner( System.in );
		char[] color = { 'R', 'G', 'B', 'Y', 'O', 'V' };
		Arrays.sort( color );

		ArrayList< ArrayList<Character> > container = new ArrayList<>();
		ArrayList<Character> auxSequence = new ArrayList<>( Collections.nCopies( 4, 'A' ) );

		for( int a = 0; a < color.length - 3; a++ )
			for( int b = a+1; b < color.length - 2; b++ )
				for( int c = b+1; c < color.length - 1; c++ )
					for( int d = c+1; d < color.length; d++ )
					{
						auxSequence.set( 0, color[a] );
						auxSequence.set( 1, color[b] );
						auxSequence.set( 2, color[c] );
						auxSequence.set( 3, color[d] );
						do{
							container.add( new ArrayList<Character>( auxSequence ) );
						}while( next_permutation(auxSequence) );
					}

		ArrayList<Guess> attend = new ArrayList<>( Collections.nCopies( 2, new Guess() ) );

		boolean isValid = true;
		int n1, n2;
		for( int t = is.nextInt(); t > 0; t-- )
		{
			attend.set( 0, new Guess( is.next(), is.nextInt(), is.nextInt() ) );
			attend.set( 1, new Guess( is.next(), is.nextInt(), is.nextInt() ) );

			for( ArrayList<Character> per: container )
			{
				isValid = true;
				for( Guess o: attend )
				{
					n1 = n2 = 0;
					for( int i = 0; i < per.size(); i++ )
					{
						if( per.get(i) == o.posPer.charAt(i) )
							n1++;
						else if( per.indexOf( o.posPer.charAt(i) ) != -1 )
							n2++;
					}
					isValid &= (n1 == o.n1);
					isValid &= (n2 == o.n2);
				}

				if( isValid )
					break;
			}
			System.out.println( isValid ? "Possible" : "Cheat" );
		}
	}

	static class Guess {
		String posPer;
		int n1, n2;
		Guess( String posPer, int n1, int n2 ) {
			this.n1 = n1;
			this.n2 = n2;
			this.posPer = posPer;
		}
		Guess() {
			this( null, 0, 0 );
		}
	}

	static boolean next_permutation( ArrayList<Character> seq )
	{
		for( int k = seq.size() - 2; k >= 0; k-- )
			if( seq.get(k) < seq.get(k+1) )
				for( int l = seq.size() - 1; l >= 0; l-- )
					if( seq.get(k) < seq.get(l) )
					{
						Collections.swap( seq, l, k );
						k++;
						for( l = seq.size() -1; k < l; k++, l-- )
							Collections.swap( seq, l, k );
						return true;
					}
		return false;
	}
}
