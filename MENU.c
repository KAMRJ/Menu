#include <stdio.h>

// Prototipos de las funciones
void mostrarInventario(float cantidades[], float precios[], char* nombres[], char* descripciones[]);
void ingresarProducto(float cantidades[], char producto);
void eliminarProducto(float cantidades[], char producto);
void modificarProducto(float cantidades[], float precios[], char producto);

int main(int argc, char *argv[]) {
    char opcion;

    float cantidades[8] = {0};
    float precios[8] = {1.5, 2, 3.40, 4.20, 12, 5, 20, 10};

    char* nombres[] = {"Jugos", "Plato fuerte", "Switch helado", "Combo de papas", "Mariscos", "Postres", "Bistec", "Tacos"};
    char* descripciones[] = {"A eleccion", "Plato fuerte", "Licor", "Porcion de papas", "Mariscos frescos", "A eleccion", "Corte de carne", "Tacos Mexicanos"};

    do {
        printf("--------------MENU-------------\n");
        printf("a. Ver Inventario\n");
        printf("b. Ingreso de Producto\n");
        printf("c. Modificar Producto\n");
        printf("d. Eliminar Producto\n");
        printf("e. Salir\n");
        printf("--------------------------------\n");

        printf("Por favor seleccione una opcion:\n");
        scanf(" %c", &opcion);

        switch (opcion) {
            case 'a':
                mostrarInventario(cantidades, precios, nombres, descripciones);
                break;
            case 'b':
                printf("Opcion 'Ingreso de Producto' seleccionada.\n");
                char producto;
                printf("Ingrese el codigo del producto: ");
                scanf(" %c", &producto);
                ingresarProducto(cantidades, producto);
                break;
            case 'c':
                printf("Opcion 'Modificar Producto' seleccionada.\n");
                printf("Ingrese el codigo del producto que desea modificar: ");
                scanf(" %c", &producto);
                modificarProducto(cantidades, precios, producto);
                break;
            case 'd':
                printf("Opcion 'Eliminar Producto' seleccionada.\n");
                printf("Ingrese el codigo del producto que desea eliminar: ");
                scanf(" %c", &producto);
                eliminarProducto(cantidades, producto);
                break;
            case 'e':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no válida. Intenta de nuevo.\n\n");
                break;
        }
    } while (opcion != 'e');

    return 0;
}

// Implementación de la función mostrarInventario
void mostrarInventario(float cantidades[], float precios[], char* nombres[], char* descripciones[]) {
    printf("------------------------------- INVENTARIO DE PRODUCTOS -------------------------------\n");
    printf("| Codigo |      Nombre      |       Descripcion       |    Cantidad    |   Precio   |\n");
    printf("---------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 8; i++) {
        printf("|   %d    | %-16s | %-25s | %12.0f | %9.2f |\n", i+1, nombres[i], descripciones[i], cantidades[i], precios[i]);
    }

    printf("---------------------------------------------------------------------------------------------\n");
}

void ingresarProducto(float cantidades[], char producto) {
    int productoIndex = producto - '1';

    if (productoIndex >= 0 && productoIndex < 8) {
        printf("Producto encontrado: %d\n", productoIndex + 1);

        // Solicitar la cantidad del nuevo producto
        float cantidad;
        printf("Ingrese la cantidad que desea ingresar: ");
        scanf("%f", &cantidad);

        // Actualizar la cantidad en el inventario
        cantidades[productoIndex] += cantidad;

        // Imprimir un mensaje de confirmación
        printf("Producto '%d' ingresado correctamente.\n", productoIndex + 1);
    } else {
        printf("Producto no encontrado: %c\n", producto);
    }
}

void eliminarProducto(float cantidades[], char producto) {
    int productoIndex = producto - '1';

    if (productoIndex >= 0 && productoIndex < 8) {
        printf("Producto encontrado: %d\n", productoIndex + 1);

        // Solicitar la cantidad a eliminar
        float cantidad;
        printf("Ingrese la cantidad que desea eliminar: ");
        scanf("%f", &cantidad);

        // Verificar si hay suficiente cantidad para eliminar
        if (cantidades[productoIndex] >= cantidad) {
            // Actualizar la cantidad en el inventario
            cantidades[productoIndex] -= cantidad;
            printf("Producto '%d' eliminado correctamente.\n", productoIndex + 1);
        } else {
            printf("No hay suficiente cantidad para eliminar.\n");
        }
    } else {
        printf("Producto no encontrado: %c\n", producto);
    }
}

void modificarProducto(float cantidades[], float precios[], char producto) {
    int productoIndex = producto - '1';

    if (productoIndex >= 0 && productoIndex < 8) {
        printf("Producto encontrado: %d\n", productoIndex + 1);

        // Solicitar el nuevo precio
        float nuevoPrecio;
        printf("Ingrese el nuevo precio del producto:\n ");
        scanf("%f", &nuevoPrecio);

        // Actualizar el precio en el inventario
        precios[productoIndex] = nuevoPrecio;

        // Imprimir un mensaje de confirmación
        printf("Producto '%d' modificado correctamente.\n", productoIndex + 1);
    } else {
        printf("Producto no encontrado: %c\n", producto);
    }
}
