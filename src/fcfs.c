#include <stdio.h>

int main() {
    int n, i;
    float media_espera = 0, media_retorno = 0;

    printf("===== Escalonamento FCFS =====\n");
    printf("Digite o numero de processos: ");
    scanf("%d", &n);

    int burst[n];
    int espera[n];
    int retorno[n];

    for (i = 0; i < n; i++) {
        printf("Digite o tempo de execucao do processo P%d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    espera[0] = 0;
    for (i = 1; i < n; i++) {
        espera[i] = espera[i - 1] + burst[i - 1];
    }

    for (i = 0; i < n; i++) {
        retorno[i] = espera[i] + burst[i];
        media_espera += espera[i];
        media_retorno += retorno[i];
    }

    printf("\nProcesso\tBurst\tEspera\tRetorno\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t%d\t%d\n", i + 1, burst[i], espera[i], retorno[i]);
    }

    printf("\nOrdem de execucao: ");
    for (i = 0; i < n; i++) {
        printf("P%d", i + 1);
        if (i < n - 1) printf(" -> ");
    }

    printf("\n\nTempo medio de espera: %.2f", media_espera / n);
    printf("\nTempo medio de retorno: %.2f\n", media_retorno / n);

    return 0;
}
