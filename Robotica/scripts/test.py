# dias = ["Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"]
# dias[1:4] # Se extrae una lista con los valores 1, 2 y 3
# dias[4:5] # Se extrae una lista con el valor 4
# dias[4:4] # Se extrae una lista vacía
# dias[:4] # Se extrae una lista hasta el valor 4 (no incluido)
# dias[4:] # Se extrae una lista desde el valor 4 (incluido)
# dias[2:-1] # del tercer al penúltimo elementos
# dias[:] # Se extrae una lista con todos los valores


# letras = ["A", "B", "C", "D", "E", "F", "G", "H"]
# print(letras)
# del letras[4] # Elimina la sublista ['E']
# print(letras)
# del letras[1:4] # Elimina la sublista ['B', 'C', 'D']
# print(letras)
# del letras # Elimina completamente la lista
# print letras # Error: la lista ya no existe

# l = (1, "A", 3.14) # Una tupla
# print(l)

# for i in range(10):
    # print(l)

# valor = 3
# posicion = 2
# lista1 = [1, 2, 3]
# lista2 = [4, 5, 6]
# lista=[ 1, [ 1, 2, 3], 3 ,4 ]
# print(lista)
# lista.append(5) # modifica lista
# print(lista)
# lista.insert(1,valor)
# print(lista)
# print(lista.pop()) # modifica lista, devuelve elemento emiminado
# print(lista.pop(posicion)) # modifica lista, devuelve elemento emiminado
# lista.remove(valor) # modifica lista
# print(lista)
# print(lista.count(valor))
# print(lista.index(valor))
# print(valor in lista) # devuelve True o False
# listaCompleta = lista1 + lista2
# print(listaCompleta)
# lista1.extend(lista2) # se modifica lista1
# print(lista1)

import random

opciones = ['piedra', 'papel', 'tijeras']
jugador = input("Elige piedra, papel o tijeras: ").lower()
computadora = random.choice(opciones)

print(f"Tú elegiste: {jugador}")
print(f"La computadora eligió: {computadora}")

if jugador == computadora:
    print("¡Es un empate!")
elif (jugador == "piedra" and computadora == "tijeras") or \
     (jugador == "tijeras" and computadora == "papel") or \
     (jugador == "papel" and computadora == "piedra"):
    print("¡Ganaste!")
else:
    print("Perdiste, ¡inténtalo de nuevo!")
