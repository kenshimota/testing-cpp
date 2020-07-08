#include <iostream>


/* estructura para los numero racionales */
typedef struct numeroRacional {
	int nominador = 0;
	int denominador = 1;
} numeroRacional;


/* predeclaracion de las funciones a utilizar */
numeroRacional simplificarRacional();
void print_options_main();
numeroRacional obtenerNumero();
numeroRacional addition();
numeroRacional restar();
numeroRacional dividir();
numeroRacional multiplicar();


/* ---------------- Main ------------------ */
int main(){
	int option = 0;
	numeroRacional result;

	while(1){
		print_options_main();
		std::cout << "Seleccione opcion: ";
		std::cin >> option;


		switch(option){
			case 1:
				result = addition();
				std::cout << "el resultado de la operacion es: ("<< result.nominador <<"/" << result.denominador  << ")" << std::endl;
			break;
			case 2:
				result = restar();
				std::cout << "el resultado de la operacion es: ("<< result.nominador <<"/" << result.denominador  << ")" << std::endl;
			break;
			case 3:
				result = multiplicar();
				std::cout << "el resultado de la operacion es: ("<< result.nominador <<"/" << result.denominador  << ")" << std::endl;
			break;
			case 4:
				result = dividir();
				std::cout << "el resultado de la operacion es: ("<< result.nominador <<"/" << result.denominador  << ")" << std::endl;
			break;
			case 5: return 0; break;
			default: std::cout << "La opcion ingresada no es valida.!" << std::endl; break;
		}

	}
}

/* mostrando las opciones del menu  */
void print_options_main(){
	std::cout << "Opciones del Menu" << std::endl
	<< "1) Suma" << std::endl
	<< "2) Resta" << std::endl 
	<< "3) Multiplicacion" << std::endl
	<< "4) Division" << std::endl
	<< "5) Salir" << std::endl << std::endl;
}

/*  funcion que se encarga de obtener el numero racional por consola */
struct numeroRacional obtenerNumero(){
	struct numeroRacional num;
	std::cout << "Ingrese el nominador: ";
	std::cin >> num.nominador;

	std::cout << "Ingrese el denominador: ";
	std::cin >> num.denominador;

	return num;
}

/* funcion que simplifica numeros racionales */
numeroRacional simplificarRacional(numeroRacional numero){
	
	if( abs(numero.denominador) == 1)
		return numero;
	else {
		int base = 2;
		while( base <= abs(numero.denominador) ){
			if( (abs(numero.denominador) % base) == 0 && (abs(numero.nominador) % base) == 0){
				numero.denominador = numero.denominador / base;
				numero.nominador = numero.nominador / base;
			}
			else 
				base++;
		}
	}

	return numero;
}

/* funcion que se encarga de hacer una suma de 2 numeros
racionales */
numeroRacional addition(){
	struct numeroRacional result;
	struct numeroRacional num1;
	struct numeroRacional num2;
	
	std::cout << "Datos del primer numero racional" << std::endl;
	num1 = obtenerNumero();
	
	std::cout << "Datos del segundo numero racional" << std::endl;
	num2 = obtenerNumero();

	result.nominador = (  (num1.nominador * num2.denominador) + (num1.denominador * num2.nominador) );
	result.denominador = (  num1.denominador * num2.denominador );

	return simplificarRacional( result );
}

/* funcion que se encarga de hacer una restar de 2 numeros
racionales */
numeroRacional restar(){
	struct numeroRacional result;
	struct numeroRacional num1;
	struct numeroRacional num2;
	
	std::cout << "Datos del primer numero racional" << std::endl;
	num1 = obtenerNumero();
	
	std::cout << "Datos del segundo numero racional" << std::endl;
	num2 = obtenerNumero();

	result.nominador = (  (num1.nominador * num2.denominador) - (num1.denominador * num2.nominador) );
	result.denominador = (  num1.denominador * num2.denominador );

	return simplificarRacional( result );
}

/* funcion que se encarga de hacer una multiplicar de 2 numeros
racionales */
numeroRacional multiplicar(){
	struct numeroRacional result;
	struct numeroRacional num1;
	struct numeroRacional num2;
	
	std::cout << "Datos del primer numero racional" << std::endl;
	num1 = obtenerNumero();
	
	std::cout << "Datos del segundo numero racional" << std::endl;
	num2 = obtenerNumero();

	result.nominador = (num1.nominador * num2.nominador);
	result.denominador = (  num1.denominador * num2.denominador );

	return simplificarRacional( result );
}


/* funcion que se encarga de hacer una dividir de 2 numeros
racionales */
numeroRacional dividir(){
	struct numeroRacional result;
	struct numeroRacional num1;
	struct numeroRacional num2;
	
	std::cout << "Datos del primer numero racional" << std::endl;
	num1 = obtenerNumero();
	
	std::cout << "Datos del segundo numero racional" << std::endl;
	num2 = obtenerNumero();

	result.nominador = (num1.nominador * num2.denominador);
	result.denominador = (  num1.denominador * num2.nominador );

	return simplificarRacional( result );
}
