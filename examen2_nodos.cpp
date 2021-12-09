#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <fstream>

using namespace std;

// Estructura del nodo
struct Nodo{
	char nombre[21];
	int clave;
	Nodo *next;
};

Nodo *primero, *actual, *ultimo, *nuevo, *previo;

int  vclave;
char vnombre[21];

char falso[2];

// Va guardando los nodos
void descarga_archivo(char archivo1[21]){
	if (primero==NULL){
		printf("La lista est%c vac%ca ...\n",160,161);
		getche();
	}
	ofstream arch;
	arch.open(archivo1,ios::out);
	actual=primero;
	while (actual!=NULL){
		arch <<actual->clave << " " << actual->nombre <<"\n";
		actual = actual->next;
		
	}
	arch.close();
}

// Agrega el nodo al final
void inserta_final(int f_clave, char f_nombre[21]){
	nuevo = new Nodo;
	nuevo->clave = f_clave;
	strcpy(nuevo->nombre, f_nombre);
	nuevo->next = NULL;
	
	if (primero==NULL){
		primero=nuevo;
		ultimo=nuevo;
		actual=nuevo;
	}
	else{
		ultimo->next=nuevo;
		ultimo=nuevo;
	}
}

// Pide los datos para la variable inserta_final
void pide_datos(){
	int c;
	char n[21];
	printf("    Ingresa la clave   : "); 
	scanf("%d", &c); gets(falso);
	printf("    Ingresa el nombre  : "); 
	gets(n);
	inserta_final(c, n);
	printf("\n    NODO AGREGADO "); 
	getche();
}

// Agraga un nuevo nodo entre un rango de dos nodos
void inserta_entre(){
	int x, y, e_clave;
	char e_nombre[21];
	bool existe;
	printf("    Ingresa la clave   : "); scanf("%d", &e_clave); gets (falso);
	printf("    Ingresa el nombre  : "); gets(e_nombre);
	printf("\n    Ingrese el rango entre los nodos \n");
	printf("    Primer valor       : "); scanf("%d", &x); gets(falso);
	printf("    Segundo valor      : "); scanf("%d", &y); gets(falso);
	
	if (primero==NULL){
		printf("    La lista est%c vac%ca\n",160,161);
		getche();
	}
	else{
		actual=primero;
		existe=false;
		while (actual!=NULL){
			if ((actual->clave==x) && (actual->next->clave == y)){
				existe=true;
				break;
			}
			actual=actual->next;
			
		}
		if (!existe){
			printf("\n    Valores de rango no validos ...\n");
			getche();
		}
		else{
			nuevo=new Nodo;
			strcpy(nuevo->nombre, e_nombre);
			nuevo->clave = e_clave;
			nuevo->next=actual->next;
			actual->next=nuevo;
			
			printf("\n    NODO AGREGADO\n");
			getche();
		}
	}

}

// Se van cargando en el archivo
void cargar_archivo(char archivo2[21]){
	ifstream arch;
	arch.open(archivo2,ios::in);
	while(!arch.eof()){
		arch >> vclave >> vnombre;
		if (!arch.eof()){
			inserta_final(vclave, vnombre);
		}
	}
	arch.close();
}

// Muestra los nodos que se encuentran en el archivo
void mostrar_lista(){
	if (primero==NULL){
		printf("\nLa lista est%c vac%ca\n",160,161);
		getche();
	}
	actual=primero;
	while (actual!=NULL){
		printf("%10d  %21s\n",actual->clave, actual->nombre);
		actual=actual->next;
	}
	getche();
}

void menu(){
	int op = 0;
	while(op!=4){
	system("clS");
	printf("\n   .-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.\n");
	printf("  (                                               )\n");
	printf("   )                     MENU                    (\n");
	printf("  (                                               )\n");
	printf("   ) 1) Insertar nodo al final                   (\n");
	printf("  (  2) Insertar nodo entre nodo                  )\n");
	printf("   ) 3) Mostrar lista enlazada                   (\n");
	printf("  (  4) TERMINAR                                  )\n");
	printf("   ._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.\n");
 	printf("\n    Indica la opci%cn deseada : ",162);
	scanf("%d", &op); gets(falso);	
	
	printf("\n");
	
	if(op==1) pide_datos();
	if(op==2) inserta_entre();
	if(op==3) mostrar_lista();
	if(op==4){
		descarga_archivo("temporal.txt");
		primero=NULL;
		cargar_archivo("temporal.txt");
	}
}
}


main(){
	cargar_archivo("examen.txt");
	menu();
	descarga_archivo("examen.txt");
}
