# Actividad 6

## ¿Incluyendo el proceso inicial, cuantos procesos son creados por el siguiente programa? Razone su respuesta.

En total se generan 7 procesos.

**Razon:** El programa que has proporcionado crea procesos utilizando la función `fork()`, que genera un nuevo proceso duplicado del proceso padre. Cada vez que se llama a `fork()`, se crea un nuevo proceso.

Vamos a analizarlo paso por paso:

1. **Primer `fork()`**:
   - El primer `fork()` crea un proceso hijo. Después de esta llamada, ahora hay **dos** procesos: el proceso original (padre) y el proceso hijo recién creado.

2. **Segundo `fork()`**:
   - Ahora, **ambos** procesos (el padre y el hijo) ejecutan la segunda llamada a `fork()`, lo que significa que **cada uno** de esos dos procesos crea un nuevo proceso hijo.
   - Ahora hay **cuatro** procesos: el proceso padre original, el primer hijo, y dos nuevos hijos creados por los dos procesos que existían antes de este `fork()`.

3. **Tercer `fork()`**:
   - Después del segundo `fork()`, hay cuatro procesos. Cada uno de estos cuatro procesos llama a `fork()` nuevamente, generando un nuevo proceso cada uno.
   - En total, después de esta llamada, hay **ocho** procesos.

**Número total de procesos creados**:
- El proceso inicial es el que ejecuta el programa.
- Después del primer `fork()`, hay 2 procesos.
- Después del segundo `fork()`, hay 4 procesos.
- Después del tercer `fork()`, hay 8 procesos.

Por lo tanto, el programa crea **7 procesos nuevos**, además del proceso original. En total, incluyendo el proceso inicial, hay **8 procesos**.

### Resumen:

- Número de procesos creados: **7**
- Número total de procesos (incluyendo el inicial): **8**.

## Procesos Zombie

- El proceso hijo se finaliza inmediatamente después de su creación llamando a exit(0);.
- El proceso padre espera durante 60 segundos usando sleep(60);, tiempo durante el cual el proceso hijo estará en estado zombie.
- Después de los 60 segundos, el proceso padre llama a wait(NULL); para leer el estado del proceso hijo y eliminar el proceso zombie.

## Ejercicio 3

El código que proporcionas parece incompleto. Vamos a completarlo y analizar cuántos procesos e hilos se crean. 

### Explicación de la ejecución del programa:

1. El programa empieza con una llamada a `fork()` que crea el **primer proceso hijo**.
2. En el primer proceso hijo, se realiza otro `fork()`, lo que crea un **segundo proceso hijo** (que sería el **nieto** del proceso original).
3. En el segundo proceso hijo (nieto), se crea un hilo con `pthread_create()`, lo que genera un hilo único en ese proceso.
4. Después de crear el hilo, en el mismo segundo proceso hijo (nieto), se realiza otro `fork()` que crea un **tercer proceso hijo** (que sería el **bisnieto** del proceso original).
5. Finalmente, se usa `wait()` en todos los procesos padres para que no terminen antes que sus hijos.

### Respuestas:

1. **¿Cuántos procesos únicos son creados?**
   - El proceso original (padre) es el primer proceso.
   - El primer `fork()` crea un proceso hijo.
   - El segundo `fork()` dentro del primer proceso hijo crea otro proceso (nieto).
   - El tercer `fork()` dentro del segundo proceso hijo crea un tercer proceso (bisnieto).

   **Total de procesos creados: 3 nuevos procesos** (más el proceso original), es decir, **4 procesos en total**.

2. **¿Cuántos hilos únicos son creados?**
   - El programa solo llama una vez a `pthread_create()`, lo que crea un único hilo en el segundo proceso hijo (nieto).

   **Total de hilos únicos creados: 1**.

### Resumen:

- **Procesos únicos creados**: 3 (además del proceso original, sumando 4 en total).
- **Hilos únicos creados**: 1.