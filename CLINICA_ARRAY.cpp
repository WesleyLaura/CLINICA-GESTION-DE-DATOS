//array ordenados y desordenados de un historial clinico de un paciente
#include <iostream>
#include <string.h>
#include <math.h>
#define MAX 2
using namespace std;

struct paciente{
	char hc[15],nomb[20];
	float peso,talla,imc;
};

void menuDesordenados(paciente *, int &);
void menuOrdenados(paciente *, int &);
void insertar_d(paciente *, int &);
void eliminar_d(paciente *,int &);
void modificar_d(paciente *, int &);
int buscar(paciente *, int );
void insertar_o(paciente *, int &);
//void eliminar_o(paciente *,int &);
//void modificar_o(paciente *, int &);

void mostrar(paciente *, int);
int main(){
	paciente x[MAX];
	int op,n;
	n=-1;
	do{
		cout<<"----MENU-----\n";
		cout<<"1.- Array DESORDENADOS\n";
		cout<<"2.- Array ORDENADOS\n";
		cout<<"3.- S A L I R\n";
		cout<<"Ingrese la opcion: "; cin>>op;
		switch(op){
			case 1:
				menuDesordenados(x,n);
				break;
			case 2:
				menuOrdenados(x,n);
				break;
			case 3:
				break;		
			
		}
	}while(op>0 && op<3);
	
	return 0;
}
//................................................
void menuDesordenados(paciente *x, int &n){
	system("cls");
int op,pos;
	do{
		cout<<"-----MENU DE ARRAY DESORDENADOS\n";
		cout<<"1.- INSERTAR\n";
		cout<<"2.- ELIMINAR\n";
		cout<<"3.- MODIFICAR\n";
		cout<<"4.- BUSCAR\n";
		cout<<"5.- MOSTRAR\n";
		cout<<"6.- REGRESAR AL MENU PRINCIPAL\n";
		cout<<"Ingrese la opcion :"; cin>>op;
		switch(op){
			
			case 1:
				insertar_d(x,n);
			    mostrar(x,n);
				break;
			case 2:
				eliminar_d(x,n);
				mostrar(x,n);
				break;
			case 3:
				modificar_d(x,n);
				mostrar(x,n);
				break;
			case 4:
				pos=buscar(x,n);
				if(pos>0){
					cout<<"La POSICION DEL DATO ES: "<<pos;
				}else{
					cout<<"No se encontro";
				}
				mostrar(x,n);
				break;
			case 5:
				mostrar(x,n);
				break;
			case 6:
				break;					
		}
		
	}while(op>0 && op<6);
}
//------------------------------------------------
void menuOrdenados(paciente *x, int &n){
	system("cls");
int op,pos;
	do{
		cout<<"-----MENU DE ARRAY ORDENADOS\n";
		cout<<"1.- INSERTAR\n";
		cout<<"2.- ELIMINAR\n";
		cout<<"3.- MODIFICAR\n";
		cout<<"4.- BUSCAR\n";
		cout<<"5.- MOSTRAR\n";
		cout<<"6.- REGRESAR AL MENU PRINCIPAL\n";
		cout<<"Ingrese la opcion :"; cin>>op;
		switch(op){
			
			case 1:
				insertar_o(x,n);
			    mostrar(x,n);
				break;
			case 2:
				//eliminar_o(x,n);
				mostrar(x,n);
				break;
			case 3:
				//modificar_o(x,n);
				mostrar(x,n);
				break;
			case 4:
			/*	pos=buscar_o(x,n);
				if(pos>=0){
					cout<<"La POSICION DEL DATO ES: "<<pos;
				}else{
					cout<<"No se encontro";
				}*/
				mostrar(x,n);
				break;
			case 5:
				mostrar(x,n);
				break;
			case 6:
				break;					
		}
		
	}while(op>0 && op<6);
}

void insertar_d(paciente *x,int &n){
	int i,cen;
	char hclinica[10];
	
	if(n<MAX-1){
		cen=0;
		i=0;
		cout<<" HISTORIA CLINICA : ";cin>>hclinica;
		if(n>-1){
			while(i<=n && (cen==0)){
				if(strcmp(x[i].hc,hclinica)==0){
					cen=1;
				}else{
					i++;
				}	
			}
		}
			if(cen==0){	
			n++;
			strcpy(x[i].hc,hclinica);
			cout<<"NOMBRE: ";cin>>x[i].nomb;
			cout<<"PESO: ";cin>>x[i].peso;
			cout<<"TALLA :";cin>>x[i].talla;
			x[i].imc=(x[i].peso/(x[i].talla*x[i].talla));
			cout<<"INDICE DE MASA CORPORAL :"<<x[i].imc;
			}else{
				cout<<"DATO YA REGISTRADO EN LA BASE DE DATOS. No se realizo la insercion...\n";
			}
	}else{
		cout<<"ARRAY LLENO, PELIGRO DE DESBORDAMIENTO...no se inserto dato\n";
	}
	cout<<"\n";
}

void eliminar_d(paciente *x, int &n){
	int i,j,cen;
	char hclinica[10];
	if(n>-1){
		cen=0;
		i=0; 
		cout<<"\nEscriba LA HISTORIA CLINICA que desea eliminar: ";cin>>hclinica;
		while((i<=n)&& (cen==0)){
			if(strcmp(hclinica,x[i].hc)==0){
				n--;
				for(j=i;j<=n;j++){
					x[j]=x[j+1];
				}
				cen=1;
			}else{
				i++;
			}
		}
		cout<<"\nDATO ELIMINADO EXITOSAMENTEE!!!!";
			if(cen==0){
				cout<<"\n---------------------------------------------\n";
				cout<<"\n|"<<hclinica<<" NO EXISTE EN LA BASE DE DATOS|\n";
				cout<<"\n---------------------------------------------\n";
			}
	}else{
		cout<<"ARRAY VACIO...No se ha eliminado nada\n";
	}
	
}

void modificar_d(paciente *x, int &n){
	int i,cen,op;
	char hc1[10];
	cout<<"\n\nCODIGO DE REGISTRO A MODIFICAR\n\n";
	cout<<"INGRESE LA HISTORIA CLINICA: "; cin>>hc1;
	if(n>-1){
		i=0;
		cen=0;
		while(i<=n && (cen==0)){
				if(strcmp(x[i].hc,hc1)==0){
					cen=1;
					cout<<"\n\nQUE CAMPO DESEA MODIFICAR\n\n";
					cout<<"\n-------------------------------------------------------\n";
					cout<<"|1.-HISTORIA CLINICA   2.-NOMBRE   3.-PESO   4.-TALLA    |";
					cout<<"\n-------------------------------------------------------\n";
					cout<<"OPCION: ";cin>>op;
					switch(op){
						
						case 1:
							cout<<"Ingrese la HISTORIA CLINICA CORRECTA: ";cin>>x[i].hc;
							break;
						case 2:
							cout<<"Ingrese el NOMBRE CORRECTO: "; cin>>x[i].nomb;
							break;
						case 3:
							cout<<"Ingrese el PESO CORRECTO: "; cin>>x[i].peso;
							x[i].imc=(x[i].peso/(x[i].talla*x[i].talla));
							break;
						case 4:
							cout<<"Ingrese la TALLA CORRECTA: "; cin>>x[i].talla;
							x[i].imc=(x[i].peso/(x[i].talla*x[i].talla));
							break;	
					}
				}else{
					i++;
				}	
			}
				if(cen==0){
				cout<<"\n---------------------------------------------------------\n";
				cout<<"|"<<hc1<<" DATO A MODIFICAR NO EXISTE EN LA BASE DE DATOS  |";
				cout<<"\n---------------------------------------------------------\n";
				}
		
	}else{
		cout<<"ARREGLO VACIOOOO!!!\n";
		system("pause");
	}
	
}

int buscar(paciente *x, int n){
	int i,pos;
	char hc1[10];
	if(n>-1){
		i=0;
	cout<<"Ingrese LA HISTORIA CLINICA QUE DESEA BUSCAR: "; cin>>hc1;
		while(i<=n){
			if(strcmp(x[i].hc,hc1)==0){
				pos=i;
			}else{
				pos=-(i+1);
			}
			i++;
		}
	
	}
	return pos;
}

void insertar_o(paciente *x, int &n){
	int pos,i;
	char hc[10];
	if(n>MAX-1){
		cout<<"Ingrese el HISTORIAL CLINICO : "; cin>>hc;
		if(n>-1){
			pos =buscar(x,n);
			if(pos<0){
				n++;
				pos=-pos;
					for(i=n;i>=pos+1;i--){
						x[i]=x[i-1];
					}
					strcpy(x[pos],hc);
			}else{
				cout<<"EL DATO YA EXISTE\n\n";
			}
		}
	}else{
		cout<<"ARRAY LLENO, PELIGRO DE DESBORDAMIENTO...no se inserto dato\n";
	}
}
void mostrar(paciente *x,int n){
	for(int i=0;i<=n;i++){
		cout<<"\n\n["<<i+1<<"] : ";
		cout<<"\nHISTORIA CLINICA : "<<x[i].hc;
		cout<<"\nNOMBRE : "<<x[i].nomb;
		cout<<"\nPESO: "<<x[i].peso;
		cout<<"\nTALLA : "<<x[i].talla;
		cout<<"\nINDICE DE MASA CORPORAL: "<<x[i].imc;	
	cout<<"\n------------------------------------\n\n";
	}
	system("pause");
}