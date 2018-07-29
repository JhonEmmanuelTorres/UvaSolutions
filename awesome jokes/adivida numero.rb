puts "Juego adivida un numero de 1 a 100"

numberCorrect = Random.rand( 100 ) + 1

i = 1
while true
    puts "Numero del intento #{i}"
    print "Ingrese su numero:\t"
    number = gets.chomp.to_i

    if number < numberCorrect
        puts "Es un numvero mas grande\n\n"
    elsif number > numberCorrect
        puts "Es un numvero mas pequeño\n\n"
    else
        puts "Felicitaciones. Encontraste el numero"
        break
    end

    i += 1
end
