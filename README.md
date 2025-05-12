# VanGuard - Controle de Acesso com Cartões NFC

VanGuard é um sistema de controle de acesso desenvolvido como Trabalho de Conclusão de Curso (TCC), utilizando tecnologia NFC (Near Field Communication) com Arduino. O projeto tem como objetivo fornecer um meio eficiente, seguro e de baixo custo para autenticação e controle de entrada e saída de pessoas, ideal para escolas, empresas ou residências.

## 🎯 Objetivos do Projeto
- Desenvolver um sistema de controle de acesso físico com validação por UID (Identificador Único) de cartões NFC.
- Garantir segurança e confiabilidade nos registros de acesso.
- Criar uma solução simples, prática e com interface direta via LED para feedback imediato ao usuário.

## ⚙️ Tecnologias Utilizadas
- Arduino Uno R3
- Leitor NFC PN532
- Cartões RFID/NFC
- LEDs e resistores
- Jumpers e protoboard
- Linguagem C (Arduino IDE)

## 🔌 Funcionamento
O sistema aguarda a aproximação de um cartão NFC.

Ao detectar o cartão, lê o UID.

Verifica se o UID está autorizado:

- **Se autorizado:** acende o LED verde.
- **Se não autorizado:** acende o LED vermelho.

Permanece em loop contínuo para novas leituras.

## 🛠️ Instalação
Clone este repositório:

```bash
git clone https://github.com/seu-usuario/VanGuard.git
