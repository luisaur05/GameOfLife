# Juego de la Vida

Este proyecto implementa una simulación del Juego de la Vida de John Conway utilizando el lenguaje de programación C. El juego incluye una interfaz interactiva en consola, animaciones iniciales y la posibilidad de personalizar el aspecto de las células en la simulación.

## Autor

Luis Ángel Arredondo Uribe  
Licenciatura en Computación Matemática

---

## Descripción del Juego

El **Juego de la Vida** es un autómata celular diseñado por el matemático John Conway. El juego se desarrolla en una cuadrícula donde cada celda puede estar "viva" o "muerta". A medida que el juego avanza, el estado de cada celda evoluciona según las siguientes reglas:

1. Una célula viva con menos de dos vecinos vivos muere por soledad.
2. Una célula viva con más de tres vecinos vivos muere por sobrepoblación.
3. Una célula muerta con exactamente tres vecinos vivos "nace".
4. En cualquier otro caso, la célula mantiene su estado actual.

---

## Características

- **Interfaz interactiva:** Permite seleccionar el símbolo y color de las células.
- **Animaciones:** Presentaciones visuales iniciales con cambios de color.
- **Estados iniciales aleatorios:** Genera configuraciones aleatorias para iniciar el juego.
- **Reglas configuradas:** Implementación fiel de las reglas del Juego de la Vida.
- **Pantalla dinámica:** Actualiza la cuadrícula en tiempo real.

---

## Requisitos del Sistema

- Sistema operativo compatible con terminal ANSI (Linux, macOS, o Windows con soporte ANSI).
- Compilador compatible con C (como GCC).
- Biblioteca estándar de C.

---

## Estructura del Proyecto

El proyecto está dividido en los siguientes archivos:

### `main.c`
- **Descripción**: Contiene el flujo principal del programa, que incluye la configuración inicial, la animación de bienvenida y la simulación del juego.
- **Funciones principales**:
  - `main`: Controla el inicio del juego y la interacción con el usuario.
  - `instrucciones`: Muestra las reglas del juego y permite al usuario seleccionar una opción (jugar o salir).
  - `opcion1`, `opcion2`: Configuran el carácter y color de las células.

### `juego.c`
- **Descripción**: Implementa las funciones principales para la manipulación del mundo del juego, como inicialización, cálculo del siguiente estado, y representación visual.
- **Funciones clave**:
  - `mimundo`: Inicializa el mundo y define las relaciones entre células vecinas.
  - `mundorandom`: Genera un estado inicial aleatorio para las células.
  - `imprimecelulas`: Representa gráficamente el estado actual del mundo en la consola.
  - `mundoactual`: Calcula el siguiente estado de cada célula según las reglas del juego.

### `juego.h`
- **Descripción**: Archivo de encabezado que contiene las definiciones de estructuras y prototipos de funciones utilizados en `juego.c`.
- **Componentes clave**:
  - Estructura `celula`: Define el estado de cada célula y sus vecinos.
  - Estructura `mundo`: Define el espacio donde ocurren las simulaciones.


## Características
- Personalización del carácter y color de las células.
- Simulación animada con transiciones entre generaciones.
- Animación de presentación al inicio del programa.
- Interfaz de consola amigable con controles sencillos.

## Requisitos del Sistema
- **Sistema operativo**: Linux, macOS o Windows con soporte para ANSI escape codes.
- **Compilador**: GCC o cualquier compilador de C compatible.
- **Librerías estándar**:
  - `stdio.h`
  - `stdlib.h`
  - `unistd.h` (para la función `usleep`).

## Instrucciones de Uso
1. Clona el repositorio o descarga los archivos del proyecto.
2. Compila el programa:
   ```bash
   gcc -o juego main.c juego.c


## Reglas del Juego

- **Nacimiento**: Una célula nace si tiene exactamente 3 vecinos vivos.
- **Soledad**: Una célula muere por soledad si tiene menos de 2 vecinos vivos.
- **Sobrepoblación**: Una célula muere por sobrepoblación si tiene más de 3 vecinos vivos.
- **Supervivencia**: En caso contrario, una célula permanece viva.

## Cómo Jugar

Al iniciar el programa, aparecerá una animación de bienvenida.

### Paso 1: Selección de símbolos
Selecciona el símbolo que deseas usar para representar las células. Puedes elegir entre:
- `*`
- `#`
- `█`

### Paso 2: Selección del color
Elige el color de las células. Algunas opciones comunes son:
- Blanco
- Rojo
- Verde
- Y otros colores disponibles en el programa.

### Paso 3: Observa la simulación
Observa cómo la simulación evoluciona en tiempo real. El programa mostrará la evolución de las células según las reglas que se apliquen.

### Paso 4: Salir del programa
Para salir del programa en cualquier momento, presiona `CTRL + C` en tu teclado.
