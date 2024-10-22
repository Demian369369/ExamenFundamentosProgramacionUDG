# ExamenFundamentosProgramacionUDG
En mi escuela se designó un examen y decidí subirlo en un repositorio. En el RM vienen las instrucciones del examen y el examen viene en Python y en C.

- Agregué comentarios explicando ciertas cosas, aunque creo que el código es muy intuitivo.
-En C no hay acentos y hay faltas de ortografía, ya que en su mayoría se interpreta en el software codeblocks y ese software
hace que en terminal se reflejen feos los acentos, a diferencia de VSCODE con Python


El objetivo de este programa es gestionar la compra de boletos para diferentes sectores de un estadio, con validación de entradas y aplicación de descuentos. pasos principales y cómo se debe proceder en el programa:

1. Mostrar el menú principal:
Al iniciar el programa, se presenta un menú con los sectores disponibles del estadio, cada uno con su número asociado. También se incluye una opción para salir del programa.

2. Solicitar la selección de sector:
El usuario debe seleccionar un sector (del 1 al 5) ingresando el número correspondiente. Si se selecciona un número fuera de este rango, se mostrará un mensaje de error y se le pedirá que ingrese una opción válida.
Si el usuario elige la opción "6", el programa terminará y mostrará un mensaje indicando que está saliendo.

3. Solicitar la cantidad de boletos:
Después de seleccionar un sector válido, se solicita la cantidad de boletos que desea comprar. El usuario debe ingresar un número entero mayor o igual a 1.
Si el usuario ingresa un número no válido (por ejemplo, un número negativo o cero), el programa mostrará un mensaje de error y volverá a solicitar una cantidad válida.

4. Calcular el precio total y el descuento:
Una vez que el usuario ha ingresado un sector y una cantidad válida de boletos, el programa calculará el precio total en función del sector seleccionado.

El programa también aplicará un descuento si el precio total supera un umbral específico para ese sector:
Sol General: 5% de descuento si el total es mayor o igual a $400.
Sol Preferente: 6% de descuento si el total es mayor o igual a $600.
Sombra: 8% de descuento si el total es mayor o igual a $800.
Tribuna y Platea: 10% de descuento si el total es mayor o igual a $1000.

5. Mostrar el total a pagar:
El programa mostrará el precio total sin descuento y, si aplica, el descuento y el total final a pagar.

6. Preguntar si desea continuar:
Después de mostrar el total, el programa le preguntará al usuario si desea realizar otra compra.
Si el usuario ingresa "s" o "S", el proceso de compra se repetirá desde el menú principal.
Si el usuario ingresa cualquier otra opción, el programa terminará mostrando un mensaje de despedida.

7. Finalizar el programa:
El programa continúa repitiendo el proceso hasta que el usuario decida salir seleccionando la opción "6" en el menú o respondiendo que no desea realizar otra compra.
Manejo de errores:
En cualquier momento en que el usuario ingrese una opción no válida, como un número fuera del rango de sectores o una cantidad de boletos no válida, el programa mostrará un mensaje de error y volverá a solicitar el dato correspondiente, garantizando que el usuario no pueda avanzar hasta ingresar información correcta.                
