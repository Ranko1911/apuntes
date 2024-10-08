# Multiplicacion en SNOW3G

01010111 * 10000011

cogemos el de menor peso: menor numero de pesos {mirar las cosas de hamin (peso de hamin, distancia de hamin, etc)}

**propiedad distributiva** => 01010111 * 00000001 + 01010111 * 00000010 + 10000000  

**se multiplica, si sale un bit fuera, se tiene que sumar el bite correspondiente al polinomio fijo**

### Ejemplo de operación:

<se suma siempre 10101001, que es equivalente a A9>

01010111 * 00000001 + 01010111 * 00000010 + 10000000 = 01010111 + 10101110 +

---------------------------------------------------
    0     |     1    |    2     |     3         |       4   | 5         |     6     |       7
01010111  | 10101110 | 01011100 | 11101010      | 10000110  | 00001100  | 01001010  | 11000110
                      10101001  | 10101001      |             10101001  | 10101001  | 10101001
                      ________    ________            
                      11110101    01000011                    10100101  | 11100011  | 01101111

*esta mierda está en las diapositivas hecha*