#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se um caractere é vogal
int ehVogal(char c) {
    c = tolower(c); // Converte para minúsculo para facilitar a comparação
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Função para substituir vogais por números
char substituirVogal(char c) {
    char letra = tolower(c);
    
    switch(letra) {
        case 'a': return '4';  // a vira 4
        case 'e': return '3';  // e vira 3
        case 'i': return '1';  // i vira 1
        case 'o': return '0';  // o vira 0
        case 'u': return '7';  // u vira 7
        default: return c;     // mantém o caractere original se não for vogal
    }
}

int main() {
    char nomeArquivo[100];
    FILE *arquivoEntrada, *arquivoSaida;
    char linha[1000];
    char nomeArquivoSaida[100];
    
    printf("Digite o nome do arquivo TXT: ");
    scanf("%s", nomeArquivo);
    
    // Abre o arquivo para leitura
    arquivoEntrada = fopen(nomeArquivo, "r");
    
    // Verifica se o arquivo foi aberto corretamente
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", nomeArquivo);
        return 1;
    }
    
    // Cria nome para o arquivo de saída
    strcpy(nomeArquivoSaida, "modificado_");
    strcat(nomeArquivoSaida, nomeArquivo);
    
    // Abre arquivo para escrita
    arquivoSaida = fopen(nomeArquivoSaida, "w");
    
    if (arquivoSaida == NULL) {
        printf("Erro ao criar arquivo de saída!\n");
        fclose(arquivoEntrada);
        return 1;
    }
    
    printf("\nProcessando arquivo...\n");
    
    // Lê linha por linha do arquivo
    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        // Processa cada caractere da linha
        for (int i = 0; linha[i] != '\0'; i++) {
            if (ehVogal(linha[i])) {
                linha[i] = substituirVogal(linha[i]);
            }
        }
        
        // Escreve a linha modificada no arquivo de saída
        fputs(linha, arquivoSaida);
    }
    
    // Fecha os arquivos
    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    
    printf("\nArquivo processado com sucesso!\n");
    printf("Resultado salvo em: %s\n", nomeArquivoSaida);
    
    // Mostra o conteúdo modificado
    printf("\nConteúdo modificado:\n");
    printf("-------------------\n");
    
    arquivoSaida = fopen(nomeArquivoSaida, "r");
    if (arquivoSaida != NULL) {
        while (fgets(linha, sizeof(linha), arquivoSaida) != NULL) {
            printf("%s", linha);
        }
        fclose(arquivoSaida);
    }
    
    return 0;
}