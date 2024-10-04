dias = ["Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"]
dias[1:4] # Se extrae una lista con los valores 1, 2 y 3
dias[4:5] # Se extrae una lista con el valor 4
dias[4:4] # Se extrae una lista vacía
dias[:4] # Se extrae una lista hasta el valor 4 (no incluido)
dias[4:] # Se extrae una lista desde el valor 4 (incluido)
dias[2:-1] # del tercer al penúltimo elementos
dias[:] # Se extrae una lista con todos los valores

print(dias[1:4])
print(dias[4:5])
print(dias[4:4])
print(dias[:4])
print(dias[4:])
print(dias[2:-1])
print(dias[:])