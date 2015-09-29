#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
//#include<cctype.h> no existe
//e = 2,7182818284590452353602874713527
//f(x) = ((218 - (12/(x^2)))*(e^(-2*x))) - 1.19


float a=1, b=1, c=1;
float fa=1, fb=1, fc=1;


float evaluarFA(float an){
	return fa=((218-(12/(an*an)))*(exp(-2*an)))-1.19;
}
float evaluarFB(float bn){
	return fb=((218-(12/(bn*bn)))*(exp(-2*bn)))-1.19;
}
float asignarC(float a, float b){
	return c=(a+b)/2;
}
float evaluarFC(float cn){
	return fc=(((218-(12/(cn*cn)))*(exp(-2*cn)))-1.19);
}

main(){
	int max_it=1;
	float tol=1, err=0.000001;
	char resp;
	
	//a debe ser diferente de b, 
	//a y b deben ser dif de cero
	//a no debe ser dif de -b (asi c no es cero en la biseccion)
		
	//do{
		printf("1. Inserte los valores correspondientes para establecer \nel intervalo [a, b] donde se buscara la raiz \n\n");	
		printf("a= ");
		scanf("%f", &a);
		printf("b= ");
		scanf("%f", &b);
		printf("\n\n\n");
		
		
		printf("2. Indique numero maximo de iteraciones\n");
		printf("(No debe sobrepasar las 99)\n\n");
		printf("iteraciones= ");
		scanf("%d", &max_it);
		if(max_it>99){	//limite de iteraciones, seteo a 99
			max_it = 99;
			printf("\n***Ha excedido el limite. \n***Hemos establecido las iteraciones a 99");
		}
		printf("\n\n\n");
		
		
		printf("3. Asignacion de la tolerancia, favor de escribirla en forma decimal\n");
		printf("(Tolerancia maxima es .0001% = 0.0000001 = 1E-8)\n\n");
		printf("tolerancia= ");
		scanf("%f", &tol);
		asignarC(a, b);
		
		
		if(evaluarFA(a)*evaluarFB(b) < 0){
			printf("\ta\t     b\t\tf(a)\t     fb)\t     c\t     f(c)\n"); 	//encabezado de tabla
			
			int i=0;
			while ((c!=0) && (evaluarFA(a)*evaluarFB(b) < 0) && (i<=max_it) )  
			{
				/*err = c;
				printf("%d  ", err);*/
				asignarC(a, b);
				/*err =  abs(err - c);
				printf("%d  \n", err);*/
				if (evaluarFA(a)*evaluarFC(c) > 0){
					printf("%2d", i);
					printf("%11.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n",a, b, fa, fb, c, fc);
					a=c;
						
				}
				else{	
					printf("%2d", i);
					printf("%11.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n",a, b, fa, fb, c, fc);
					b=c;
				}	
				i++;			
			}
		}else
			printf("No se encuentra ninguna raiz dentro del intervalo especificado");
		
		printf("Si desea evaluar otro intervalo presione [S]: ");
		resp = getchar();
		
	//}while(resp == "S" || resp == "s");
		
	system("pause");
}

	
	/*printf("%f",fa);
	printf("\n\n");
	printf("%f",fb);
	printf("\n\n");
	printf("%f",c);
	printf("\n\n");
	printf("%f",fc);
	*/
