#include <iostream>
#include <string>


using namespace std;
string nombreCliente;
int edadCliente, id;
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
float descCarneMolida, descCarneCerdo, descCarnepA, descTomate, descRepollo, descPapa, descuentoTotal, descCervezaNac, descCervezaExt, descTerceraEdad, descVino, descVodka, descAdicional;


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
			descCarneMolida = subtCarneM * 0.04;
			descCarneCerdo = subtCarneC * 0.04;
			descCarnepA = subtCarnepA * 0.04;
			descTomate = subTomates * 0.04;
			descRepollo = subtRepollo * 0.04;
			descPapa = subtPapas * 0.04;
			descuentoTotal = descCarneCerdo + descCarneMolida + descCarnepA + descTomate + descPapa + descRepollo;
			break;
		case 2:
			descCarneMolida = subtCarneM * 0.03;
			descCarneCerdo = subtCarneC * 0.03;
			descCarnepA = subtCarnepA * 0.03;
			descuentoTotal = subtCarnepA + subtCarneC + subtCarneM;
			break;
		case 3:
			descCervezaNac = subtCervezasN * 0.02;
			descCervezaExt = subtCervezasE * 0.02;
			descVino = subtBTVino * 0.02;
			descVodka = subtBTVodka * 0.02;
			descuentoTotal = descVodka + descVino +  descCervezaExt + descCervezaNac;
			break;
		default:
			cout << "Tipo de cliente invalido.\n";
			return;
	}  
		if (diaSemana == 1 || diaSemana == 3){
			descAdicional = subTotal * 0.03;
		    descuentoTotal += descAdicional;
		}
		if (diaSemana == 5 && edadCliente >= 65){
            descTerceraEdad += descTerceraEdad *0.10;
			descuentoTotal += descTerceraEdad;
		}

	}
		
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
			cin >> repolloLb;
			      acumLbrRepollo = acumLbrRepollo + repolloLb;
				  subtRepollo = (repolloLb*15);
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
	subTotal += subTomates + subtPapas + subtRepollo; ;
}
void menuCarnes() {
	int opcion;
	do {
		cout << "\033[33m******CARNES******\033[0m"<<endl;;
		cout << "4. Carne Molida ----------"<<"Lps.50 libra"<<endl;
		cout << "5. Carne de cerdo --------"<<"Lps.70 libra"<<endl;
		cout << "6. Carne para Asar -----------------"<<"Lps.75 libra"<<endl;
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
			acumLbrCarnepA = acumLbrCarneC + carneParaAsarLb;
			subtCarnepA = carneParaAsarLb * 75;
			break;
		case 7:
			cout << "Regresando al menu principal...\n";
			break;
		default:
			cout << "Opcion invalida. Intentalo de nuevo.\n";
		}
	} while (opcion != 7);
	
	subTotal +=  subtCarneM + subtCarneC + subtCarnepA;
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
  
	subTotal += subtBTVino  + subtBTVodka + subtCervezasE + subtCervezasN;;
}

int main() {
	
	cout<<"\033[31m**********BIENVENIDOS A PUMA MARKET**********\033[0m"<<endl;
		cout << "Ingrese su nombre completo: ";
		cin.ignore(); // Limpia el buffer antes de usar getline
		getline(cin, nombreCliente);
		
		cout<<"Ingrese su edad: "<<endl;
		cin>>edadCliente;
		
		while(edadCliente <= 10 || edadCliente >=100 ){
			cout<<"Edad fuera de rango valido (10 a 100 años)."<<endl;
			cout<<"Ingrese su edad nuevamente: "<<endl;
			cin>>edadCliente;
		}
		
		cout<<"Ingrese su numero de identidad: "<<endl;
		cin>> id;
		
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
		
		// Opcional: mensaje segun tipo
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
			cout<<"Dia De La Semana Incorrecto, Ingrese nuevamente su seleccion: "<<endl;
			cin>>diaSemana;
		}
		if (diaSemana == 1) {
			cout << "Ha seleccionado: Lunes----"<<"3% adicional"<< endl;
		} else if (diaSemana == 2) {
			cout << "Ha seleccionado: Martes" << endl;
		} else if (diaSemana == 3) {
			cout << "Ha seleccionado: Miercoles----"<<"3% adicional"<< endl;
		} else if (diaSemana == 4) {
			cout << "Ha seleccionado: Jueves" << endl;
		} else if (diaSemana == 5) {
			cout << "Ha seleccionado: Viernes-----" <<"10% adicional para la tercera edad (+65 años)"<< endl;
		} else if (diaSemana == 6) {
			cout << "Ha seleccionado: Sabado" << endl;
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

 
