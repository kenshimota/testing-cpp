#include <iostream>
#include <string>
#include <string.h>
#include <vector>

/* -------- Estructura de Contactos -------- */
typedef struct Contactos {
	std::string nombre;
	std::string telefono;
	std::string email;
} Contactos;


/* Prototipo de funciones a ser usadas */
void imprimeOpciones();
void ordenarPorColumna(int columna, std::vector<Contactos> &agenda);
Contactos crearContact();
void mostarContactos(std::vector<Contactos> &agenda);
int checkString(std::string &s1, std::string &s2);

/* ----------- Main ----------- */
int main(){
	
	std::vector<Contactos> agenda;
	int option = 0;

	while(1){
		imprimeOpciones();
		std::cout << "Seleccione opcion: ";
		std::cin >> option;

		switch(option){
			case 1: mostarContactos(agenda); break;
			case 2: agenda.push_back( crearContact() ); break;
			case 3: ordenarPorColumna( 1, agenda ); break;
			case 4: ordenarPorColumna( 2, agenda ); break; 
			case 5: ordenarPorColumna( 3, agenda ); break;
			case 6: return 1; break;
			default: std::cout << "La opcion seleccionada no es valida"; break;
		}

		std::cout << std::endl << std::endl;

	}


	return 0;
}

/* imprime las opciones disponibles */
void imprimeOpciones(){
	std::cout << "1) Mostar Contactos." << std::endl
	<< "2) Crear Contacto." << std::endl
	<< "3) Ordena contactos por nombre." << std::endl
	<< "4) Ordena contactos por telefono." << std::endl
	<< "5) Ordena contactos por email" << std::endl
	<< "6) Salir" << std::endl << std::endl;
}

/* funcion que se encarga de mostrar los contactos */
void mostarContactos(std::vector<Contactos> &agenda){
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "| Nombre | Telefono | Correo Electronico |" << std::endl;
	for (size_t i = 0; i < agenda.size(); ++i)
		std::cout << "| " << agenda[i].nombre << " | " << agenda[i].telefono << " | " <<  agenda[i].email << " | " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

/*  funcion que te permite crear un contacto */
Contactos crearContact(){
	Contactos contacto;
	std::cout << "Creando un Nuevo Contacto" << std::endl << std::endl;
	
	std::cout << "Nombre: ";
	std::cin >> contacto.nombre;

	std::cout << "Telefono: ";
	std::cin >> contacto.telefono;
	
	std::cout << "Correo Electronico: ";
	std::cin >> contacto.email;

	return contacto;
}

/* esta es una funcio que nos permite determina porque columna se va
ha obtenerel valor usado para el ordenamiento */
std::string obtenerValorColumna(int columna, Contactos &c){
	switch(columna){
		case 1: return c.nombre; break;
		case 2: return c.telefono; break;
		case 3: return c.email; break;
	}
	return "";
}

void ordenarPorColumna(int columna, std::vector<Contactos> &agenda){
	std::string s1; // string1
	std::string s2; // string2
	Contactos temp;

	for (size_t i = 1; i < agenda.size(); ++i){
		s1 = obtenerValorColumna(columna, agenda[i]);
		for (size_t j = 0; j <  agenda.size(); ++j){
			s2 = obtenerValorColumna(columna, agenda[j]);
			if( i != j ){
				
				if( checkString(s1, s2) > 0 ){
					temp = agenda[j];
					agenda[j] = agenda[i];
					agenda[i] = temp;
				}

			}
		}
	}

	std::cout << "Sus contactos han sido ordenados" << std::endl;
	mostarContactos( agenda );
}

/* compara 2 string */
int checkString(std::string &s1, std::string &s2){
	
	for (int i = 0; i < s2.length() && i < s1.length() ; ++i){
		if(  s1[i] < s2[i] )
			return 1;
		else if( s1[i] > s2[i] )
			return -1;
	}

	return 0;
}