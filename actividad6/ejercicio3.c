#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Función que ejecutará el hilo
void* thread_function(void* arg) {
    printf("Hilo creado. PID: %d\n", getpid());
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t thread;

    // Primer fork() - se crea el primer proceso hijo
    pid = fork();
    
    if (pid == -1) {
        perror("Error al crear el proceso");
        exit(1);
    }

    if (pid == 0) { // Código del proceso hijo
        printf("Proceso hijo 1 (PID: %d)\n", getpid());

        // Segundo fork() en el proceso hijo
        pid = fork();

        if (pid == -1) {
            perror("Error al crear el proceso");
            exit(1);
        }

        if (pid == 0) { // Código del segundo proceso hijo (nieto del proceso original)
            printf("Proceso hijo 2 (PID: %d)\n", getpid());

            // Crear un hilo en el segundo proceso hijo (nieto)
            pthread_create(&thread, NULL, thread_function, NULL);
            pthread_join(thread, NULL);

            // Tercer fork() en el segundo proceso hijo
            pid = fork();

            if (pid == -1) {
                perror("Error al crear el proceso");
                exit(1);
            }

            if (pid == 0) { // Tercer proceso hijo (bisnieto)
                printf("Proceso hijo 3 (PID: %d)\n", getpid());
                exit(0); // Salir del tercer proceso hijo
            } else {
                wait(NULL); // Esperar que el tercer proceso hijo termine
            }
        } else {
            wait(NULL); // Esperar que el segundo proceso hijo termine
        }
    } else {
        wait(NULL); // Esperar que el primer proceso hijo termine
    }

    return 0;
}
