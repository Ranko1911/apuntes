VLAN separa la topología logica de la física
Surgen para acotar dominios de broadcast
  dominio de broadcast -> todos los dispositivos conetados a la area local

BROADCAST:
  las topologías de switch se hacaen en forma de arbol y
  se puede poner un cierto grado de redundancia ( varias conexiones multiples, multiples caminos entre todos)
  por esto va a tener enlaces duplicados y dispositivos duplicados
  se introducen los ciclos, lo que produce un efecto negativo dentro de la topología

  Ejemplo: 
    Dipositivo 1 conectado a switch 1, switch1 y 2 conectados
    si dispositivo 1 hace broadcast le llega a si mismo otra vez
  
  la trama broadcast se reenvía por todos los puertos excepto por el que entró
  este problema se llama "tormenta de broadcast"

  si haces un ciclo CAGASTE, porque el rendimiento de la red baja drásticamente

  la tormenta se identifica si hay una locura de brillos en el switch  

  La solucion está en los protocoles spannig-tree ( arbol generador¿)
  SPANNIG-TREE:
    esto va con grafos, nada de aparatos
    se genera un árbol a aprtir de un nodo inicial
    a partir de las aristas de ese nodo, y así sucesivamente
    EJEMPLO:
      5 nodos conectados entre sí (1 con 2,3,4 | 2 con 1,4,5 | 3 con 1,4 | 4 con 1,2,3,5 | 5 con 2,4)
      empezando en nodod raiz (n1), se genera el arbol inicial
      n1 -> n2 ,n3 ,n4
      n2 -> n5

    el arbol resultante es el que se tiene en cuenta para hacer los envíos
    esto se usa para tener cables backup que ya estén coenctados, es decir, que si se rompe uno automaticamnete ya tiene el camino disponible
    se recalcula cuandos se modifica la topología
    y mientras que se recalcula se detiene el envío de datos por toda la red 
    1.  spanning tree(STP): 
      la convergencia es lenta ~ 30 segundos (mucho)
    2. Rapid SpanningTree (RSTP):
      convergencia es rapida que da susto
    
    Estos dos protocolos admiten una única instancia de spanning tree para toda la tipología

    #los servidores sonde 4 a 6 cifras, esto es por algo relacionado con que para evitar que estén aprados o algo así, no lo entendí muy bien

    3. Multiple Spanning Tree(MSTP):
      es rapido que da susto
      permite varias instancias de spanning tree
      solo se puede hacer cunado hay varios VLANs, si no no hay multiples instancias de spannig tree
      se pueden hacer agrupaciones de VLANs -> 20,30 son dos VLANs pero son una aprupación a y 40 es otra agrupacion b y otra VLAN
    
    el psanning tree se hace sobre el dominio de broadcast
    
    al principio de la comunicacion se mandan paquetes de 64 bits, 48 de estos sond e la dirección MAC, los otros 16 se parten en 2, 4 bits para la prioridad 
    12 para la ID extendido. El apquete se llama BID

    Por defecto los 4 bits están puestos a 1111, son absolutamente todos iguales.
    Raíz: el switch con BID menor, [el de arriba en el arbol de switch], se pone en el CORE.

    existen switches d eacceso, distribución y CORE, están mencionados de abajoa  arriba en el árbol
    


# enrutamiento
  - Pasarela interioir
      - Enrutamiento dentro del sistema autonomo 
        - RIP 
            - basado en vectores de didstancia
            - la metrica se bas en el numero de saltos
            - tiene un limite de 15 saltos
            - Lento con ganas
          Había 3 versiones d eRIP:
            - RIP: enrutamiento con clases
            - RIPv2: enrutamiento sin clases
            - RIPng: 
        -  OSPF
            - basado en estados de enlace
            - la metrica se basa en ancho de banda*
            - no tiene limite de saltos 
            - rápida convergencia
            - escalable
          - versiones:
            - OSPF:enrutamiento con clase, ipv4
            - OSPFv2: enrutamiento sin clases, ipv4
            - OSPFv3: 
        Lo que se busca cuando se pasa de RIP a OSPF es la escalabilidad
  - pasarela exterior
      Enrutamiento entre sistemas autonomos
        -  BGP
            - _literalmente no apuntó nada_


  OSPF:
    su principal objetivo es la escalabilidad

    - mapa de redes:
      son 3 subredes de 3 routers con una maquina cada uno, conectados por un router externo (exepto uno de ellos, uno de llos usa uno de sus propios routers)
      
      ![busca una foto en el movil que se parezca a esto, el día que se añadió estos apuntes]()
      - RIB
        - Info base:
          - Tabla de enrutemiento
    
    Area: es un conjunto, que pueden estar o no en un espacio de direccionamiento "continuo?", manejan muy bien los agrupamientos
    en el ejemplo descrito arriba deberían ser 4 areas (1 para cada sub-red y 1 para la conexion de sub-redes)

    - Areas OSPF:
      - troncal
        - su mision es interconectar otras areas
        - es el area 0, otro identificador significa que no es troncal
        - es **obligatorio** que exista un area 0 en una topología OSPF.
        - puede ser que sea muy chiquita, pues entonces minimo necesitas la 0 (no te libras de hacer la troncal, por algo se llama troncal)
      - standard
        - entran tipos de mansaje 3,4,5
      - stub
        - los tipos 3 pasan sin problema, pero lo externo al ospf, nodentran y se cambian por una ruta por defecto 
      - totally stub
        - no permite ni la entrada de mensajes tipo 3
        - entra un tipo 3 , sa cambia por una ruta por defecto
      - NSSA (NOT SO STABLE AREA)
        - 

    - Tipos de routersopf(es una clasificacion de lo que te puedes encontrar):
      - router troncal
        - que tiene nodos del area 0
      - router interno
        - que está conectado a un solo area
      - router fronterizo de area (ABR)
        - conectado a más d eun area
      - router fronterizo de sistemas autonomos(ASBR)
        - Está conectado con un router que no es de OSPF

      - Tipos de mensajes de estado de enlace: **tutoría para esto?**
        -  tipo 1: tipo router
          -  mision: recopilar informacion si es posible y enviarsela a sus vecinos 
        -  tipo 2: tipo network
          -  mision: recopilar informacion si es posible y enviarsela a sus vecinos
        - tipo 3: Summary
          - hace una agrupación?
        - tipo 4: ASBR router
        - tipo 5: external network
        - tipo 6: son los padres
        - tipo 7: external network 2?
          - se traduce a un tipo 5 en caso de que el quieras que algo pase del asbr no troncal
        PAra evitar los broadcast tochos, se hace uno muy intelligente, se desinaga un router como un reouter designado, el tipo 2 se aprende las "coas " y lo copio a la
        --- , vamos que agrupa para enviarlos datos ___.


