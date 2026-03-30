#include <stdio.h>

// enums
enum SO { AND, IOS };
enum RES { HD, FHD, _4K };
enum TIPO { SMAR, NOTE, TV };

// union
union Dados {
    enum SO so;// smartphone
    struct {
        float telaN;
        int ram;
    } note; //notebook
    struct {
        float telaT;
        enum RES res;
    } telev;//tv
};

// struct
typedef struct {
    char nome[30];
    float preco;
    enum TIPO tipo;
    union Dados esp;
} Produto;

// simple functions
char* getSO(int x) { return x == 0 ? "Android" : "iOS"; }
char* getRES(int x) { return x == 0 ? "HD" : x == 1 ? "Full HD" : "4K"; }

int main() {
    Produto p[50];
    int qtd = 0, op;
    
    while(1) {
        printf("\n1-Cadastrar 2-Listar 0-Sair: ");
        scanf("%d", &op);
        
        if(op == 0) break;
        
        if(op == 1) {
            int tipo;
            printf("Tipo (0-Smart 1-Note 2-TV): ");
            scanf("%d", &tipo);
            
            printf("Nome: ");
            scanf(" %[^\n]", p[qtd].nome);
            printf("Preco: ");
            scanf("%f", &p[qtd].preco);
            
            p[qtd].tipo = tipo;
            
            // Switch para cada tipo
            switch(tipo) {
                case 0: // smart
                    printf("SO (0-And 1-iOS): ");
                    scanf("%d", (int*)&p[qtd].esp.so);
                    break;
                case 1: // note
                    printf("Tela: ");
                    scanf("%f", &p[qtd].esp.note.telaN);
                    printf("RAM: ");
                    scanf("%d", &p[qtd].esp.note.ram);
                    break;
                case 2: // tv
                    printf("Tela: ");
                    scanf("%f", &p[qtd].esp.telev.telaT);
                    printf("Res (0-HD 1-FHD 2-4K): ");
                    scanf("%d", (int*)&p[qtd].esp.telev.res);
                    break;
            }
            qtd++;
        }
        
        if(op == 2) {
            for(int i = 0; i < qtd; i++) {
                printf("\n%s - R$%.2f\n", p[i].nome, p[i].preco);
                
                if(p[i].tipo == 0)
                    printf("SO: %s\n", getSO(p[i].esp.so));
                else if(p[i].tipo == 1)
                    printf("%.1f\" %dGB\n", p[i].esp.note.telaN, p[i].esp.note.ram);
                else
                    printf("%.1f\" %s\n", p[i].esp.telev.telaT, 
                           getRES(p[i].esp.telev.res));
            }
        }
    }
    return 0;
}
