#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Crear el proceso hijo
    pid = fork();

    if (pid < 0) {
        // Error al crear el proceso hijo
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Código del proceso hijo
        printf("Proceso hijo (PID: %d) finalizado.\n", getpid());
        exit(0);  // El proceso hijo termina inmediatamente
    } else {
        // Código del proceso padre
        printf("Proceso padre (PID: %d), hijo creado con PID: %d\n", getpid(), pid);

        // Esperar 60 segundos antes de recoger al hijo, permitiendo que sea un zombie
        sleep(60);

        // Recoger el estado del proceso hijo (esto elimina al proceso zombie)
        wait(NULL);

        printf("Proceso zombie (hijo) eliminado.\n");
    }

    return 0;
}
