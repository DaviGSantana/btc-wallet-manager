#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpc.h"

void get_balance() {
    const char* resp = rpc_call("getbalance", NULL);
    printf("Saldo: %s BTC\n", resp);
    free((void*)resp);
}

void generate_address() {
    const char* resp = rpc_call("getnewaddress", NULL);
    printf("Novo endereço: %s\n", resp);
    free((void*)resp);
}

void list_transactions() {
    const char* resp = rpc_call("listtransactions", "[]");
    printf("Transações: %s\n", resp);
    free((void*)resp);
}

void send_btc() {
    char address[256];
    double amount;
    printf("Endereço de destino: ");
    scanf("%255s", address);
    printf("Quantia a enviar: ");
    scanf("%lf", &amount);

    char params[512];
    snprintf(params, sizeof(params), "[\"%s\", %.8f]", address, amount);
    const char* resp = rpc_call("sendtoaddress", params);
    printf("TXID: %s\n", resp);
    free((void*)resp);
}
