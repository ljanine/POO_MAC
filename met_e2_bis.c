#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

//#include<cctype.h> no existe
//e = 2,7182818284590452353602874713527
//f(x) = ((218 - (12/(x^2)))*(e^(-2*x))) - 1.19


float a=1, b=1, c=1;
float f, fa=1, fb=1, fc=1;


float evaluarF2(float n){
	return ((218-(12/(n*n)))*(exp(-2*n)))-1.19;
}


main(){
	int max_it=1;
	float tol=1, err=0.000001;
	int resp=0;
	
	//a debe ser diferente de b, 
	//a y b deben ser dif de cero
	//a no debe ser dif de -b (asi c no es cero en la biseccion, evitamos indeterminacion)
		
	do{
		//pedir el intervalo
		printf("1. Inserte los valores correspondientes para establecer \n   el intervalo [a, b] donde se buscara la raiz \n\n");	
		printf("a= ");
		scanf("%f", &a);
		printf("b= ");
		scanf("%f", &b);
		//Verificacion del intervalo
		do{
			if(a==b){
				printf("\n  ** \"a\" no puede ser igual a \"b\", sino no hay intervalo \n");
				printf("  ** Reestablezca el intervalo\n\n");		
				printf("a= ");
				scanf("%f", &a);
				printf("b= ");
				scanf("%f", &b);
			}
			if(a == -b){
				printf("\n  ** \"a\" no puede ser igual a \"-b\", sino se indetermina la ecuacion\n");
				printf("  ** Reestablezca el intervalo\n\n");		
				printf("a= ");
				scanf("%f", &a);
				printf("b= ");
				scanf("%f", &b);
			}
			if((a == 0) || (b == 0)){
				printf("\n  ** Tanto \"a\" como \"b\" no pueden ser igual a cero,\n");
				printf("  ** sino se indetermina la ecuacion\n");
				printf("  ** Reestablezca el intervalo\n\n");		
				printf("a= ");
				scanf("%f", &a);
				printf("b= ");
				scanf("%f", &b);
			}	
		}while((a==b)||(a== -b)||(a == 0)||(b == 0));
		printf("\n\n\n");
		c=(a+b)/2;
		
		//pedir las iteraciones
		printf("2. Indique numero maximo de iteraciones\n");
		printf("   (No debe sobrepasar las 99)\n\n");
		printf("iteraciones= ");
		scanf("%d", &max_it);
		//verificacion de las iteraciones
		do{
			if(max_it>99){	
				printf("\n  ** El limite de iteraciones son 99. No puede sobrepasarlo\n");
				printf("  ** Reestablezca el numero de iteraciones \n\n");	
				printf("iteraciones= ");
				scanf("%d", &max_it);
			}
			if(max_it<1){	
				printf("\n  ** Minimo de iteraciones es 1\n");
				printf("  ** Reestablezca el numero de iteraciones \n\n");	
				printf("iteraciones= ");
				scanf("%d", &max_it);
			}		
		}while((max_it>99) || (max_it<1));
		printf("\n\n\n");
		
		//pedir la tolerancia
		printf("3. Asignacion de la tolerancia, favor de escribirla en forma decimal\n");
		printf("   (Tolerancia minima es 0.000001)\n\n");
		printf("tolerancia= ");
		scanf("%f", &tol);
		//verificacion de la tolerancia
		do{
			if(tol<0.000001){
				printf("\n  ** La tolerancia debe ser positiva y mayor a 0.000001\n");
				printf("  ** Reestablezca la tolerancia\n\n");		
				printf("tolerancia= ");
				scanf("%f", &tol);	
			}
		}while(tol<0.000001);
		
		
		if(evaluarF2(a)*evaluarF2(b) < 0){
			printf("\ta\t     b\t\tf(a)\t     fb)\t     c\t     f(c)\n"); 	//encabezado de tabla
			
			int i=1;
			while ( (i<=max_it))  
			{
				c=(a+b)/2;
				evaluarF2(c);
				
				if (evaluarF2(a)*evaluarF2(c) > 0){
					printf("%2d", i);
					printf("%11.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n",a, b, evaluarF2(a), evaluarF2(b), c, evaluarF2(c));
					a=c;
						
				}
				else{	
					printf("%2d", i);
					printf("%11.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n",a, b, evaluarF2(a), evaluarF2(b), c, evaluarF2(c));
					b=c;
					
				}	
				i++;			
			}
		}
		else{
			printf("\n\n\t**\n");
			printf("\t** ERROR: Lo sentimos! :(  \n");
			printf("\t**\n");
			printf("\t** No se encuentro ninguna raiz dentro del intervalo especificado\n");
			printf("\t**\n\n\n");
		}
		printf("\n\nSi desea evaluar otro intervalo, presione 1: ");
		scanf("%d", &resp);
		if(resp==1)
			printf("\n\n\n");
		
	}while(resp == 1);
		
	system("pause");
}
