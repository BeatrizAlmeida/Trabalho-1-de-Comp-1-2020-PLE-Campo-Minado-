#ifndef MOLDE_H
#define MOLDE_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<windows.h>
#include "defs.h"
#define ATIVA 9


void desmarcar_bomba(QUADRADO *p, int i, int j);
int n_marcado(QUADRADO *p, int i, int cont);
void abre_bloco(QUADRADO *p, int i, int j, QUADRADO *original);
void printar_campo (QUADRADO *p, int i, int j);
void mostra_campo_derrota (QUADRADO *p);
void escolha_usuario(QUADRADO *p);
void marcar_bomba(QUADRADO *p, int i, int j);
void fimDeJogo (int result);
void inicializa ();
void menu();
void gabarito (QUADRADO *p);
void zerar_passei(QUADRADO *p);
void confere_vitoria(QUADRADO *p);

#endif
