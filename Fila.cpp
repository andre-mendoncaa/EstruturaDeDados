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
			printf("Selecione uma op��o: \n" // exibe o menu de op��es dentro de um loop que s� para quando a opcao escolhida for maior que 4.
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
		struct No *novo; //O novo vai apontar para um endere�o que � alguma coisa da estrutura No.
		novo = (struct No*)malloc(sizeof(struct No)); //sizeof d� um tamanho de uma estrutura No, para o malloc armazenar com o tamanho achado criando espa�os.
		//Fun��o que vai na mem�ria e aloca um n de bytes, get um end.
		//O endere�o que o malloc devolve n�o � mais por byte, � pela estrutura No o n�mero devolvido de bytes na sequ�ncia.
		//Novo est� apontando para:
		novo -> info = n;
		//Para onde o NOVO est� apontando agora � o NULL.
		novo -> prox = NULL;
		if(topo == NULL)
		{
		topo = novo; //topo recebeu o endere�o de NOVO.
	    }
		else
		{
		   //para onde o ult aponta recebe:
		   ult -> prox = novo;
		}
		ult = novo;	//o endere�o que ult guarda passa a ser novo (depois do else);			
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
 		struct No *aux; // Salva o topo em uma var�avel para n�o ter risco de perder o endere�o.
 		aux = topo;
 		
 		
 		while(aux!=NULL){ //enquanto a struct No for diferente de vazio
 			printf("%X %i -> %X \n", aux, aux -> info, aux->prox); // printa o endere�o da struct No, seu valor info e o endere�o que prox aponta.
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
