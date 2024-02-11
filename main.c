#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define facil 20
#define medio 15
#define dificil 6
int acabou = 0;


int main(void) {
  do {
  //IMPRIMINDO PALAVRAS NA TELA
  printf("                                                  \n");
	printf("          P  /_\\  P                              \n");
	printf("         /_\\_|_|_/_\\                            \n");
	printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
	printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
	printf("    |\" \"  |  |_|  |\"  \" |                     \n");
	printf("    |_____| ' _ ' |_____|                         \n");
	printf("          \\__|_|__/                              \n");
  printf("                                                  \n");

  int verificacao2 = 1;
  int repetir;

  //DECLARAÇÃO DE VARIÁVEL
 double pontos = 1000;
 int nivel;
 int min;
 int max;
 int intervalo;
 int verificacao = 1;
  
  printf("Você precisa adivinhar o número no qual estou pensando\n"); 
  printf("que estará em um intervalo de sua escolha, essa\n");
  printf("que será feita agora:\n");
  printf("                \n");
  printf("Escolha um número inteiro mínimo para o intervalo:\n");
    scanf("%d" , &min);

 while (verificacao < 2)   {  
  printf("             \n");
  printf("Escolha um número inteiro máximo para o intervalo de\n");
  printf("números: ");
  scanf("%d" , &max);
  if (max < 0)   {
    printf("Esse número não pode ser considerado máximo, ");
    printf("precisa ser um número maior que 0.");
    printf("              \n");
    continue;
  }
   else if (max < min) {
     printf("Esse número é menor do que o mínimo, escolha um maior.\n");
     continue;
   }
 else {
     verificacao++;
   }}

  srand(time(0));
  int numerosecreto = min + (rand() % max);
  
  printf("                                \n");
  printf("Agora escolha uma dificuldade para o jogo:\n");
  printf("1 para fácil - 20 tentativas\n");
  printf("2 para médio - 15 tentativas\n");
  printf("3 para difícil - 6 tentativas\n");
  printf("Escolha: ");
  scanf("%d" , &nivel);
  printf("         \n");
  
  int chute;
  int ultimochute;
  int tentativas;

  switch (nivel)   {
    case 1 :
    tentativas = facil;
    printf("Você escolheu fácil, vamos lá:\n");
    printf("Pontos iniciais: %.2f" , pontos);
    printf("          \n");
    break;
    
    case 2 :
    tentativas = medio;
    printf("Você escolheu médio, vamos lá:\n");
    printf("Pontos iniciais: %.2f" , pontos);
    printf("          \n");
    break;

    default :
    tentativas = dificil;
    printf("Você escolheu difícil, vamos lá:\n");
    printf("Pontos iniciais: %.2f" , pontos);
    printf("          \n");
    break;
    ;
  }

  for (int i = 1; i <= tentativas; i++)   {

  printf("               \n");
  printf("Qual o seu %dº chute de %d? " , i , tentativas);
  scanf("%d" , &chute);
  printf("Seu chute é %d" , chute);

    //TESTANDO VALOR
    if (chute == ultimochute)   {
      printf("         \n");
      printf("Você acabou de tentar este número, tente outro!\n");
      i--;
      continue;
    }
    else if (chute < min)   {
      printf("     \n");
      printf("Esse valor é inválido, chute um número válido.\n");
      i--;
      continue;
    }
  else if (chute > max)  {
    printf("     \n");
    printf("Esse valor é inválido, chute um número válido.\n");
    i--;
    continue;
    } 
  else if (chute == numerosecreto)   {
    printf("                                       \n");
    printf("             OOOOOOOOOOO               \n");
		printf("         OOOOOOOOOOOOOOOOOOO           \n");
		printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
		printf("    OOOOOO      OOOOO      OOOOOO      \n");
		printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
		printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
		printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
		printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
		printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
		printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
		printf("         OOOOOO         OOOOOO         \n");
		printf("             OOOOOOOOOOOO              \n");
    printf("                                       \n");
    printf("Parabéns, você acertou o número secreto!\n");
    break;  
  } 
  else if (chute > numerosecreto)   {
        printf("               \n");
        printf("Seu chute é maior do que o número secreto.\n");
        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
        ultimochute = chute;
        printf("Pontuação: %.2f" , pontos);
        printf("          \n");
   }
      else   {
        printf("          \n");
        printf("Seu chute é menor do que o número secreto.\n");
        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
        ultimochute = chute;
        printf("Pontuação: %.2f" , pontos);
        printf("         \n");
      }
}
  
//DERROTA
  if (pontos < 1) {
    printf("                         \n");
    printf("       \\|/ ____ \\|/    \n");   
    printf("        @~/ ,. \\~@      \n");   
    printf("       /_( \\__/ )_\\    \n");   
    printf("          \\__U_/        \n");
    printf("                         \n");
    printf("Você perdeu todos os pontos, FIM DE JOGO!!!\n");
  }

  //VITÓRIA
  else if (chute == numerosecreto)   {
  printf("         \n");
  printf("FIM DE JOGO!!!\n");
  printf("Pontuação final: %.2f\n" , pontos);
    }
  else   {
    printf("                         \n");
    printf("       \\|/ ____ \\|/    \n");   
    printf("        @~/ ,. \\~@      \n");   
    printf("       /_( \\__/ )_\\    \n");   
    printf("          \\__U_/        \n");
    printf("                         \n");
  printf("Chances esgotadas, VOCÊ PERDEU!!!");
    printf("O número secreto era %d!" , numerosecreto);
    printf("                            \n");
  }
    printf("                       \n");
    printf("Você deseja jogar novamente?\n");
    printf("Digite 1 para SIM\n");
    printf("Digite 2 para NÃO\n");
    scanf("%d" , &repetir);

    if (repetir == 2) {
      printf("\n");
      printf("Obrigado por jogar, volte sempre!\n");
      acabou = 1;
      break;
    }
    
    } while (acabou == 0);
  }