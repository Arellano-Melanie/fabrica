#include <stdio.h>
#include <string.h>
#include "funciones.h"

float validarFloatRango(float a, float b) {
    float num;
    int val;

    do {
        val = scanf("%f", &num);

        while (getchar() != '\n');

        if (val != 1 || num < a || num > b) {
            printf("Error: valor incorrecto. Intente nuevamente: ");
        }

    } while (val != 1 || num < a || num > b);

    return num;
}

void leerCadena(char cadena[], int n) {
    fgets(cadena, n, stdin);

    int len = strlen(cadena);

    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    } else {
        while (getchar() != '\n');
    }
}

int validarEnteroRango(int a, int b) {
    int num;
    int val;

    do {
        val = scanf("%d", &num);

        while (getchar() != '\n');

        if (val != 1 || num < a || num > b) {
            printf("Error: valor incorrecto. Intente nuevamente: ");
        }

    } while (val != 1 || num < a || num > b);

    return num;
}

int validarEnteroPositivo() {
    int num;
    int val;

    do {
        val = scanf("%d", &num);

        while (getchar() != '\n');

        if (val != 1 || num <= 0) {
            printf("Error: ingrese un entero positivo: ");
        }

    } while (val != 1 || num <= 0);

    return num;
}

float validarFloatMinimo(float minimo) {
    float num;
    int val;

    do {
        val = scanf("%f", &num);

        while (getchar() != '\n');

        if (val != 1 || num < minimo) {
            printf("Error: valor incorrecto. Intente nuevamente: ");
        }

    } while (val != 1 || num < minimo);

    return num;
}

int buscarProducto(int estado[5], char nombres[5][50], char buscar[]) {

    for (int i = 0; i < 5; i++) {

        if (estado[i] == 1 && strcasecmp(buscar, nombres[i]) == 0) {
            return i;
        }
    }

    return -1;
}

void registrarProducto(int estado[5], char nombres[5][50],int cantidades[5], float tiempos[5],float recursos[5]) {

    int indice = -1;

    for (int i = 0; i < 5; i++) {
        if (estado[i] == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nNo hay espacio disponible.\n");
        return;
    }

    printf("\nNombre del producto: ");
    leerCadena(nombres[indice], 50);

    while (strlen(nombres[indice]) == 0 ||buscarProducto(estado, nombres, nombres[indice]) != -1) {

        printf("Nombre vacio o producto repetido. Ingrese otro: ");
        leerCadena(nombres[indice], 50);
    }

    printf("Cantidad demandada: ");
    cantidades[indice] = validarEnteroPositivo();

    printf("Tiempo de fabricacion por unidad: ");
    tiempos[indice] = validarFloatMinimo(0);

    printf("Recursos necesarios por unidad: ");
    recursos[indice] = validarFloatMinimo(0);

    estado[indice] = 1;

    printf("\nProducto registrado correctamente.\n");
}

void mostrarProductos(int estado[5], char nombres[5][50],int cantidades[5], float tiempos[5],float recursos[5]) {

    printf("\n===== PRODUCTOS REGISTRADOS =====\n");
    printf("Pos\tProducto\tCantidad\tTiempo\tRecursos\n");

    int contador = 0;

    for (int i = 0; i < 5; i++) {

        if (estado[i] == 1) {

            printf("%d\t%s\t\t%d\t\t%.2f\t%.2f\n",i, nombres[i], cantidades[i],tiempos[i], recursos[i]);

            contador++;
        }
    }

    if (contador == 0) {
        printf("No existen productos registrados.\n");
    }
}

void editarProducto(int estado[5], char nombres[5][50],int cantidades[5], float tiempos[5],float recursos[5]) {

    char buscar[50];
    int indice;

    printf("\nIngrese el nombre del producto que desea editar: ");
    leerCadena(buscar, 50);

    indice = buscarProducto(estado, nombres, buscar);

    if (indice == -1) {
        printf("\nProducto no encontrado.\n");
        return;
    }

    printf("\nProducto encontrado: %s\n", nombres[indice]);

    printf("Nuevo nombre: ");
    leerCadena(buscar, 50);

    while (strlen(buscar) == 0) {
        printf("El nombre no puede estar vacio. Ingrese otro: ");
        leerCadena(buscar, 50);
    }

    int repetido = buscarProducto(estado, nombres, buscar);

    while (repetido != -1 && repetido != indice) {
        printf("Ese nombre ya existe. Ingrese otro: ");
        leerCadena(buscar, 50);
        repetido = buscarProducto(estado, nombres, buscar);
    }

    strcpy(nombres[indice], buscar);

    printf("Nueva cantidad demandada: ");
    cantidades[indice] = validarEnteroPositivo();

    printf("Nuevo tiempo por unidad: ");
    tiempos[indice] = validarFloatMinimo(0);

    printf("Nuevos recursos por unidad: ");
    recursos[indice] = validarFloatMinimo(0);

    printf("\nProducto actualizado correctamente.\n");
}

void eliminarProducto(int estado[5], char nombres[5][50],int cantidades[5], float tiempos[5],float recursos[5]) {
    char buscar[50];
    int indice;

    printf("\nIngrese el nombre del producto que desea eliminar: ");
    leerCadena(buscar, 50);

    indice = buscarProducto(estado, nombres, buscar);

    if (indice == -1) {
        printf("\nProducto no encontrado.\n");
        return;
    }

    estado[indice] = 0;
    strcpy(nombres[indice], "");
    cantidades[indice] = 0;
    tiempos[indice] = 0;
    recursos[indice] = 0;

    printf("\nProducto eliminado correctamente.\n");
}

void calcularProduccion(int estado[5], int cantidades[5],float tiempos[5], float recursos[5]) {

    float totalTiempo = 0;
    float totalRecursos = 0;
    int contador = 0;

    for (int i = 0; i < 5; i++) {

        if (estado[i] == 1) {
            totalTiempo += cantidades[i] * tiempos[i];
            totalRecursos += cantidades[i] * recursos[i];
            contador++;
        }
    }

    if (contador == 0) {
        printf("\nNo existen productos registrados.\n");
        return;
    }

    printf("\n===== RESULTADOS DE PRODUCCION =====\n");
    printf("Tiempo total necesario: %.2f\n", totalTiempo);
    printf("Recursos totales necesarios: %.2f\n", totalRecursos);
}

void verificarProduccion(int estado[5], int cantidades[5],float tiempos[5], float recursos[5]) {
    float totalTiempo = 0;
    float totalRecursos = 0;
    float tiempoDisponible;
    float recursosDisponibles;
    int contador = 0;

    for (int i = 0; i < 5; i++) {

        if (estado[i] == 1) {
            totalTiempo += cantidades[i] * tiempos[i];
            totalRecursos += cantidades[i] * recursos[i];
            contador++;
        }
    }

    if (contador == 0) {
        printf("\nNo existen productos registrados.\n");
        return;
    }

    printf("\nTiempo disponible en la fabrica: ");
    tiempoDisponible = validarFloatMinimo(0);

    printf("Recursos disponibles en la fabrica: ");
    recursosDisponibles = validarFloatMinimo(0);

    printf("\n===== VERIFICACION DE PRODUCCION =====\n");

    printf("Tiempo requerido: %.2f\n", totalTiempo);
    printf("Tiempo disponible: %.2f\n", tiempoDisponible);

    printf("Recursos requeridos: %.2f\n", totalRecursos);
    printf("Recursos disponibles: %.2f\n", recursosDisponibles);

    if (totalTiempo <= tiempoDisponible &&
        totalRecursos <= recursosDisponibles) {
        printf("\nLa fabrica SI puede cumplir con la demanda.\n");
    } else {
        printf("\nLa fabrica NO puede cumplir con la demanda.\n");
        if (totalTiempo > tiempoDisponible) {
            printf("No existe suficiente tiempo disponible.\n");
        }
        if (totalRecursos > recursosDisponibles) {
            printf("No existen suficientes recursos.\n");
        }
    }
}