#include <stdio.h>
#include <string.h>

#define MAX 50

// student struct
typedef struct {
    char nome[50];
    float n1, n2;
} Aluno;

// mean calculator function
float mediaAluno(Aluno a) {
    return (a.n1 + a.n2) / 2;
}

int main() {
    Aluno alunos[MAX];
    int n, i;
    float somaMedias = 0, mediaClasse;
    int aprovados = 0, reprovados = 0;
    
    // get data from keyboard
    printf("Quantos alunos? ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].n1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].n2);
    }
    
    // calculate statistics
    for(i = 0; i < n; i++) {
        float media = mediaAluno(alunos[i]);
        somaMedias += media;
        
        if(media >= 6.0)
            aprovados++;
        else
            reprovados++;
    }
    
    mediaClasse = somaMedias / n;
    
    // report as file
    FILE *arq = fopen("relatorio.txt", "w");
    
    fprintf(arq, "=== RELATORIO DA CLASSE ===\n");
    fprintf(arq, "Media da classe: %.2f\n", mediaClasse);
    fprintf(arq, "Aprovados: %d\n", aprovados);
    fprintf(arq, "Reprovados: %d\n", reprovados);
    fprintf(arq, "Porcentagem de aprovados: %.1f%%\n", 
            (float)aprovados / n * 100);
    
    fclose(arq);
    
    // student's data files
    FILE *arq2 = fopen("dados_alunos.txt", "w");
    
    for(i = 0; i < n; i++) {
        fprintf(arq2, "%s, %.1f, %.1f\n", 
                alunos[i].nome, alunos[i].n1, alunos[i].n2);
    }
    
    fclose(arq2);
    
    printf("\nRelatorio gerado com sucesso!\n");
    
    return 0;
}
