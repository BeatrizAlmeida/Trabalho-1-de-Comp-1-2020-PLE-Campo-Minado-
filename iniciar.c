#include "molde.h"


void inicializa (){
	/* essa função, aloca espaço para a matriz e para o vetor de minas aleatórias, zera os atributos de cada campo da matriz, 
	aloca as minas na matriz de forma aleatória, e por fim calcula o numero de minas por perto*/
	QUADRADO *p;
	int	contbomba, i, ran, z, j;
	/*ran receberá o número randômico e bo são as bombas da partida. */
	int *bo;
	
	bo = (int *) malloc(bomba * sizeof(int));
	p = ( QUADRADO *) malloc (tam1 * tam2 * sizeof( QUADRADO ));

	
	for(i = 0; i < (tam1 * tam2); i++){/*repetição para zerar os quadrados*/
		(p + i)->mina = 0;
		(p + i)->adj = 0;
		(p + i)->aparece = 0;
		(p + i)->passei = 0;
		(p + i)->bomba = 0;
	}
	/*repeticao para zerar o vetor que sera utilizado para guardar os numeros 
	fornecidos pelo rand, para nao serem escolhidos numeros repetidos*/
	for(i = 0; i < bomba; i++){
		*(bo+i) =-1;
	}
	z = 0;
	/*a função rand precisa ser inicializada antes para evitar q os valores 
	sempre sejam os mesmos*/
	srand(time(NULL));
	for(i = 0; i < bomba; i++){/*repeticao que aloca as bombas de maneira aleatória. Do while impede de existirem duas bombas no mesmo lugar*/
		do{
			contbomba = 0;
			ran = rand() % (tam1 * tam2);
		
			for(j = 0;j < bomba; j++){
				if(ran == *(bo + j)){
					contbomba++;
				}
			}	
		}while(contbomba != 0);
		
		*(bo + z) = ran;
		z++;
		
		(p+ran)->mina=ATIVA;
	}
	
	/*Adiciona os números referentes as minas adjacentes*/		
																
	for(i = 0; i < tam1 ; i++){                                 
	
		for(j = 0; j < tam2 ; j++){
				
			if((tam2 * i + j + p)->mina != ATIVA){
				
				if(j!=tam2-1){
					if((i * tam2 + j + 1 +p)->mina == ATIVA)
						(i * tam2 + j + p)->adj++;
					
				}	
				if(j!=0){
					if((i * tam2 + j - 1 + p)->mina == ATIVA)
						(i * tam2 + j + p)->adj++;
					
				}
				if(i!=tam1-1){
					if(((i + 1) * tam2 + j + p)->mina == ATIVA)
						(i * tam2 + j + p)->adj++;
					
				}
				if(i!=0){	
					if(((i - 1) * tam2 + j + p)->mina == ATIVA)
						(i * tam2 + j + p)->adj++;
					
				}
				if((j!=tam2-1)&&(i!=tam1-1)){
					if(((i + 1) * tam2 + j + 1 + p)->mina == ATIVA)
						(i * tam2 + j + p)->adj++;
					
				}	
				if((j!=0)&&(i!=tam1-1)){
					if(((i + 1) * tam2 + j - 1 + p)->mina == ATIVA)
						(i * tam2 + j + p)->adj++;
					
				}
				if((j!=tam2-1)&&(i!=0)){
					if(((i - 1) * tam2 + j + 1 + p)->mina == ATIVA)
						(i * tam2 + j + p)->adj++;
					
				}
				if((j!=0)&&(i!=0)){
					if(((i - 1) * tam2 + j - 1 + p)->mina == ATIVA)
						(i * tam2 + j + p)->adj++;
					
				}
			}
			
		}
	
	}
	
	printar_campo(p, 0,0);	

	free(bo);
	free(p);
}


/*Função responsável por fazer a parte Final de uma rodada de 
Campo Minado*/
void fimDeJogo(int result){
	int op;
	if (result == 0){
		printf ("\nVoc%c foi derrotado!\n", 136);
		printf ("Selecione 1 para continuar ou 2 para Sair\n");
		scanf ("%d", &op);
		while (op < 0 && op <= 2){
			printf ("\nERRO! Op%c%co Invalida, Tente Novamente:\n", 135, 198);
			printf ("Selecione 1 para continuar ou 2 para Sair\n");
			scanf ("%d", &op);
		}
		if(op == 1){
			printf ("\n");
			menu();
		}
		else{
			printf ("Fim de Jogo");
			exit (0);
		}
	}
	else{
		printf ("Voc%c Venceu!\n", 136);
		printf ("Selecione 1 para continuar ou 2 para Sair\n");
		scanf ("%d", &op);
		while (op < 0 && op <= 2){
			printf ("\nERRO! Op%c%co Invalida, Tente Novamente:\n", 135, 198);
			printf ("Selecione 1 para continuar ou 2 para Sair\n");
			scanf ("%d", &op);
		}
		if(op == 1){
			printf ("\n");
			menu();
		}
		else{
			printf ("Fim de Jogo");
			exit (0);
		}
	}
}

/*Função que apresenta um pequeno menu para receber
a dificuldade desejada pelo usuário*/
void menu(){
	int dificuldade;
	printf("Seja bem-vindo ao jogo Campo Minado!\n");
	printf("Escolha o n%cmero da dificuldade desejada\n1 - F%ccil\n2 - M%cdio\n3 - Dificil\n0 - Sair:\n", 163, 160, 130);
	scanf("%d", &dificuldade);
	while (dificuldade < 0 || dificuldade > 3){
		printf ("\nERRO! Op%c%co Inv%clida, Tente Novamente:", 135, 198, 160);
		printf("\nEscolha o n%cmero da dificuldade desejada\n1 - F%ccil\n2 - M%cdio\n3 - Dificil\n0 - Sair:\n", 163, 160, 130);
		scanf("%d", &dificuldade);
	}
	if(dificuldade == 0){
		exit(0);
	}
	if(dificuldade == 1){
		tam1 = 8;
		tam2 = 10;
		bomba = 10;
	}
	if(dificuldade == 2){
		tam1 = 14;
		tam2 = 18;
		bomba = 40;
	}
	if(dificuldade == 3){
		tam1 = 20;
		tam2 = 24;
		bomba = 99;
	}
	band=bomba;
	inicializa ();
}
