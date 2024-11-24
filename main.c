// JUEGO DE LA VIDA
// LUIS ANGEL ARREDONDO URIBE LICENCIATURA EN COMPUTACIÓN MATEMÁTICA

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "juego.h" // Contiene funciones y constantes necesarias para el juego

#define SCREEN_NC 80 // Número de columnas de la pantalla
#define SCREEN_NR 24 // Número de filas de la pantalla

int main() {
    int idxChar = 0; // Índice para manejar caracteres en la animación
    int desicion;    // Decisión del usuario (iniciar juego o salir)
    int caracter;    // Representación visual de las células
    int pigmento;    // Color de las células
    clearScreen();   // Limpia la pantalla al inicio

    while (1) {
        int c = C_INI; // Coordenda inicial de columna para la animación de presentación
        int color = 0; 

        // Animacion inicial con cambio de colores
        for (color = 0; c < C_FIN; c += 2) {
            usleep(150000); // Pausa de 150 ms entre cada iteración
            setColor(color % N_COLORS); // Cambia el color de la animación
            presentacion(); // Muestra la animación inicial
            color++;
        }
        idxChar = (idxChar + 1) % N_CHARS; // Actualiza el índice de caracteres cíclicamente

        setColor(7); // Color blanco estándar
        desicion = instrucciones(); // obtiene la decisión del usuario

        if (desicion == 1 || desicion == 2) { 
            if (desicion == 1) { // Inicia el juego
                clearScreen();
                caracter = opcion1(); // Selección del carácter para representar las células
                pigmento = opcion2(); // Selección del color de las células
                clearScreen();
                break;
            } else { // Si decide salir
                quitarjuego(); // Limpia recursos antes de salir
                return 0;
            }
        }
        clearScreen();
    }

    GotoXY(0, 0); // Coloca el cursor en la esquina superior izquierda
    mundo juegodevida; // Estructura que representa el estado del juego

    while (1) { 
        int c = C_INI;
        int color = 0;

        // Animación secundaria con colores
        for (color = 0; c < C_FIN; c += 2) {
            usleep(150000); 
            setColor(color % N_COLORS);
            presentacion2(); // Segunda animación antes de iniciar el juego
            color++;
        }
        idxChar = (idxChar + 1) % N_CHARS;

        quitaCursor(); // Oculta el cursor en la consola
        setColor(pigmento - 1); // Configura el color seleccionado por el usuario

        // Configuración inicial del mundo del juego
        if (mimundo(&juegodevida, 116, 22)) { 
            mundorandom(&juegodevida); // Genera un estado inicial aleatorio
            do {
                imprimecelulas(&juegodevida, caracter, stdout); // Dibuja las células en la pantalla
                mundoactual(&juegodevida); // Calcula el siguiente estado del mundo
            } while (1); // Mantiene el bucle infinito para la simulación
            destruyemundo(&juegodevida); // Libera los recursos usados por el mundo
        }
    }

    return 0;
}