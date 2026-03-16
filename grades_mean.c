#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float n1, n2;
} taluno;

int main()
{
    taluno turma[50];
    int qtd = 0;
    char resp;

    do
    {
        printf("Nome: ");
        scanf(" %[^\n]", turma[qtd].nome);
        printf("Nota 1: ");
        scanf("%f", &turma[qtd].n1);
        printf("Nota 2: ");
        scanf("%f", &turma[qtd].n2);

        qtd++;

        if(qtd < 50) {
            printf("Continuar? (s/n): ");
            scanf(" %c", &resp);
        } else {
            printf("Limite de alunos atingido!\n");
            resp = 'n'; 
        }
    } while(resp == 's' && qtd <= 50);

    float soma = 0, media;
    int aprov = 0, reprov = 0;

    for(int i = 0 ; i < qtd ; i++)
    {
        media = (turma[i].n1 + turma[i].n2) / 2;
        soma += media;

        if(media >= 7)
        {
            aprov++;
        }
        else
        {
            reprov++;
        }
    }

    float mediaTurma = soma / qtd;
    float porcentAprov = (float)aprov / qtd * 100;

    FILE *arq = fopen("relatorio.txt", "w");

    if(arq == NULL) {  
        printf("Erro ao criar arquivo!\n");
        return 1;
    }

    fprintf(arq, "===== RELATÓRIO =====\n");
    fprintf(arq, "Média da Turma: %.2f\n", mediaTurma);
    fprintf(arq, "Aprovados: %d\n", aprov);
    fprintf(arq, "Reprovados: %d\n", reprov);
    fprintf(arq, "Porcentagem de Aprovação: %.2f%%\n", porcentAprov);

    fclose(arq);

    printf("\nArquivo 'relatorio.txt' criado com sucesso...\n");

    return 0;
}