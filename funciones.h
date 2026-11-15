float validarFloatRango(float a, float b);
int validarEnteroRango(int a, int b);
int validarEnteroPositivo();
float validarFloatMinimo(float minimo);

void leerCadena(char cadena[], int n);

int buscarProducto(int estado[5], char nombres[5][50], char buscar[]);

void mostrarProductos(int estado[5], char nombres[5][50],int cantidades[5], float tiempos[5],float recursos[5]);

void registrarProducto(int estado[5], char nombres[5][50],int cantidades[5], float tiempos[5],float recursos[5]);

void editarProducto(int estado[5], char nombres[5][50],int cantidades[5], float tiempos[5],float recursos[5]);

void eliminarProducto(int estado[5], char nombres[5][50],int cantidades[5], float tiempos[5],float recursos[5]);

void calcularProduccion(int estado[5], int cantidades[5],float tiempos[5], float recursos[5]);

void verificarProduccion(int estado[5], int cantidades[5],float tiempos[5], float recursos[5]);