#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Validacao.h"

int Ultimo_ID() {
    FILE *arquivo = fopen("Pessoas.csv", "r");
    int ultimo_id = 0;

    if (arquivo != NULL) {
        char linha[200];

        while (fgets(linha, sizeof(linha), arquivo)) {
            int id_lido;

            // Lê o ID (int) do início da linha
            if (sscanf(linha, "%d;", &id_lido) == 1) {
                if (id_lido > ultimo_id) {
                    ultimo_id = id_lido;
                }
            }
        }

        fclose(arquivo);
    }

    return ultimo_id;
}

int validar_Nome(const char* nome) {
    int tamanho = strlen(nome);

    // Verifica se o nome tem mais de 2 caracteres
    if (tamanho <= 2) {
        printf("Tamanho inválido, nome deve ter mais de 2 caracteres.\n");
        return 0; // Nome inválido
    }
   // Verificar se já existe nome no arquivo
    FILE *arquivo = fopen("Pessoas.csv", "r");
    if (arquivo != NULL) {

        char linha[200];

        while (fgets(linha, sizeof(linha), arquivo)) {

            int id_lido;
            char nome_existente[31];

            // Lê ID (int) e Nome (string até o próximo ;)
            if (sscanf(linha, "%d;%30[^;]", &id_lido, nome_existente) == 2) {

                // Comparação exata
                if (strcmp(nome, nome_existente) == 0) {
                    fclose(arquivo);
                    printf("Esse nome já existe na lista.\n");
                    return 0;   // Nome já existe
                }
            }
        }

        fclose(arquivo);
    }
    return 1; // Nome válido
}

int validar_DataNasc(const char* dataNasc) {
    // Verifica o formato DD/MM/AAAA
    if (strlen(dataNasc) != 10 ||
        dataNasc[2] != '/' || dataNasc[5] != '/') {
        printf("Formato inválido, use DD/MM/AAAA.\n");
        return 0; // Data inválida
    }

    //verifica valores de dia, mês e ano
    int dia, mes, ano;
    if (sscanf(dataNasc, "%2d/%2d/%4d", &dia, &mes, &ano) != 3) {
        printf("Data inválida. digite apenas números no formato DD/MM/AAAA.\n");
        return 0; // Data inválida
    }

    // Verifica valores válidos para dia, mês e ano
    if (ano > 2025 || mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        printf("Data inválida. Valores de dia, mês ou ano fora do intervalo comum.\n");
        return 0; // Data inválida
    }

    // Verifica dias e meses específicos
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        printf("Data inválida. O valor do dia é inválido para o mês informado.\n");
        return 0; // Data inválida
    }
    if (mes == 2) {
        int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
        if (dia > (bissexto ? 29 : 28)) {
            printf("Data inválida. O valor do dia é inválido para o mês informado.\n");
            return 0; // Data inválida
        }
    }

    //verifica se a data é a data atual ou futura(21/11/2025)
    if (ano > 2025  || (ano == 2025 && mes > 11) || (ano == 2025 && mes == 11 && dia >= 21)) {
        printf("Data inválida, data de nascimento não pode ser a data atual ou futura.\n");
        return 0; // Data inválida
    }


    return 1; // Data válida
}

int validar_CPF(const char* cpf) {
    int i, j, soma, resto;
    int digitos[11];
    bool digito1 = true;
    bool digito2 = true;
    // Verifica se tem 11 caracteres
    if (strlen(cpf) != 11) {
        printf("CPF inválido, deve conter exatamente 11 números.\n");
        return 0; // Numero invalido
    }

    // Verifica se todos são números e converte para inteiros
    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            printf("CPF inválido, deve conter apenas números.\n");
            return 0; // Numero invalido
        }
        digitos[i] = cpf[i] - 48; // Converte char para int
    }

    // Verifica se todos os números são iguais (ex.: 11111111111)
    bool todosIguais = true;
    for (i = 1; i < 11; i++) {
        if (digitos[i] != digitos[0]) {
            todosIguais = false;
            break;
        }
    }
    if (todosIguais) {
        printf("CPF inválido, todos os números são iguais.\n");
        return 0; // Nao eh valido
    }

    // Calcula o primeiro dígito verificador
    soma = 0;
    for (i = 0, j = 10; i < 9; i++, j--) {
        soma += digitos[i] * j;
    }
    resto = soma % 11;
    if (resto>=0 && resto<=1) resto = 0;
    if(resto >=2 && resto<=10) resto = 11 - resto;
    if (resto != digitos[9]) {
        digito1 = false;
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    for (i = 0, j = 11; i < 10; i++, j--) {
        soma += digitos[i] * j;
    }
    resto = soma % 11;
    if (resto>=0 && resto<=1) resto = 0;
    if(resto >=2 && resto<=10) resto = 11 - resto;
    if (resto != digitos[10]) {
        digito2 = false;
    }

    if(digito1 && digito2){
        return 1;
    } else {
        printf("CPF inválido, dígitos verificadores não conferem.\n");
        return 0; // CPF invalido       
    }
}

int validar_Email(const char* email) {
    // Verifica se o email contém um '@' e um '.'
    const char* at = strchr(email, '@');
    const char* dot = strrchr(email, '.');

    if (at == NULL || dot == NULL || at > dot) {
        printf("Email inválido, deve conter '@' e '.' na ordem correta.\n");
        return 0; // Email inválido
    }

    // Verifica se há caracteres antes do '@' e entre '@' e '.'
    if (at == email || dot - at <= 1) {
        printf("Email inválido, formato incorreto.\n");
        return 0; // Email inválido
    }

    return 1; // Email válido
}   

int validar_Telefone(const char* telefone) {

    int tam=strlen(telefone);
    // Verifica se o telefone tem exatamente 11 ou 10 dígitos
    if (tam != 11 && tam != 10) {
        printf("Telefone inválido, deve conter exatamente 10 ou 11 números.\n");
        return 0; // Telefone inválido
    }

    // Verifica se todos os caracteres são dígitos
    for (int i = 0; i < tam; i++) {
        if (!isdigit(telefone[i])) {
            printf("Telefone inválido, deve conter apenas números.\n");
            return 0; // Telefone inválido
        }
    }

    return 1; // Telefone válido
}

int Procurar_Nome(const char* nome){

    FILE *arquivo = fopen("Pessoas.csv", "r");
    if (arquivo != NULL) {

        char linha[200];
        while (fgets(linha, sizeof(linha), arquivo)) {
            int id_lido;
            char nome_existente[31];

            // Lê ID (int) e Nome (string até o próximo ;)
            if (sscanf(linha, "%d;%30[^;]", &id_lido, nome_existente) == 2) {

                // Comparação exata
                if (strcmp(nome, nome_existente) == 0) {
                    return id_lido;   
                }
                     
            }
           id_lido++;    
        }
        return 0;
        fclose(arquivo);
    }
}

char* Procurar_ID(int id) {
    FILE *arquivo = fopen("Pessoas.csv", "r");
    char *nome_alocado = NULL; 

    if (arquivo != NULL) {
        char linha[200];
        
        while (fgets(linha, sizeof(linha), arquivo)) {
            int id_lido;
            char nome_existente[31]; 

            
            if (sscanf(linha, "%d;%30[^;]", &id_lido, nome_existente) >= 2) { 
                
                if (id == id_lido) {
                
                    nome_alocado = (char *)malloc(31 * sizeof(char));
                    strcpy(nome_alocado, nome_existente);
                    fclose(arquivo);
                    return nome_alocado; 
                }
            }
           id_lido++; 
        }
        fclose(arquivo); 
    }
    
    return NULL;
}