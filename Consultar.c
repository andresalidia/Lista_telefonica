#include "Consultar.h"
#include "Contatos.h"
#include "Validacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

void Consultar_pessoa(){
    char continuar = 's';
    char nome[31];
    int ID;
    int retornoID; 
    char *retornoNome;

    while (continuar == 's' || continuar == 'S') {

        printf("Consultar Pessoa por:\n");
        printf("1 - Nome\n");
        printf("2 - ID\n");
        printf("3 - Retornar\n");
        printf("Escolha: ");
        
        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {

            // ====== Consultar POR NOME ======
            case 1: {
                printf("Nome: ");
                scanf("%30s", nome);

                retornoID = Procurar_Nome(nome);

                if (retornoID == 0) {
                    printf("Nome não encontrado!\n");
                } else {
                    atualizar_Pessoas_Consultar(retornoID);
                }
                break;
            }

            // ====== Consultar POR ID ======
            case 2: {
                printf("ID: ");
                scanf("%d", &ID);

                retornoNome = Procurar_ID(ID);

                if (retornoNome == NULL) {
                    printf("ID não encontrado!\n");
                } else {
                    atualizar_Pessoas_Consultar(ID);
                    free(retornoNome);
                }
                break;
            }

            // ====== RETORNAR ======
            case 3:
                printf("Voltando ao menu...\n");
                return;

            default:
                printf("Opção inválida!\n");
        }

        printf("Deseja Consultar outra pessoa? (s/n): ");
        scanf(" %c", &continuar);
    }
}


void Consultar_telefone(){
    char continuar = 's';
    char nome[31];
    int ID;
    int retornoID; 
    char *retornoNome;

    while (continuar == 's' || continuar == 'S') {

        printf("Consultar Telefone por:\n");
        printf("1 - Nome\n");
        printf("2 - ID\n");
        printf("3 - Retornar\n");
        printf("Escolha: ");
        
        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {

            // ====== Consultar POR NOME ======
            case 1: {
                printf("Nome: ");
                scanf("%30s", nome);

                retornoID = Procurar_Nome(nome);

                if (retornoID == 0) {
                    printf("Nome não encontrado!\n");
                } else {
                    atualizar_telefone_Consultar(retornoID);
                }
                break;
            }

            // ====== Consultar POR ID ======
            case 2: {
                printf("ID: ");
                scanf("%d", &ID);

                retornoNome = Procurar_ID(ID);

                if (retornoNome == NULL) {
                    printf("ID não encontrado!\n");
                } else {
                    atualizar_telefone_Consultar(ID);
                    free(retornoNome);
                }
                break;
            }

            // ====== RETORNAR ======
            case 3:
                printf("Voltando ao menu...\n");
                return;

            default:
                printf("Opção inválida!\n");
        }

        printf("Deseja Consultar outra pessoa? (s/n): ");
        scanf(" %c", &continuar);
    }
    
}

void atualizar_Pessoas_Consultar(int id_encontrado) {

    char linha[256];
    int id_lido;

    // Fecha qualquer instância que possa estar aberta
    fflush(stdin);

    // ==== 1. ABRIR ARQUIVOS DE PESSOAS ====

    FILE *arqP = fopen("Pessoas.csv", "r");
    if (!arqP) {
        printf("Erro ao abrir Pessoas.csv\n");
        return;
    }

    // ==== 2. PROCESSAR PESSOAS ====

    while (fgets(linha, sizeof(linha), arqP)) {

        int leitura;
        char nome[31], dataNasc[11], cpf[12], email[31];

        leitura = sscanf(linha, "%d;%30[^;];%10[^;];%11[^;];%30[^\n]",
                         &id_lido, nome, dataNasc, cpf, email);

        if (leitura == 5) {
            if (id_lido == id_encontrado) {
                printf("%d;%s;%s;%s;%s\n",id_lido, nome, dataNasc, cpf, email);
            }
        }
    }

    fclose(arqP);
   
}

void atualizar_telefone_Consultar(int id) {
    char linha[200];
    int id_lido;
    char nome[31];
    char telefone_Existente[12];
    int i = 1;
    int j = 0;
    int validar;

    // Fecha qualquer instância que possa estar aberta
    fflush(stdin);
    
    FILE *arquivoTelefone = fopen("Telefones.csv", "r");
    if (!arquivoTelefone) {
        printf("Erro ao abrir Telefones.csv para leitura\n");
        return;
    }

    printf("Telefones vinculados\n");

    // Primeira leitura: mostrar os telefones
    while(fgets(linha, sizeof(linha), arquivoTelefone)) {
        if (sscanf(linha, "%d;%30[^;];%11[^\n]", &id_lido, nome, telefone_Existente) == 3) {
            if (id_lido == id) {
                printf("%d - %s\n", i, telefone_Existente);
                i++;
            }
        }
    }

    // Se não encontrou telefones
    if (i == 1) {
        printf("Nenhum telefone encontrado para este ID.\n");
        fclose(arquivoTelefone);
        return;
    }

    

    fclose(arquivoTelefone);
    
}