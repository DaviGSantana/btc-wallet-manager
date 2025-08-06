#include <stdio.h>
#include <stdlib.h>
#include "wallet.h"

int main() {
    printf("=== BTC Wallet Manager ===\n");

    int opcao;
    do {
        printf("\n1. Ver saldo\n2. Novo endereço\n3. Listar transações\n4. Enviar BTC\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                get_balance();
                break;
            case 2:
                generate_address();
                break;
            case 3:
                list_transactions();
                break;
            case 4:
                send_btc();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
