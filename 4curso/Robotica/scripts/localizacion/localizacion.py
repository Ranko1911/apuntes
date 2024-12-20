#! /usr/bin/env python
# -*- coding: utf-8 -*-

# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Robótica Computacional
# Curso: 4º
# Práctica 3: Simulación de robots móviles holonómicos y no holonómicos
# Autor: Ancor Gonzalez Carballo (alu0101327679@ull.edu.es)

# localizacion.py

import sys
from math import *
from robot import robot  # Clase que representa un robot
import random
import numpy as np
import matplotlib.pyplot as plt
from datetime import datetime

# ******************************************************************************
# Declaración de funciones


def distancia(a, b):
    """
    Calcula la distancia euclidiana entre dos puntos en 2D.
    Si 'a' y 'b' contienen orientación, solo se consideran las coordenadas x, y.
    """
    return np.linalg.norm(np.subtract(a[:2], b[:2]))


def angulo_rel(pose, p):
    """
    Calcula la diferencia angular entre la orientación actual del robot (pose)
    y un punto objetivo (p). Esto indica hacia dónde debe girar el robot.
    """
    w = atan2(p[1] - pose[1], p[0] - pose[0]) - pose[2]
    # Ajustar el ángulo para que esté entre -pi y pi
    while w > pi:
        w -= 2 * pi
    while w < -pi:
        w += 2 * pi
    return w


def mostrar(objetivos, ideal, trayectoria):
    """
    Representa gráficamente:
    - Los objetivos (puntos a alcanzar).
    - La trayectoria ideal (sin ruido).
    - La trayectoria real (con ruido).
    """
    # Convertir las listas en formato adecuado para graficar
    objT = np.array(objetivos).T.tolist()
    trayT = np.array(trayectoria).T.tolist()
    ideT = np.array(ideal).T.tolist()

    # Definir bordes y escala del gráfico
    bordes = [min(trayT[0] + objT[0] + ideT[0]), max(trayT[0] + objT[0] + ideT[0]),
              min(trayT[1] + objT[1] + ideT[1]), max(trayT[1] + objT[1] + ideT[1])]
    centro = [(bordes[0] + bordes[1]) / 2., (bordes[2] + bordes[3]) / 2.]
    radio = max(bordes[1] - bordes[0], bordes[3] - bordes[2]) * 0.75
    plt.xlim(centro[0] - radio, centro[0] + radio)
    plt.ylim(centro[1] - radio, centro[1] + radio)

    # Dibujar la trayectoria ideal (verde) y la trayectoria real (roja)
    plt.plot(ideT[0], ideT[1], '-g')
    plt.plot(trayectoria[0][0], trayectoria[0][1], 'or')
    r = radio * 0.1
    for p in trayectoria:
        plt.plot([p[0], p[0] + r * cos(p[2])], [p[1], p[1] + r * sin(p[2])], '-r')
    objT = np.array(objetivos).T.tolist()
    plt.plot(objT[0], objT[1], '-.o')  # Puntos objetivos

    # Mostrar el gráfico
    plt.ion()
    plt.show()
    input()  # Esperar una tecla para continuar
    plt.clf()  # Limpiar el gráfico para la siguiente iteración


def localizacion(balizas, real, ideal, centro, radio, mostrar=0):
    """
    Busca la posición más probable del robot real, basada en sus mediciones
    y las de un robot ideal, dentro de una región cuadrada definida por
    un centro y un radio.
    """
    imagen = []  # Matriz que guarda los errores para cada punto
    min_error = sys.maxsize  # Error mínimo inicial (muy grande)
    mejor_punto = []  # Punto con el menor error
    incremento = 0.05  # Resolución de la búsqueda (pasos)

    for i in np.arange(-radio, radio, incremento):
        imagen.append([])
        for j in np.arange(-radio, radio, incremento):
            x = centro[0] + j
            y = centro[1] + i
            ideal.set(x, y, ideal.orientation)  # Mover robot ideal al punto actual
            error = real.measurement_prob(ideal.sense(balizas), balizas)  # Calcular error
            imagen[-1].append(error)
            if error < min_error:
                min_error = error
                mejor_punto = [x, y]

    # Ajustar posición del robot ideal al punto más probable
    ideal.set(mejor_punto[0], mejor_punto[1], real.orientation)
    print("Mejor:", mejor_punto, min_error)

    if mostrar:
        # Representar gráficamente la matriz de errores y posiciones
        plt.ion()
        plt.xlim(centro[0] - radio, centro[0] + radio)
        plt.ylim(centro[1] - radio, centro[1] + radio)
        imagen.reverse()
        plt.imshow(imagen, extent=[centro[0] - radio, centro[0] + radio,
                                   centro[1] - radio, centro[1] + radio])
        balT = np.array(balizas).T.tolist()
        plt.plot(balT[0], balT[1], 'or', ms=10)
        plt.plot(ideal.x, ideal.y, 'D', c='#ff00ff', ms=10, mew=2)
        plt.plot(real.x, real.y, 'D', c='#00ff00', ms=10, mew=2)
        plt.show()
        input()
        plt.clf()


# ******************************************************************************

# Configuración inicial del robot y sus movimientos:
P_INICIAL = [0., 4., 0.]  # Posición inicial (x, y, orientación)
V_LINEAL = .7             # Velocidad lineal en m/s
V_ANGULAR = 140.          # Velocidad angular en grados/s
FPS = 10                  # Resolución temporal (fotogramas por segundo)
EPSILON = .05             # Umbral para considerar que el robot llegó al objetivo
V = V_LINEAL / FPS        # Velocidad por fotograma
W = V_ANGULAR * pi / (180 * FPS)  # Velocidad angular en radianes por fotograma

# Definición de trayectorias:
trayectorias = [
    [[1, 3]],
    [[0, 2], [4, 2]],
    [[2, 4], [4, 0], [0, 0]],
    [[2, 4], [2, 0], [0, 2], [4, 2]],
    [[2 + 2 * sin(.8 * pi * i), 2 + 2 * cos(.8 * pi * i)] for i in range(5)]
]

# Seleccionar la trayectoria según el argumento recibido al ejecutar el script
if len(sys.argv) < 2 or int(sys.argv[1]) < 0 or int(sys.argv[1]) >= len(trayectorias):
    sys.exit(sys.argv[0] + " <indice entre 0 y " + str(len(trayectorias) - 1) + ">")
objetivos = trayectorias[int(sys.argv[1])]

# Crear robots ideal y real:
ideal = robot()
ideal.set_noise(0, 0, .03)  # Añadir ruido a sensores/motores del ideal
ideal.set(*P_INICIAL)

real = robot()
real.set_noise(.01, .01, .01)  # Ruido más alto para el robot real
real.set(*P_INICIAL)

# Simulación de movimiento:
random.seed(int(datetime.now().timestamp()))  # Semilla para generación aleatoria
tray_ideal = [ideal.pose()]  # Trayectoria ideal (sin ruido)
tray_real = [real.pose()]    # Trayectoria real (con ruido)

# Localización inicial del robot:
localizacion(objetivos, real, ideal, ideal.pose(), 5, mostrar=1)

# Bucle principal: mover el robot hacia los objetivos
for punto in objetivos:
    while distancia(tray_ideal[-1], punto) > EPSILON and len(tray_ideal) <= 1000:
        pose = ideal.pose()
        w = angulo_rel(pose, punto)  # Calcular ángulo de giro
        v = distancia(pose, punto)  # Calcular velocidad lineal

        # Limitar velocidades
        w = max(min(w, W), -W)
        v = max(min(v, V), 0)

        # Mover robots (ideal y real)
        ideal.move(w, v)
        real.move(w, v)

        tray_ideal.append(ideal.pose())
        tray_real.append(real.pose())

        # Relocalizar el robot si las mediciones no son precisas
        if real.measurement_prob(ideal.sense(objetivos), objetivos) > EPSILON:
            localizacion(objetivos, real, ideal, ideal.pose(), 0.2, mostrar=0)

# Mostrar resultados:
if len(tray_ideal) > 1000:
    print("<!> Trayectoria muy larga - puede que no se haya alcanzado la posición final.")
print("Recorrido: " + str(round(len(tray_ideal) * V, 3)) + "m / " + str(len(tray_ideal) / FPS) + "s")
print("Distancia real al objetivo: " + str(round(distancia(tray_real[-1], objetivos[-1]), 3)) + "m")
mostrar(objetivos, tray_ideal, tray_real)  # Representar gráficamente
