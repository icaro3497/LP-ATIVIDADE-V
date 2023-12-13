#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct dadosProduto {
    char nome[200];
    float preco;
    int qntEstoque;
};

float calcularTotalEstoque (struct dadosProduto produto) {
    return produto.preco * produto.qntEstoque;
}

struct dadosProduto atualizarEstoque (struct dadosProduto produto) {
    int quantidade;

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidade); 

  if (quantidade > 0 && quantidade <= produto.qntEstoque) {
    produto.qntEstoque -= quantidade;
    printf("Compra realizada com sucesso. Total: R$ %.2f\n", quantidade * produto.preco);
    } else {
    printf("Quantidade insuficiente em estoque.\n");
}
   return produto;
}



void consultaEstoque(struct dadosProduto produto) {
    printf("Nome do produto :%s \n", produto.nome);
    printf("Preço :%.2f \n", produto.preco);
    printf("Quantidade em estoque: %d \n", produto.qntEstoque);
    printf("Valor total em estoque: R$ %.2f \n", calcularTotalEstoque(produto));
}


int main () {

    struct dadosProduto Produto;
    int opcao;
    char nomeProduto[200];
    int codigo;
    int quantidade = 0;
    char loginSalvo [200] = "Marta";
    char senhaSalva [200] = "senha123";
    char login [200];
    char senha [200];

    do {
    printf("\n------ MENU ------ \n");
    printf("1 - logar Systema  \n");
    printf("2 - Adicionar Produto \n");
    printf("3 - Realizar uma compra \n");
    printf("4 - Consultar estoque \n");
    printf("5 - Sair do programa. \n");
    printf("Digite a opção escolhida: \n");
    scanf("%d", &opcao);
    
    system("cls || clear");
    
    switch (opcao) {
    case 1 :    
    fflush(stdin);
    printf("Digite seu login: \n");
    gets(login);
    fflush(stdin);
    printf("Digite sua senha: \n");
    gets(senha);
  
    if (strcmp(loginSalvo,login) == 0 && strcmp(senhaSalva,senha) == 0) {
    printf("Bem vindo!");
    } else {
    printf("Login ou senha inválidas.");
    }

    break;
    case 2 :
    fflush(stdin);
        printf("Nome do Produto: \n");
        scanf("%s", &nomeProduto);
        fflush(stdin);
        printf("Qual o codigo do Produto: \n");
        scanf("%d", &codigo);
        fflush(stdin);
        printf("Digite o preço do produto: \n");
        scanf("%f", &Produto.preco);  
        printf("Digite a quantidade em estoque: \n");
        scanf("%d", &Produto.qntEstoque);
        break;
        
        case 3 :
        Produto = atualizarEstoque(Produto);
        break;

        case 4 :
        consultaEstoque(Produto);
        break;

    default:
    printf("Opção inválida. \n");
        break;
    }
    
    } while (opcao != 5);

    return 0;
}