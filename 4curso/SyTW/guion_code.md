## Documentación del Funcionamiento del Código: StatisticsComponent

### Descripción General
El `StatisticsComponent` es un componente standalone desarrollado en Angular que se encarga de mostrar y gestionar las estadísticas de almacenes y productos, así como generar gráficos interactivos utilizando la librería PrimeNG y Chart.js. Este componente interactúa con varios servicios para recuperar datos relacionados con almacenes, productos, empleados y token de autenticación.

### Importaciones
El componente utiliza una serie de módulos y servicios esenciales:

1. **Módulos de Angular:**
   - `CommonModule`: Proporciona directivas y tuberías comunes.
   - `ReactiveFormsModule` y `FormsModule`: Facilitan la creación de formularios reactivos y de plantilla.
   - `NgFor`: Permite el renderizado dinámico de listas.

2. **Librerías de terceros:**
   - `ChartModule` y `DialogModule` de PrimeNG: Facilitan la generación de gráficos y la creación de diálogos.
   - `Chart` de Chart.js: Se utiliza para graficar datos estadísticos.
   - `ButtonModule`: Proporciona botones interactivos.

3. **Servicios personalizados:**
   - `WarehouseService`: Gestiona las operaciones relacionadas con los almacenes.
   - `ProductService`: Recupera información de los productos.
   - `AuthService`: Maneja la autenticación y el token del usuario.
   - `StatisticsService` y `ChartService`: Proveen datos para cálculos y gráficos.

4. **Interfaces:**
   - `ProductStats`: Define la estructura de las estadísticas de productos.
   - `WarehouseStats`: Define la estructura de las estadísticas de almacenes.

---

### Decorador `@Component`
- **`selector`:** Define el nombre del componente como `app-statistics`.
- **`standalone: true`:** Permite que el componente funcione sin necesidad de un `NgModule`.
- **`imports`:** Lista los módulos necesarios para el funcionamiento del componente.
- **`templateUrl` y `styleUrls`:** Enlazan la plantilla HTML y las hojas de estilo CSS.

---

### Propiedades Principales

1. **Autenticación y Control:**
   - `token`: Almacena el token de autenticación.
   - `isOwner`: Determina si el usuario es dueño del almacén.

2. **Datos de Almacén y Productos:**
   - `warehouses`: Lista de almacenes asociados al usuario.
   - `products`: Lista de productos disponibles en el almacén seleccionado.
   - `selectedWarehouseId`: Almacena el ID del almacén seleccionado.
   - `warehouseStats` y `productStats`: Estructuras que contienen las estadísticas calculadas.

3. **Datos para Gráficos:**
   - `data`, `stockData`, `monthlyEarningsData`: Configuración de datos para los gráficos.
   - `options`, `stockOptions`, `monthlyEarningsOptions`: Configuración de opciones para la apariencia de los gráficos.

---

### Métodos Principales

#### 1. **ngOnInit**
- Carga el token de autenticación y verifica si el usuario es dueño.
- Carga los almacenes del usuario mediante `loadWarehouses()`.
- Selecciona el primer almacén por defecto y carga sus estadísticas iniciales.

#### 2. **loadWarehouses**
- Utiliza `WarehouseService` para recuperar la lista de almacenes del usuario.
- Requiere un token válido para realizar la solicitud.

#### 3. **loadProducts**
- Recupera la lista de productos del almacén seleccionado utilizando `ProductService`.
- Retorna una promesa para encadenar operaciones asíncronas.

#### 4. **calculateWarehouseStats**
- Calcula las estadísticas del almacén, como:
  - `totalStock`: Cantidad total de productos.
  - `totalInvested`: Inversión total calculada como `precio x stock`.
  - `totalEarned`: Ganancia estimada con un margen del 20%.
  - `totalEmployees`: Recupera el número de empleados mediante `WarehouseService`.

#### 5. **calculateProductStats**
- Itera sobre la lista de productos y calcula:
  - `stock`: Cantidad disponible.
  - `invested`: Inversión total.
  - `earned`: Ganancia total con margen del 20%.
- Almacena los resultados en un objeto indexado por el ID del producto.

#### 6. **calculateMonthlyEarnings**
- Agrupa las ganancias mensuales calculando las ventas de productos por mes.
- Asegura que todos los meses (0 a 11) estén presentes con valor 0 si no hay ventas.

#### 7. **generateWarehouseChartPrimeNG**
- Genera un gráfico circular utilizando PrimeNG con datos agregados:
  - Total de stock, inversión y ganancias.
- Configura colores y opciones responsivas.

#### 8. **generateStockChart**
- Genera un gráfico de barras que muestra el stock disponible de cada producto.
- Utiliza colores dinámicos generados con `generateColors`.

#### 9. **generateMonthlyEarningsChart**
- Configura un gráfico de barras horizontales para mostrar las ganancias mensuales.

#### 10. **onWarehouseSelect**
- Gestiona el evento de selección de un almacén:
  - Carga productos y sus estadísticas.
  - Genera los gráficos correspondientes según la acción seleccionada.

---

### Flujo de Funcionamiento
1. **Autenticación:** El componente carga el token del usuario mediante `AuthService`.
2. **Cargar Almacenes:** Recupera los almacenes disponibles con `WarehouseService`.
3. **Seleccionar Almacén:** Por defecto, se selecciona el primer almacén disponible.
4. **Cargar Productos:** Los productos del almacén seleccionado se recuperan con `ProductService`.
5. **Calcular Estadísticas:** Se calculan las estadísticas tanto de productos como del almacén.
6. **Generar Gráficos:**
   - Gráficos generales del almacén: Stock, inversión y ganancias.
   - Gráficos de stock por producto.
   - Gráficos de ganancias mensuales.

---

### Conclusión
El `StatisticsComponent` combina la recuperación de datos, el cálculo de estadísticas y la representación visual mediante gráficos para proporcionar una herramienta interactiva y eficiente de análisis de almacenes y productos. Es modular, reutilizable y altamente configurable, facilitando su integración en aplicaciones Angular de mayor escala.

