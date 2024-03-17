#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 using namespace std;

void empilhar(int nr);
void exibirPilha();
void desempilhar();
void exibirTopo();
void qtdPilha();


struct No {
	int info;
	struct No *prox;
};

	struct No *topo = NULL;
	
	main() 
	{
		
		int opcao, valor;
 		
 		do{
			printf("P I L H A   D I N A M I CA\n"
			  "Selecione uma opção: \n" // exibe o menu de opções dentro de um loop que só para quando a opcao escolhida for maior que 4.
		 	  "1 - Empilhar \n" 
			  "2 - Desempilhar \n"
			  "3 - Exibir Pilha \n"
			  "4 - Exibir Topo da Pilha  \n"
			  "5 - Exibir tamanho da pilha \n" 
			  "6   SAIR \n");
			  cin>>opcao;
			  system("cls");
			  
			switch(opcao){
		 	case 1: 
		 		cout<<"Digite um valor a ser inserido: \n";
		 		cin>>valor;
		 		empilhar(valor);
		 		system("cls");
		 		break;
		 	
		 	case 2:
		 		cout<<"Desempilhando\n";
		 		desempilhar();
		 		break;
		 	
		 	case 3:
		 		exibirPilha();
		 		break;
		 		
		 	case 4:
		 		exibirTopo();
		 		break;

			case 5:
		 		qtdPilha();
		 		break;
		 		
		 	case 6:
		 		cout<<"Saindo!";
		 		break;
		 	}
		 }while (opcao < 6);
		 
	/*empilhar(10);
	empilhar(20);
	empilhar(30);
	exibirPilha();
	exibirTopo();
	qtdPilha();
	desempilhar();
	exibirTopo();
	qtdPilha();*/
}

void empilhar(int nr)
{
	struct No *novo;
	
	novo = (struct No*)malloc(sizeof(struct No));
	novo -> info = nr;
	novo -> prox = topo;
	topo = novo;
}

void exibirPilha()
{
	struct No *aux = topo;
	
	if(topo != NULL)
	{
	while(aux != NULL)
	{
		printf("%X %d -> %X \n", aux, aux -> info, aux -> prox);
		aux = aux -> prox;
	}
}
else{
	printf("Pilha vazia!\n");
}
}

void desempilhar()
{
	struct No *aux = topo;
	
	if(topo != NULL)
	{
		cout<<"Desempilhando o valor "<<topo->info<<"que estava no topo da pilha. \n";
		topo = topo -> prox;
		free(aux);
		}
		
		else
		{
			printf("Pilha vazia!\n");
		}
	}
	
void exibirTopo()
{
	printf("%X %d -> %X \n", topo, topo->info, topo->prox);
	printf("\nTopo \n");
	
}

	void qtdPilha()
	{
		struct No *aux; 
		aux = topo; // Salva a cabeça em uma varíavel para não ter risco de perder o endereço.
		int quantidade = 0; // Cria uma varíavel para contar os elementos.
		
		while(aux!=NULL){ //enquanto a struct No for diferente de vazio
			aux = aux -> prox; // auxiliar passa a ser seu valor prox.
 			quantidade = quantidade + 1; // a quantidade de elementos passa a ser sua quantidade + 1.
		 }
		 printf("Numero de elementos: %d \n", quantidade); // Printa o numero de elementos.
	 }
	 
