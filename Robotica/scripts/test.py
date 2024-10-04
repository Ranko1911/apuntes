dias = ["Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"]
dias[1:4] # Se extrae una lista con los valores 1, 2 y 3
dias[4:5] # Se extrae una lista con el valor 4
dias[4:4] # Se extrae una lista vacía
dias[:4] # Se extrae una lista hasta el valor 4 (no incluido)
dias[4:] # Se extrae una lista desde el valor 4 (incluido)
dias[2:-1] # del tercer al penúltimo elementos
dias[:] # Se extrae una lista con todos los valores


letras = ["A", "B", "C", "D", "E", "F", "G", "H"]
# print(letras)
del letras[4] # Elimina la sublista ['E']
# print(letras)
del letras[1:4] # Elimina la sublista ['B', 'C', 'D']
# print(letras)
del letras # Elimina completamente la lista
# print letras # Error: la lista ya no existe

l = (1, "A", 3.14) # Una tupla
print(l)

for i in range(10):
    print(l)