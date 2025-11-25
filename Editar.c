#include "Editar.h"
#include "Contatos.h"
#include "Validacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void Editar_pessoa(){
    
    printf("Editar Pessoa por:\n");
    printf("1-Nome\n");
    printf("2-ID\n");
    printf("3-Retornar: ");
    int escolha;
    scanf("%d", &escolha);
    switch (escolha){
        case 1:
        {

            char continuar[1];
            bool nome_encontrado = false;
            char continuar_mesmoNome[1];
            char nome[31];
            char novo_nome[31];
            int escolha_editar;
            do{
                printf("Digite um nome para editar:" );
                scanf("%s", nome);
                int id_encontrado = Procurar_Nome(nome);
                if (id_encontrado != 0){
                    nome_encontrado = true;
                    printf("Nome encontrado Prosseguindo com a edição...\n");
                    do{
                        printf("Escolha o que deseja editar:\n");
                        printf("1-Nome\n");
                        printf("2-Data de Nascimento\n");
                        printf("3-CPF\n");
                        printf("4-Email\n");
                        printf("5-Retornar\n");
                        scanf("%d", &escolha_editar);
                        switch (escolha_editar){    
                            case 1:{
                                printf("Novo nome de %s: ", nome);
                                scanf("%s", novo_nome);
                               
                                atualizar_Pessoas(novo_nome, id_encontrado);    
                                atualizar_telefone(novo_nome, id_encontrado);
                                
                                
                                printf("Nome atualizado com sucesso para %s.\n", novo_nome);

                                break;
                            }
                            case 2:
                                //editar data de nascimento
                                break;
                            case 3:
                                //editar cpf
                                break;
                            case 4:
                                //editar email
                                break;
                            case 5:
                                printf("Retornando ao menu anterior...\n");
                                break;
                            default:
                                printf("Opcao invalida, digite um número entre 1 à 5.\n");
                                printf("Tente novamente.\n");
                                break;
                        }
                    }while (escolha_editar != 5);
                    
                } else {
                    printf("Nome não encontrado na lista.\n");
                    printf("Deseja tentar novamente? (s/n): ");
                    scanf("%s", continuar);
                }
                if (nome_encontrado) {
                   continuar[0] = 'n'; // Sai do loop se o nome foi encontrado
                }

            }while (continuar[0]=='s' || continuar[0]=='S');
            
            break;
        } 
        case 2:{
        //editar por id
        break;
        }
        case 3:
            printf("Retornando ao menu anterior...\n");
            break;
        default:
            printf("Opcao invalida, digite um número entre 1 à 3.\n");
            printf("Tente novamente.\n");
            break;
    }
}
void atualizar_telefone(char novo_nome[31], int id_encontrado){
    struct Contato contato;
    int id_lido=1;
    char nome_existente[31];
    char telefone[12];
    char linha[200];
    FILE *arquivoTelefone = fopen("Telefones.csv", "r");
    FILE *arquivo_temp = fopen("Telefones_temp.csv", "w");
    if(!arquivoTelefone || !arquivo_temp){
        printf("Erro ao abrir arquivos.\n");
        return;
   }
        
    //atualizar nome na lista de contatos
    while (fgets(linha, sizeof(linha), arquivoTelefone)) {
                                    

         // Lê os dados da linha
        if (sscanf(linha, "%d;%30[^;];%11[^\n]",&id_lido, nome_existente, telefone) == 3) {
                                        
        if (id_lido == id_encontrado) {
            // Atualiza o nome
            strcpy(nome_existente, novo_nome);
        }
        // Escreve os dados (atualizados ou não) no arquivo temporário
        fprintf(arquivo_temp, "%d;%s;%s\n",id_lido, nome_existente, telefone);
        }
        id_lido++;
    }

                               
    fclose(arquivoTelefone);
    fclose(arquivo_temp);
                                
    // Substitui o arquivo original pelo temporário
    remove("Telefones.csv");
    rename("Telefones_temp.csv", "Telefones.csv");

}

void atualizar_Pessoas(char novo_nome[31], int id_encontrado){
    struct Contato pessoa;
    int id_lido=1;
    char nome_existente[31];
    char email[31];
    char CPF[12];
    char dataNasc[11];
    char linha[200];
    FILE *arquivoPessoas = fopen("Pessoas.csv", "r");
    FILE *arquivo_temp = fopen("Pessoas_temp.csv", "w");
    if(!arquivoPessoas || !arquivo_temp){
        printf("Erro ao abrir arquivos.\n");
        return;
   }
        
    //atualizar nome na lista de contatos
    while (fgets(linha, sizeof(linha), arquivoPessoas)) {
                                    

         // Lê os dados da linha
        if (sscanf(linha, "%d;%30[^;];%10[^;];%11[^;];%30[^\n]",&id_lido, nome_existente, dataNasc, CPF, email) == 5) {
                                        
        if (id_lido == id_encontrado) {
            // Atualiza o nome
            strcpy(nome_existente, novo_nome);
        }
        // Escreve os dados (atualizados ou não) no arquivo temporário
        fprintf(arquivo_temp, "%d;%s;%s;%s;%s\n",id_lido, nome_existente, dataNasc, CPF, email);
        }
        id_lido++;
    }

                               
    fclose(arquivoPessoas);
    fclose(arquivo_temp);
                                
    // Substitui o arquivo original pelo temporário
    remove("Pessoas.csv");
    rename("Pessoas_temp.csv", "Pessoas.csv");

}   
void Editar_telefone(){
}