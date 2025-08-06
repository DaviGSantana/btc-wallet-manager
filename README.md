#  BTC Wallet Manager (ainda em desenvolvimento)

Gerenciador simples de carteira Bitcoin em C usando comunicação RPC com um `bitcoind` local.

## 📦 Funcionalidades

- Ver saldo
- Gerar novo endereço
- Listar transações
- Enviar BTC

## 🛠 Requisitos

- bitcoind em execução com RPC ativado
- libcurl (`sudo apt install libcurl4-openssl-dev`)

## 🚀 Execução

```bash
make
./btc-wallet
