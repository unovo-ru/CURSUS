# Philosophers

[English Version](#english-version) | [Versión en Español](#versión-en-español)

---

<div id="english-version"></div>

## English Version

### Summary
In this project, you will learn the basics of threading a process. You will learn how to make threads and discover mutexes.

### Description
The "Dining Philosophers" problem.
* One or more philosophers sit at a round table.
* There is a large bowl of spaghetti in the middle of the table.
* The philosophers take turns eating, thinking, or sleeping.
* While they are eating, they cannot think or sleep; while thinking, they cannot sleep or eat; and while sleeping, they cannot eat or think.
* There are as many forks on the table as there are philosophers.
* Because serving and eating spaghetti with only one fork is awkward, a philosopher takes their right and left forks to eat, one in each hand.
* When a philosopher finishes eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
* All philosophers need to eat and should never starve.
* Philosophers do not speak to each other.
* Philosophers do not know if another philosopher is about to die.
* Philosophers should avoid dying!

### General Instructions
* Global variables are forbidden!
* The program should take the following arguments:
  `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `[number_of_times_each_philosopher_must_eat]`
  * `number_of_philosophers`: The number of philosophers and also the number of forks.
  * `time_to_die` (in ms): If a philosopher doesn't start eating `time_to_die` milliseconds after the start of their last meal or the start of the simulation, they die.
  * `time_to_eat` (in ms): The time it takes for a philosopher to eat. During this time, they will hold two forks.
  * `time_to_sleep` (in ms): The time a philosopher spends sleeping.
  * `number_of_times_each_philosopher_must_eat` (optional argument): If all philosophers eat at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
* Each philosopher is assigned a number from 1 to `number_of_philosophers`.
* Philosopher number 1 wraps next to philosopher number `number_of_philosophers`.

### Mandatory Part
* **Program name**: `philo`
* **Files to submit**: `Makefile`, `*.h`, `*.c`, in the `philo/` directory.
* **Arguments**: `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `[number_of_times_each_philosopher_must_eat]`
* **External functions**: `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`.
* **Libft authorized**: No.
* **Description**: Philosophers with threads and mutexes.
  * Each philosopher should be a thread.
  * One fork between each philosopher. Therefore, if there are multiple philosophers, each philosopher has a fork on their left and one on their right.
  * To prevent philosophers from duplicating forks, you should protect the fork state with a mutex.

### Bonus Part
* **Program name**: `philo_bonus`
* **Files to submit**: `Makefile`, `*.h`, `*.c`, in the `philo_bonus/` directory.
* **Arguments**: Same as mandatory part.
* **External functions**: `memset`, `printf`, `malloc`, `free`, `write`, `fork`, `kill`, `exit`, `pthread_create`, `pthread_detach`, `pthread_join`, `usleep`, `gettimeofday`, `waitpid`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`.
* **Libft authorized**: No.
* **Description**: Philosophers with processes and semaphores.
  * All forks are in the middle of the table.
  * Forks have no states in memory, but the number of available forks is represented by a semaphore.
  * Each philosopher should be a process, and the main process should not be a philosopher.

### Usage
Run `make` in the program directory.
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [meals_required]
```

---

<div id="versión-en-español"></div>

## Versión en Español

### Resumen
En este proyecto, aprenderás los principios básicos de hilar un proceso. Vas a aprender a cómo crear hilos y descubrirás los mutex.

### Descripción
Problema de los filósofos comensales.
* Uno o más filósofos se sientan en una mesa redonda.
* En el centro de la mesa se encuentra un gran bol de espaguetis.
* Los filósofos tomarán turnos para comer, pensar, o dormir.
* Mientras están comiendo, no pueden pensar ni dormir; mientras están pensando, no pueden dormir ni comer; y, mientras están durmiendo, no pueden comer ni pensar.
* En la mesa habrá también tantos tenedores como filósofos.
* Como coger y comer espaguetis con un solo tenedor puede ser incómodo, los filósofos deben tomar el tenedor de la derecha y el de la izquierda, uno en cada mano.
* Cuando un filósofo termine de comer, dejará los tenedores en la mesa e inmediatamente empezará a dormir. Una vez se despierte, empezará a pensar nuevamente. La simulación se detendrá cuando un filósofo muere por inanición.
* Todos los filósofos necesitan comer y nunca deben morir de hambre.
* Los filósofos no hablan entre ellos.
* Los filósofos no saben si otro filósofo va a morir.
* ¡Todos deben evitar morir!

### Instrucciones Generales
* ¡Las variables globales están prohibidas!
* Tu(s) programa(s) debe(n) aceptar los siguientes argumentos:
  `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `[number_of_times_each_philosopher_must_eat]`
  * `number_of_philosophers`: es el número de filósofos, pero también el número de tenedores.
  * `time_to_die` (en milisegundos): si un filósofo no empieza a comer en `time_to_die` milisegundos desde que comenzó su ultima comida o desde el principio de la simulación, este morirá.
  * `time_to_eat` (en milisegundos): es el tiempo que tarda un filósofo en comer. Durante ese tiempo, tendrá los tenedores ocupados.
  * `time_to_sleep` (en milisegundos): es el tiempo que está un filósofo durmiendo.
  * `number_of_times_each_philosopher_must_eat` (argumento opcional): si todos los filósofos comen al menos `number_of_times_each_philosopher_must_eat` veces, la simulación se detendrá. Si no se especifica, la simulación se detendrá con la muerte de un filósofo.
* Cada filósofo tendrá asignado un número del 1 al `number_of_philosophers`.
* El filósofo número 1 se sentará al lado del filósofo número `number_of_philosophers`.

### Parte Obligatoria
* **Nombre de programa**: `philo`
* **Archivos a entregar**: `Makefile`, `*.h`, `*.c`, en el directorio `philo/`.
* **Argumentos**: `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `[number_of_times_each_philosopher_must_eat]`
* **Funciones autorizadas**: `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`.
* **Libft**: No.
* **Descripción**: Philosophers con hilos y mutex.
  * Cada filósofo debe ser representado como un hilo independiente.
  * Hay un tenedor entre cada filósofo. Por lo tanto, si hay varios filósofos, cada filósofo debe tener un tenedor a su izquierda y otro a su derecha.
  * Para prevenir que los filósofos dupliquen los tenedores, deberás proteger el estado de cada tenedor con un mutex.

### Bonus
* **Nombre de programa**: `philo_bonus`
* **Archivos a entregar**: `Makefile`, `*.h`, `*.c`, en el directorio `philo_bonus/`.
* **Argumentos**: Los mismos que en la parte obligatoria.
* **Funciones autorizadas**: `memset`, `printf`, `malloc`, `free`, `write`, `fork`, `kill`, `exit`, `pthread_create`, `pthread_detach`, `pthread_join`, `usleep`, `gettimeofday`, `waitpid`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`.
* **Libft**: No.
* **Descripción**: Philosophers con procesos y semáforos.
  * Todos los tenedores están en el centro de la mesa.
  * Los tenedores no tienen estados en memoria, pero el número de tenedores disponibles está representado por un semáforo.
  * Cada filósofo debe ser un proceso, y el proceso principal no debe ser un filósofo.

### Uso
Ejecutar `make` en el directorio del programa.
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [veces_que_debe_comer]
```
