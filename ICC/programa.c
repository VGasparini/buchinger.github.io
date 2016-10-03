// ATEN��O: tudo o que estiver depois do "//" � apenas coment�rio
// texto que n�o � considerado no algoritmo

#include <stdio.h> // permite o uso das instru��es de entrada e sa�da de dados
#include <math.h>  // permite o uso das principais fun��es matem�ticas

main(){                       // define o in�cio do algoritmo
       int a,b,c;             // declara algumas vari�veis inteiras
       float delta, x1, x2;   // declara outras vari�veis reais (decimais)
       printf("Digite os valores de a, b e c: ");  // mostra texto na tela
       scanf("%i %i %i", &a, &b, &c);              // recebe os valores
       delta = b*b - 4*a*c;  // calcula delta
       if( delta>=0 ){       // testa se delta � positivo (ou zero)
           x1 = (-b + sqrt(delta)) / (2*a);    // calcula x1
           x2 = (-b - sqrt(delta)) / (2*a);    // calcula x2
           printf("x' = %f\n", x1);            // mostra valor de x1
           printf("x'' = %f\n", x2);           // mostra valor de x2
       } // indica o final da condi��o "se"
       else{                 // sen�o, se delta n�o for maior ou igual a zero
            printf("Nao existem raizes reais!!\n");  // mostra texto
       } // indica o final do "sen�o"
       printf("\nFIM =)\n"); // mostra texto na tela
       system("pause"); // faz com que o programa pare antes de fechar / terminar
} // indica o final do programa
