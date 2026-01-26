# fract-ol

[English Version](#english-version) | [Versión en Español](#versión-en-español)

---

<div id="english-version"></div>

## English Version

### Summary
This project involves creating graphically beautiful fractals.

### Introduction
The term fractal was first used by mathematician Benoit Mandelbrot in 1974. He based it on the Latin word fractus which means "broken" or "fractured". A fractal is an abstract mathematical object, such as a curve or a surface, whose pattern remains consistent at every scale.

### Objectives
It's time for you to create a basic computer graphics project!
You will use the school's graphical library, the MiniLibX. This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.

### Common Instructions
* Your project must be written in C.
* Your project must be written in accordance with the Norm.
* Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.) except for undefined behavior.
* All heap-allocated memory must be properly freed when necessary. Memory leaks will not be tolerated.
* You must submit a Makefile that compiles your source files to the required output with the flags -Wall, -Wextra, and -Werror, using cc.
* Your Makefile must contain at least the rules $(NAME), all, clean, fclean and re.

### Mandatory Part
* **Program Name**: `fractol`
* **Files to Submit**: `Makefile`, `*.h`, `*.c`
* **Arguments**: The type of fractal to display and any other option available.
* **External Functions**:
  * `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`.
  * All functions of the math library (-lm compiler option, man 3 math).
  * All functions of the MiniLibX library.
  * `gettimeofday`
  * `ft_printf` or any equivalent YOU coded.
* **Libft authorized**: Yes
* **Description**: This project is about creating a small fractal exploration program.

**Rendering Rules**:
* Your program must offer the Julia set and the Mandelbrot set.
* The mouse wheel allows zooming in and out almost infinitely (within the computer's limits).
* You must be able to create different Julia sets by passing different parameters to the program.
* A parameter is passed on the command line to define what type of fractal will be displayed in a window.
  * You can handle more parameters to use them as rendering options.
  * If no parameter is provided, or if the parameter is invalid, the program displays a list of available parameters and exits properly.
* You must use at least a few colors to reveal the depth of each fractal.

**Graphic Management**:
* Your program has to display the image in a window.
* Window management must remain smooth (e.g., switching to another window, minimizing, etc.).
* Pressing ESC must close the window and quit the program in a clean way.
* Clicking on the cross on the window's frame must close the window and quit the program in a clean way.
* The use of the images of the MiniLibX library is mandatory.

### Bonus Part
You will get some extra points with the following features:
* One more different fractal (more than a hundred different types of fractals are referenced online).
* The zoom follows the actual mouse position.
* In addition to zooming, allow moving the view using the arrow keys.
* Make the color range shift.

---

<div id="versión-en-español"></div>

## Versión en Español

### Resumen
Este proyecto trata sobre la creación de fractales gráficamente hermosos.

### Introducción
El término fractal fue utilizado por primera vez por el matemático Benoit Mandelbrot en 1974. Basado en la palabra latina fractus que significa "roto" o "fracturado". Un fractal es un objeto matemático abstracto, como una curva o una superficie, cuyo patrón permanece consistente a cualquier escala.

### Objetivos
¡Es hora de crear un proyecto básico de gráficos por ordenador!
Utilizarás la librería gráfica de la escuela, la MiniLibX. Esta librería fue desarrollada internamente e incluye herramientas básicas necesarias para abrir una ventana, crear imágenes y manejar eventos de teclado y ratón.

### Instrucciones Comunes
* Tu proyecto debe estar escrito en C.
* Tu proyecto debe seguir la Norma.
* Tus funciones no deben terminar inesperadamente (segmentation fault, bus error, double free, etc.) excepto por comportamiento indefinido.
* Toda la memoria asignada en el heap debe ser liberada correctamente cuando sea necesario. No se tolerarán fugas de memoria.
* Debes entregar un Makefile que compile tus archivos fuente con las flags -Wall, -Wextra, y -Werror, usando cc.
* Tu Makefile debe contener al menos las reglas $(NAME), all, clean, fclean y re.

### Parte Obligatoria
* **Nombre del Programa**: `fractol`
* **Archivos a entregar**: `Makefile`, `*.h`, `*.c`
* **Argumentos**: El tipo de fractal a mostrar y cualquier otra opción disponible.
* **Funciones Externas**:
  * `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`.
  * Todas las funciones de la librería matemática (opción de compilador -lm, man 3 math).
  * Todas las funciones de la librería MiniLibX.
  * `gettimeofday`
  * `ft_printf` o cualquier equivalente que TÚ hayas codificado.
* **Libft autorizada**: Sí
* **Descripción**: Este proyecto trata sobre crear un pequeño programa de exploración de fractales.

**Reglas de Renderizado**:
* Tu programa debe ofrecer el conjunto de Julia y el conjunto de Mandelbrot.
* La rueda del ratón permite hacer zoom in y out casi infinitamente (dentro de los límites del ordenador).
* Debes poder crear diferentes conjuntos de Julia pasando diferentes parámetros al programa.
* Un parámetro se pasa en la línea de comandos para definir qué tipo de fractal se mostrará en una ventana.
  * Puedes manejar más parámetros para usarlos como opciones de renderizado.
  * Si no se proporciona ningún parámetro, o si el parámetro es inválido, el programa muestra una lista de parámetros disponibles y termina correctamente.
* Debes usar al menos algunos colores para revelar la profundidad de cada fractal.

**Gestión Gráfica**:
* Tu programa tiene que mostrar la imagen en una ventana.
* La gestión de la ventana debe ser fluida (ej. cambiar a otra ventana, minimizar, etc.).
* Presionar ESC debe cerrar la ventana y salir del programa de forma limpia.
* Hacer clic en la cruz del marco de la ventana debe cerrar la ventana y salir del programa de forma limpia.
* El uso de las imágenes de la librería MiniLibX es obligatorio.

### Parte Bonus
Obtendrás puntos extra con las siguientes características:
* Un fractal diferente más (hay más de cien tipos diferentes de fractales referenciados online).
* El zoom sigue la posición real del ratón.
* Además del zoom, permitir mover la vista usando las flechas del teclado.
* Hacer que el rango de colores cambie.
