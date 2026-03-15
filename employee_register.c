#include <stdio.h>
#include <string.h>

typedef struct
{
  char nome[50];
  int idade;
  char cargo[50];
  float salario;
}tFuncionario;

void cadastrar(tFuncionario funcionario[], int *n)
{
  printf("Nome: ");
  scanf(" %[^\n]", funcionario[*n].nome);
  printf("Idade: ");
  scanf(" %d", &funcionario[*n].idade);
  printf("Cargo: ");
  scanf(" %[^\n]", funcionario[*n].cargo);
  printf("Salário: ");
  scanf("%f", &funcionario[*n].salario);
(*n)++;  
}

void buscar(tFuncionario funcionario[], int n)
{
  char buscaNome[50];
  
  printf("Nome para a busca: \n");
  scanf(" %[^\n]", buscaNome);
  
  for(int i = 0 ; i < n ; i++)
  {
    if(strcmp(funcionario[i].nome, buscaNome) == 0)
    {
      printf("Nome: %s\n", funcionario[i].nome);
      printf("Idade: %d\n", funcionario[i].idade);
      printf("Cargo: %s\n", funcionario[i].cargo);
      printf("Salário: %f\n", funcionario[i].salario);
      return;
    }
    else
    {
      printf("Esse funcionário não foi encontrado.\n");
    }
  }
}
int main()
{
  tFuncionario funcionarios[50];
  int n = 0;
  int op;
  
  do
  {
    printf("====== SELECIONE A OPÇÃO DESEJADA ======\n1: CADASTRO\t\t2: BUSCA\n0: SAIR\n");
    scanf("%d", &op);
    
    switch(op)
    {
      case 1:
      cadastrar(funcionarios, &n);
      break;
      case 2:
      buscar(funcionarios, n);
      break;
    }
  }while(op != 0);

return 0;
}
// if struct array: Funcionario funcionarios[100];
// if read name with spacebar (\n): scanf(" %[^\n]", funcionarios[i].nome);
// if search of a name: if(strcmp(funcionarios[i].nome, nomeBusca) == 0) {}
    // found
// control of number of registered employees: int contador = 0; // global or main
    // when registering;
    //funcionario[contador] = dados;
    //contador ++;
