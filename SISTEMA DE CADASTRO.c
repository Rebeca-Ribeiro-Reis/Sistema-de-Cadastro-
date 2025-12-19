// SISTEMA DE CADASTRO DE PRODUTOS



// bibliotecas que vao ser utilizadas :  
#include <stdio.h>  // para ler a entrada e saída , printf e scanf
#include <stdlib.h> // para pode usar o system para limpar a tela
#include <string.h>  // biblioteca para utilizar a função strcmp que compara as categorias do mercado 


# define SENHA_CORRETA 772211  // constante que define a senha correta usada na condição da senha
# define MAXIMO_PRODUTOS 5 // constante que define o maximo de produtos que o usuario pode cadastrar no sistema
# define MAXIMO_NOME 30 // constante que define o tamanho do nome que o usuario pode escrever 
# define MAXIMO_CATEGORIA 15 // constante que define o tamanho maximo que o usuario pode escrever na categoria

//  arrays globais para armazenar os dados dos produtos:

char nomes[MAXIMO_PRODUTOS][30]; // array bi que guarda os nomes(30) de ate 5 produtos
char categorias[MAXIMO_PRODUTOS][15]; // array bi que guarda as categorias(15) de ate 5 produtos
float precos[MAXIMO_PRODUTOS]; //array uni que guarda os preços de ate 5 produtos  
int quantidades[MAXIMO_PRODUTOS]; // array uni que guarda a quantidade de ate 5 produtos

//variavel global:					
int total_produtos = 0; // variavel contador, conta quantos produtos ja foram cadastrados

// funções utilizadas: 

void mostrarMenu(); // função que mostra o menu na tela para o usuario
void pausarApp(); // função que faz o programa aguardar o usuario teclar enter para continuar (tempo para ler a tela)
int verificarSenha(); // função que verifica se a senha esta correta ou não, se estiver retorna 1 se nao estiver retorna 0 parando o programa.
void cadastrarProduto();// função que permite ao usuario cadastrar o seu produto fazendo a validação das categorias e do limite e coletando os dados.
void despedida(); // função que agradece a saida do usuario quando ele aperta em sair e lista os produtos cadastrados


int main(int argc, char *argv[]) {
	
	int opcao = 0; // Variavel int para a escolha do menu, iniciada em 0.
	
      mostrarMenu(); // mostra o menu para o usuario

    //  solicitar e verificar Senha
    if (!verificarSenha()) {
        printf("\nSenha Inválida. Encerrando o sistema.\n");
        return 0; // Encerra o App se a senha for inválida (retorna 0)
    }
    
    // laço de repetição principal:
    do {
       system("cls"); // Limpa a tela do console
        
        cadastrarProduto(); // Realiza o cadastro
        
        //  Opção de Sair ou Fazer Dnv
        printf("\n\n* Digite 1 para CONTINUAR cadastrando, ou 0 para SAIR: ");
        scanf("%d", &opcao);
        
        while (getchar() != '\n'); //limpa o buffer do teclado
        
    } while (opcao != 0);
    
    despedida();
    
    return 0;
}


            // função que mostra o menu na tela para o usuario:
  void mostrarMenu(){
   	system("cls"); //limpa a tela 
	printf("\n========================================================\n");
    printf("|         MERCADO SILVA - SISTEMA DE CADASTRO          |\n");
	printf("========================================================\n");
   }

// essa função que verifica se esta certa a senha e guarda oque o usuario digitou:
 

int verificarSenha() {
	
    int senha_digitada; // variavel da senha que o usuario digitou
    printf("\n-> Digite a senha para prosseguir: ");
    scanf("%d", &senha_digitada);  // sistama le a senha do usuario 
    
    while(getchar() != '\n');     //limpa o buffer do teclado,remove sobras de digitação que atrapalham o próximo scanf
    
    // condição para ver se a senha_digitada é igual a SENHA_CORRETA se for retorna 1 se não retorna 0
    if (senha_digitada == SENHA_CORRETA) { 
        printf("Senha Correta! Acesso Liberado.\n");
        return 1;
    } else {
        return 0;
    }
}


    //função que faz o programa aguardar o usuario teclar enter para continuar (tempo para ler a tela):
	
	void pausarApp() {
 printf("\nPressione ENTER para continuar...");
    getchar();
}

//função que agradece a saida do usuario quando ele aperta em sair e lista os produtos cadastrados : 

void despedida() {
system("cls"); //Limpa a tela 

    printf("\n--- LISTAGEM FINAL DE PRODUTOS CADASTRADOS (%d) ---\n", total_produtos); // imprime o texto mais quantos produtos foram cadastrados.
    
    //condição que verifica se há produtos para listar:

    if (total_produtos == 0) { 
        printf("Nenhum produto foi cadastrado nesta sessao.\n");
    } else {
    
    
        //estrutura de repeticao para Listagem, Usa um laço for para exibir cada produto.:
        int i; //é o contador do loop
        
        for (i = 0; i < total_produtos; i++) {
            
            // exibe o número do item e a Categoria
            printf("[%d] Categoria: %s\n", i + 1, categorias[i]);  // o i + 1 só muda o número que aparece na tela de 0 para 1, e nao altera o indice para acessar os dados
            
            //exibe o nome
            printf("Nome: %s\n", nomes[i]);


            //exibe Preco e Quantidade 
            printf("Preco: R$ %.2f\n", precos[i]); 
            printf("Quantidade em Estoque: %d\n", quantidades[i]);

        }
    }
    
    //imprime a mensagem de finalização:
    printf("\n+-------------------------------------------+\n");
    printf("|          Mercado Silva volte sempre!      |\n");
    printf("+-------------------------------------------+\n");
    
    pausarApp(); // usada para tirar a linha do Code Blocks terminal do Windows que ficava um ------ aleatorio

} 

// função de cadastrar :  Se o cadastro for confirmado incrementa a variável global total_produtos,
// garantindo que o produto seja salvo e a contagem seja atualizada para o próximo item.



void cadastrarProduto() {
    int confirmacao_ok;
    int indice_atual = total_produtos; // serve para definir onde ou em  qual posição do array o novo produto vai ser salvo

    //  nessa condição verifica se passou do limite de 5 produtos 
    if (total_produtos >= MAXIMO_PRODUTOS) {
        printf("\nATENÇÃO: Estoque Cheio Maximo de %d produtos atingido.\n", MAXIMO_PRODUTOS);
        pausarApp();
        return;
    }
    
    // laço para garantir a categoria valida: 
    do {
        printf("\n[CADASTRO %d/%d]\n", total_produtos + 1, MAXIMO_PRODUTOS); // aqui exibe para o usuario o texto cadastro mais o total de produtos e a quantidade maxima 1/5....
        printf("Categorias validas: higiene, comida, eletronicos\n");
        printf("Digite a Categoria: ");
        
        // Mapeando para o array global categorias
        scanf("%14s", categorias[indice_atual]); // o 14s ali diz pra ler no máximo 14 carac nesse texto
        
        while(getchar() != '\n'); //limpa o buffer do teclado,remove sobras de digitação que atrapalham o próximo scanf
        
        // condicao que Valida a categoria (aceita apenas: higiene, comida, eletrônicos).
        
        
        if (strcmp(categorias[indice_atual], "higiene") == 0 ||  // puxa  a array categoria declada la em cima
            strcmp(categorias[indice_atual], "comida") == 0 ||   // == 0  igualdade perfeita
            strcmp(categorias[indice_atual], "eletronicos") == 0) {
            
            break; //  ele so sai quando o usuario digitar uma categoria valida
        } else {
            printf("\nERRO: Categoria inválida. Por favor, digite uma das opções válidas.\n");
        }
    } while (1); // faz continuar ate um break ser adicionado 
    
    /// Solicita categoria, nome, quantidade e preço:
    // nome 
    
    printf("Nome do Produto: ");
    scanf(" %29[^\n]", nomes[indice_atual]);
    
    while(getchar() != '\n');//limpa o buffer do teclado,remove sobras de digitação que atrapalham o próximo scanf

 // quantidade do produto mapeando para o array de quantidade
 
    printf("Quantidade: ");
    scanf("%d", &quantidades[indice_atual]);
    
    while(getchar() != '\n'); //limpa o buffer do teclado,remove sobras de digitação que atrapalham o próximo scanf

    // preco do produto mapeando para o array de preco
    printf("Preco (R$): ");
    scanf("%f", &precos[indice_atual]);
    
    while(getchar() != '\n'); //limpa o buffer do teclado,remove sobras de digitação que atrapalham o próximo scanf


    // lista e confirma os produtos 
    //Mostra um resumo e pede confirmação antes de salvar
    printf("\n+---------------------------------------------------+\n");
    printf("| PRODUTO CADASTRADO TEMPORARIAMENTE:               |\n");
    printf("+---------------------------------------------------+\n");
    printf("| Categoria: %38s |\n", categorias[indice_atual]);
    printf("| Nome: %43s |\n", nomes[indice_atual]);
    printf("| Preco: R$ %39.2f |\n", precos[indice_atual]);
    printf("| Quantidade em Estoque: %26d |\n", quantidades[indice_atual]);
    printf("+---------------------------------------------------+\n");



    
    printf("\n"); // linha para separar
    
    // confirmação se os dados estao certos:  
    // Se o usuário confirmar, adiciona ao contador total_produtos.
    
    printf("Dados estao corretos? (1-Sim / 0-Cancelar): ");
    scanf("%d", &confirmacao_ok);
    
    while(getchar() != '\n'); //limpa o buffer do teclado,remove sobras de digitação que atrapalham o próximo scanf

    if (confirmacao_ok == 1) {
        total_produtos++; // incrementa o produto fazendo o proximo começar em 1 e etc
        printf("\nCadastro finalizado e salvo com sucesso!\n");
    } else {
        printf("\nCadastro CANCELADO. O produto não foi salvo.\n");
    }
    
}
