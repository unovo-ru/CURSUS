# ft_printf

[English Version](#english-version) | [Versión en Español](#versión-en-español)

---

<div id="english-version"></div>

## English Version

### Description
The goal of this project is to reimplement the famous `printf()` function from the C standard library.
You will learn about variadic functions and how to handle a variable number of arguments.
The key to passing this project is having a well-structured and extensible code.
Once this project is passed, you will be able to include `ft_printf()` in your `libft` for use in future C projects.

### Mandatory Part
* **Program Name**: `libftprintf.a`
* **Files to Submit**: `Makefile`, `*.h`, `*/*.h`, `*.c`, `*/*.c`
* **External Functions**: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`
* **Libft Authorized**: Yes
* **Description**: Write a library containing the `ft_printf()` function, which mimics the original `printf()`.

**Requirements**:
* Prototype: `int ft_printf(char const *, ...);`
* Do not implement the buffer management of the original `printf()`.
* It must handle the following conversions: `cspdiuxX%`
* It will be compared against the original `printf()`.
* Use the `ar` command to create the library. Using `libtool` is forbidden.

**Conversions**:
* `%c`: Prints a single character.
* `%s`: Prints a string (as defined by the default C convention).
* `%p`: The void * pointer argument has to be printed in hexadecimal format.
* `%d`: Prints a decimal number (base 10).
* `%i`: Prints an integer in base 10.
* `%u`: Prints an unsigned decimal number (base 10).
* `%x`: Prints a number in hexadecimal (base 16) lowercase format.
* `%X`: Prints a number in hexadecimal (base 16) uppercase format.
* `%%`: Prints a percent sign.

### Instructions
**Compilation**
To compile the library, run:
```bash
make
```

**Usage**
Include the header in your C file:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    return (0);
}
```
Compile your program with the library:
```bash
cc main.c libftprintf.a -o my_program
./my_program
```

### Resources & AI Usage
This project may use AI tools for:
* Understanding the concept of variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`).
* Explaining how `printf` parsing generally works.
* *[Specify here if/how AI was used in your specific implementation]*

**References:**
* `man printf` (3)
* `man stdarg` (3)

### Algorithm & Data Structure
*[Add your detailed explanation and justification of the chosen algorithm and data structure here. For example: logic for parsing the format string, how variadic arguments are processed, any helper data structures used.]*

### Bonus Part
* Manage any combination of the following flags: `-`, `0`, `.` and the field minimum width under all possible conversions.
* Manage all the following flags: `#`, ` +` (yes, one of them is a space).

---

<div id="versión-en-español"></div>

## Versión en Español

### Descripción
El objetivo de este proyecto es reimplementar la famosa función `printf()` de la librería estándar de C.
Aprenderás sobre funciones variádicas y cómo manejar un número variable de argumentos.
La clave para superar este proyecto es tener un código bien estructurado y extensible.
Una vez superado este proyecto, podrás incluir `ft_printf()` en tu `libft` para usarla en futuros proyectos de C.

### Parte Obligatoria
* **Nombre del Programa**: `libftprintf.a`
* **Archivos a Entregar**: `Makefile`, `*.h`, `*/*.h`, `*.c`, `*/*.c`
* **Funciones Externas**: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`
* **Libft Autorizada**: Sí
* **Descripción**: Escribe una librería que contenga la función `ft_printf()`, que imite el `printf()` original.

**Requisitos**:
* Prototipo: `int ft_printf(char const *, ...);`
* No implementar la gestión del buffer del `printf()` original.
* Debe manejar las siguientes conversiones: `cspdiuxX%`
* Se comparará con el `printf()` original.
* Usar el comando `ar` para crear la librería. El uso de `libtool` está prohibido.

**Conversiones**:
* `%c`: Imprime un solo carácter.
* `%s`: Imprime una cadena de caracteres (como se define por defecto en C).
* `%p`: El puntero void * dado como argumento se imprime en formato hexadecimal.
* `%d`: Imprime un número decimal (base 10).
* `%i`: Imprime un entero en base 10.
* `%u`: Imprime un número decimal (base 10) sin signo.
* `%x`: Imprime un número hexadecimal (base 16) en minúsculas.
* `%X`: Imprime un número hexadecimal (base 16) en mayúsculas.
* `%%`: Imprime el símbolo del porcentaje.

### Instrucciones
**Compilación**
Para compilar la librería, ejecuta:
```bash
make
```

**Uso**
Incluye el header en tu archivo C:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola, %s!\n", "mundo");
    return (0);
}
```
Compila tu programa con la librería:
```bash
cc main.c libftprintf.a -o mi_programa
./mi_programa
```

### Recursos y Uso de IA
Este proyecto puede utilizar herramientas de IA para:
* Entender el concepto de funciones variádicas (`va_list`, `va_start`, `va_arg`, `va_end`).
* Explicar cómo funciona el parseo de `printf` en general.
* *[Especifica aquí si/cómo se usó la IA en tu implementación específica]*

**Referencias:**
* `man printf` (3)
* `man stdarg` (3)

### Algoritmo y Estructura de Datos
*[Añade aquí tu explicación detallada y justificación sobre la elección del algoritmo y la estructura de datos. Por ejemplo: lógica para parsear el string de formato, cómo se procesan los argumentos variádicos, cualquier estructura de datos auxiliar utilizada.]*

### Parte Bonus
* Gestiona cualquier combinación de las siguientes flags: `-`, `0`, `.` y el ancho mínimo de campo bajo todas las conversiones posibles.
* Gestiona las siguientes flags: `#`, ` +` (sí, uno de ellos es un espacio).
