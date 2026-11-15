#include <stdio.h>
#include "funciones.h"

int main() {

    int estado[5] = {0};
    char nombres[5][50] = {{0}};
    int cantidades[5] = {0};
    float tiempos[5] = {0};
    float recursos[5] = {0};

    int opc, opc2;

    do {

        printf("\n===== FABRICA DE COMPONENTES =====\n");
        printf("1. Registrar productos\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar productos\n");
        printf("4. Eliminar productos\n");
        printf("5. Calcular produccion\n");
        printf("6. Verificar produccion\n");
        printf("7. Salir\n");

        printf("\nSeleccione una opcion: ");
        opc = validarEnteroRango(1, 7);

        switch (opc) {

            case 1:
                registrarProducto(estado, nombres, cantidades,tiempos, recursos);
                break;

            case 2:
                mostrarProductos(estado, nombres, cantidades,tiempos, recursos);
                break;

            case 3:
                editarProducto(estado, nombres, cantidades,tiempos, recursos);
                break;

            case 4:
                eliminarProducto(estado, nombres, cantidades,tiempos, recursos);
                break;

            case 5:
                calcularProduccion(estado, cantidades,tiempos, recursos);
                break;

            case 6:
                verificarProduccion(estado, cantidades,tiempos, recursos);
                break;

            case 7:
                printf("\nGRACIAS POR TU VISITA\n");
                break;
        }

        if (opc != 7) {
            printf("\nDesea seleccionar otra opcion? 1.Si / 2.No\n");
            opc2 = validarEnteroRango(1, 2);
        } else {
            opc2 = 2;
        }

    } while (opc2 == 1);

    return 0;
}