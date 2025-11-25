#include "Editar.h"
#include "Contatos.h"
#include "Validacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

void Editar_pessoa(){
    char continuar[1];
    bool nome_encontrado = false;
    char continuar_mesmoNome[1];
    char nome[31];
    int ID;
    char novo_nome[31];
    char nova_data_nascimento[11];
    char novo_cpf[12];
    char novo_email[31];
    int escolha_editar;
    int validade;
    char* nome_encontrado1; 
    printf("Editar Pessoa por:\n");
    printf("1-Nome\n");
    printf("2-ID\n");
    printf("3-Retornar: ");
    int escolha;
    scanf("%d", &escolha);
    switch (escolha){
        case 1:
        {

           
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
                            
                                do{
                                    printf("Novo nome de %s: ", nome);
                                    scanf("%s", novo_nome);
                                    validade = validar_Nome(novo_nome);
                                }while (validade != 1);
                                
                                atualizar_Pessoas_Nome(novo_nome, id_encontrado);    
                                atualizar_telefone_Nome(novo_nome, id_encontrado);

                                printf("Nome atualizado com sucesso para %s.\n", novo_nome);

                                break;
                            }
                            case 2:
                                do{
                                    printf("Nova data de nascimento de %s: ", nome);
                                    scanf("%s", nova_data_nascimento);
                                    validade = validar_DataNasc(nova_data_nascimento);
                                }while (validade != 1);

                                atualizar_Pessoas_DataNascimento(nova_data_nascimento, id_encontrado);    
                                printf("Data de nascimento atualizada com sucesso para %s.\n", nova_data_nascimento);

                                break;
                            case 3:
                                do{
                                    printf("Novo CPF de %s: ", nome);
                                    scanf("%s", novo_cpf);
                                    validade = validar_CPF(novo_cpf);
                                }while (validade != 1);

                                atualizar_Pessoas_CPF(novo_cpf, id_encontrado);    
                                printf("CPF atualizado com sucesso para %s.\n", novo_cpf);

                                break;
                            case 4:
                                do{
                                    printf("Novo email de %s: ", nome);
                                    scanf("%s", novo_email);
                                    validade = validar_Email(novo_email);
                                }while (validade != 1);

                                atualizar_Pessoas_Email(novo_email, id_encontrado);    
                                printf("Email atualizado com sucesso para %s.\n", novo_email);

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
            
            do{
                printf("Digite um ID para editar:" );
                scanf("%s", ID);
                 nome_encontrado1 = Procurar_ID(ID);
                if (nome_encontrado1 != NULL){
                    nome_encontrado = true;
                    printf("ID encontrado Prosseguindo com a edição...\n");
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
                            
                                do{
                                    printf("Novo nome de %s: ", nome);
                                    scanf("%s", novo_nome);
                                    validade = validar_Nome(novo_nome);
                                }while (validade != 1);
                                
                                atualizar_Pessoas_Nome(novo_nome, ID);    
                                atualizar_telefone_Nome(novo_nome, ID);

                                printf("Nome atualizado com sucesso para %s.\n", novo_nome);

                                break;
                            }
                            case 2:
                                do{
                                    printf("Nova data de nascimento de %s: ", nome);
                                    scanf("%s", nova_data_nascimento);
                                    validade = validar_DataNasc(nova_data_nascimento);
                                }while (validade != 1);

                                atualizar_Pessoas_DataNascimento(nova_data_nascimento, ID);    
                                printf("Data de nascimento atualizada com sucesso para %s.\n", nova_data_nascimento);

                                break;
                            case 3:
                                do{
                                    printf("Novo CPF de %s: ", nome);
                                    scanf("%s", novo_cpf);
                                    validade = validar_CPF(novo_cpf);
                                }while (validade != 1);

                                atualizar_Pessoas_CPF(novo_cpf, ID);    
                                printf("CPF atualizado com sucesso para %s.\n", novo_cpf);

                                break;
                            case 4:
                                do{
                                    printf("Novo email de %s: ", nome);
                                    scanf("%s", novo_email);
                                    validade = validar_Email(novo_email);
                                }while (validade != 1);

                                atualizar_Pessoas_Email(novo_email, ID);    
                                printf("Email atualizado com sucesso para %s.\n", novo_email);

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
                    printf("ID não encontrado na lista.\n");
                    printf("Deseja tentar novamente? (s/n): ");
                    scanf("%s", continuar);
                }
                if (nome_encontrado) {
                   continuar[0] = 'n'; // Sai do loop se o nome foi encontrado
                }

            }while (continuar[0]=='s' || continuar[0]=='S');
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


void Editar_telefone() {
    char continuar[2] = "s";
    char nome[31];
    int ID;
    int validade_ID; 
    char *validade_nome; // Mudar para ponteiro

    printf("Editar Telefone por:\n");
    printf("1-Nome\n");
    printf("2-ID\n");
    printf("3-Retornar: ");
    int escolha;
    scanf("%d", &escolha);
    
    switch (escolha) {
        case 1: {
            do {
                printf("Nome: ");
                scanf("%30s", nome); // Corrigido: removido &
                validade_ID = Procurar_Nome(nome);
                
                if (validade_ID == 0) {
                    printf("Nome não encontrado. Deseja tentar outro? (s/n): ");
                    scanf("%1s", continuar);
                }
            } while (validade_ID == 0 && (continuar[0] == 's' || continuar[0] == 'S'));
            
            if (validade_ID != 0) {
                do {
                    // CORREÇÃO: Chamar função específica para editar telefone, não recursão
                    atualizar_telefone(validade_ID); // Você precisa criar esta função
                    
                    printf("Deseja editar mais um numero de %s? (s/n): ", nome);
                    scanf("%1s", continuar);
                    
                } while (continuar[0] == 's' || continuar[0] == 'S'); // Corrigido: aspas simples
            }
            break;
        } 
        
        case 2: {
            do {
                printf("ID: ");
                scanf("%d", &ID); // Corrigido: %d para inteiro
                validade_nome = Procurar_ID(ID);
                
                if (validade_nome == NULL) {
                    printf("ID não encontrado. Deseja tentar outro? (s/n): ");
                    scanf("%1s", continuar);
                }
            } while (validade_nome == NULL && (continuar[0] == 's' || continuar[0] == 'S'));
            
            if (validade_nome != NULL) {
                do {
                    // CORREÇÃO: Chamar função específica para editar telefone, não recursão
                    atualizar_telefone(ID); // Você precisa criar esta função
                    
                    printf("Deseja editar mais um numero de %s? (s/n): ", validade_nome);
                    scanf("%1s", continuar);
                    
                } while (continuar[0] == 's' || continuar[0] == 'S'); // Corrigido: aspas simples
                
                // LIBERAR memória alocada por Procurar_ID
                free(validade_nome);
            }
            break;
        }
        
        case 3:
            printf("Retornando ao menu anterior...\n");
            break;
            
        default:
            printf("Opção inválida!\n");
            break;
    }
}

void atualizar_telefone_Nome(char novo_nome[31], int id_encontrado) {
    struct Contato contato;
    int id_lido;
    char nome_existente[31];
    char telefone[12];
    char linha[200];
    
    FILE *arquivoTelefone = fopen("Telefones.csv", "r");
    FILE *arquivo_temp = fopen("Telefones_temp.csv", "w");
    
    if (!arquivoTelefone || !arquivo_temp) {
        printf("Erro ao abrir arquivos.\n");
        if (arquivoTelefone) fclose(arquivoTelefone);
        if (arquivo_temp) fclose(arquivo_temp);
        return;
    }

    
    while (fgets(linha, sizeof(linha), arquivoTelefone)) {
        
        if (sscanf(linha, "%d;%30[^;];%11[^\n]", &id_lido, nome_existente, telefone) == 3) {
            
            if (id_lido == id_encontrado) {
                // Atualiza o nome
                strcpy(nome_existente, novo_nome);
            }
            
            // Escreve os dados (atualizados ou não) no arquivo temporário
            fprintf(arquivo_temp, "%d;%s;%s\n", id_lido, nome_existente, telefone);
        }
       
    }

    fclose(arquivoTelefone);
    fclose(arquivo_temp);

    // Dá tempo para o sistema liberar os arquivos
    Sleep(100);  // 100ms delay

    // Substitui o arquivo original pelo temporário
    if (remove("Telefones.csv") != 0) {
        printf("Aviso: Não foi possível remover Telefones.csv\n");
    }
    
    if (rename("Telefones_temp.csv", "Telefones.csv") != 0) {
        printf("Erro ao renomear arquivo temporário de telefones\n");
        perror("Detalhe");
    } else {
        printf("\n");
    }
}

 void atualizar_Pessoas_Nome(char novo_nome[31], int id_encontrado) {
    int id_lido;
    char nome_existente[31];
    char dataMasc[11];
    char CPF[12];
    char email[31];
    char linha[200];
    
    // Fecha qualquer instância que possa estar aberta
    fflush(stdin);
    
    FILE *arquivoPessoas = fopen("Pessoas.csv", "r");
    if (!arquivoPessoas) {
        printf("Erro: Não foi possível abrir Pessoas.csv para leitura\n");
        return;
    }
    
    FILE *arquivo_temp = fopen("Pessoas_temp.csv", "w");
    if (!arquivo_temp) {
        printf("Erro: Não foi possível criar arquivo temporário\n");
        fclose(arquivoPessoas);
        return;
    }

    // Atualizar nome na lista de contatos
    while (fgets(linha, sizeof(linha), arquivoPessoas)) {
        // Lê os dados da linha
        if (sscanf(linha, "%d;%30[^;];%10[^;];%11[^;];%30[^\n]", 
                   &id_lido, nome_existente, dataMasc, CPF, email) == 5) {
            
            if (id_lido == id_encontrado) {
                // Atualiza o nome
                strcpy(nome_existente, novo_nome);
            }
            
            // Escreve no arquivo temporário
            fprintf(arquivo_temp, "%d;%s;%s;%s;%s\n", id_lido, nome_existente, dataMasc, CPF, email);
        }
    }

    fclose(arquivoPessoas);
    fclose(arquivo_temp);

    // Dá tempo para o sistema liberar os arquivos
    Sleep(100);  // 100ms delay

    
    // Primeiro remove o original
    if (remove("Pessoas.csv") == 0) {
     
        
        // Depois renomeia o temporário
        if (rename("Pessoas_temp.csv", "Pessoas.csv") == 0) {
            printf("\n");
        } else {
            printf("ERRO: Não foi possível renomear Pessoas_temp.csv\n");
            perror("Detalhe do rename");
        }
    } else {
        printf("ERRO: Não foi possível remover Pessoas.csv\n");
        perror("Detalhe do remove");
        // Remove o temporário se não conseguiu substituir
        remove("Pessoas_temp.csv");
    }
}

 void atualizar_Pessoas_DataNascimento(char nova_data_nascimento[11], int id_encontrado) {
    int id_lido;
    char nome[31];
    char dataNasc_existente[11];
    char CPF[12];
    char email[31];
    char linha[200];
    
    // Fecha qualquer instância que possa estar aberta
    fflush(stdin);
    
    FILE *arquivoPessoas = fopen("Pessoas.csv", "r");
    if (!arquivoPessoas) {
        printf("Erro: Não foi possível abrir Pessoas.csv para leitura\n");
        return;
    }
    
    FILE *arquivo_temp = fopen("Pessoas_temp.csv", "w");
    if (!arquivo_temp) {
        printf("Erro: Não foi possível criar arquivo temporário\n");
        fclose(arquivoPessoas);
        return;
    }

    // Atualizar nome na lista de contatos
    while (fgets(linha, sizeof(linha), arquivoPessoas)) {
        // Lê os dados da linha
        if (sscanf(linha, "%d;%30[^;];%10[^;];%11[^;];%30[^\n]", 
                   &id_lido, nome, dataNasc_existente, CPF, email) == 5) {
            
            if (id_lido == id_encontrado) {
                // Atualiza o nome
                strcpy(dataNasc_existente, nova_data_nascimento);
            }
            
            // Escreve no arquivo temporário
            fprintf(arquivo_temp, "%d;%s;%s;%s;%s\n", id_lido, nome, dataNasc_existente, CPF, email);
        }
    }

    fclose(arquivoPessoas);
    fclose(arquivo_temp);

    // Dá tempo para o sistema liberar os arquivos
    Sleep(100);  // 100ms delay

    
    // Primeiro remove o original
    if (remove("Pessoas.csv") == 0) {
     
        
        // Depois renomeia o temporário
        if (rename("Pessoas_temp.csv", "Pessoas.csv") == 0) {
            printf("\n");
        } else {
            printf("ERRO: Não foi possível renomear Pessoas_temp.csv\n");
            perror("Detalhe do rename");
        }
    } else {
        printf("ERRO: Não foi possível remover Pessoas.csv\n");
        perror("Detalhe do remove");
        // Remove o temporário se não conseguiu substituir
        remove("Pessoas_temp.csv");
    }
}

void atualizar_Pessoas_CPF(char novo_cpf[12], int id_encontrado) {
    int id_lido;
    char nome[31];
    char dataNasc[11];
    char CPF_Existente[12];
    char email[31];
    char linha[200];
    
    // Fecha qualquer instância que possa estar aberta
    fflush(stdin);
    
    FILE *arquivoPessoas = fopen("Pessoas.csv", "r");
    if (!arquivoPessoas) {
        printf("Erro: Não foi possível abrir Pessoas.csv para leitura\n");
        return;
    }
    
    FILE *arquivo_temp = fopen("Pessoas_temp.csv", "w");
    if (!arquivo_temp) {
        printf("Erro: Não foi possível criar arquivo temporário\n");
        fclose(arquivoPessoas);
        return;
    }

    // Atualizar nome na lista de contatos
    while (fgets(linha, sizeof(linha), arquivoPessoas)) {
        // Lê os dados da linha
        if (sscanf(linha, "%d;%30[^;];%10[^;];%11[^;];%30[^\n]", 
                   &id_lido, nome, dataNasc, CPF_Existente, email) == 5) {
            
            if (id_lido == id_encontrado) {
                // Atualiza o nome
                strcpy(CPF_Existente, novo_cpf);
            }
            
            // Escreve no arquivo temporário
            fprintf(arquivo_temp, "%d;%s;%s;%s;%s\n", id_lido, nome, dataNasc, CPF_Existente,email);
        }
    }

    fclose(arquivoPessoas);
    fclose(arquivo_temp);

    // Dá tempo para o sistema liberar os arquivos
    Sleep(100);  // 100ms delay

    
    // Primeiro remove o original
    if (remove("Pessoas.csv") == 0) {
     
        
        // Depois renomeia o temporário
        if (rename("Pessoas_temp.csv", "Pessoas.csv") == 0) {
            printf("\n");
        } else {
            printf("ERRO: Não foi possível renomear Pessoas_temp.csv\n");
            perror("Detalhe do rename");
        }
    } else {
        printf("ERRO: Não foi possível remover Pessoas.csv\n");
        perror("Detalhe do remove");
        // Remove o temporário se não conseguiu substituir
        remove("Pessoas_temp.csv");
    }
}

void atualizar_Pessoas_Email(char novo_email[31], int id_encontrado) {
    int id_lido;
    char nome[31];
    char dataNasc[11];
    char CPF[12];
    char email_Existente[31];
    char linha[200];
    
    // Fecha qualquer instância que possa estar aberta
    fflush(stdin);
    
    FILE *arquivoPessoas = fopen("Pessoas.csv", "r");
    if (!arquivoPessoas) {
        printf("Erro: Não foi possível abrir Pessoas.csv para leitura\n");
        return;
    }
    
    FILE *arquivo_temp = fopen("Pessoas_temp.csv", "w");
    if (!arquivo_temp) {
        printf("Erro: Não foi possível criar arquivo temporário\n");
        fclose(arquivoPessoas);
        return;
    }

    // Atualizar nome na lista de contatos
    while (fgets(linha, sizeof(linha), arquivoPessoas)) {
        // Lê os dados da linha
        if (sscanf(linha, "%d;%30[^;];%10[^;];%11[^;];%30[^\n]", 
                   &id_lido, nome, dataNasc, CPF, email_Existente) == 5) {
            
            if (id_lido == id_encontrado) {
                // Atualiza o nome
                strcpy(email_Existente, novo_email);
            }
            
            // Escreve no arquivo temporário
            fprintf(arquivo_temp, "%d;%s;%s;%s;%s\n", id_lido, nome, dataNasc, CPF, email_Existente);
        }
    }

    fclose(arquivoPessoas);
    fclose(arquivo_temp);

    // Dá tempo para o sistema liberar os arquivos
    Sleep(100);  // 100ms delay

    
    // Primeiro remove o original
    if (remove("Pessoas.csv") == 0) {
     
        
        // Depois renomeia o temporário
        if (rename("Pessoas_temp.csv", "Pessoas.csv") == 0) {
            printf("\n");
        } else {
            printf("ERRO: Não foi possível renomear Pessoas_temp.csv\n");
            perror("Detalhe do rename");
        }
    } else {
        printf("ERRO: Não foi possível remover Pessoas.csv\n");
        perror("Detalhe do remove");
        // Remove o temporário se não conseguiu substituir
        remove("Pessoas_temp.csv");
    }
}

void atualizar_telefone(int id) {
    char linha[200];
    int id_lido;
    char nome[31];
    char telefone_Existente[12];
    int i = 1;
    int j = 0;
    char novo_telefone[12];
    int validar;

    // Fecha qualquer instância que possa estar aberta
    fflush(stdin);
    
    FILE *arquivoTelefone = fopen("Telefones.csv", "r");
    if (!arquivoTelefone) {
        printf("Erro ao abrir Telefones.csv para leitura\n");
        return;
    }

    printf("Qual desses telefones deseja editar:\n");

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
    printf("Escolha o telefone para editar (1-%d): ", i-1);
    scanf("%d", &opcao);

    // Validar opção
    if (opcao < 1 || opcao >= i) {
        printf("Opção inválida!\n");
        fclose(arquivoTelefone);
        return;
    }

    // Solicitar novo telefone
    do {
        printf("Digite um novo número: ");
        scanf("%11s", novo_telefone); // CORREÇÃO: removido &
        validar = validar_Telefone(novo_telefone);
        if (validar != 1) {
            printf("Telefone inválido! Tente novamente.\n");
        }
    } while (validar != 1);

    //Voltar ao início do arquivo para a segunda leitura
    rewind(arquivoTelefone);

    // Abrir arquivo temporário para escrita
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
                if (j == opcao) {
                    // Atualiza o telefone escolhido
                    strcpy(telefone_Existente, novo_telefone);

                }
            }

            fprintf(arquivo_temp, "%d;%s;%s\n", id_lido, nome, telefone_Existente);
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