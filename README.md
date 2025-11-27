# ☎️ Lista Telefonica

Este projeto foi desenvolvido em C como parte da disciplina de Algoritmos e consiste na implementação de uma lista telefônica funcional e persistente. O sistema permite o cadastro, consulta, edição e exclusão de pessoas e seus respectivos telefones, garantindo organização e integridade dos dados por meio de armazenamento permanente. O objetivo é exercitar conceitos fundamentais da linguagem C, como manipulação de arquivos, ponteiros, estruturas e modularização.

---
## 🚀 Tecnologias Utilizadas

<img src="https://img.icons8.com/?size=100&id=40670&format=png&color=000000" width="40" style="vertical-align:middle; margin-right:10px;" />

---

## 🗂️ Estrutura de Dados (MER)

A estrutura do projeto é baseada em duas tabelas principais — **Pessoas** e **Telefones** — com relacionamento de **um para muitos**, onde uma pessoa pode ter vários telefones, mas cada telefone pertence a apenas uma pessoa.

### 📊 Diagrama MER

![Diagrama MER](diagrama-mer.png)

## 📐 Especificações dos Campos

| **Campo**           | **Descrição**                              | **Tamanho Máximo**            |
|---------------------|---------------------------------------------|-------------------------------|
| **Nome**            | Nome completo da pessoa.                   | Texto de **30 caracteres**    |
| **Telefone**        | Número de telefone (incluindo DDD).        | Texto de **11 caracteres**    |
| **E-mail**          | Endereço de e-mail.                        | Texto de **30 caracteres**    |
| **CPF**             | Cadastro de Pessoa Física.                 | Texto de **11 caracteres**    |
| **Data de Nascimento** | Data de nascimento da pessoa.          | Texto de **10 caracteres**    |

