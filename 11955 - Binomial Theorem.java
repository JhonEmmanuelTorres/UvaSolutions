import java.util.Scanner;

class Main
{
    public static long[] coefientBinom( int n )
    {
        long[][] pascalTriangule = new long[ n ][ n ];
        for( int i = 0; i < n; i++ )
            pascalTriangule[i][0] = pascalTriangule[i][i] = 1;
        for( int i = 2; i < n; i++ )
            for( int j = 1; j < i; j++ )
                pascalTriangule[i][j] = pascalTriangule[i-1][j-1] + pascalTriangule[i-1][j];
        return pascalTriangule[n-1];
    }

    public static void main(String[] args)
    {
        Scanner is = new Scanner( System.in );
        byte t = Byte.parseByte( is.nextLine() );
        String a, b;
        String[] auxiliar;
        int exponenta, exponentb;
        long[] accumulatorBinom;
        for( byte c = 0; c < t; c++ )
        {
            auxiliar = is.nextLine().split( "\\W" );
            exponenta = Integer.parseInt( auxiliar[4] );
            exponentb = 0;
            a = auxiliar[1];
            b = auxiliar[2];
            accumulatorBinom = coefientBinom( exponenta + 1 );
            System.out.print( "Case " + ( c + 1 ) + ": " );
            for( int i = 0; i < accumulatorBinom.length; i++ )
            {
                if( i == 0 )
                {
                    System.out.print( a );
                    if( exponenta != 1 )
                        System.out.print( "^" + exponenta );
                    System.out.print("+");
                }
                else if( i + 1 == accumulatorBinom.length )
                {
                    System.out.print( b );
                    if( exponentb != 1 )
                        System.out.print( "^" + exponentb );

                }
                else{
                    System.out.print( accumulatorBinom[i] + "*" );
                    System.out.print( a );
                    if( exponenta >= 2 )
                        System.out.print( "^" + exponenta );
                    System.out.print( "*" + b );
                    if( exponentb >= 2 )
                        System.out.print( "^" + exponentb );
                    System.out.print( "+" );
                }
                exponenta--;
                exponentb++;
            }
            System.out.println();
        }
    }
}
