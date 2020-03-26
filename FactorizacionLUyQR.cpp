#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


struct Matriz
{
 
        double A[100][100];
        void Ingresar(int N);
        void Mostrar(int N);
        void Llenar_L(int N);
        void Llenar_U(int N);      
}A,L,U;


struct L_U
{
        L_U Factorizar(int N) //El algoritmo que debe de hacerse para poder sacar las matrices L y U
        {
        double suma,suma1;
  
        L.Llenar_L(N);
        U.Llenar_U(N);
        
        for ( int i = 1 ; i <= N ; i++)
            {
            for ( int j = i ; j <= N ; j++)
                {
                suma = 0;
                for ( int k = 1 ; k <= i - 1 ; k++)
                     suma = L.A[i][k]*U.A[k][j] + suma;
                 
                 U.A[i][j] = A.A[i][j] - suma;
                }
            
            for ( int j = i + 1; j <= N ; j++)    
                {
                 suma = 0;     
                 for ( int k = 1 ; k <= i - 1 ; k++)
                      suma = L.A[j][k]*U.A[k][i] + suma;
             
                 L.A[j][i] = (A.A[j][i] - suma)/U.A[i][i];
                }
             L.A[i][i] = 1;
           }          
        }
        
        void mostrar_LU(int N) //Esta función muestra las matrices L y U.
        {
         cout<<endl<<endl<<" L (Matriz lower, es decir, la triangular inferior) = ";
         L.Mostrar(N);
                     
         cout<<endl<<endl<<" U (Matriz upper, es decir, la triangular superior) = ";
         U.Mostrar(N);
        }    
}LU;



void Matriz :: Ingresar(int N) //Aquí pedimos al usuario que introduzca los valores de la matriz de la dimensión que ha elegido.
{
 cout<<endl;
 for ( int i = 1 ; i <= N ; i++ )
     for ( int j = 1 ; j <= N ; j++ )
         {
          cout<<"["<<i<<","<<j<<"] : " ;
          cin>>A[i][j];
         }  
}

void Matriz :: Mostrar(int N) //Esta función muestra la matrices L, U y A (la del usuario) de tal forma que parezca una matriz en la consola.
{
 
 cout<<endl;
 for( int i = 1 ; i <= N ; i++ ){
     cout<<""<<endl;
     for( int j = 1 ; j <= N ; j++ )
		if((A[i][j]<0.00001&&A[i][j]>0)||(A[i][j]>-0.00001&&A[i][j]<0))
            cout<<setw(6)<<0<<setw(6);
        else
            cout<<setw(6)<<setprecision(3)<<A[i][j]<<setw(6);
        cout<<""<<endl;
    }
    cout<<endl;
}


void Matriz :: Llenar_L(int N){ //Esta función crea la matriz L, que al principio es una matriz identidad. 

 
 for ( int i = 1 ; i <= N ; i++ ){
      for ( int j = 1 ; j <= N ; j++ ){
           if ( i == j ){
              A[i][j] = 1;
        	}
           else{
              A[i][j] = 0;
			}
        }
    }
}

void Matriz :: Llenar_U(int N){ //Esta función inicializa la matriz triangular superior llenándola de 0.


 for ( int i = 1 ; i <= N ; i++ ){  //Estos bucles for sirven para recorrer todos los elementos de la matriz
      for ( int j = 1 ; j <= N ; j++ ){
          A[i][j] = 0;
        }
}
}


int main(){
	float a1[3];
	float a2[3];
	float a3[3];
	float u1[3];
	float u2[3];
	float u3[3];
	float e1[3];
	float e2[3];
	float e3[3];
	int cont=0;
	int valor=0;
	float suma0=0;
	float suma1=0;
	float suma2=0;
	float suma3=0;
	float suma4=0;
	float suma5=0;
	float MatrizA[3][3];
 	
	Matriz L;
	int N; 
	
	int c;
	
	cout<<"Seleccione una opcion:"<<endl;
	cout<<"1. Factorizacion LU:"<<endl;
	cout<<"2. Factorizacion QR:"<<endl;
	
	cin>>c;
	
	switch(c){
		case 1:{
			cout<<" Introduzca la dimension de la Matriz (por favor, solo introduzca numeros): ";
    		cin>>N;
    		A.Ingresar(N);
    		cout<<endl<<endl<<" A (La matriz introducida por el usuario) = ";
   			A.Mostrar(N);
    		LU.Factorizar(N);
    		LU.mostrar_LU(N);	
    		
		}break;
		
		case 2:{
			cout<<"Introduzca los valores de la matriz 3x3:"<<endl;
			cout<<endl;
	
//Aquí introducimos los valores de la matriz A

 		for ( int i = 0 ; i < 3 ; i++ ){
   		 	for ( int j = 0 ; j < 3 ; j++ ){
    		cout<<"["<<i+1<<","<<j+1<<"] : " ;
       		cin>>MatrizA[i][j];
    		}
		}
         
//Todos estos for forman el algoritmo de la factorización QR

		for (int i=0; i<3; i++){
			a1[i]=MatrizA[i][cont];
		}
	
	for (int i=0; i<3; i++){
		a2[i]=MatrizA[i][cont+1];
	}
	
	for (int i=0; i<3; i++){
		a3[i]=MatrizA[i][cont+2];
	}
	
	for (int i=0; i<3; i++){
		u1[i]=a1[i];
	}
	
	for (int i=0; i<3; i++){
		e1[i]=u1[i]/sqrt((u1[0]*u1[0])+(u1[1]*u1[1])+(u1[2]*u1[2]));
	}
	
	for (int i=0; i<3; i++){
		suma0+=a2[i]*e1[i];
	}
		
	for (int i=0; i<3; i++){
		u2[i]=a2[i]-(suma0)*e1[i];
	}
	
	for (int i=0; i<3; i++){
		e2[i]=(u2[i]/sqrt((u2[0]*u2[0])+(u2[1]*u2[1])+(u2[2]*u2[2])));
	}
	
	
	for (int i=0; i<3; i++){
		suma1+=a3[i]*e1[i];
	}
	
	for (int i=0; i<3; i++){
		suma2+=a3[i]*e2[i];
	}
	
	for (int i=0; i<3; i++){
		suma3+=a1[i]*e1[i];
	}
	
	for (int i=0; i<3; i++){
		suma4+=a2[i]*e2[i];
	}
	
	for (int i=0; i<3; i++){
		suma5+=a3[i]*e3[i];
	}
	
	for (int i=0; i<3; i++){
		u3[i]=a3[i]-(suma1)*e1[i]-(suma2)*e2[i];
	}
	
	for (int i=0; i<3; i++){
		e3[i]=(u3[i]/sqrt((u3[0]*u3[0])+(u3[1]*u3[1])+(u3[2]*u3[2])));
	}
		
//Aquí declaramos las matrices Q y R (las ortogonales y la triangular superior)
	
	float MatrizQ[3][3]={{e1[0], e2[0], e3[0]},{e1[1], e2[1], e3[1]},{e1[2], e2[2], e3[2]}};	
	float MatrizR[3][3]={{suma3, suma0, suma1},{0,suma4 ,suma2},{0, 0, suma5}};	

cout<<endl;

//Todos estos cout, mostraran las matrices por pantalla

cout<<"La matriz A introducida es:"<<endl;
cout<<endl;
for (int i=0; i<3; i++){
	for (int j=0; j<3; j++){
		cout<<"    "<<MatrizA[i][j]<<"    ";
	}
	cout<<endl;
	cout<<endl;
}

cout<<endl;

cout<<"La matriz Q (el conjunto de matrices ortogonales) es:"<<endl;
cout<<endl;
for (int i=0; i<3; i++){
	for (int j=0; j<3; j++){
		cout<<"    "<<MatrizQ[i][j]<<"    ";
	}
	cout<<endl;
	cout<<endl;
}

cout<<endl;

cout<<"La matriz R (la matriz triangular superior) es:"<<endl;
cout<<endl;

	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			cout<<"    "<<MatrizR[i][j]<<"    ";
		}
		cout<<endl;
		cout<<endl;
	}

		}break;
	}
   return 0;
	
}
