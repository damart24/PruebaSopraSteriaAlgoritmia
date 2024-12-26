#pragma once
#include <iostream>
#include <vector>

using namespace std;

// 1. Escriba un algoritmo que lea un número entero y determine si es par o impar.
// Si es par, que escriba todos los pares de manera descendiente desde sí mismo y hasta el cero.Si es impar, 
// que escriba todos los impares de manera descendiente desde si sí mismo hasta el uno.Utilice la instrucción 
// LEER NUMERO al inicio del programa para cargar un número en la variable NUMERO.

void LeerNumero(int numero) {
	if (numero % 2 == 0) {
		std::cout << "El numero " << numero << " es par" << "\n";
		while (numero >= 0)
		{
			std::cout << "Descendientes pares: " << numero << "\n";
			numero -= 2;
		}
	}
	else {
		std::cout << "El numero " << numero << " es impar" << "\n";
		while (numero >= 1)
		{
			std::cout << "Descendientes impares: " << numero << "\n";
			numero -= 2;
		}
	}
}

// 2. Escriba un algoritmo que visualice una clasificación de 50 personas según edad y sexo.Deberá mostrar los siguientes resultados :
// a.Cantidad de personas mayores de edad(18 años o más).
// b.Cantidad de personas menores de edad.
// c.Cantidad de personas masculinas mayores de edad.
// d.Cantidad de personas femeninas menores de edad.
// e.Porcentaje que representan las personas mayores de edad respecto al total de personas.
// f.Porcentaje que representan las mujeres respecto al total de personas.
// 
// Utilice la instrucción LEER PERSONAS al inicio del programa para cargar los datos de las 50 personas en un variable, PERSONAS, que actúa como un vector de 50 posiciones.
// Cada elemento de PERSONAS es de un tipo estructurado que dispone dos campos :
// SEXO y EDAD.

// Enum para ordenar hombre y mujer
enum Sexo{ Hombre, Mujer };

vector<pair<Sexo, int>> rellenarVectorPersonas() {
    std::vector<std::pair<Sexo, int>> vectorDeDuplas = {
       {Sexo::Hombre, 20},
       {Sexo::Mujer, 2},
       {Sexo::Hombre, 30},
       {Sexo::Mujer, 22},
       {Sexo::Hombre, 3},
       {Sexo::Mujer, 33},
       {Sexo::Hombre, 50},
       {Sexo::Mujer, 28},
       {Sexo::Hombre, 35},
       {Sexo::Mujer, 60},
       {Sexo::Hombre, 45},
       {Sexo::Mujer, 6},
       {Sexo::Hombre, 31},
       {Sexo::Mujer, 23},
       {Sexo::Hombre, 29},
       {Sexo::Mujer, 37},
       {Sexo::Hombre, 38},
       {Sexo::Mujer, 40},
       {Sexo::Hombre, 41},
       {Sexo::Mujer, 50},
       {Sexo::Hombre, 22},
       {Sexo::Mujer, 20},
       {Sexo::Hombre, 24},
       {Sexo::Mujer, 27},
       {Sexo::Hombre, 55},
       {Sexo::Mujer, 62},
       {Sexo::Hombre, 3},
       {Sexo::Mujer, 61},
       {Sexo::Hombre, 23},
       {Sexo::Mujer, 26},
       {Sexo::Hombre, 42},
       {Sexo::Mujer, 30},
       {Sexo::Hombre, 36},
       {Sexo::Mujer, 32},
       {Sexo::Hombre, 48},
       {Sexo::Mujer, 47},
       {Sexo::Hombre, 27},
       {Sexo::Mujer, 41},
       {Sexo::Hombre, 52},
       {Sexo::Mujer, 34},
       {Sexo::Hombre, 53},
       {Sexo::Mujer, 39},
       {Sexo::Hombre, 33},
       {Sexo::Mujer, 46},
       {Sexo::Hombre, 44},
       {Sexo::Mujer, 29},
       {Sexo::Hombre, 25},
       {Sexo::Mujer, 21},
       {Sexo::Hombre, 28},
       {Sexo::Mujer, 54},
    };

	return vectorDeDuplas;
}

void LeerPersonas(vector<pair<Sexo, int>> personas) {
	int personasMayores = 0, personasMenores = 0, hombresMayores = 0, mujeresMenores = 0, numeroTotalMujeres = 0;

	for (auto persona : personas) {

		if (persona.first == Sexo::Mujer)
			numeroTotalMujeres++;

		if (persona.second >= 18) {

			personasMayores++;

			if (persona.first == Sexo::Hombre)
				hombresMayores++;
		}

		//Hago la comprobación asegurando que los datos pudiesen ser erróneos y menor que 0
		else if (persona.second >= 0) {

			personasMenores++;

			if (persona.first == Sexo::Mujer)
				mujeresMenores++;
		}
	}

	float porcentajePersonasMayores = personasMayores * 100 / personas.size();

	std::cout << "Personas mayores de edad: " << personasMayores << "\n";
	std::cout << "Personas menores de edad: " << personasMenores << "\n";
	std::cout << "Hombres mayores de edad: " << hombresMayores << "\n";
	std::cout << "Mujeres menores de edad: " << mujeresMenores << "\n";
	std::cout << "Porcentaje de personas mayores de edad: " << porcentajePersonasMayores << "%\n";
	std::cout << "Numero total de mujeres: " << numeroTotalMujeres << "\n";
}

// 3. Desarrolle un algoritmo para el cálculo del salario de un trabajador.
// El importe liquidado(sueldo) depende de una tarifa o precio por hora establecida y 
// de un condicionante sobre las horas trabajadas : si la cantidad de horas trabajadas es mayor a 40 horas, 
// la tarifa se incrementa en un 50 % para las horas extras.
// Calcular el sueldo recibido por el trabajador en base las horas trabajadas y la tarifa.
// Utilice las instrucciones LEER HORASTRABAJADAS y LEER TARIFA al inicio del programa para cargar 
// los valores en las variables HORASTRABAJADAS y TARIFA.

// Leo las horas trabajadas y en el primer int del pair pongo las trabajadas normales, y en el segundo las extra
pair<int, int> leerHorasTrabajadas(int horasTrabajadas){
    pair<int, int> horasParaLaTarifa(0, 0);
    if (horasTrabajadas > 40) {
        horasParaLaTarifa.first = 40;
        horasParaLaTarifa.second = horasTrabajadas - 40;
    }
    else
        horasParaLaTarifa.first = horasTrabajadas;

    return horasParaLaTarifa;
}

void leerTarifa(pair<int, int> horasCalculadas, int tarifa) {
    // Calculo el sueldo según una variable tarifa de base, y una tarifa mas el 50 % para las horas extra
    float sueldoTrabajador = (horasCalculadas.first * tarifa) + (horasCalculadas.second * tarifa * 1.5);

    std::cout << "El sueldo a cobrar es de: " << sueldoTrabajador <<
        " euros, con un total de " << horasCalculadas.first << " horas trabajadas sin extras, mas "
        << horasCalculadas.second << " horas extras realizadas \n";
}

int main()
{
	LeerNumero(200);

	std::cout << "\n";
	
	LeerPersonas(rellenarVectorPersonas());

    std::cout << "\n";

    leerTarifa(leerHorasTrabajadas(30), 10);
}