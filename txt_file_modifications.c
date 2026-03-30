#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float nota1, nota2;
} Aluno;

int ler(Aluno a[], char *arq) {
    FILE *f = fopen(arq, "r");
    if(!f) return 0;
    
    int i = 0;
    while(fscanf(f, " %[^,], %f, %f\n", a[i].nome, &a[i].nota1, &a[i].nota2) == 3)
        i++;
    fclose(f);
    return i;
}

void salvar(Aluno a[], int n, char *arq) {
    FILE *f = fopen(arq, "w");
    for(int i = 0; i < n; i++)
        fprintf(f, "%s, %.1f, %.1f\n", a[i].nome, a[i].nota1, a[i].nota2);
    fclose(f);
}

void alterar(Aluno a[], int n) {
    char nome[50];
    printf("Nome: ");
    scanf(" %[^\n]", nome);
    
    for(int i = 0; i < n; i++) {
        if(strcmp(a[i].nome, nome) == 0) {
            printf("1-Nome 2-Nota1 3-Nota2: ");
            int op;
            scanf("%d", &op);
            
            if(op == 1) {
                printf("Novo nome: ");
                scanf(" %[^\n]", a[i].nome);
            } else if(op == 2) {
                printf("Nova nota1: ");
                scanf("%f", &a[i].nota1);
            } else if(op == 3) {
                printf("Nova nota2: ");
                scanf("%f", &a[i].nota2);
            }
            return;
        }
    }
    printf("Nao encontrado!\n");
}

int main() {
    Aluno alunos[100];
    int total = ler(alunos, "alunos.txt");
    
    alterar(alunos, total);
    salvar(alunos, total, "alunos.txt");
    
    return 0;
}
