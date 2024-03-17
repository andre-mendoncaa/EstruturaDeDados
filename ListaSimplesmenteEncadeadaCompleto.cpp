#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>

 using namespace std;
 
 void inserirLista(int n);
 void exibirLista();
 void quantidadeLista();
 void removerLista(int valor);
 
 	struct No{
 		int info; // O inteiro é o número da lista.
 		struct No *prox; // É struct pois aponta, guarda o endereço da estrutura No.
	};
	 
	 struct No *cabeca; //Inicializmos a variável com Null
	 struct No *ult;
 	
 	main(){
 		
 		int opcao, valor;
 		
 		do{
			printf("Selecione uma opção: \n" // exibe o menu de opções dentro de um loop que só para quando a opcao escolhida for maior que 4.
		 	  "1 - Inserir \n" 
			  "2 - Exibir \n"
			  "3 - Quantidade de elementos na Lista \n"
			  "4 - Remover item \n"
			  "5 - Sair \n");
			  cin>>opcao;
			  system("cls");
			  
			switch(opcao){
		 	case 1: 
		 		cout<<"Digite um valor a ser inserido: \n";
		 		cin>>valor;
		 		inserirLista(valor);
		 		system("cls");
		 		break;
		 	
		 	case 2:
		 		cout<<"Exibindo a Lista \n";
		 		exibirLista();
		 		break;
		 	
		 	case 3:
		 		quantidadeLista();
		 		break;
		 		
		 	case 4:
		 		cout<<"Digite o valor a ser removido:";
		 		cin>>valor;
		 		removerLista(valor);
		 		break;

		 	case 5:
		 		cout<<"Saindo!";
		 		break;
		 	}
		 }while (opcao < 5);
		 
	}
	
	void inserirLista(int n){
		struct No *novo; //O novo vai apontar para um endereço que é alguma coisa da estrutura No.
		novo = (struct No*)malloc(sizeof(struct No)); //sizeof dá um tamanho de uma estrutura No, para o malloc armazenar com o tamanho achado criando espaços.
		//Função que vai na memória e aloca um n de bytes, get um end.
		//O endereço que o malloc devolve não é mais por byte, é pela estrutura No o número devolvido de bytes na sequência.
		//Novo está apontando para:
		novo -> info = n;
		//Para onde o NOVO está apontando agora é o NULL.
		novo -> prox = NULL;
		if(cabeca == NULL)
		{
		cabeca = novo; //Cabeça recebeu o endereço de NOVO.
	    }
		else
		{
		   //para onde o ult aponta recebe:
		   ult -> prox = novo;
		}
		ult = novo;	//o endereço que ult guarda passa a ser novo (depois do else);			
    } 	
 	
 	void exibirLista()
 	{
 		struct No *aux; // Salva a cabeça em uma varíavel para não ter risco de perder o endereço.
 		aux = cabeca;
 		
 		
 		while(aux!=NULL){ //enquanto a struct No for diferente de vazio
 			printf("%X %i -> %X \n", aux, aux -> info, aux->prox); // printa o endereço da struct No, seu valor info e o endereço que prox aponta.
 			aux = aux -> prox; // auxiliar passa a ser seu valor prox.
 		}
	 }
	 
	void quantidadeLista()
	{
		struct No *aux; 
		aux = cabeca; // Salva a cabeça em uma varíavel para não ter risco de perder o endereço.
		int quantidade = 0; // Cria uma varíavel para contar os elementos.
		
		while(aux!=NULL){ //enquanto a struct No for diferente de vazio
			aux = aux -> prox; // auxiliar passa a ser seu valor prox.
 			quantidade = quantidade + 1; // a quantidade de elementos passa a ser sua quantidade + 1.
		 }
		 printf("Numero de elementos: %d \n", quantidade); // Printa o numero de elementos.
	 }
		
	void removerLista(int valor)
	{
	    struct No *ant = NULL;
	    struct No *aux = cabeca;
		
		if (cabeca != NULL)
		{
		    while (aux != NULL && aux->info != valor) {
		        ant = aux;
		        aux = aux->prox;
		    }
		    if (aux != NULL) {
		        if (aux == cabeca) {
		            // Removendo o primeiro elemento
		            cabeca = aux->prox;
		        } else {
		            // Removendo elemento no meio ou final
		            ant->prox = aux->prox;
		        }
		        free(aux); // Liberando o endereço de memória
		        cout << "Elemento " << valor << " apagado! \n";
		    } else {
		        cout << "Elemento " << valor << " não encontrado! \n";
		    }
		}
		else {
			cout<<"Lista Vazia! \n";
		}
	}

 		
