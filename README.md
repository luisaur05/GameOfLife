# Game of Life

This project implements a simulation of John Conway's Game of Life using the C programming language. The game includes an interactive console interface, initial animations, and the possibility to customize the appearance of the cells in the simulation.


---

## Game Description

The **Game of Life** is a cellular automaton designed by mathematician John Conway. The game takes place on a grid where each cell can be either "alive" or "dead." As the game progresses, the state of each cell evolves according to the following rules:

1. A live cell with fewer than two live neighbors dies from loneliness.
2. A live cell with more than three live neighbors dies from overpopulation.
3. A dead cell with exactly three live neighbors "comes to life."
4. In any other case, the cell remains in its current state.

---

## Features

- **Interactive Interface:** Allows selecting the symbol and color of the cells.
- **Animations:** Initial visual presentations with color changes.
- **Random initial states:** Generates random configurations to start the game.
- **Configured rules:** Accurate implementation of the Game of Life rules.
- **Dynamic screen:** Updates the grid in real-time.

---

## System Requirements

- Operating system compatible with ANSI terminal (Linux, macOS, or Windows with ANSI support).
- C-compatible compiler (such as GCC).
- C standard library.

---

## Project Structure

The project is divided into the following files:

### `main.c`
- **Description**: Contains the main flow of the program, including initial setup, welcome animation, and the game simulation.
- **Main functions**:
  - `main`: Controls the start of the game and user interaction.
  - `instrucciones`: Displays the game rules and allows the user to select an option (play or exit).
  - `opcion1`, `opcion2`: Set the character and color of the cells.

### `juego.c`
- **Description**: Implements the main functions for manipulating the game world, such as initialization, calculating the next state, and visual representation.
- **Key functions**:
  - `mimundo`: Initializes the world and defines the relationships between neighboring cells.
  - `mundorandom`: Generates a random initial state for the cells.
  - `imprimecelulas`: Graphically represents the current state of the world in the console.
  - `mundoactual`: Calculates the next state of each cell based on the game's rules.

### `juego.h`
- **Description**: Header file containing the structure definitions and function prototypes used in `juego.c`.
- **Key components**:
  - Structure `celula`: Defines the state of each cell and its neighbors.
  - Structure `mundo`: Defines the space where the simulations occur.

## Features
- Customization of the character and color of the cells.
- Animated simulation with transitions between generations.
- Welcome animation at the start of the program.
- Friendly console interface with simple controls.

## System Requirements
- **Operating system**: Linux, macOS, or Windows with ANSI escape code support.
- **Compiler**: GCC or any compatible C compiler.
- **Standard libraries**:
  - `stdio.h`
  - `stdlib.h`
  - `unistd.h` (for the `usleep` function).

## Usage Instructions
1. Clone the repository or download the project files.
2. Compile the program:
   ```bash
   gcc -o juego main.c juego.c

## Game Rules

- **Birth**: A cell is born if it has exactly 3 live neighbors.
- **Loneliness**: A cell dies from loneliness if it has fewer than 2 live neighbors.
- **Overpopulation**: A cell dies from overpopulation if it has more than 3 live neighbors.
- **Survival**: Otherwise, a cell remains alive.

## How to Play

Upon starting the program, a welcome animation will appear.

### Step 1: Symbol selection
Select the symbol you want to use to represent the cells. You can choose from:
- `*`
- `#`
- `█`

### Step 2: Color selection
Choose the color of the cells. Some common options are:
- White
- Red
- Green
- And other colors available in the program.

### Step 3: Observe the simulation
Watch how the simulation evolves in real time. The program will show the evolution of the cells according to the rules that apply.

### Step 4: Exit the program
To exit the program at any time, press `CTRL + C` on your keyboard.
