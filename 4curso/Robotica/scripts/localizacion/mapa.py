import matplotlib.pyplot as plt
import numpy as np

def crear_mapa(dimension=(100, 100), num_balizas=5):
    # Crear una imagen en blanco (tamaño 100x100 píxeles)
    mapa = np.ones(dimension)
    
    # Generar algunas balizas aleatorias (puntos rojos)
    for _ in range(num_balizas):
        x = np.random.randint(0, dimension[0])  # Coordenada X aleatoria
        y = np.random.randint(0, dimension[1])  # Coordenada Y aleatoria
        mapa[x, y] = 0  # Poner un valor diferente (negro) para las balizas

    # Guardar la imagen generada
    plt.imshow(mapa, cmap='gray')
    plt.axis('off')  # Desactivar los ejes
    plt.savefig('mapa.png', bbox_inches='tight', pad_inches=0)
    plt.close()  # Cerrar la figura

# Crear el mapa y guardarlo
crear_mapa()
