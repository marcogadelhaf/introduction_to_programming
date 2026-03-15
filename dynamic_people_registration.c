#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct Pessoa
typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

// person registration function
Pessoa* cadastrarPessoa() {
    Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
    
    if(p == NULL) {
        printf("Erro de alocacao!\n");
        return NULL;
    }
    
    printf("Nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Idade: ");
    scanf("%d", &p->idade);
    printf("Altura: ");
    scanf("%f", &p->altura);
    
    return p;
}

// people vector function creation
Pessoa* criarVetor(int n) {
    Pessoa *v = (Pessoa*) malloc(n * sizeof(Pessoa));
    
    if(v == NULL) {
        printf("Erro de alocacao!\n");
        return NULL;
    }
    
    return v;
}

// print of person function
void imprimirPessoa(Pessoa p) {
    printf("Nome: %s | Idade: %d | Altura: %.2f\n", 
           p.nome, p.idade, p.altura);
}

int main() {
    int n, i;
    Pessoa *pessoas;
    
    // vector allocation 
    printf("Quantas pessoas? ");
    scanf("%d", &n);
    
    pessoas = criarVetor(n);
    if(pessoas == NULL) return 1;
    
    // registration
    for(i = 0; i < n; i++) {
        printf("\nPessoa %d:\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", pessoas[i].nome);
        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
        printf("Altura: ");
        scanf("%f", &pessoas[i].altura);
    }
    
    // list
    printf("\n--- PESSOAS CADASTRADAS ---\n");
    for(i = 0; i < n; i++) {
        imprimirPessoa(pessoas[i]);
    }
    
    // memory release
    free(pessoas);
    
    return 0;
}
