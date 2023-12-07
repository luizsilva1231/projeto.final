#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Veiculo {
    char combustivel[20];
    char placa[8];
    char proprietario[50];
    char modelo[50];
    char cor[20];

    struct Veiculo* proximo;
};

struct Veiculo* criarVeiculo(char combustivel[], char placa[], char proprietario[], char modelo[], char cor[]) {
    struct Veiculo* novoVeiculo = (struct Veiculo*)malloc(sizeof(struct Veiculo));
    strcpy(novoVeiculo->combustivel, combustivel);
    strcpy(novoVeiculo->placa, placa);
    strcpy(novoVeiculo->proprietario, proprietario);
    strcpy(novoVeiculo->modelo, modelo);
    strcpy(novoVeiculo->cor, cor);
    novoVeiculo->proximo = NULL;
    return novoVeiculo;
}

void adicionarVeiculo(struct Veiculo** lista, char combustivel[], char placa[], char proprietario[], char modelo[], char cor[]) {
    struct Veiculo* novoVeiculo = criarVeiculo(combustivel, placa, proprietario, modelo, cor);
    novoVeiculo->proximo = *lista;
    *lista = novoVeiculo;
}

void listarDiesel2010(struct Veiculo* lista) {
    printf("Veículos do ano de 2010 ou posterior e movidos a diesel:\n");
    while (lista != NULL) {
        if (atoi(lista->placa + 4) >= 2010 && strcmp(lista->combustivel, "diesel") == 0) {
            printf("Proprietário: %s\n", lista->proprietario);
        }
        lista = lista->proximo;
    }
}

void listarPlacasJ(struct Veiculo* lista) {
    printf("Placas que começam com J e terminam com 0, 2, 4 ou 7 e seus respectivos proprietários:\n");
    while (lista != NULL) {
        if (lista->placa[0] == 'J' && (lista->placa[7] == '0' || lista->placa[7] == '2' || lista->placa[7] == '4' || lista->placa[7] == '7')) {
            printf("Placa: %s, Proprietário: %s\n", lista->placa, lista->proprietario);
        }
        lista = lista->proximo;
    }
}

void listarModeloCorVogalPar(struct Veiculo* lista) {
    printf("Modelo e cor dos veículos com placas que têm segunda letra vogal e soma dos valores numéricos é par:\n");
    while (lista != NULL) {
        if (strchr("aeiouAEIOU", lista->placa[1]) && ((lista->placa[4] - '0') + (lista->placa[5] - '0') + (lista->placa[6] - '0') + (lista->placa[7] - '0')) % 2 == 0) {
            printf("Modelo: %s, Cor: %s\n", lista->modelo, lista->cor);
        }
        lista = lista->proximo;
    }
}

void trocarProprietario(struct Veiculo* lista, char placa[], char novoProprietario[]) {
    while (lista != NULL) {
        if (strcmp(lista->placa, placa) == 0 && strcspn(lista->placa, "0") == 7) {
            strcpy(lista->proprietario, novoProprietario);
            printf("Proprietário alterado com sucesso!\n");
            return;
        }
        lista = lista->proximo;
    }
    printf("Placa não encontrada ou contém dígito zero.\n");
 getchar()
}

int main() {
    struct Veiculo* lista = NULL;

    adicionarVeiculo(&lista, "diesel", "ABC1234", "Proprietario1", "Modelo1", "Cor1");
    adicionarVeiculo(&lista, "gasolina", "JJK5678", "Proprietario2", "Modelo2", "Cor2");
    adicionarVeiculo(&lista, "diesel", "JKL4321", "Proprietario3", "Modelo3", "Cor3");
    adicionarVeiculo(&lista, "alcool", "JKM9876", "Proprietario4", "Modelo4", "Cor4");

    listarDiesel2010(lista);
    listarPlacasJ(lista);
    listarModeloCorVogalPar(lista);
    trocarProprietario(lista, "ABC1234", "NovoProprietario");

    while (lista != NULL) {
        struct Veiculo* temp = lista;
        lista = lista->proximo;
        free(temp);
    }

    return 0;
}
