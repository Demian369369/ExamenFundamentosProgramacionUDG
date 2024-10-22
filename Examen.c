#include <stdio.h>
void mostrar_menu() {
    printf("*********************************************\n");
    printf("BIENVENIDO AL ESTADIO OLIMPICO UNIVERSITARIO\n");
    printf("*********************************************\n");
    printf("SECTORES DEL ESTADIO:\n");
    printf("(1) Sol General\n");
    printf("(2) Sol Preferente\n");
    printf("(3) Sombra\n");
    printf("(4) Tribuna\n");
    printf("(5) Platea\n");
    printf("(6) Salir\n");
}
float obtener_precio_sector(int opcion) {
    switch (opcion) {
        case 1: return 100.0; // Sol General
        case 2: return 150.0; // Sol Preferente
        case 3: return 200.0; // Sombra
        case 4: return 250.0; // Tribuna
        case 5: return 300.0; // Platea
        default: return 0.0;
    }
}
float calcular_descuento(float precio_total, int sector) {
    switch (sector) {
        case 1: return (precio_total >= 400.0) ? precio_total * 0.05 : 0.0;
        case 2: return (precio_total >= 600.0) ? precio_total * 0.06 : 0.0;
        case 3: return (precio_total >= 800.0) ? precio_total * 0.08 : 0.0;
        case 4: //Aqui se puede omitir porque pues los boletos del case4 y 5 hacen lo mismo solo el precio es distinto
        case 5: return (precio_total >= 1000.0) ? precio_total * 0.10 : 0.0;
        default: return 0.0;
    }
}
int pedir_input_valido(const char *mensaje, int (*validacion_func)(int)) {
    int valor;
    while (1) {
        printf("%s", mensaje);
        if (scanf("%d", &valor) != 1) {
            while (getchar() != '\n');  // Esto es adicional pero sirve para limpiar el buffer
            printf("Error: Debes ingresar un numero valido.\n");
            continue;
        }
        if (validacion_func(valor)) {
            return valor;
        } else {
            printf("Opcion no valida. Intente de nuevo.\n");
        }
    }
}
void procesar_compra(int sector, int boletos) {
    float precio_unitario = obtener_precio_sector(sector);
    float precio_total = boletos * precio_unitario;
    float descuento = calcular_descuento(precio_total, sector);
    float precio_final = precio_total - descuento;
    printf("\nHas seleccionado %d boleto(s) en el sector %d.\n", boletos, sector);
    printf("Precio normal: %.2f\n", precio_total);
    if (descuento > 0) {
        printf("Descuento aplicado: %.2f\n", descuento);
    }
    printf("Total a pagar: %.2f\n\n", precio_final);
}
int validar_sector(int valor) {
    return valor >= 1 && valor <= 6;
}
int validar_boletos(int valor) {
    return valor >= 1;
}
int main() {
    int continuar = 1;
    while (continuar) {
        mostrar_menu();
        int sector = pedir_input_valido(
            "Seleccione el sector (1-5) o 6 para salir: ",
            validar_sector
        );
        if (sector == 6) {
            printf("Saliendo del programa...\n");
            break;
        }
        int boletos = pedir_input_valido(
            "Ingrese la cantidad de boletos a comprar (minimo 1): ",
            validar_boletos
        );
        procesar_compra(sector, boletos);
        char opcion;
        printf("¿Desea continuar comprando boletos? (s/n): ");
        scanf(" %c", &opcion);
        if (opcion != 's' && opcion != 'S') {
            printf("Gracias por su compra. Saliendo del programa...\n");
            continuar = 0;
        }
    }
    return 0;
}
