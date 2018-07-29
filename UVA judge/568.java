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
        int n, digits, n2;
        String number;
        while( is.hasNext() )
        {
            n = is.nextInt();
            number = fact(n).toString();
            digits = 0;
            n2 = n;
            do{
                n2 /= 10;
                digits++;
            }while( n2 != 0 );
            switch( digits )
            {
                case 1:
                    System.out.print( "    " );
                    break;
                case 2:
                    System.out.print( "   " );
                    break;
                case 3:
                    System.out.print( "  " );
                    break;
                case 4:
                    System.out.print( " " );
                    break;
                default:
                    break;
            }

            System.out.print( n + " -> " );
            for( int i = number.length() - 1; i >= 0; i-- )
                if( number.charAt(i) != '0' )
                {
                    System.out.println(number.charAt(i));
                    break;
                }

        }
    }
}
