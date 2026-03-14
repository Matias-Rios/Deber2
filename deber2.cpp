#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <chrono>
#include <ctime>
#include <sstream>
#include <cmath>

using namespace std;


string Divisas_comprobacion(string divisa){
	int longitud=0;
	longitud=divisa.length();
	while (longitud != 3){
		cout<<"Ingrese una Divisa valida: ";
		cin>>divisa;
		longitud=divisa.length();
		}
    for (int i = 0; i < longitud; i++) { //[AI-START]
        divisa[i] = toupper(divisa[i]);   //[AI END]
		}
    return divisa;
}


double numero_combrobacion(double numero){   
	while (numero < 0 or numero==0){
		cout<<"Ingrese un numero valido ";
		cin>>numero;
	}
	return numero;
}


string separador_miles(double valor, int dec = 2) {

    double factor = pow(10, dec);
    valor = round(valor * factor) / factor;

    stringstream ss;
    ss << fixed << setprecision(dec) << valor;
    string s = ss.str();

    int punto = s.find('.');
    for (int i = punto - 3; i > 0; i -= 3) {
        s.insert(i, ",");
    }

    return s;
}


string Fecha() {
    auto ahora = chrono::system_clock::now();  //[AI START]
    time_t tiempo = chrono::system_clock::to_time_t(ahora); 
    tm* local = localtime(&tiempo);  

    stringstream ss;  
    ss << put_time(local, "%Y-%m-%d %H:%M:%S"); 

    return ss.str();  //[AI END]
}


string minusula_desicion(string palabra){
	    int longitud=0;
	    longitud=palabra.length();
		for (int i = 0; i < longitud; i++) { 
        	palabra[i] = tolower(palabra[i]);
		}
        return palabra;
}

int main(){
	string Divisa_base;
	string Divisa_cambio;
	double Tasa_cambio;
	double Monto_base;
	double Monto_cambio;
	bool Flag=true;
	string Desicion;
	
	
	cout<<"Bienvenido, Introduzca las divisas que desea cambiar a partir de 3 de sus digitos "<<endl;
	cout<<"Ejemplo: USD "<<endl;
	
	while(Flag){
		cout<<"Divisa base: ";
		cin>>Divisa_base;
		Divisa_base=Divisas_comprobacion(Divisa_base);
	
	
		cout<<"Divisa cambio: ";
		cin>>Divisa_cambio;
		Divisa_cambio=Divisas_comprobacion(Divisa_cambio);
		while (Divisa_cambio == Divisa_base){
			cout<<"Ingrese una divisa distinta ";
			cin>>Divisa_cambio;
			Divisa_cambio=Divisas_comprobacion(Divisa_cambio);
		}
	
	
		cout<<"Las divisas ingresadas son "<<Divisa_base<<"/"<<Divisa_cambio<<endl;
		cout<<"Ingrese la tasa de cambio de 1 "<<Divisa_base<<" a "<<Divisa_cambio<<" ";
		cin>>Tasa_cambio;
		Tasa_cambio=numero_combrobacion(Tasa_cambio);
	
	
		cout<<"Ingrese el monto de cambio ";
		cin>>Monto_base;
		Monto_base=numero_combrobacion(Monto_base);
	
	
		Monto_cambio=Monto_base*Tasa_cambio;
	
	
		cout<<" "<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<" "<<endl;
		cout<<"Snapshot de mercado"<<endl;
		cout<<left<<setw(25)<<"Divisas:"
			<<Divisa_base<<"/"<<Divisa_cambio<<endl;
		cout<<left<<setw(25)<<"Tasa de cambio:"
			<<separador_miles(Tasa_cambio,6)<<endl;
		cout<<left<<setw(25)<< "Monto base:"
    	 	<<separador_miles(Monto_base)<< endl;
		cout<<left<<setw(25)<<"Monto de cambio:"
            <<separador_miles(Monto_cambio)<< endl;
		cout<<" "<<endl;
		cout<<"Fecha de consulta:"<<Fecha();
		
		cout<<" "<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<" "<<endl;
		
		cout<<"Desea continuar (y/n): ";
		cin>>Desicion;
		Desicion=minusula_desicion(Desicion);
		while(Desicion!= "y" and Desicion!="n"){
			cout<<"Introduzca una desicion valida (y/n): ";
			cin>>Desicion;
		}
		
		if (Desicion == "n"){
			break;
		}
	}
	return 0;
	
}