#include "juego.h"
#include <stdlib.h>  // Para calloc, free, srand, rand
#include <time.h>    // Para time

unsigned char cubito = 254;

/* Función que posiciona el cursor */
void GotoXY(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}

/* Función que limpia la pantalla */
void clearScreen(void) {
    printf("\033[2J\033[H");
}


/* Función que asigna el color del texto */
void setColor(int idxColor) {
    const char *colors[] = {
        "\033[0m",         // Normal (default)
        "\033[31m",        // Rojo
        "\033[32m",        // Verde
        "\033[33m",        // Amarillo
        "\033[34m",        // Azul
        "\033[35m",        // Magenta
        "\033[36m",        // Cian
        "\033[37m"         // Blanco
    };
    printf("%s", colors[idxColor % 8]);
}

/* Funciones de presentación */
void presentacion(void) {
    quitaCursor();
    GotoXY(48, 0);
    printf("######**********######");
    GotoXY(48, 1);
    printf("@= JUEGO DE LA VIDA =@");
    GotoXY(48, 2);
    printf("######**********######");
    GotoXY(43, 4);
    printf("-BIENVENIDO AL JUEGO DE LA VIDA-");
    quitaCursor();
}

void presentacion2(void) {
    quitaCursor();
    GotoXY(48, 0);
    printf("######**********######");
    GotoXY(48, 1);
    printf("@= JUEGO DE LA VIDA =@");
    GotoXY(48, 2);
    printf("######**********######");
    GotoXY(43, 4);
    printf("-BIENVENIDO AL JUEGO DE LA VIDA-");
    GotoXY(40, 5);
    printf("-PARA SALIR PRESIONE LAS TECLAS CTRL C-");
    quitaCursor();
}

/* Función para quitar el cursor de la pantalla */
void quitaCursor(void) {
    printf("\033[?25l");
}

int instrucciones(void){
	int respuesta;
	GotoXY(0,6);
	printf("\nReglas Del Juego.\n");
    printf("1. Una celula nace en una caja vacia cuando tiene exactamente 3 vecinos.\n");
    printf("2. Una celula muere de soledad si tiene menos de 2 vecinos.\n");
    printf("3. Una celula muere de hacinamiento si tiene mas de 3 vecinas.\n");
    printf("4. De lo contrario, las celulas sobreviven.\n");
    printf("\nSeleccione la opcion del menu principal.\n\n");
    printf("\t\t:Menu principal:\n");
    printf("1.Iniciar Juego con celulas aleatorias\n");
    printf("2.Salir del Juego\n");
    printf("\tTu Seleccion: ");
    scanf ("%d", &respuesta);
    
    return respuesta; 
}


int opcion1(void){
	int caracter;
	//char cubito=254;
	
	GotoXY(0,0);
	printf("\t\t:Eleccion de celula:\n");
    printf("1.Celula representada con el caracter *\n");
    printf("2.Celula representada con el caracter #\n");
    printf("3.Celula representada con el caracter %c\n", cubito);
	printf("\tTu Seleccion: ");
    scanf ("%d", &caracter);

	return caracter;
}


int opcion2(void){
	int pigmento;
	
	GotoXY(0,7);
	printf("\t\t:Eleccion de color de celula:\n");
	setColor(0);
    printf("1. Color Blanco.\n");
    setColor(1);
    printf("2. Color Rojo.\n");
    setColor(2);
    printf("3. Color Verde.\n");
    setColor(3);
    printf("4. Color Amarillo.\n");
    setColor(4);
    printf("5. Color Azul.\n");
    setColor(5);
    printf("6. Color Margenta.\n");
    setColor(6);
    printf("7. Color Cian.\n");
    setColor(7);
    printf("\tTu Seleccion: ");
    scanf ("%d", &pigmento);
    
	return pigmento;
}



void quitarjuego(void){
	GotoXY(0,20);
	printf("\n\t\t===============\n");
    printf("\t\t@ Quitar Juego @\n");
    printf("\t\t================\n");
    printf("Gracias por probar este juego. Espero que te hayas divertido.\n");
}


/* Inicializa el mundo del juego asignando memoria y configurando vecinos */
int mimundo(mundo *mundito, int ancho, int alto){
    int i;
    int j;
    unsigned long base = sizeof(celula *) * alto;  // Calcula el tamaño para almacenar los punteros de las filas.
    unsigned long pueblo = sizeof(celula) * ancho; // Calcula el tamaño de una fila completa de células.

    // Reserva memoria para la matriz de punteros y todas las células contiguamente.
    if(!(mundito->mem = calloc(base + (pueblo * alto), 1))){
        return 0;  // Si falla la asignación de memoria, retorna 0.
    }

    // Ajusta los punteros para organizar las filas dentro de la memoria asignada.
    mundito->arreglo = mundito->mem;
    mundito->ancho = ancho; // Guarda el ancho del mundo.
    mundito->alto = alto;   // Guarda el alto del mundo.

    // Establece las direcciones de memoria de cada fila en la matriz.
    for(i = 0; i < alto; i++){
        mundito->arreglo[i] = mundito->mem + base + (i * pueblo);
    }

    // Configura los vecinos de cada célula para todas las posiciones en la matriz.
    for(i = 0; i < alto; i++){
        for(j = 0; j < ancho; j++){
            // Vecino izquierdo.
            if(j != 0){
                (mundito->arreglo[i][j]).vecinos[3] = &(mundito->arreglo[i][j-1]);
            }
            // Vecino superior.
            if(i != 0){
                (mundito->arreglo[i][j]).vecinos[1] = &(mundito->arreglo[i-1][j]);
            }
            // Vecino derecho.
            if(j != (ancho-1)){
                (mundito->arreglo[i][j]).vecinos[4] = &(mundito->arreglo[i][j+1]);
            }
            // Vecino inferior.
            if(i != (alto-1)){
                (mundito->arreglo[i][j]).vecinos[6] = &(mundito->arreglo[i+1][j]);
            }
            // Vecino superior izquierdo.
            if((i != 0) && (j != 0)){
                (mundito->arreglo[i][j]).vecinos[0] = &(mundito->arreglo[i-1][j-1]);
            }
            // Vecino inferior derecho.
            if((i != (alto-1)) && (j != (ancho-1))){
                (mundito->arreglo[i][j]).vecinos[7] = &(mundito->arreglo[i+1][j+1]);
            }
            // Vecino inferior izquierdo.
            if((i != (alto-1)) && (j != 0)){
                (mundito->arreglo[i][j]).vecinos[5] = &(mundito->arreglo[i+1][j-1]);
            }
            // Vecino superior derecho.
            if((i != 0) && (j != (ancho-1))) {
                (mundito->arreglo[i][j]).vecinos[2] = &(mundito->arreglo[i-1][j+1]);
            }
        }
    }

    return 1;  // Retorna 1 si la inicialización fue exitosa.
}

/* Rellena el mundo con un estado aleatorio */
void mundorandom(mundo *mundito){
    int i;
    int j;

    srand(time(NULL));  // Inicializa la semilla del generador de números aleatorios.

    for(i = 0; i < mundito->alto; i++){
        for(j = 0; j < mundito->ancho; j++) {
            // Asigna un estado aleatorio (0 o 1) a cada célula.
            (mundito->arreglo[i][j]).encendido = rand() & 1;
        }
    }
}

/* Dibuja las células en la consola */
void imprimecelulas(mundo *mundito, int caracter, FILE *pOutput){
    int i;
    int j;

    quitaCursor();   // Oculta el cursor en la consola para evitar parpadeos.
    GotoXY(0, 7);    // Posiciona el cursor en un punto fijo de la consola.

    for(i = 0; i < mundito->alto; i++) {
        for(j = 0; j < mundito->ancho; j++){
            // Selecciona el carácter a imprimir según el estado de la célula y el parámetro `caracter`.
            if(caracter == 1){
                fprintf(pOutput, "%c", (mundito->arreglo[i][j]).encendido ? 42 : ' ');  // Asterisco '*'.
            }
            else if(caracter == 2){
                fprintf(pOutput, "%c", (mundito->arreglo[i][j]).encendido ? 35 : ' ');  // Almohadilla '#'.
            }
            else{
                fprintf(pOutput, "%c", (mundito->arreglo[i][j]).encendido ? 254 : ' '); // Bloque sólido.
            }
        }
        fputc((int)'\n', pOutput);  // Salta a la siguiente línea después de imprimir una fila.
    }
    fflush(pOutput);  // Asegura que el contenido se escriba en el archivo o consola inmediatamente.
}


/* Calcula el estado siguiente del mundo */
void mundoactual(mundo *mundito){
    int i;
    int j;
    int a;
    int vecinos;  // Contador para el número de vecinos vivos de una célula.

    // Primera pasada: calcula los estados futuros basándose en las reglas del juego.
    for(i = 0; i < mundito->alto; i++){
        for(j = 0; j < mundito->ancho; j++, vecinos = 0){
            // Cuenta los vecinos vivos de la célula actual.
            for(a = 0; a < 8; a++) {
                if((mundito->arreglo[i][j].vecinos[a]) && 
                   (mundito->arreglo[i][j]).vecinos[a]->encendido & 1){
                    vecinos++;
                }
            }

            // Aplica las reglas del juego:
            if((vecinos < 2) || (vecinos > 3)){  // Regla 1 y 3: soledad o sobrepoblación.
                (mundito->arreglo[i][j]).encendido |= 2;  // Marca la célula para apagarse.
            }
            else if(vecinos == 3){  // Regla 4: reproducción.
                (mundito->arreglo[i][j]).encendido |= 4;  // Marca la célula para encenderse.
            }
        }
    }

    // Segunda pasada: actualiza los estados de las células según las marcas.
    for(i = 0; i < mundito->alto; i++){
        for(j = 0; j < mundito->ancho; j++){
            if(mundito->arreglo[i][j].encendido & 4){  // Si estaba marcada para encenderse.
                mundito->arreglo[i][j].encendido = 1;  // Establece el estado como encendida.
            }
            else if(mundito->arreglo[i][j].encendido & 2){  // Si estaba marcada para apagarse.
                mundito->arreglo[i][j].encendido = 0;  // Establece el estado como apagada.
            }
        }
    }
}

/* Libera la memoria asignada al mundo */
void destruyemundo(mundo *mundito){
	free(mundito->mem);
}