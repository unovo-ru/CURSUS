# Libft

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)

[English](#english) | [Español](#español)

---

## <a name="english"></a>English

### Description
**Libft** is a foundational project at 42 School that involves coding a custom C library. The goal is to create a collection of useful functions that will be used in future curriculum projects, as the school often restricts the use of standard C library functions.

This repository contains my personal implementation of:
- Standard libc functions (string manipulation, memory management, character checks).
- Additional utility functions (string splitting, joining, mapping).
- **Linked List** manipulation functions (bonus part).
- **ft_printf**: A custom reimplementation of the `printf` function.
- **get_next_line**: A function to read a file line by line.

### Project Structure
The library covers the following categories:
- **Libc Functions**: `ft_strlen`, `ft_memset`, `ft_strchr`, `ft_atoi`, etc.
- **Additional Functions**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`.
- **Linked Lists (Bonus)**: `ft_lstnew`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstmap`, etc.
- **Extensions**:
  - `ft_printf`: Formatted output conversion.
  - `get_next_line`: Reading lines from file descriptors.

### Usage

1. **Clone the repository:**
   ```bash
   git clone <repository_url>
   cd libft/libft
   ```

2. **Compile the library:**
   Run `make` to compile the source files and generate the `libft.a` static library.
   ```bash
   make
   ```

3. **Use in your project:**
   Include the header file and link the library when compiling your own code.
   ```c
   #include "libft.h"

   int main(void)
   {
       ft_printf("Hello, Libft!\n");
       return (0);
   }
   ```
   Compile command:
   ```bash
   gcc main.c -L. -lft -o my_program
   ```

---

## <a name="español"></a>Español

### Descripción
**Libft** es un proyecto fundamental en 42 School que consiste en programar una librería personalizada en C. El objetivo es crear una colección de funciones útiles que se utilizarán en futuros proyectos del currículo, ya que la escuela a menudo restringe el uso de las funciones estándar de la librería de C.

Este repositorio contiene mi implementación personal de:
- Funciones estándar de libc (manipulación de strings, gestión de memoria, validación de caracteres).
- Funciones de utilidad adicionales (división de strings, uniones, mapeo).
- Funciones para manipulación de **Listas Enlazadas** (parte bonus).
- **ft_printf**: Una reimplementación personalizada de la función `printf`.
- **get_next_line**: Una función para leer un archivo línea por línea.

### Estructura del Proyecto
La librería cubre las siguientes categorías:
- **Funciones Libc**: `ft_strlen`, `ft_memset`, `ft_strchr`, `ft_atoi`, etc.
- **Funciones Adicionales**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`.
- **Listas Enlazadas (Bonus)**: `ft_lstnew`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstmap`, etc.
- **Extensiones**:
  - `ft_printf`: Conversión de salida formateada.
  - `get_next_line`: Lectura de líneas desde descriptores de archivo.

### Uso

1. **Clonar el repositorio:**
   ```bash
   git clone <url_del_repositorio>
   cd libft/libft
   ```

2. **Compilar la librería:**
   Ejecuta `make` para compilar los archivos fuente y generar la librería estática `libft.a`.
   ```bash
   make
   ```

3. **Usar en tu proyecto:**
   Incluye el archivo de cabecera y enlaza la librería al compilar tu propio código.
   ```c
   #include "libft.h"

   int main(void)
   {
       ft_printf("Hola, Libft!\n");
       return (0);
   }
   ```
   Comando de compilación:
   ```bash
   gcc main.c -L. -lft -o mi_programa
   ```
