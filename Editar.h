#ifndef EDITAR_H
#define EDITAR_H

void Editar_pessoa();
void Editar_telefone();
void atualizar_telefone_Nome(char novo_nome[31], int id_encontrado);
void atualizar_Pessoas_Nome(char novo_nome[31], int id_encontrado);
void atualizar_Pessoas_DataNascimento(char nova_data_nascimento[11], int id_encontrado);
void atualizar_Pessoas_CPF(char novo_cpf[12], int id_encontrado);
void atualizar_Pessoas_Email(char novo_email[31], int id_encontrado);


#endif