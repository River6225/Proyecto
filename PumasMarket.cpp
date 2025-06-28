#include <iostream>


using namespace std;


 int acumCervezasN = 0, cantidadCervezaNacional, contSixpacksN = 0, cervezasNSueltas, subtCervezasN, acumCervezasE = 0, contSixpacksE = 0, cantidadCervezaExtranjera = 0, cervezasE, cervezasESueltas, subtCervezasE;
 int acumBTVino = 0, botellasVino, subtBTVino, acumBTVodka = 0, botellasVodka, subtBTVodka, edadCliente, num, productoBotella;
 string nombreCliente;
 int acumLbrPapas = 0, papasLb, subtPapas, acumLbrTomates = 0,  tomatesLb, subTomates,  acumLbrRepollo = 0, repolloLb, subtRepollo;   
 int repollo, subTotal, id, tipoCliente, diaSemana;





void menuVerduras() {
	int opcion;
	do {
		cout << "\033[32m******VERDURAS******\033[0m"<<endl;;
		cout << "1. Tomates------"<<"Lps.10 libra"<<endl;
		cout << "2. Repollo------"<<"Lps.15 libra"<<endl;
		cout << "3. Papas--------"<<"Lps.17 libra"<<endl;
		cout << "4. Regresar\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Has seleccionado Tomates\n";
			cout << "Cantidad de Libras de tomates a llevar: \n";
			cin >> tomatesLb;
			       acumLbrTomates = acumLbrTomates + tomatesLb;
				   subTomates = (tomatesLb * 10);
			break;
		case 2:
			cout << "Has seleccionado Repollo\n";
			cout << "Cantidad de repollos a llevar: \n";
			cin >> repollo;
			      acumLbrRepollo = acumLbrRepollo + repolloLb;
				  subtRepollo = (repollo*15);
			break;
		case 3:
			cout<< "Has seleccionado Papas\n";
			cout << "Cantidad de Libras de papas a llevar: \n";
			cin >> papasLb;
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
	
	subTotal = subTomates + subtPapas + subtRepollo;
	subTotal = subTotal + (subTomates + subtPapas + subtRepollo);
	
	
}

void menuCarnes() {
	int opcion;
	do {
		cout << "\033[33m******CARNES******\033[0m"<<endl;;
		cout << "4. Carne de res----------"<<"Lps.50 libra"<<endl;
		cout << "5. Carne de cerdo--------"<<"Lps.70 libra"<<endl;
		cout << "6. Pollo-----------------"<<"Lps.75 libra"<<endl;
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
		cout << "\033[34m******LICORES******\033[0m"<<endl;
		cout << "7. Cervezas------------------"<<"Lps.50 c/u"<<endl;
		cout << "8. Cervezas Extranjeras------"<<"Lps.80 c/u"<<endl;
		cout << "9. Vinos---------------------"<<"Lps.200 c/u"<<endl;
		cout << "10. Vodka--------------------"<<"Lps.100 c/u"<<endl;;
		cout << "11. Regresar\n";
		cout << "Selecciona una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 7:
			cout << "Has seleccionado Cervezas\n";
			cout << "Cantidad de cerveza nacional a llevar:  \n";
			cin >> cantidadCervezaNacional;
			       acumCervezasN = acumCervezasN + cantidadCervezaNacional;
				   contSixpacksN = acumCervezasN / 6;
				   cervezasNSueltas = acumCervezasN % 6;
				   subtCervezasN = (contSixpacksN*6*50)-(contSixpacksN*10)+(cervezasNSueltas*50);
			break;
		case 8: 
			cout << "Has seleccionado Cervezas Extranjeras\n";
			cout << "Cantidad de cervezas extranjeras a llevar: \n";
			cin >> cervezasE;
			       acumCervezasE = acumCervezasE + cantidadCervezaExtranjera;
				   contSixpacksE = acumCervezasE / 6;
				   subtCervezasE = (contSixpacksE *6*80)-(contSixpacksE*10)+(cervezasESueltas*80);
			     
			break;
		case 9:
			cout << "Has seleccionado Vinos\n";
			cout << "Cantidad de botellas de vino a Llevar \n";
			cin >> botellasVino;
			       acumBTVino = acumBTVino + botellasVino;
				   subtBTVino = (botellasVino * 200);
				  
			break;
		case 10:
			cout << "Has seleccionado Vodka\n";
			cout << "Cantidad de botellas de vodka a llevar: \n";
			cin >> botellasVodka;
			
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
	
	subTotal = subtBTVino  + subtBTVodka + subtCervezasE + subtCervezasN;
	subTotal = subTotal + subtBTVino  + subtBTVodka + subtCervezasE + subtCervezasN;
}

int main() {
	
		cout<<"\033[31m**********BIENVENIDOS A PUMA MARKET**********\033[0m"<<endl;
		cout << "Ingrese su nombre completo: ";
		cin.ignore(); // Limpia el buffer antes de usar getline
		getline(cin, nombreCliente);
		
		cout<<"Ingrese su edad: "<<endl;
		cin>>edadCliente;
		
		while(edadCliente <= 10 || edadCliente >=100 ){
			cout<<"Edad fuera de rango válido (10 a 100 años)."<<endl;
			cout<<"Ingrese su edad nuevamente: "<<endl;
			cin>>edadCliente;
		}
		
		cout<<"Ingrese su numero de identidad: "<<endl;
		cin>>id;
		
		cout <<"Seleccione el tipo de cliente: "<< endl;
		cout <<"1 = Estrella" << endl;
		cout <<"2 = Regular" << endl;
		cout <<"3 = Nuevo" << endl;
		cout <<"Ingrese su opcion: "<<endl;
		cin >> tipoCliente;
		cin.clear();
		
		while (tipoCliente < 1 || tipoCliente > 3) {
			cin.clear();
			cout << "Opcion invalida. Debe ingresar 1, 2 o 3." << endl;
			cout << "Ingrese nuevamente el tipo de cliente: "<<endl;
			cin >> tipoCliente;
		}
		
		// Opcional: mensaje según tipo
		if (tipoCliente == 1) {
			cout << "Ha seleccionado: Cliente Estrella." << endl;
		} else if (tipoCliente == 2) {
			cout << "Ha seleccionado: Cliente Regular." << endl;
		} else {
			cout << "Ha seleccionado: Cliente Nuevo." << endl;
		}
		
		cout<<"Ingrese el dia 1 = Lunes, 2 = Martes, 3 = Miercoles, 4 = Jueves, 5 = Viernes, 6 = Sabado, 7 = Domingo "<<endl;
		cin>>diaSemana;
		
		while(diaSemana <1 || diaSemana >7 ){
			cout<<"Dia De La Semana Incorrecto, Ingrese nuevamente su selección: "<<endl;
			cin>>diaSemana;
		}
		if (diaSemana == 1) {
			cout << "Ha seleccionado: Lunes----"<<"3% adicional"<< endl;
		} else if (diaSemana == 2) {
			cout << "Ha seleccionado: Martes" << endl;
		} else if (diaSemana == 3) {
			cout << "Ha seleccionado: Miércoles----"<<"3% adicional"<< endl;
		} else if (diaSemana == 4) {
			cout << "Ha seleccionado: Jueves" << endl;
		} else if (diaSemana == 5) {
			cout << "Ha seleccionado: Viernes-----" <<"10% adicional para la tercera edad (+65 años)"<< endl;
		} else if (diaSemana == 6) {
			cout << "Ha seleccionado: Sábado" << endl;
		} else if (diaSemana == 7) {
			cout << "Ha seleccionado: Domingo" << endl;
		}
		
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

 

 
