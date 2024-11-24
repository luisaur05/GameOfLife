#ifndef JUEGO_H
#define JUEGO_H

#include <stdio.h>

#define SCREEN_NC 80
#define SCREEN_NR 24
#define R_INI 10
#define R_FIN 10
#define C_INI 5
#define C_FIN 70
#define N_CHARS 4

#define N_COLORS 8
#define I_NRM  0
#define I_RED  1
#define I_GRN  2
#define I_YEL  3
#define I_BLU  4
#define I_MAG  5
#define I_CYN  6
#define I_WHT  7

typedef struct celula {
    int encendido;
    struct celula *vecinos[8];
} celula;

typedef struct mundo {
    celula **arreglo;
    int ancho;
    int alto;
    void *mem;
} mundo;

// Declaración de funciones 
void GotoXY(int x, int y);
void clearScreen(void);
void setColor(int idxColor);
void quitaCursor(void);
int mimundo(mundo *mundito, int ancho, int alto);
void mundorandom(mundo *mundito);
void imprimecelulas(mundo *mundito, int caracter, FILE *pOutput);
void mundoactual(mundo *mundito);
void destruyemundo(mundo *mundito);
int instrucciones(void);
int opcion1(void);
int opcion2(void);
void quitarjuego(void);
void presentacion(void);
void presentacion2(void);

#endif