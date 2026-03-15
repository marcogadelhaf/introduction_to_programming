#include <stdio.h>
#include <string.h>

#define MAX 50

// Struct Funcionario
typedef struct {
    char nome[50];
    int idade;
    char cargo[30];
    float salario;
} Funcionario;

// Cadastro de Funcionários
void cadastrar(Funcionario func[], int *n) {
    printf("Nome: ");
    scanf(" %[^\n]", func[*n].nome);
    printf("Idade: ");
    scanf("%d", &func[*n].idade);
    printf("Cargo: ");
    scanf(" %[^\n]", func[*n].cargo);
    printf("Salario: ");
    scanf("%f", &func[*n].salario);
    (*n)++;
}

// Busca de Funcionário
void buscar(Funcionario func[], int n) {
    char nomeBusca[50];
    printf("Nome a buscar: ");
    scanf(" %[^\n]", nomeBusca);
    
    for(int i = 0; i < n; i++) {
        if(strcmp(func[i].nome, nomeBusca) == 0) {
            printf("\nNome: %s\n", func[i].nome);
            printf("Idade: %d\n", func[i].idade);
            printf("Cargo: %s\n", func[i].cargo);
            printf("Salario: %.2f\n", func[i].salario);
            return;
        }
    }
    printf("Funcionario nao encontrado!\n");
}

int main() {
    Funcionario funcionarios[MAX];
    int n = 0, op;
    
    do {
        printf("\n1-Cadastrar\n2-Buscar\n0-Sair\nOpcao: ");
        scanf("%d", &op);
        
        switch(op) {
            case 1: cadastrar(funcionarios, &n);
            break;
            case 2: buscar(funcionarios, n);
            break;
        }
    } while(op != 0);
    
    return 0;
}
