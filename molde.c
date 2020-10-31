#include "molde.h"



/*
o bloco tem que ter o aparece igual a 0, e o valor do adjacente dele 
tem que ser 0 essa função percorre as adjacencias do quadrado escolhido
de forma que va revelando  os zeros em conjunto, sendo executado com  o
mesmo metodo de chamamento de uma arvore binaria
*/

void abre_bloco(QUADRADO *p, int i, int j, QUADRADO *original){
	/*gabarito (original);*/
	if((p->adj != 0)||(p->mina == ATIVA)||(p->bomba==1)){
		if(p->mina != ATIVA){
			if(p->bomba!=1){
			p->aparece = 1;
			confere_vitoria(original);
				
			}
				p->passei = 1;
		}
		else{
			/*gabarito(original);*/
			mostra_campo_derrota(original);
			fimDeJogo(0);
		}
	}
	else{
		
		if((p->adj == 0) && p->passei == 0){
			p->aparece = 1;
			p->passei = 1;
			if((j != 0) && (i != 0)){
				if(((-1)*tam2 + p - 1)->passei == 0)
				abre_bloco(((-1)*tam2 + p - 1), i - 1, j - 1, original);	
			}
			if((i != 0)){	
				if(((-1)*tam2 + p)->passei == 0)
				abre_bloco(((-1)*tam2 + p), i - 1, j, original);
			}
			if((j != tam2 - 1) && (i != 0) ){
				if(((-1)*tam2 + p+1)->passei == 0)
				abre_bloco(((-1)*tam2 + p + 1), i - 1, j + 1, original);
			}
			if((j != tam2 - 1)){
				if((p + 1)->passei == 0)
				abre_bloco((p + 1), i, j + 1, original);					
			}
			if(((j != tam2 - 1) && (i != tam1 - 1))){
				if(((1)*tam2 + p+1)->passei == 0)
				abre_bloco(((1)*tam2 + p + 1), i + 1, j + 1, original);		
			}
			if((i != tam1 - 1)){
				if(((1)*tam2 + p)->passei == 0)
				abre_bloco(((1)*tam2 + p), i + 1, j, original);		
			}
			if((j != 0) && (i != tam1 - 1)){
				if(((1)*tam2 + p-1)->passei == 0)
				abre_bloco(((1)*tam2 + p-1), i + 1, j - 1, original);	
			}
			if((j != 0)){
				if((p - 1)->passei == 0)
				abre_bloco((p - 1), i, j - 1, original);
			}
		}
	}	
}

/*void gabarito (QUADRADO *p){
	int i, j;
	for(i = 0;i < tam1; i++){
		for(j = 0; j < tam2; j++){
			if((tam2 * i + j + p)->mina == ATIVA){
				printf("* ");
			}
			else{
				printf("%d ",(tam2 * i + j + p)->adj);
			}					
		}
		printf("\n");
	}
	printf("\n");
}*/




/*Mostra Campo, com todas as minas em evidência, para o usuário
após a sua derrota*/
void mostra_campo_derrota (QUADRADO *p){
	int i, j;
	for(i = -1; i < tam1; i++){
		if(i != -1){
			printf("%2d ", i + 1);
		}
		for(j = 0; j < tam2; j++){
			if(i == -1){
				if(j == 0){
					printf("   ");
				}
				printf("%2d ", j + 1);
				if(j==tam2-1){
					printf("\n");
				}
			}else{
				if((tam2 * i + j + p)->mina == ATIVA){
					printf(" * ");
				}
				else{
					if((tam2 * i + j + p)->aparece == 1){
						printf("%2d ",(tam2 * i + j + p)->adj);
					}
					else{
						printf("%2c ", 254);	
					}
				}
			}		
		}
		printf("\n");
	}
}

/*Função que mostra o campo minado na tela*/
void printar_campo(QUADRADO *p, int i, int j){
	printf("\nNumero de bandeiras: %d\n\n", band);

	for(i = -1; i < tam1; i++){
		if(i != -1){
			printf("%2d ", i + 1);
		}
		for(j = 0; j < tam2; j++){
			if(i == -1){
				if(j == 0){
					printf("   ");
				}
				printf("%2d ", j + 1);
				if(j==tam2-1){
					printf("\n");
				}
			}else{
				if((tam2 * i + j + p)->aparece == 0 && (tam2 * i + j + p)->bomba==0){
					printf("%2c ", 254);
				}else{	
					if((tam2 * i + j + p)->mina == ATIVA){
						if(((tam2 * i + j + p)->bomba == 1) && ((tam2 * i + j + p)->aparece==0)){
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0<<4|4);
							printf("%2c ", 254);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0<<0|15);
						}
						else
							printf("%2c ", 42);
					}
					else{
						if((tam2 * i + j + p)->bomba == 1){
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0<<4|4);
							printf("%2c ", 254);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0<<0|15);
							
						}else{
							printf("%2d ",(tam2 * i + j + p)->adj);
						}
					}
				}
			}		
		}
		printf("\n");
	}
	escolha_usuario(p);
}



/*Função que realiza a escolha do usuário 
(Abrir um espaço ou marcar uma bomba) */
void escolha_usuario (QUADRADO *p){
	int opcao, i, j;
	printf("\nEntre com o n%cmero da op%c%co desejada:\n1 - Abrir um espa%co\n2 - Marcar uma bomba\n3 - Desmarcar uma bomba\n0 - Sair\n", 163, 135, 198, 135);
	scanf("%d", &opcao);
	while (opcao < 0 || opcao > 3){
		printf ("\nERRO! Op%c%co Invalida, Tente Novamente:", 135, 198);
	printf("\nEntre com o n%cmero da op%c%co desejada:\n1 - Abrir um espa%co\n2 - Marcar uma bomba\n3 - Desmarcar uma bomba\n0 - Sair\n", 163, 135, 198, 135);
		scanf ("%d", &opcao);
	}
	if(opcao == 0){
		exit(0);
	}
	if(opcao == 1){
		printf("\nEntre com o numero da linha e coluna que deseja abrir: ");
		scanf("%d %d", &i, &j);
		while (i < 1 || i > tam1 || j < 1 || j > tam2){
			printf ("\nERRO! Op%c%co Invalida, Tente Novamente:", 135, 198);
			printf("\nEntre com o numero da linha e coluna que deseja abrir: ");
			scanf("%d %d", &i, &j);
		}
		i--; /* esse decréscimo é pq para o usuário i e j começam com 1, enquanto no programa começam com 0*/
		j--;
		if((i * tam2 + j + p)->bomba!=1)
			abre_bloco((i * tam2 + j + p), i, j, p);
		else{
			printf("\nEssa pe%ca j%a esta marcada, para abri-la deve desmarca-la\n", 135, 160);
		}	
		
		zerar_passei(p);
	}
	if(opcao == 2){
		printf("\nEntre com o numero da linha e coluna que deseja marcar a bomba: ");
		scanf("%d %d", &i, &j);
		while (i < 1 || i > tam1 || j < 1 || j > tam2){
			printf ("\nERRO! Op%c%co Invalida, Tente Novamente:", 135, 198);
			printf("\nEntre com o numero da linha e coluna que deseja marcar a bomba: ");
			scanf("%d %d", &i, &j);
		}
		i--;
		j--;
		if((i * tam2 + j + p)->bomba==0)
			band--;
		marcar_bomba(p, i, j);
	}
	if(opcao==3){
		if(n_marcado(p, 0,0)!=0){
			printf("\nEntre com o numero da linha e coluna que deseja desmarcar a bomba: ");
			scanf("%d %d", &i, &j);
			while (i < 1 || i > tam1 || j < 1 || j > tam2){
				printf ("\nERRO! Op%c%co Invalida, Tente Novamente:", 135, 198);
				printf("\nEntre com o numero da linha e coluna que deseja desmarcar a bomba: ");
				scanf("%d %d", &i, &j);
			}
			i--;
			j--;
			
			if((i * tam2 + j + p)->bomba==1)
				band++;
			desmarcar_bomba(p, i, j);
		}
		
		
	}
	
	printar_campo(p, 0, 0);
}
int n_marcado(QUADRADO *p, int i, int cont){
	
	for(i=0; i<tam1*tam2; i++){
		if((p+i)->bomba==1)
		cont++;
	}
	return cont;
}
/* Função que marca o local desejado com B, identificado ali como um
possível local contendo uma bomba */
void marcar_bomba(QUADRADO *p, int i, int j){
	if((tam2 * i + j + p)->aparece == 1){
		printf("\nEspa%co j%c selecionado anteriormente.\n", 135, 160);
		escolha_usuario(p);
	}
	else if ((tam2 * i + j + p)->bomba == 1){
		printf("\nEspa%co j%c selecionado anteriormente.\n", 135, 160);
		escolha_usuario(p);
	}
	else{
		(tam2 * i + j + p)->bomba = 1;
	}
}
void desmarcar_bomba(QUADRADO *p, int i, int j){
	if((tam2 * i + j + p)->aparece == 1){
		printf("\nEspa%co j%c selecionado anteriormente.\n", 135, 160);
		escolha_usuario(p);
	}
	else if ((tam2 * i + j + p)->bomba == 1){
		(tam2 * i + j + p)->bomba = 0;	
	}
	else{
		printf("\nN%co tem como desmarcar um espa%co que n%c foi marcado.\n", 198, 135, 198);
		escolha_usuario(p);
	}
}

void zerar_passei(QUADRADO *p){
	int i;
	for(i=0; i<tam1*tam2; i++){
		(p+i)->passei=0;
	}
}
void confere_vitoria(QUADRADO *p){
	int i, j, contador=0;
	for(i = 0; i < tam1; i++){
		for(j = 0; j < tam2; j++){
			if((tam2 * i + j + p)->aparece == 1){
				contador++;
			}	
		}
	}
	if(contador == tam1*tam2 - bomba){
		mostra_campo_derrota(p);
		fimDeJogo(1);
	}
}

