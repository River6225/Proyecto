#include <iostream>


using namespace std;


 int acumCervezasN = 0, cantidadCervezaNacional, contSixpacksN = 0, cervezasNSueltas, subtCervezasN, acumCervezasE = 0, contSixpacksE = 0, cantidadCervezaExtranjera = 0, cervezasE, cervezasESueltas, subtCervezasE;
 int acumBTVino = 0, botellasVino, subtBTVino, acumBTVodka = 0, botellasVodka, subtBTVodka, edadCliente, num, productoBotella;
 string nombreCliente;







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
				  subtRepollo = (repollo*15);
			break;
		case 3:
			cout <<"Has seleccionado Papas"\n;
			
			break;
				default:
					cout << "Opcion invalida. Intentalo de nuevo.\n";
				}
			} while (opcionChiles != 3);
			break;
		case 4:
			cout << "Regresando al menu principal...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 4);
}

void menuCarnes() {
	int opcion;
	do {
		cout << "\nCARNES\n";
		cout << "4. Carne de res\n";
		cout << "5. Carne de cerdo\n";
		cout << "6. Pollo\n";
		cout << "7. Regresar\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 4:
			cout << "Has seleccionado Carne de res\n";
			break;
		case 5:
			int opcionCerdo;
			do {
				cout << "\nCARNE DE CERDO\n";
				cout << "1. Nacional\n";
				cout << "2. Exportada\n";
				cout << "3. Regresar\n";
				cout << "Selecciona una opcion: ";
				cin >> opcionCerdo;
				
				switch (opcionCerdo) {
				case 1:
					cout << "Has seleccionado Carne de cerdo Nacional\n";
					break;
				case 2:
					cout << "Has seleccionado Carne de cerdo Exportada\n";
					break;
				case 3:
					cout << "Regresando al menu anterior...\n";
					break;
				default:
					cout << "Opcion invalida. Intentalo de nuevo.\n";
				}
			} while (opcionCerdo != 3);
			break;
		case 6:
			cout << "Has seleccionado Pollo\n";
			break;
		case 7:
			cout << "Regresando al menu principal...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 7);
}

void menuLicores() {
	
	if(edadCliente <18 ){
		
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
}

int main() {
	
		cout<<"\033[31m**********BIENVENIDOS A PUMA MARKET**********\033[0m"<<endl;
		cout << "Ingrese su nombre completo: ";
		cin.ignore(); // Limpia el buffer antes de usar getline
		getline(cin, nombreCliente);
		
		cout<<"Ingrese su edad: "<<endl;
		cin>>edadCliente;
		
		
		
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
			menuLicores();
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

 
