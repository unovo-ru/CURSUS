# Pipex

[English Version](#english-version) | [Versión en Español](#versión-en-español)

---

<div id="english-version"></div>

## English Version

### Summary
This project will allow you to explore a UNIX mechanism in detail, one that you are already familiar with, by implementing it in your program.

### Mandatory Part
* **Program name**: `pipex`
* **Turn in files**: `Makefile`, `*.h`, `*.c`
* **Arguments**: `file1 cmd1 cmd2 file2`
* **External functions**:
  * `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`
  * `ft_printf` or any equivalent YOU coded
* **Libft authorized**: Yes
* **Description**: This project focuses on handling pipes.

**Requirements**:
Your program should be executed as follows:
```bash
./pipex file1 cmd1 cmd2 file2
```
It must take 4 arguments:
* `file1` and `file2` are file names.
* `cmd1` and `cmd2` are shell commands with their parameters.

It must behave exactly like the following shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

**Examples**:
```bash
$> ./pipex infile "ls -l" "wc -l" outfile
```
Should be equivalent to: `< infile ls -l | wc -l > outfile`

```bash
$> ./pipex infile "grep a1" "wc -w" outfile
```
Should be equivalent to: `< infile grep a1 | wc -w > outfile`

### Bonus Part
You can earn extra points if you:
* Handle multiple pipes.
```bash
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Should behave like:
```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
* Support here-doc when the first parameter is "here_doc".
```bash
$> ./pipex here_doc LIMITER cmd cmd1 file
```
Should behave like:
```bash
cmd << LIMITER | cmd1 >> file
```

---

<div id="versión-en-español"></div>

## Versión en Español

### Resumen
Este proyecto te permitirá explorar un mecanismo de UNIX en detalle, con el que ya estás familiarizado, implementándolo en tu programa.

### Parte Obligatoria
* **Nombre del programa**: `pipex`
* **Archivos a entregar**: `Makefile`, `*.h`, `*.c`
* **Argumentos**: `file1 cmd1 cmd2 file2`
* **Funciones externas**:
  * `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`
  * `ft_printf` o cualquier equivalente que TÚ hayas codificado
* **Libft autorizada**: Sí
* **Descripción**: Este proyecto se centra en el manejo de pipes (tuberías).

**Requisitos**:
Tu programa debe ejecutarse de la siguiente manera:
```bash
./pipex file1 cmd1 cmd2 file2
```
Debe tomar 4 argumentos:
* `file1` y `file2` son nombres de archivos.
* `cmd1` y `cmd2` son comandos de shell con sus parámetros.

Debe comportarse exactamente como el siguiente comando de shell:
```bash
< file1 cmd1 | cmd2 > file2
```

**Ejemplos**:
```bash
$> ./pipex infile "ls -l" "wc -l" outfile
```
Debe ser equivalente a: `< infile ls -l | wc -l > outfile`

```bash
$> ./pipex infile "grep a1" "wc -w" outfile
```
Debe ser equivalente a: `< infile grep a1 | wc -w > outfile`

### Parte Bonus
Puedes obtener puntos extra si:
* Manejas múltiples pipes.
```bash
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Debe comportarse como:
```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
* Soportas here-doc cuando el primer parámetro es "here_doc".
```bash
$> ./pipex here_doc LIMITER cmd cmd1 file
```
Debe comportarse como:
```bash
cmd << LIMITER | cmd1 >> file
```
