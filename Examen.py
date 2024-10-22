def mostrar_menu():
    print("*********************************************")
    print("BIENVENIDO AL ESTADIO OLIMPICO UNIVERSITARIO")
    print("*********************************************")
    print("SECTORES DEL ESTADIO:")
    print("(1) Sol General")
    print("(2) Sol Preferente")
    print("(3) Sombra")
    print("(4) Tribuna")
    print("(5) Platea")
    print("(6) Salir")
def obtener_precio_sector(opcion):
    precios = {
        1: 100,  # Sol General
        2: 150,  # Sol Preferente
        3: 200,  # Sombra
        4: 250,  # Tribuna
        5: 300   # Platea
    }
    return precios.get(opcion, 0)
def calcular_descuento(precio_total, sector):
    descuentos = {
        1: (400, 0.05),  # Sol General
        2: (600, 0.06),  # Sol Preferente
        3: (800, 0.08),  # Sombra
        4: (1000, 0.10),  # Tribuna
        5: (1000, 0.10)  # Platea
    }
    descuento_minimo, porcentaje_descuento = descuentos.get(sector, (0, 0))
    if precio_total >= descuento_minimo:
        return precio_total * porcentaje_descuento
    return 0
def pedir_input_valido(prompt, validacion_func):
    while True:
        try:
            valor = int(input(prompt))
            if validacion_func(valor):
                return valor
            else:
                print("Opción no válida. Intente de nuevo.")
        except ValueError:
            print("Error: Debes ingresar un número válido.")
def procesar_compra(sector, boletos):
    precio_unitario = obtener_precio_sector(sector)
    precio_total = boletos * precio_unitario
    descuento = calcular_descuento(precio_total, sector)
    precio_final = precio_total - descuento
    print(f"\nHas seleccionado {boletos} boleto(s) en el sector {sector}.")
    print(f"Precio normal: {precio_total:.2f}")
    if descuento > 0:
        print(f"Descuento aplicado: {descuento:.2f}")
    print(f"Total a pagar: {precio_final:.2f}\n")
def main():
    while True:
        mostrar_menu()
        sector = pedir_input_valido(
            "Seleccione el sector (1-5) o 6 para salir: ",
            lambda x: 1 <= x <= 6
        )
        if sector == 6:
            print("Saliendo del programa...")
            break
        boletos = pedir_input_valido(
            "Ingrese la cantidad de boletos a comprar (mínimo 1): ",
            lambda x: x >= 1
        )
        procesar_compra(sector, boletos)
        continuar = input("¿Desea continuar comprando boletos? (s/n): ").strip().lower()
        if continuar != 's':
            print("Gracias por su compra. Saliendo del programa...")
            break
if __name__ == "__main__":
    main()
