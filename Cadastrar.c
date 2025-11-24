#include "Cadastrar.h"
#include "Contatos.h"
#include "Validacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *Telefone()
{
    char telefone_temp[12]; // Variável local temporária para leitura
    char *telefone_retorno; // Ponteiro para a memória alocada

    do {
        printf("Telefone (Apenas numeros): ");
        scanf("%s", telefone_temp);
    } while (!validar_Telefone(telefone_temp));

    // 1. Aloca memória no heap para a string (12 caracteres + \0)
    telefone_retorno = (char *)malloc(12 * sizeof(char));
    
    // 2. Verifica se a alocação foi bem-sucedida
    if (telefone_retorno == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL; // Retorna NULL em caso de falha
    }
    
    // 3. Copia a string lida para a memória alocada
    strcpy(telefone_retorno, telefone_temp);
    
    // 4. Retorna o ponteiro alocado
    return telefone_retorno;
}

void Cadastrar_pessoa(){
    struct Contato novo_contato;
    char continua[1] = "s";
    do{
        printf("Nome:");
        scanf("%s", novo_contato.nome);
    } while (!validar_Nome(novo_contato.nome));
    
    do{
        printf("Data de Nascimento (DD/MM/AAAA): ");
        scanf("%s", novo_contato.dataNasc);
    } while (!validar_DataNasc(novo_contato.dataNasc));
    do{
        printf("CPF (Apenas numeros): ");
        scanf("%s", novo_contato.CPF);
    } while (!validar_CPF(novo_contato.CPF));
    
    do{
        printf("E-mail: ");
        scanf("%s", novo_contato.email);
    } while (!validar_Email(novo_contato.email));

     // Salvando pessoa em um arquivo
    FILE *arquivo = fopen("Pessoas.csv", "a");
    if (arquivo == NULL) {
        printf("Arquivo não pôde ser aberto.\n");
        return;
    }
    
    fprintf(arquivo, "%d;%s;%s;%s;%s\n", Ultimo_ID() + 1, novo_contato.nome, novo_contato.dataNasc, novo_contato.CPF, novo_contato.email);
    //printf("Cadastro realizado com sucesso!\n");
    fclose(arquivo);

    // Salvando telefone em um arquivo
    FILE *arquivo_telefone = fopen("Telefones.csv", "a");
    if (arquivo_telefone == NULL) {
        printf("Arquivo de telefones não pôde ser aberto.\n");
        return;
    }
    do{
        fprintf(arquivo_telefone, "%d;%s;%s\n", Ultimo_ID() + 1,novo_contato.nome, Telefone());
        printf("Telefone cadastrado com sucesso!\n");
        printf("Deseja cadastrar outro telefone para %s? (s/n): ", novo_contato.nome);
        scanf("%s", continua);  
    }while (continua[0]=='s' || continua[0]=='S');
    fclose(arquivo_telefone);

   
}

void Cadastrar_telefone(){
    struct Contato novo_telefone;
   


    printf("Cadastro de Telefone por:\n");
    printf("1-Nome\n");
    printf("2-ID\n");
    printf("3-Retornar: ");
    int escolha;
    scanf("%d", &escolha);
    switch (escolha){
    case 1:{
    char nome[31];
    char continua[1] = "s";
    char continuar_mesmoNome[1] = "s";
    bool nome_encontrado = false; 
       do{ 
            printf("Digite o nome: ");
            scanf("%s",nome);
            if (Procurar_Nome(nome)!=0){
                printf("Nome encontrado! Prosseguindo com o cadastro do telefone...\n");
                FILE *arquivo_telefone = fopen("Telefones.csv", "a");
                if (arquivo_telefone == NULL) {
                    printf("Arquivo de telefones não pôde ser aberto.\n");
                    return;
                }
                char *Telefone_cadastrado = Telefone();
                strcpy(novo_telefone.telefone, Telefone_cadastrado);
                do{
                    fprintf(arquivo_telefone, "%d;%s;%s\n",Procurar_Nome(nome),nome, novo_telefone.telefone);
                    printf("Telefone cadastrado com sucesso!\n");
                    printf("Deseja cadastrar outro telefone para %s? (s/n): ", nome);
                    scanf("%s", continuar_mesmoNome);
                }while (continuar_mesmoNome[0]=='s' || continuar_mesmoNome[0]=='S');

                nome_encontrado = true;
                fclose(arquivo_telefone);
                
            } else {
                printf("Nome não encontrado na lista. Deseja tentar novamente? (s/n): ");
                scanf("%s", continua);
            }

            if(nome_encontrado){
                printf("Deseja cadastrar telefone para outro nome? (s/n): ");
                scanf("%s", continua);  
            }
            
        }while (continua[0]=='s' || continua[0]=='S');
        

        break;
    }
   case 2: {
    char continuar[2];
    char continuar_mesmoNome[2] = "s";
    bool id_encontrado = false;
    do {
        continuar[0] = 's';
        int id_busca;
        printf("Digite o ID: ");
        scanf("%d", &id_busca);
        
        char *nome_encontrado = Procurar_ID(id_busca);
        
        if (nome_encontrado != NULL) {
            printf("ID encontrado! Prosseguindo com o cadastro do telefone...\n");
            FILE *arquivo_telefone = fopen("Telefones.csv", "a");
            
            if (arquivo_telefone == NULL) {
                printf("Arquivo de telefones não pôde ser aberto.\n");
                free(nome_encontrado);
                break;
            }
            
            do {
                char *telefone_cadastrado = Telefone();
                char novo_telefone[31];
                strcpy(novo_telefone, telefone_cadastrado);
                
                fprintf(arquivo_telefone, "%d;%s;%s\n", id_busca, nome_encontrado, novo_telefone);
                printf("Telefone cadastrado com sucesso!\n");
                
                printf("Deseja cadastrar outro telefone para o ID %d que pertence a %s? (s/n): ",id_busca, nome_encontrado);
                scanf("%1s", continuar_mesmoNome);
                
                free(telefone_cadastrado); // Liberar memória alocada por Telefone()
                
            } while (continuar_mesmoNome[0] == 's' || continuar_mesmoNome[0] == 'S');
            id_encontrado = true;
            fclose(arquivo_telefone);
            free(nome_encontrado);
            
        } else {
            printf("ID não encontrado na lista. Deseja tentar novamente? (s/n): ");
            scanf("%1s", continuar);
        }
        if (id_encontrado) {
            printf("Deseja cadastrar telefone para outro ID? (s/n): ");
            scanf("%1s", continuar);
        }

        
    } while (continuar[0] == 's' || continuar[0] == 'S');
    break;
    }
    case 3:
        printf("Retornando ao menu anterior...\n");
        break;  

    default:
        printf("Opção inválida. Digite uma opção válida.\n"); 
        break;
    }
}