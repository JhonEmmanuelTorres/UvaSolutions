number = 0
variable = 1

def pascalTriangule( n )
    n += 1
    pascal = [0]*n
    for i in 1 .. n
        pascal[i-1] = [0]*i
    end
    for i  in 0 ... n
        pascal[i][i] = pascal[i][0] = 1
    end

    for i in 2 ... n
        for j in 1 ... i
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]
        end
    end

    return pascal[n-1]
end

expression, exponent = gets.chomp.split("^").map{ |e| e.strip() }
exponent = exponent.to_i
operators = []

firstTerm , secondTerm = expression[ 1 ... expression.size() - 1 ].split( "+" )
firstTerm = firstTerm.split( "*" ).map{ |e| e.strip() }
secondTerm = secondTerm.split( "*" ).map{ |e| e.strip() }
firstTerm[number] = firstTerm[number].to_i
secondTerm[number] = secondTerm[number].to_i

termIndepedent = pascalTriangule( exponent.to_i )

i = 0; j = exponent.to_i
for ele in termIndepedent
    if i == 0
        print ( firstTerm[number]  ** j ), "*" ,firstTerm[variable], "^" , j , " + "
    elsif j == 0
        print ( secondTerm[number] ** i ), "*" , secondTerm[variable], "^" , i, "\n"
    else
        expX = i == 1 ? "" : "^"+i.to_s
        expY = j == 1 ? "" : "^"+j.to_s
        print ele*( firstTerm[number] ** j ) * ( secondTerm[number] ** i ), "*" ,firstTerm[variable], expY ,"*" ,secondTerm[variable], expX , " + "
    end
    i += 1
    j -= 1
end

# falta mejorarlo
