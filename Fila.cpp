#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 using namespace std;


void exibirFila();
void inserirFila(int valor);
void removerFila();
void primeiro_element();


struct No {
	int info;
	struct No *prox;
};

	struct No *topo = NULL;
	struct No *ult;
	
	main() 
	{
		
		int opcao, valor;
 		
 		do{
			printf("Selecione uma opção: \n" // exibe o menu de opções dentro de um loop que só para quando a opcao escolhida for maior que 4.
			  "1 - Inserir Fila \n"
			  "2 - Exibir Fila  \n"
			  "3 - Remover fila \n" 
			  "4 - Primeiro elemento Fila \n" 
			  "5 - Sair \n");
			  cin>>opcao;
			  system("cls");
			  
			switch(opcao){
		 	case 1:
		 		cout<<"Digite um valor a ser inserido: \n";
		 		cin>>valor;
		 		inserirFila(valor);
		 		break;
		 		
		 	case 2:
		 		exibirFila();
		 		break;

			case 3:
		 		removerFila();
		 		break;
		 		
		 	case 4:
		 	primeiro_element();
		 	break;
		 		
		 	case 5:
		 		cout<<"Saindo!";
		 		break;	
		 	}
		 }while (opcao < 5);
}
 
void inserirFila(int n){
		struct No *novo; //O novo vai apontar para um endereço que é alguma coisa da estrutura No.
		novo = (struct No*)malloc(sizeof(struct No)); //sizeof dá um tamanho de uma estrutura No, para o malloc armazenar com o tamanho achado criando espaços.
		//Função que vai na memória e aloca um n de bytes, get um end.
		//O endereço que o malloc devolve não é mais por byte, é pela estrutura No o número devolvido de bytes na sequência.
		//Novo está apontando para:
		novo -> info = n;
		//Para onde o NOVO está apontando agora é o NULL.
		novo -> prox = NULL;
		if(topo == NULL)
		{
		topo = novo; //topo recebeu o endereço de NOVO.
	    }
		else
		{
		   //para onde o ult aponta recebe:
		   ult -> prox = novo;
		}
		ult = novo;	//o endereço que ult guarda passa a ser novo (depois do else);			
    } 
    
void removerFila()
{
	struct No *aux = topo;
	
	if(topo != NULL)
	{
		cout<<"Removendo o elemento: "<<topo->info<<" da fila.\n";
		topo = topo -> prox; // Direciona o topo para o novo primeiro elemento
		free(aux); //remove o antigo primeiro elemento
		}
		
		else
		{
			printf("Fila vazia!\n");
		}
	}
	
void exibirFila()
 	{
 		struct No *aux; // Salva o topo em uma varíavel para não ter risco de perder o endereço.
 		aux = topo;
 		
 		
 		while(aux!=NULL){ //enquanto a struct No for diferente de vazio
 			printf("%X %i -> %X \n", aux, aux -> info, aux->prox); // printa o endereço da struct No, seu valor info e o endereço que prox aponta.
 			aux = aux -> prox; // auxiliar passa a ser seu valor prox.
 		}
	 }
	 
void primeiro_element()
{
	struct No *aux = topo;
	
	if(topo != NULL)
	{
	
		printf("%X %i -> %X \n", aux, aux -> info, aux->prox);
		}
		
		else
		{
			printf("Fila vazia!\n");
		}
	}
