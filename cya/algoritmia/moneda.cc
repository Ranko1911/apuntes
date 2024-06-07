#include <stdio.h>

#include <iostream>
#include <vector>

std::vector<int> cambio_moneda(int cant) {
  std::vector<int> monedas = {500, 200, 100, 50, 20, 10, 5, 2, 1};
  std::vector<int> cambio;  // conjunto de lña solucion
  int suma = 0;
  while (suma != cant) {
    for (int i = 0; i < monedas.size(); i++) {
      if (suma + monedas[i] <= cant) {
        cambio.push_back(monedas[i]);
        suma += monedas[i];
        break;
      }
    }
  }
  return cambio;
}

std::vector<int> cambio_moneda_optimo(int cant) {
  std::vector<int> monedas = {500, 200, 100, 50, 20, 10, 5, 2, 1};
  std::vector<int> cambio;  // conjunto de lña solucion
  int suma = 0;
  for (int i = 0; i < monedas.size(); i++) {
    int c = (cant - suma) / monedas[i];
    if (c > 0) {
      cambio.push_back(c);
      suma = suma + c * monedas[i];
    } else {
      cambio.push_back(0);
    }
  }
  return cambio;
}

int main() {
  std::vector<int> monedas = {500, 200, 100, 50, 20, 10, 5, 2, 1};
  std::cout << "Las monedas disponibles son:" << std::endl;

  for (int i = 0; i < monedas.size(); i++) {
    std::cout << monedas[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Usando el algoritmo no óptimo:" << std::endl;
  std::vector<int> cambio = cambio_moneda(1234);
  std::cout << "El cambio es: ";
  for (int i = 0; i < cambio.size(); i++) {
    std::cout << cambio[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "usando el algoritmo optimo:" << std::endl;
  cambio = cambio_moneda_optimo(1234);
  std::cout << "El cambio es: ";
  for (int i = 0; i < cambio.size(); i++) {
    std::cout << cambio[i] << " ";
  }
  std::cout << std::endl;
}