//Cifrado Vigenere

// Los arreglos usados en este script son string ya que estos cuentan como arreglos de chars.
// Ejemplo: string ['H','o','l','a']#include <iostream>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstring>
using namespace std;
// Esta funcion se encarga del proceso para convertir la frase.
/* Lo primero que hace es igualar el pin que ingresa el usuario con la longitud que tiene la frase,
	y de esta manera tener la secuencia numerica que se utilizara para encriptar la frase. */
// Realizando la conversion por medio del cifrado Ascii.
void longitudPin(char frase[50], int pin) {
	int i = 0;
	string fraseNumerada;
	string pinString = to_string(pin);
	int internalIndex = 0;
	for(i = 0; i<strlen(frase); i++) {
		if(internalIndex == pinString.length()) {
			internalIndex = 0;
		}
		fraseNumerada = fraseNumerada + char(pinString[internalIndex]);
		internalIndex = internalIndex + 1;
	}
	cout << "\n- RESULTADOS DE ENCRIPTACION\n"<< endl;
	cout << "- Secuencia Encriptada: " << fraseNumerada << endl;
	string nuevaFrase;
	for(i=0; i<strlen(frase); i++) {
		string letra;
		letra.push_back(frase[i]);
		int codigoAscii = int(letra[0]);
		if(codigoAscii == 32) {
			nuevaFrase = nuevaFrase + letra;
		} else {
			string numero;
			numero.push_back(fraseNumerada[i]);
			int nuevoAscii = codigoAscii + stoi(numero);
			if(nuevoAscii >= 91) {
				nuevoAscii = nuevoAscii - 26;
			}
			nuevaFrase = nuevaFrase + char(nuevoAscii);
		}
	}
	cout << "- Resultado Encriptado: " << nuevaFrase << endl;
}

int main() {
	char frase[50], fraseMayuscula[50];
	int pin;
	cout << "- CODIGO VIGENERE\n\n";
	cout << "- Ingrese la frase que desea Encriptar: ";
	cin.getline(frase,50,'\n');
	for(int i = 0; i < strlen(frase); i++) {
		fraseMayuscula[i] = toupper(frase[i]);
	}
	cout << "- Ingrese el pin de encriptacion: ";
	cin >> pin;
	longitudPin(fraseMayuscula, pin);
	getch();
	return 0;
}