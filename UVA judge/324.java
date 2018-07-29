import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static BigInteger fact( int n )
    {
        BigInteger accumulator = new BigInteger( "1" );
        for( long i = 2; i <= n; i++ )
            accumulator = accumulator.multiply( BigInteger.valueOf( i ) );
        return accumulator;
    }

    public static void main(String[] args)
    {
        Scanner is = new Scanner( System.in );
        int n;
        int []digits;
        String number;
        while( true )
        {
            n = is.nextInt();
            if( n == 0 ) break;
            number = fact(n).toString();
            digits = new int[ 10 ];
            for( int i = 0; i < number.length(); i++ )
                digits[ number.charAt(i) - '0' ]++;
            System.out.println( n + "! --" );
            for( int i = 0; i < 10; i++ )
            {
                System.out.print( "(" + i + ")" + digits[i] );
                if( i == 4 || i == 9 )
                    System.out.println();
            }

        }
    }
}
