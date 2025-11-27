#include "Excluir.h"
#include "Contatos.h"
#include "Validacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

void Excluir_pessoa(){
    char continuar = 's';
    char nome[31];
    int ID;
    int retornoID; 
    char *retornoNome;

    while (continuar == 's' || continuar == 'S') {

        printf("Excluir Pessoa por:\n");
        printf("1 - Nome\n");
        printf("2 - ID\n");
        printf("3 - Retornar\n");
        printf("Escolha: ");
        
        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {

            // ====== EXCLUIR POR NOME ======
            case 1: {
                printf("Nome: ");
                scanf("%30s", nome);

                retornoID = Procurar_Nome(nome);

                if (retornoID == 0) {
                    printf("Nome não encontrado!\n");
                } else {
                    atualizar_Pessoas_Excluir(retornoID);
                    printf("Contato excluido com Sucesso!");
                }
                break;
            }

            // ====== EXCLUIR POR ID ======
            case 2: {
                printf("ID: ");
                scanf("%d", &ID);

                retornoNome = Procurar_ID(ID);

                if (retornoNome == NULL) {
                    printf("ID não encontrado!\n");
                } else {
                    atualizar_Pessoas_Excluir(ID);
                    printf("Contato excluido com Sucesso!");
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

        printf("Deseja excluir outra pessoa? (s/n): ");
        scanf(" %c", &continuar);
    }
}


void Excluir_telefone(){
    char continuar = 's';
    char nome[31];
    int ID;
    int retornoID; 
    char *retornoNome;

    while (continuar == 's' || continuar == 'S') {

        printf("Excluir Telefone por:\n");
        printf("1 - Nome\n");
        printf("2 - ID\n");
        printf("3 - Retornar\n");
        printf("Escolha: ");
        
        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {

            // ====== EXCLUIR POR NOME ======
            case 1: {
                printf("Nome: ");
                scanf("%30s", nome);

                retornoID = Procurar_Nome(nome);

                if (retornoID == 0) {
                    printf("Nome não encontrado!\n");
                    printf("Telefone Excluido com Sucesso!");
                } else {
                    atualizar_telefone_Excluir(retornoID);
                }
                break;
            }

            // ====== EXCLUIR POR ID ======
            case 2: {
                printf("ID: ");
                scanf("%d", &ID);

                retornoNome = Procurar_ID(ID);

                if (retornoNome == NULL) {
                    printf("ID não encontrado!\n");
                } else {
                    atualizar_telefone_Excluir(ID);
                    printf("Telefone Excluido com Sucesso!");
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

        printf("Deseja excluir outra pessoa? (s/n): ");
        scanf(" %c", &continuar);
    }
    
}

void atualizar_Pessoas_Excluir(int id_encontrado) {

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

    FILE *tmpP = fopen("Pessoas_temp.csv", "w");
    if (!tmpP) {
        printf("Erro ao criar Pessoas_temp.csv\n");
        fclose(arqP);
        return;
    }

    // ==== 2. PROCESSAR PESSOAS ====

    while (fgets(linha, sizeof(linha), arqP)) {

        int leitura;
        char nome[31], dataNasc[11], cpf[12], email[31];

        leitura = sscanf(linha, "%d;%30[^;];%10[^;];%11[^;];%30[^\n]",
                         &id_lido, nome, dataNasc, cpf, email);

        if (leitura == 5) {
            if (id_lido != id_encontrado) {
                fprintf(tmpP, "%d;%s;%s;%s;%s\n",
                        id_lido, nome, dataNasc, cpf, email);
            }
        }
    }

    fclose(arqP);
    fclose(tmpP);

    Sleep(100);
    // ==== 3. ABRIR ARQUIVOS DE TELEFONES ====

    FILE *arqT = fopen("Telefones.csv", "r");
    if (!arqT) {
        printf("Erro ao abrir Telefones.csv\n");
        return;
    }

    FILE *tmpT = fopen("Telefones_temp.csv", "w");
    if (!tmpT) {
        printf("Erro ao criar Telefones_temp.csv\n");
        fclose(arqT);
        return;
    }

    // ==== 4. PROCESSAR TELEFONES ====

    while (fgets(linha, sizeof(linha), arqT)) {

        int leitura;
        char telefone[12];

        leitura = sscanf(linha, "%d;%11[^\n]",
                         &id_lido, telefone);

        if (leitura == 2) {
            if (id_lido != id_encontrado) {
                fprintf(tmpT, "%d;%s\n",
                        id_lido, telefone);
            }
        }
    }

    fclose(arqT);
    fclose(tmpT);


    // ==== 5. SUBSTITUIR ARQUIVOS ====

    remove("Pessoas.csv");
    rename("Pessoas_temp.csv", "Pessoas.csv");

    remove("Telefones.csv");
    rename("Telefones_temp.csv", "Telefones.csv");
}

void atualizar_telefone_Excluir(int id) {
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

    printf("Qual desses telefones deseja Excluir:\n");

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

    int opcao;
    printf("Escolha o telefone para Excluir (1-%d): ", i-1);
    scanf("%d", &opcao);

    // Validar opção
    if (opcao < 1 || opcao >= i) {
        printf("Opção inválida!\n");
        fclose(arquivoTelefone);
        return;
    }

    //Voltar ao início do arquivo para a segunda leitura
    rewind(arquivoTelefone);

    // Abrir arquivo temporário para excluir
    FILE *arquivo_temp = fopen("Telefones_temp.csv", "w");
    if (!arquivo_temp) {
        printf("Erro ao criar arquivo temporário\n");
        fclose(arquivoTelefone);
        return;
    }

    // Segunda leitura: processar e atualizar
    j = 0;
    while(fgets(linha, sizeof(linha), arquivoTelefone)) {
        if (sscanf(linha, "%d;%30[^;];%11[^\n]", &id_lido, nome, telefone_Existente) == 3) {
            if (id_lido == id) {
                j++;
                if (j != opcao) {
                   
                    fprintf(arquivo_temp, "%d;%s;%s\n", id_lido, nome, telefone_Existente); 

                }
            }

        } else {
            // Escreve linhas que não seguem o formato esperado (para backup)
            fprintf(arquivo_temp, "%s", linha);
        }
    }

    fclose(arquivoTelefone);
    fclose(arquivo_temp);

    // Dá tempo para o sistema liberar os arquivos
    Sleep(100);

    
    if (remove("Telefones.csv") == 0) {
        
        
        // Depois renomeia o temporário
        if (rename("Telefones_temp.csv", "Telefones.csv") == 0) {
            printf("Telefone atualizado com sucesso!\n");
        } else {
            printf("ERRO: Não foi possível renomear Telefones_temp.csv\n");
            perror("Detalhe do rename");
            // Tenta restaurar o backup se o rename falhar
            rename("Telefones.csv", "Telefones_backup.csv");
        }
    } else {
        printf("ERRO: Não foi possível remover Telefones.csv\n");
        perror("Detalhe do remove");
        // Remove o temporário se não conseguiu substituir
        remove("Telefones_temp.csv");
    }
}