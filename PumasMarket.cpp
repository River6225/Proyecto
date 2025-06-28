#include <iostream>
#include <string>


using namespace std;
string nombreCliente;
int edadCliente;
// separar las variables por area por areas para evitar problemas
//Licores
int acumCervezasN = 0, cantidadCervezaNacional, contSixpacksN = 0, cervezasNSueltas;
int  acumCervezasE = 0, contSixpacksE = 0, cantidadCervezaExtranjera = 0, cervezasE, cervezasESueltas;
int acumBTVino = 0, botellasVino, acumBTVodka = 0, botellasVodka, num, productoBotella; 
float subtCervezasN, subtCervezasE, subtBTVodka, subtBTVino;
// Verduras
int  tomatesLb,repolloLb, papasLb;
float  acumLbrTomates, subTomates,acumLbrRepollo, subtRepollo, acumLbrPapas, subtPapas;
// Carnes 
int carneMolidaLb, carneDeCerdoLb,carneParaAsarLb;
int acumLbrCarneM,acumLbrCarneC,acumLbrCarnepA;
float subtCarneM,subtCarneC, subtCarnepA;
// Impuestos
float isvConLicores, isv;
// TOTALES PARA IMPRIMIR 
float subTotal, totalAPagar;
// Descuentos
int tipoCliente, diaSemana;
float descCliente, descAdicional, descTerceraEdad, subtCarnes, subtVerduras, subtLicores, totalDescuento;


void calcularISV (){
    if (cantidadCervezaExtranjera > 0 || cantidadCervezaNacional > 0 || botellasVino > 0 || botellasVodka > 0)
    {
        // Aplicar isv 18% al llevar licores
        isvConLicores = subTotal * 0.18;
        totalAPagar = subTotal + isvConLicores;
    }else{
		// Aplicar 15% en General
        isv = subTotal * 0.15;
        totalAPagar = subTotal + isv;
    }
    

}

void calcularDescuentos() {
	if (edadCliente >= 65)
	{
		descTerceraEdad = subTotal * 0.25;
	}
	
		switch (tipoCliente) {
		case 1:
			descCliente = (subtCarnes + subtVerduras) * 0.04;
			break;
		case 2:
			descCliente = subtCarnes * 0.03;
			break;
		case 3:
			descCliente = subtLicores * 0.02;
			break;
		default:
			cout << "Tipo de cliente invalido.\n";
			return;
	}  
		if (diaSemana == 1 || diaSemana == 3)
			descAdicional = subTotal * 0.03;
		
		if (diaSemana == 5 && edadCliente >= 65)
			descTerceraEdad = descTerceraEdad + subTotal * 0.10;
		
		 totalDescuento = descCliente + descAdicional + descTerceraEdad;
	
	}
		
void menuVerduras() {
	int opcion;
	do {
		cout << "\nVERDURAS\n";
		cout << "1. Tomates\n";
		cout << "2. Repollos\n";
		cout << "3. Papas\n";
		cout << "4. Regresar\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Has seleccionado Tomates\n";
			       acumLbrTomates = acumLbrTomates + tomatesLb;
			       subTomates = (tomatesLb * 10);
			break;
		case 2:
			cout << "Has seleccionado Repollo\n";
			       acumLbrRepollo = acumLbrRepollo + repolloLb;
			       subtRepollo = (repolloLb*15);
			break;
		case 3:
			cout <<"Has seleccionado Papas\n";
			        acumLbrPapas = acumLbrPapas + papasLb;                               
			        subtPapas = (papasLb * 17);
			break;	
		case 4:
			cout << "Regresando al menu principal...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 4);   
	subtVerduras = (subTomates + subtPapas + subtRepollo); 
	subTotal = subTotal + subtVerduras;
}
void menuCarnes() {
	int opcion;
	do {
		cout << "\nCARNES\n";
		cout << "4. Carne  Molida\n";
		cout << "5. Carne de cerdo\n";
		cout << "6. Carne para Asar\n";
		cout << "7. Regresar\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 4:
			cout << "Has seleccionado Carne Molida\n";
			cout <<  "Cantidad de Libras Carne Molida a Llevar \n";
			cin >> carneMolidaLb;
			acumLbrCarneM = acumLbrCarneM + carneMolidaLb;
			subtCarneM = carneMolidaLb * 50;
			break;
		case 5:
			cout << "Has seleccionado Carne de Cerdo\n";
			cout <<  "Cantidad de Libras Carne De Cerdo a Llevar \n";
			cin >> carneDeCerdoLb;
			acumLbrCarneC = acumLbrCarneC + carneDeCerdoLb;
			subtCarneC = carneDeCerdoLb * 70;
			break;
		case 6:
			cout << "Has seleccionado Carne para Asar\n";
			cout <<  "Cantidad de Libras Carne Para Asar a Llevar \n";
			cin >> carneParaAsarLb;
			acumLbrCarneM = acumLbrCarneC + carneParaAsarLb;
			subtCarnepA = carneParaAsarLb * 75;
			break;
		case 7:
			cout << "Regresando al menu principal...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 7);
	subtCarnes = subtCarneM + subtCarneC + subtCarnepA;
	subTotal += subtCarnes;
}

void menuLicores(int edad) {
	
	if(edad <18 ){
		
		cout<<"No se le vende alcohol a menores de edad."<<endl;
		
		return;
	}
	
	
	
	int opcion;
	do {
		cout << "\nLICORES\n";
		cout << "7. Cervezas\n";
		cout << "8. Cervezas Extranjeras\n";
		cout << "9. Vinos\n";
		cout << "10. Vodka\n";
		cout << "11. Regresar\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 7:
			cout << "Has seleccionado Cervezas\n";
			       acumCervezasN = acumCervezasN + cantidadCervezaNacional;
				   contSixpacksN = acumCervezasN / 6;
				   cervezasNSueltas = acumCervezasN % 6;
				   subtCervezasN = (contSixpacksN*6*50)-(contSixpacksN*10)+(cervezasNSueltas*50);
			break;
		case 8: 
			cout << "Has seleccionado Cervezas Extranjeras\n";
			       acumCervezasE = acumCervezasE + cantidadCervezaExtranjera;
				   contSixpacksE = acumCervezasE / 6;
				   subtCervezasE = (contSixpacksE *6*80)-(contSixpacksE*10)+(cervezasESueltas*80);
			     
			break;
		case 9:
			cout << "Has seleccionado Vinos\n";
			       acumBTVino = acumBTVino + botellasVino;
				   subtBTVino = (botellasVino * 200);
				  
			break;
		case 10:
			cout << "Has seleccionado Vodka\n";
			     acumBTVodka = acumBTVodka + botellasVodka;
				 subtBTVodka = (botellasVodka * 100);
				
			break;
		case 11:
			cout << "Regresando al menu principal...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 11);
    subtLicores = subtBTVino  + subtBTVodka + subtCervezasE + subtCervezasN;
	subTotal += subtLicores;
}

int main() {
	
		cout<<"\033[31m**********BIENVENIDOS A PUMA MARKET**********\033[0m"<<endl;
		cout << "Ingrese su nombre completo: ";
		cin.ignore(); // Limpia el buffer antes de usar getline
		getline(cin, nombreCliente);
		
		cout<<"Ingrese su edad: "<<endl;
		cin>> edadCliente;
		
		
		
	int opcion;
	do {
		cout << "\nMENU PRINCIPAL\n";
		cout << "1. Verduras\n";
		cout << "2. Carnes\n";
		cout << "3. Licores\n";
		cout << "4. Salir\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			menuVerduras();
			break;
		case 2:
			menuCarnes();
			break;
		case 3:
			menuLicores(edadCliente);
			break;
		case 4:
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 4);
	
	return 0;
}

 
