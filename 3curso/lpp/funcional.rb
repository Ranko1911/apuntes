# Suma de los 10 primeros números naturales cuyos cuadrados son múltiplos de cinco
def suma_cuadrados_multiplos_5
  naturales_filtrado = []
  i = 1
  while naturales_filtrado.size < 10
    naturales_filtrado << i if (i**2) % 5 == 0
    i += 1
  end
  suma = naturales_filtrado.sum
  return suma
end
puts "La suma de los 10 primeros números naturales cuyos cuadrados son múltiplos de cinco es:" 
puts suma_cuadrados_multiplos_5


#producto de los 100 primeros naturales pares
def producto_naturales_pares
  naturales_pares = []
  i = 1
  while naturales_pares.size < 100
    naturales_pares << i if i.even?
    i += 1
  end
  producto = naturales_pares.inject(:*)
  return producto
end

# puts "El producto de los 100 primeros números naturales pares es:"
# puts producto_naturales_pares

#Max 100 primeros num naturales
def max_naturales
  #sacamos los anturales
  naturales = (1..Float::INFINITY).lazy.select{|x| x}
  #tomamos los primeros 100
  cien= naturales.first(100)
  #sacamos el maximo
  max = cien.max
  return max
end

puts "El máximo de los 100 primeros números naturales es:"
puts max_naturales

#numeros pares de los 100 primeros naturales
def pares_naturales
  naturales=(1...Float::INFINITY).lazy.select{|x| x}
  cien=naturales.first(100)
  pares=cien.select{|x| x.even?}
  return pares
end

# puts "Los números pares de los 100 primeros números naturales son:"
# puts pares_naturales

#numeros impares de los 100 primeros naturales
def num_impares
  naturales=(1...Float::INFINITY).lazy.select{|x| x}
  cien=naturales.first(100)
  impares=cien.select{|x| x.odd?}
  return impares
end

# puts "Los números impares de los 100 primeros números naturales son:"
# puts num_impares

# Media de los 100 primeros naturales multiplos de 3
def media_mult_3
  naturales=(1...Float::INFINITY).lazy.select{|x| x}
  multiplos=naturales.select{|x| x%3==0}.first(100)
  sumatorio=multiplos.sum
  media=sumatorio/100
  return media
end

puts "La media de los 100 primeros números naturales múltiplos de 3 es:"
puts media_mult_3