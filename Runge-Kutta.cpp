#include<iostream>
#include<math.h>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include <stdlib.h>
#include <string>
#include "ctype.h"

using namespace std;

double funcion_yReal(double x);
double funcion_Runge(double x, double y, double h);
double funcion_Euler(double x, double y, double h);
double funcion_EulerMejorado(double x, double y, double h);
void  Imprimir(double x0,double y0,double h,double x2);

int main(void){
	double x0=0,y0=0,x2=0,h=0;
	string x0_="", y0_="", x2_="", h_="";
	//char x0_[]="", y0_[]="", x2_[]="", h_[]="";
	int opc; 
	bool es0;   
do{
	x0=0,y0=0,x2=0,h=0;
	
    
    cout<<"************************************************************************************************************************\n";
    cout<< "\tAutor: José Evaristo Canales Ensastiga\n";
    cout<<"************************************************************************************************************************\n";
  
	
  	cout << "\nIngresa el valor de x0: ";cin>>x0_;
  	x0=atof(x0_.c_str());
  	//x0=std::strtod(x0_, x0);
  	//cout<<"a: "<<x0_<<" b: "<<x0;
	if(x0_=="0" || x0_=="0.0"){es0=true;}
	else{es0=false;}
	
  	if( !( x0=atof(x0_.c_str())) && (es0==false) ) {
		cout<<"Error, No debes de meter letras, caracteres especiales, alfanumericos";	
	}else{
		cout << "\nIngresa el valor de y0: ";cin>>y0_;
		y0=atof(y0_.c_str());
		if(y0_=="0" || y0_=="0.0"){es0=true;}
		else{es0=false;}
		if( !( y0=atof(y0_.c_str())) && (es0==false) ) {
			cout<<"Error, No debes de meter letras, caracteres especiales, alfanumericos";
		}else{
			cout << "\nIngresa el tamanio de paso h: ";cin>>h_;
			h=atof(h_.c_str());
			if(h_=="0" || h_=="0.0"){es0=true;}
			else{es0=false;}
			if( !( h=atof(h_.c_str())) && (es0==false)){
				cout<<"Error, No debes de meter letras, caracteres especiales, alfanumericos";
			}else{
				cout << "\nIngresa el numero de interaciones: ";cin>>x2_;
				x2=atof(x2_.c_str());
				if(x2_=="0" || x2_=="0.0"){es0=true;}
				else{es0=false;}
				if( !( x2=atof(x2_.c_str())) ){
					cout<<"Error, No debes de meter letras, caracteres especiales, alfanumericos";
				}else{
					cout <<"\n\n";
  	
  	if( x0>=0 && y0>=0 && h>=0 && x2>=0 ){	
  		cout<< "-----------------------------------------------------------------------------------------------------------------\n";
  		cout << " |No. Interaciones|  |Xn|  |Y_real|  |Y_euler|  |Y_euler M|  |Y_runge K|  |Er_euler|  |Er_euler M|  |Er_runge K|\n";
  		cout<< "-----------------------------------------------------------------------------------------------------------------\n";
		Imprimir(x0,y0,h,x2);	
	}else{
  		cout<<"ERROR, No puedes meter numeros negativos!!";
	}
				}
			}
		}
	}
 	
	
	
	cout<<"\n\n¿Desea repetir el codigo? (1=Si / 2=No) ";
	cin>>opc;
	if(opc==1){
		system("cls");
	}
}while(opc==1);
	cout<<"\n\n\tAdios";
}

void Imprimir(double x0,double y0,double h,double x2)
{
  int noI=0;
  double yReal=y0, yEuler=y0, yEulerM=y0, yRunge=y0, erEuler, erEulerM, erRunge, yF=y0, hF=h;
  do{
  	if(noI==0){
  		yEuler=funcion_Euler(x0,y0,0);
		yEulerM=funcion_EulerMejorado(x0,y0,0);
		yRunge=funcion_Runge(x0,y0,0);
		yReal=funcion_yReal(x0);
		erEuler=(100*(yEuler-yReal)/yReal);
		erEulerM=(100*(yEulerM-yReal)/yReal);
		erRunge=(100*(yRunge-yReal)/yReal);
	}else{
		yEuler=funcion_Euler(x0,yEuler,hF);
		yEulerM=funcion_EulerMejorado(x0,yEulerM,hF);
		yRunge=funcion_Runge(x0,yRunge,hF);
		x0 = x0+h;
		yReal=funcion_yReal(x0);
		erEuler=(100*(yEuler-yReal)/yReal);
		erEulerM=(100*(yEulerM-yReal)/yReal);
		erRunge=(100*(yRunge-yReal)/yReal);	
	}	
		
		cout <<"	  "<<noI;
		cout <<setprecision(1) << "	     " << fixed << x0;
		cout <<setprecision(6) << "   "  << fixed << yReal;
		cout <<setprecision(6) << "  "  << fixed << yEuler;
		cout <<setprecision(6) << "   "  << fixed << yEulerM;
		cout <<setprecision(6) << "     "  << fixed << yRunge;
		cout <<setprecision(6) << "     "  << fixed << abs(erEuler) <<"%";
		cout <<setprecision(6) << "    "  << fixed << abs(erEulerM) <<"%";
		cout <<setprecision(6) << "    "  << fixed << abs(erRunge) <<"% \n";
		
	noI++;
	}while(noI<=x2);
  		cout << "\n";
  		
}

//====================================================================

double funcion_yReal(double x0){
	
	double y = pow(((log(2 * (x0)+ 1) / 4) + 2), 2);
	
	return y;
}


double funcion_Euler(double x, double y, double h){            //función y´= Raiz(y)/2x+1{	
  	
  double k1 = sqrt(y) / (2*(x)+1);
  
  double y1 = y + (h*k1);

  return y1;
}


double funcion_EulerMejorado(double x, double y, double h)            
{	
	
  double U1 = (y + h *( sqrt(y) / (2*(x)+1) ) );

  double y1 = (y + h * .5 *( (sqrt(y) / (2*(x)+1)) + (sqrt(U1) / (2*(x+h)+1)) ) );

  return y1;
  //cout<<U1;
}

double funcion_Runge(double x, double y, double h)            
{	
	
  double k1 = sqrt(y) / (2*(x)+1);                
  
  double k2= ( sqrt(y+(.5*k1*h) ) / ( 2*(x+(.5*h)) +1) );

  double k3= ( sqrt(y+(.5*k2*h) ) / ( 2*(x+(.5*h)) +1) );
  
  double k4= ( sqrt(y+(k3*h) ) / ( 2*(x+h) +1) );
  
  double y1= (y + ( (1./6.) *(k1 + (2*k2) + (2*k3) + k4)*h ) );

  return y1;
}
