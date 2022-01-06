
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
using namespace std;
using namespace System;
void imprimirCuadro(int ancho, int alto, int x, int y) {
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);

			if (i == 0 && j == 0)cout << char(218);
			if (i == 0 && j == ancho - 1)cout << char(191);

			if (i == alto - 1 && j == 0)cout << char(192);
			if (i == alto - 1 && j == ancho - 1)cout << char(217);

			if ((j == 0 || j == ancho - 1) && i > 0 && i < alto - 1)
				cout << char(179);
			if ((i == 0 || i == alto - 1) && j > 0 && j < ancho - 1)
				cout << char(196);

		}
	}
}
void presentacionJuego() {
	int alto = 20;
	int ancho = 60;
	int cont = 0;
	int colores[] = { 4,1,6,2 };//mas oscuro
	//int colores[]={12,9,14,10};//mas claro
	while (!_kbhit()) {
		Console::ForegroundColor = ConsoleColor(colores[cont]);
		cont++;
		if (cont > 3)cont = 0;

		imprimirCuadro(ancho, alto, 45, 9);

		Console::SetCursorPosition(38 + ancho / 4, 9 + alto / 4);
		cout << "***       ***    ***  ******       ********  ";
		Console::SetCursorPosition(38 + ancho / 4, 10 + alto / 4);
		cout << "***       ***    ***  ***  ***    **********   ";
		Console::SetCursorPosition(38 + ancho / 4, 11 + alto / 4);
		cout << "***       ***    ***  ***   ***   ***    *** ";
		Console::SetCursorPosition(38 + ancho / 4, 12 + alto / 4);
		cout << "***       ***    ***  ***    ***  ***    ***";
		Console::SetCursorPosition(38 + ancho / 4, 13 + alto / 4);
		cout << "***       ***    ***  ***    ***  ***    ***";
		Console::SetCursorPosition(38 + ancho / 4, 14 + alto / 4);
		cout << "***       ***    ***  ***    ***  ***    ***";
		Console::SetCursorPosition(38 + ancho / 4, 15 + alto / 4);
		cout << "***       ***    ***  ***    ***  ***    ***";
		Console::SetCursorPosition(38 + ancho / 4, 16 + alto / 4);
		cout << "***       ***    ***  ***   ***   ***    ***";
		Console::SetCursorPosition(38 + ancho / 4, 17 + alto / 4);
		cout << "********  **********  ***  ***    **********";
		Console::SetCursorPosition(38 + ancho / 4, 18 + alto / 4);
		cout << "********   ********   ******       ******** ";


		Console::SetCursorPosition(68 + ancho / 4, 21 + alto / 4);
		cout << "Por ZeuCode";
		Console::ResetColor();
		Console::SetCursorPosition(40 + ancho / 4, 26 + alto / 4);
		cout << "Presionar cualquier tecla para continuar";
		Sleep(200);
		system("cls");

	}
}

int elegirOpcion(int opciones, int x, int y) {
	int tecla = 0;
	int limSuperior = y;
	int limInferior = y + opciones - 1;
	while (_kbhit()) { tecla = _getch(); }//para limpiar el buffer 
	tecla = 0;
	do {
		Console::SetCursorPosition(x, y);
		Console::ForegroundColor = ConsoleColor::DarkRed;
		cout << "<" << char(205);
		tecla = _getch();
		Console::SetCursorPosition(x, y); cout << "  ";
		switch (tecla) {
		case 72://arriba
			if (y - 1 < limSuperior) {
				y = limInferior;
				break;
			}
			y -= 1;
			break;
		case 80://abajo
			if (y + 1 > limInferior) {
				y = limSuperior;
				break;
			}
			y += 1;
			break;
		}
	} while (tecla != 13);
	Console::ResetColor();
	return y - limSuperior + 1;
}


int menuOpciones() {
	int alto = 12;
	int ancho = 54;
	char opcion = NULL;
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(53 + j, 10 + i);

			if (i == 0 && j == 0)cout << char(218);
			if (i == 0 && j == ancho - 1)cout << char(191);

			if (i == alto - 1 && j == 0)cout << char(192);
			if (i == alto - 1 && j == ancho - 1)cout << char(217);

			if ((j == 0 || j == ancho - 1) && i > 0 && i < alto - 1)
				cout << char(179);
			if ((i == 0 || i == alto - 1) && j > 0 && j < ancho - 1)
				cout << char(196);

		}
	}

	Console::SetCursorPosition(55, 12);
	cout << "Usar las teclas direccionales para mover la flecha";
	Console::SetCursorPosition(61, 13);
	cout << "Presionar enter para elegir una opcion";
	Console::SetCursorPosition(73, 15);
	cout << "1. Jugar";
	Console::SetCursorPosition(73, 16);
	cout << "2. Como jugar";
	Console::SetCursorPosition(73, 17);
	cout << "3. Creditos";
	Console::SetCursorPosition(73, 18);
	cout << "4. Salir";

	return elegirOpcion(4, 88, 15);
}




int elegirCantidadJugadores() {
	imprimirCuadro(37, 8, 55, 11);
	Console::SetCursorPosition(58, 13);
	cout << "Elegir la cantidad de jugadores";
	Console::SetCursorPosition(72, 15);
	cout << "2";
	Console::SetCursorPosition(72, 16);
	cout << "4";
	switch (elegirOpcion(2, 80, 15)) {
	case 1:
		return 2;
		break;
	case 2:
		return 4;
		break;
	default:
		return 0;//esto no sucede, pero lo pongo para evitar una advertenciaaa
	}
}

void imprimirTablero() {
	system("cls");


	Console::BackgroundColor = ConsoleColor::Green;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {

			Console::SetCursorPosition(44 + 4 * j, 4 + 2 * i);
			cout << "    ";
			Console::SetCursorPosition(44 + 4 * j, 4 + 2 * i + 1);
			cout << "    ";

		}
	}

	Console::BackgroundColor = ConsoleColor::White;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Console::SetCursorPosition(48 + 4 * j, 6 + 2 * i);
			cout << "    ";
			Console::SetCursorPosition(48 + 4 * j, 6 + 2 * i + 1);
			cout << "    ";

		}
	}
	Console::BackgroundColor = ConsoleColor::Red;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			Console::SetCursorPosition(81 + 4 * j, 4 + 2 * i);
			cout << "    ";
			Console::SetCursorPosition(81 + 4 * j, 4 + 2 * i + 1);
			cout << "    ";
		}
	}

	Console::BackgroundColor = ConsoleColor::White;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Console::SetCursorPosition(85 + 4 * j, 6 + 2 * i);
			cout << "    ";
			Console::SetCursorPosition(85 + 4 * j, 6 + 2 * i + 1);
			cout << "    ";

		}
	}

	Console::BackgroundColor = ConsoleColor::Yellow;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			Console::SetCursorPosition(44 + 4 * j, 21 + 2 * i);
			cout << "    ";
			Console::SetCursorPosition(44 + 4 * j, 21 + 2 * i + 1);
			cout << "    ";
		}
	}

	Console::BackgroundColor = ConsoleColor::White;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Console::SetCursorPosition(48 + 4 * j, 23 + 2 * i);
			cout << "    ";
			Console::SetCursorPosition(48 + 4 * j, 23 + 2 * i + 1);
			cout << "    ";

		}
	}

	Console::BackgroundColor = ConsoleColor::Blue;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			Console::SetCursorPosition(81 + 4 * j, 21 + 2 * i);
			cout << "    ";
			Console::SetCursorPosition(81 + 4 * j, 21 + 2 * i + 1);
			cout << "    ";
		}
	}

	Console::BackgroundColor = ConsoleColor::White;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Console::SetCursorPosition(85 + 4 * j, 23 + 2 * i);
			cout << "    ";
			Console::SetCursorPosition(85 + 4 * j, 23 + 2 * i + 1);
			cout << "    ";

		}
	}

	//posiciones

	Console::ForegroundColor = ConsoleColor::Black;
	Console::BackgroundColor = ConsoleColor::White;

	//vertical

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			switch (j) {
			case 0:
				Console::SetCursorPosition(68, 4 + 2 * i);
				cout << "    ";
				Console::SetCursorPosition(68, 4 + 2 * i + 1);
				cout << " " << char(196) << char(196) << char(196);
				break;
			case 1:

				Console::SetCursorPosition(72, 4 + 2 * i);
				cout << char(179);
				Console::BackgroundColor = ConsoleColor::Red;
				cout << "   ";
				Console::BackgroundColor = ConsoleColor::White;
				cout << char(179);
				Console::SetCursorPosition(72, 4 + 2 * i + 1);
				cout << char(179);
				Console::BackgroundColor = ConsoleColor::Red;
				cout << char(196) << char(196) << char(196);
				Console::BackgroundColor = ConsoleColor::White;
				cout << char(179);
				break;
			case 2:
				Console::SetCursorPosition(77, 4 + 2 * i);
				cout << "    ";
				Console::SetCursorPosition(77, 4 + 2 * i + 1);
				cout << char(196) << char(196) << char(196) << " ";
				break;

			}
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			switch (j) {
			case 0:
				Console::SetCursorPosition(68, 21 + 2 * i);
				cout << " " << char(196) << char(196) << char(196);
				Console::SetCursorPosition(68, 21 + 2 * i + 1);
				cout << "    ";
				break;
			case 1:
				Console::SetCursorPosition(72, 21 + 2 * i);
				cout << char(179);
				Console::BackgroundColor = ConsoleColor::Yellow;
				cout << char(196) << char(196) << char(196);
				Console::BackgroundColor = ConsoleColor::White;
				cout << char(179);
				Console::SetCursorPosition(72, 21 + 2 * i + 1);
				cout << char(179);
				Console::BackgroundColor = ConsoleColor::Yellow;
				cout << "   ";
				Console::BackgroundColor = ConsoleColor::White;
				cout << char(179);
				break;
			case 2:
				Console::SetCursorPosition(77, 21 + 2 * i);
				cout << char(196) << char(196) << char(196) << " ";
				Console::SetCursorPosition(77, 21 + 2 * i + 1);
				cout << "    ";
				break;

			}
		}
	}
	//horizontal
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			switch (j) {
			case 0:
				Console::SetCursorPosition(44 + 4 * i, 16 + 2 * j);
				cout << "   " << char(179);
				Console::SetCursorPosition(44 + 4 * i, 16 + 2 * j + 1);
				cout << char(196) << char(196) << char(196) << char(196);
				break;
			case 1:
				Console::BackgroundColor = ConsoleColor::Green;
				Console::SetCursorPosition(44 + 4 * i, 16 + 2 * j);
				cout << "   " << char(179);
				Console::BackgroundColor = ConsoleColor::White;
				Console::SetCursorPosition(44 + 4 * i, 16 + 2 * j + 1);
				cout << char(196) << char(196) << char(196) << char(196);
				break;
			case 2:
				Console::SetCursorPosition(44 + 4 * i, 16 + 2 * j);
				cout << "   " << char(179);
				break;

			}
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			switch (j) {
			case 0:
				Console::SetCursorPosition(81 + 4 * i, 16 + 2 * j);
				cout << char(179) << "   ";
				Console::SetCursorPosition(81 + 4 * i, 16 + 2 * j + 1);
				cout << char(196) << char(196) << char(196) << char(196);
				break;
			case 1:
				Console::BackgroundColor = ConsoleColor::Blue;
				Console::SetCursorPosition(81 + 4 * i, 16 + 2 * j);
				cout << char(179) << "   ";
				Console::BackgroundColor = ConsoleColor::White;
				Console::SetCursorPosition(81 + 4 * i, 16 + 2 * j + 1);
				cout << char(196) << char(196) << char(196) << char(196);

				break;
			case 2:
				Console::SetCursorPosition(81 + 4 * i, 16 + 2 * j);
				cout << char(179)<<"   ";
				break;

			}
		}
	}

	//flechas (metas)
	Console::BackgroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(70, 16);
	cout << "         ";
	Console::SetCursorPosition(72, 17);
	cout << "     ";

	Console::BackgroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(72, 19);
	cout << "     ";
	Console::SetCursorPosition(70, 20);
	cout << "         ";

	Console::BackgroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(68, 16);
	cout << "  ";
	Console::SetCursorPosition(68, 17);
	cout << "    ";
	Console::SetCursorPosition(68, 18);
	cout << "      ";
	Console::SetCursorPosition(68, 19);
	cout << "    ";
	Console::SetCursorPosition(68, 20);
	cout << "  ";

	Console::BackgroundColor = ConsoleColor::Blue;
	Console::SetCursorPosition(79, 16);
	cout << "  ";
	Console::SetCursorPosition(77, 17);
	cout << "    ";
	Console::SetCursorPosition(75, 18);
	cout << "      ";
	Console::SetCursorPosition(77, 19);
	cout << "    ";
	Console::SetCursorPosition(79, 20);
	cout << "  ";

	//salidas
	Console::SetCursorPosition(48, 16);
	Console::BackgroundColor = ConsoleColor::Green;
	cout << "   ";
	Console::SetCursorPosition(77, 6);
	Console::BackgroundColor = ConsoleColor::Red;
	cout << "   ";
	Console::SetCursorPosition(98, 20);
	Console::BackgroundColor = ConsoleColor::Blue;
	cout << "   ";
	Console::SetCursorPosition(69, 30);
	Console::BackgroundColor = ConsoleColor::Yellow;
	cout << "   ";


}

string* ingresarNombres(int cantidadJugadores) {
	system("cls");
	string* nombres = nullptr;
	nombres = new string[cantidadJugadores];
	for (int i = 0; i < cantidadJugadores; i++) {
		imprimirCuadro(37, 8, 55, 11);
		Console::SetCursorPosition(59, 13);
		cout << "Ingresar nombre del jugador " << i + 1;
		Console::SetCursorPosition(59, 15);
		getline(cin >> ws, nombres[i]);
		system("cls");
	}
	return nombres;
}



int* imprimirDevolverPosicionesIniciales(int cantidadJugadores, string nombres[], int posiciones[][2]) {
	int x = 52;
	int y = 8;
	int* jugadores = nullptr;
	jugadores = new int[cantidadJugadores];

	if (cantidadJugadores == 2) {
		jugadores[0] = rand() % 3;
		jugadores[1] = rand() % (4 - (jugadores[0] + 1)) + jugadores[0] + 1;
	}
	else {
		for (int i = 0; i < cantidadJugadores; i++) {
			jugadores[i] = i;
		}
	}
	for (int i = 0; i < cantidadJugadores; i++) {
		switch (jugadores[i]) {
		case 0:
			Console::BackgroundColor = ConsoleColor::Green;
			Console::SetCursorPosition(52, 8);
			cout << "GGG";
			Console::SetCursorPosition(57, 8);
			cout << "GGG";
			Console::SetCursorPosition(52, 11);
			cout << "GGG";
			Console::SetCursorPosition(57, 11);
			cout << "GGG";

			break;
		case 1:
			Console::BackgroundColor = ConsoleColor::Red;
			Console::SetCursorPosition(89, 8);
			cout << "RRR";
			Console::SetCursorPosition(94, 8);
			cout << "RRR";
			Console::SetCursorPosition(89, 11);
			cout << "RRR";
			Console::SetCursorPosition(94, 11);
			cout << "RRR";

			break;
		case 2:
			Console::BackgroundColor = ConsoleColor::Blue;
			Console::SetCursorPosition(89, 25);
			cout << "BBB";
			Console::SetCursorPosition(94, 25);
			cout << "BBB";
			Console::SetCursorPosition(89, 28);
			cout << "BBB";
			Console::SetCursorPosition(94, 28);
			cout << "BBB";
			break;
		case 3:
			Console::BackgroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(52, 25);
			cout << "YYY";
			Console::SetCursorPosition(57, 25);
			cout << "YYY";
			Console::SetCursorPosition(52, 28);
			cout << "YYY";
			Console::SetCursorPosition(57, 28);
			cout << "YYY";
			break;
		}


	}

	Console::ResetColor();
	for (int i = 0; i < cantidadJugadores; i++) {
		switch (jugadores[i]) {
		case 0:
			Console::SetCursorPosition(posiciones[0][0], posiciones[0][1]);
			cout << nombres[i];
			Console::SetCursorPosition(posiciones[0][0], posiciones[0][1] + 3);
			cout << "Lanzamientos: 0";
			break;
		case 1:
			Console::SetCursorPosition(posiciones[1][0], posiciones[1][1]);
			cout << nombres[i];
			Console::SetCursorPosition(posiciones[1][0], posiciones[1][1] + 3);
			cout << "Lanzamientos: 0";
			break;
		case 2:
			Console::SetCursorPosition(posiciones[2][0], posiciones[2][1]);
			cout << nombres[i];
			Console::SetCursorPosition(posiciones[2][0], posiciones[2][1] + 3);
			cout << "Lanzamientos: 0";
			break;
		case 3:
			Console::SetCursorPosition(posiciones[3][0], posiciones[3][1]);
			cout << nombres[i];
			Console::SetCursorPosition(posiciones[3][0], posiciones[3][1] + 3);
			cout << "Lanzamientos: 0";
			break;
		}
	}
	return jugadores;

}

int lanzarDado() {
	int numero = 0;
	int tecla = 0;
	Console::SetCursorPosition(71, 37);
	cout << "               ";
	//while (_kbhit()) { tecla = _getch(); }//para limpiar el buffer 
	//tecla = 0;
	//Console::BackgroundColor = ConsoleColor::Cyan;
	//Console::ForegroundColor = ConsoleColor::Black;
	do {
		Console::SetCursorPosition(60, 35);
		cout << "Presionar enter para lanzar el dado";
		tecla = _getch();
	} while (tecla != 13);
	Console::SetCursorPosition(60, 35);
	cout << "                                       ";
	numero = rand() % 6 + 1;
	Console::SetCursorPosition(71, 37);
	cout << "Salio un " << numero;
	return numero;
}


void imprimirTurno(string nombre) {
	Console::SetCursorPosition(75, 2);
	cout << "                                                ";
	Console::SetCursorPosition(67, 2);
	cout << "Turno de " << nombre;
}
void imprimirCantidadLanzamientos(int jugador, int posiciones[][2], int turno) {

	switch (jugador) {
	case 0:
		Console::SetCursorPosition(posiciones[0][0] + 14, posiciones[0][1] + 3);
		cout << turno;
		break;
	case 1:
		Console::SetCursorPosition(posiciones[1][0] + 14, posiciones[1][1] + 3);
		cout << turno;
		break;
	case 2:
		Console::SetCursorPosition(posiciones[2][0] + 14, posiciones[2][1] + 3);
		cout << turno;
		break;
	case 3:
		Console::SetCursorPosition(posiciones[3][0] + 14, posiciones[3][1] + 3);
		cout << turno;
		break;
	}

}

void llenarPosicionJugadores(int arreglo[4][4][2], int arregloOriginal[4][4][2]) {
	//[Jugador][Ficha][posicion(x,y)]
	//jugador 0, ficha 0, posicion x...
	//jugador 0, ficha 0, posicion y...
	//....

	arreglo[0][0][0] = 52;
	arreglo[0][0][1] = 8;
	arreglo[0][1][0] = 57;
	arreglo[0][1][1] = 8;
	arreglo[0][2][0] = 52;
	arreglo[0][2][1] = 11;
	arreglo[0][3][0] = 57;
	arreglo[0][3][1] = 11;

	arreglo[1][0][0] = 89;
	arreglo[1][0][1] = 8;
	arreglo[1][1][0] = 94;
	arreglo[1][1][1] = 8;
	arreglo[1][2][0] = 89;
	arreglo[1][2][1] = 11;
	arreglo[1][3][0] = 94;
	arreglo[1][3][1] = 11;

	arreglo[2][0][0] = 89;
	arreglo[2][0][1] = 25;
	arreglo[2][1][0] = 94;
	arreglo[2][1][1] = 25;
	arreglo[2][2][0] = 89;
	arreglo[2][2][1] = 28;
	arreglo[2][3][0] = 94;
	arreglo[2][3][1] = 28;

	arreglo[3][0][0] = 52;
	arreglo[3][0][1] = 25;
	arreglo[3][1][0] = 57;
	arreglo[3][1][1] = 25;
	arreglo[3][2][0] = 52;
	arreglo[3][2][1] = 28;
	arreglo[3][3][0] = 57;
	arreglo[3][3][1] = 28;

	//guardando las posiciones originales

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				arregloOriginal[i][j][k] = arreglo[i][j][k];
			}
		}
	}
}

int elegirFicha(int fichas[4][2], int jugador, int posicionesIniciales[4][2], bool esSeis) {

	int tecla = 0;
	int numFicha = 0;
	do {
		do {
			if ((fichas[numFicha][1] == 14 && (fichas[numFicha][0] <= 64 || fichas[numFicha][0] >= 85)) ||
				(fichas[numFicha][1] == 22 && (fichas[numFicha][0] <= 64 || fichas[numFicha][0] >= 85))) {
				numFicha++;
				if (numFicha > 3)numFicha = 0;
			}
			if (!esSeis) {
				while (fichas[numFicha][0] == posicionesIniciales[numFicha][0] && fichas[numFicha][1] == posicionesIniciales[numFicha][1]) {
					numFicha++;
					if (numFicha > 3)numFicha = 0;
				}
			}
		} while ((fichas[numFicha][1] == 14 && (fichas[numFicha][0] <= 64 || fichas[numFicha][0] >= 85)) ||
			(fichas[numFicha][1] == 22 && (fichas[numFicha][0] <= 64 || fichas[numFicha][0] >= 85)));





		Console::BackgroundColor = ConsoleColor::Magenta;
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(fichas[numFicha][0], fichas[numFicha][1]);
		switch (jugador) {
		case 0:
			cout << "GGG";
			break;
		case 1:
			cout << "RRR";
			break;
		case 2:
			cout << "BBB";
			break;
		case 3:
			cout << "YYY";
			break;
		}
		tecla = _getch();
		Console::SetCursorPosition(fichas[numFicha][0], fichas[numFicha][1]);
		Console::ForegroundColor = ConsoleColor::Black;
		if ((fichas[numFicha][0] == posicionesIniciales[numFicha][0] && fichas[numFicha][1] == posicionesIniciales[numFicha][1]) ||
			fichas[numFicha][0] == 73 || fichas[numFicha][1] == 18) {
			switch (jugador) {
			case 0:
				Console::BackgroundColor = ConsoleColor::Green;
				cout << "GGG";
				break;
			case 1:
				Console::BackgroundColor = ConsoleColor::Red;
				cout << "RRR";
				break;
			case 2:
				Console::BackgroundColor = ConsoleColor::Blue;
				cout << "BBB";
				break;
			case 3:
				Console::BackgroundColor = ConsoleColor::Yellow;
				cout << "YYY";
				break;
			}
		}
		else {
			Console::BackgroundColor = ConsoleColor::White;
			switch (jugador) {
			case 0:
				cout << "GGG";
				break;
			case 1:
				cout << "RRR";
				break;
			case 2:
				cout << "BBB";
				break;
			case 3:
				cout << "YYY";
				break;
			}
		}

		if (tecla == 32) {
			numFicha++;
			if (numFicha > 3)numFicha = 0;
		}

	} while (tecla == 32 && tecla != 13);
	Console::ResetColor();
	return numFicha;

}
bool mover(int pasos, int ficha[], int jugador, bool& gameOver, int fichas[][2], int posicionJugadores[][4][2], int numFicha, int cantidadJugadores, int jugadores[], int posicionesIniciales[][4][2]) {
	//se devolvera true solo si se debe perder el turno

	int marca = 0;
	int x = ficha[0];//guardar las posicionesAnteriores
	int y = ficha[1];
	bool pierdeTurno = false;
	Console::ForegroundColor = ConsoleColor::Black;
	if (ficha[0] == 73) {
		if (ficha[1] <= 16) { Console::BackgroundColor = ConsoleColor::Red; }
		else { Console::BackgroundColor = ConsoleColor::Yellow; }
	}
	else if (ficha[1] == 18) {
		if (ficha[0] <= 68) {
			Console::BackgroundColor = ConsoleColor::Green;
		}
		else {
			Console::BackgroundColor = ConsoleColor::Blue;
		}
	}
	else {
		Console::BackgroundColor = ConsoleColor::White;
	}

	if (ficha[0] == 48 && ficha[1] == 16)Console::BackgroundColor = ConsoleColor::Green;
	if (ficha[0] == 77 && ficha[1] == 6)Console::BackgroundColor = ConsoleColor::Red;
	if (ficha[0] == 98 && ficha[1] == 20)Console::BackgroundColor = ConsoleColor::Blue;
	if (ficha[0] == 69 && ficha[1] == 30)Console::BackgroundColor = ConsoleColor::Yellow;

	Console::SetCursorPosition(ficha[0], ficha[1]);
	cout << "   ";
	if (ficha[1] == 16) {
		if (ficha[0] <= 64) {
			if (ficha[0] + pasos * 4 > 64) {
				marca = (64 - ficha[0]) / 4;
				ficha[0] = 69;
				ficha[1] = 14 - ((pasos - marca - 1) * 2);
			}
			else {
				ficha[0] += pasos * 4;
			}
		}
		else {
			if (ficha[0] + pasos * 4 > 102) {
				marca = (102 - ficha[0]) / 4;
				ficha[0] = 102 - ((pasos - marca - 1) * 4);
				if (jugador == 2) {

					ficha[1] = 18;
				}
				else {
					ficha[1] = 20;
				}
			}
			else {
				ficha[0] += pasos * 4;
			}
		}
	}
	else
		if (ficha[1] == 20) {
			if (ficha[0] <= 64) {
				if (ficha[0] - pasos * 4 < 44) {
					marca = (ficha[0] - 44) / 4;
					ficha[0] = 44 + ((pasos - marca - 1) * 4);
					if (jugador == 0) {
						ficha[1] = 18;
					}
					else {
						ficha[1] = 16;
					}
				}
				else {
					ficha[0] -= pasos * 4;
				}
			}
			else {
				if (ficha[0] - pasos * 4 < 82) {
					marca = (ficha[0] - 82) / 4;
					ficha[0] = 77;
					ficha[1] = 22 + ((pasos - marca - 1) * 2);
				}
				else {
					ficha[0] -= pasos * 4;
				}
			}
		}
		else
			if (ficha[0] == 69) {
				if (ficha[1] <= 14) {
					if (ficha[1] - pasos * 2 < 4) {
						marca = (ficha[1] - 4) / 2;
						ficha[1] = 4 + ((pasos - marca - 1) * 2);
						if (jugador == 1) {
							ficha[0] = 73;
						}
						else {
							ficha[0] = 77;
						}
					}
					else {
						ficha[1] -= pasos * 2;
					}
				}
				else {
					if (ficha[1] - pasos * 2 < 22) {
						marca = (ficha[1] - 22) / 2;
						ficha[0] = 64 - ((pasos - marca - 1) * 4);
						ficha[1] = 20;
					}
					else {
						ficha[1] -= pasos * 2;
					}
				}
			}
			else
				if (ficha[0] == 77) {
					if (ficha[1] <= 14) {
						if (ficha[1] + pasos * 2 > 14) {
							marca = (14 - ficha[1]) / 2;
							ficha[0] = 82 + ((pasos - marca - 1) * 4);
							ficha[1] = 16;
						}
						else {
							ficha[1] += pasos * 2;
						}
					}
					else {
						if (ficha[1] + pasos * 2 > 32) {
							marca = (32 - ficha[1]) / 2;
							ficha[1] = 32 - ((pasos - marca - 1) * 2);
							if (jugador == 3) {
								ficha[0] = 73;
							}
							else {
								ficha[0] = 69;
							}
						}
						else {
							ficha[1] += pasos * 2;
						}
					}
				}
				else {
					if (ficha[0] == 73) {
						if (ficha[1] <= 14) {
							if (ficha[1] + pasos * 2 > 16) {
								marca = (16 - ficha[1]) / 2;
								ficha[1] = 14 - ((pasos - marca - 1) * 2);
							}
							else {
								ficha[1] += pasos * 2;
							}
						}
						else {
							if (ficha[1] - pasos * 2 < 20) {
								marca = (ficha[1] - 20) / 2;
								ficha[1] = 22 + ((pasos - marca - 1) * 2);
							}
							else {
								ficha[1] -= pasos * 2;
							}
						}
					}
					else if (ficha[1] == 18) {
						if (ficha[0] <= 64) {
							if (ficha[0] + pasos * 4 > 68) {
								marca = (68 - ficha[0]) / 4;
								ficha[0] = 64 - ((pasos - marca - 1) * 4);
							}
							else {
								ficha[0] += pasos * 4;
							}
						}
						else {
							if (ficha[0] - pasos * 4 < 78) {
								marca = (ficha[0] - 78) / 4;
								ficha[0] = 82 + ((pasos - marca - 1) * 4);
							}
							else {
								ficha[0] -= pasos * 4;
							}
						}
					}
				}

	for (int i = 0; i < 4; i++) {
		if (i != numFicha) {
			if (fichas[i][0] == ficha[0] && fichas[i][1] == ficha[1]) {
				ficha[0] = x;
				ficha[1] = y;
				pierdeTurno = true;
				break;
			}
		}
	}
	for (int i = 0; i < cantidadJugadores; i++) {//comer fichas rivales
		if (jugadores[i] != jugador) {
			for (int j = 0; j < 4; j++) {
				if (posicionJugadores[jugadores[i]][j][0] == ficha[0] && posicionJugadores[jugadores[i]][j][1] == ficha[1]) {
					posicionJugadores[jugadores[i]][j][0] = posicionesIniciales[jugadores[i]][j][0];
					posicionJugadores[jugadores[i]][j][1] = posicionesIniciales[jugadores[i]][j][1];
					Console::SetCursorPosition(posicionJugadores[jugadores[i]][j][0], posicionJugadores[jugadores[i]][j][1]);
					switch (jugadores[i]) {
					case 0:
						Console::BackgroundColor = ConsoleColor::Green;
						cout << "GGG";
						break;
					case 1:
						Console::BackgroundColor = ConsoleColor::Red;
						cout << "RRR";
						break;
					case 2:
						Console::BackgroundColor = ConsoleColor::Blue;
						cout << "BBB";
						break;
					case 3:
						Console::BackgroundColor = ConsoleColor::Yellow;
						cout << "YYY";
						break;
					}
					break;
				}
			}
		}
	}

	if (ficha[0] == 73) {
		if (ficha[1] <= 16) { Console::BackgroundColor = ConsoleColor::Red; }
		else { Console::BackgroundColor = ConsoleColor::Yellow; }
	}
	else if (ficha[1] == 18) {
		if (ficha[0] <= 68) {
			Console::BackgroundColor = ConsoleColor::Green;
		}
		else {
			Console::BackgroundColor = ConsoleColor::Blue;
		}
	}
	else {
		Console::BackgroundColor = ConsoleColor::White;
	}

	if (ficha[0] == 48 && ficha[1] == 16)Console::BackgroundColor = ConsoleColor::Green;
	if (ficha[0] == 77 && ficha[1] == 6)Console::BackgroundColor = ConsoleColor::Red;
	if (ficha[0] == 98 && ficha[1] == 20)Console::BackgroundColor = ConsoleColor::Blue;
	if (ficha[0] == 69 && ficha[1] == 30)Console::BackgroundColor = ConsoleColor::Yellow;

	if ((ficha[0] == 68 && ficha[1] == 18) ||
		(ficha[0] == 73 && ficha[1] == 16) ||
		(ficha[0] == 78 && ficha[1] == 18) ||
		(ficha[0] == 73 && ficha[1] == 20)) {
		int cont = 0;//para contar fichas que ya llegaron a la meta
		for (int i = 0; i < 4; i++) {
			if (fichas[i][1] == 14) {
				if (fichas[i][0] <= 64) cont++;
				else if (fichas[i][0] >= 85)cont++;
			}
			else if (fichas[i][1] == 22) {
				if (fichas[i][0] <= 64)cont++;
				else if (fichas[i][0] >= 85)cont++;
			}
		}
		switch (jugador) {
		case 0:
			ficha[0] = 48 + cont * 4;
			ficha[1] = 14;
			break;
		case 1:
			ficha[0] = 85 + cont * 4;
			ficha[1] = 14;
			break;
		case 2:
			ficha[0] = 85 + cont * 4;
			ficha[1] = 22;
			break;
		case 3:
			ficha[0] = 48 + cont * 4;
			ficha[1] = 22;
			break;

		}
		cont++;
		if (cont == 4) {
			gameOver = true;
			cout << "\a";
		}
	}

	Console::SetCursorPosition(ficha[0], ficha[1]);
	switch (jugador) {
	case 0:
		cout << "GGG";
		break;
	case 1:
		cout << "RRR";
		break;
	case 2:
		cout << "BBB";
		break;
	case 3:
		cout << "YYY";
		break;
	}
	Console::ResetColor();
	return pierdeTurno;
}



bool estaEnBase(int ficha[], int posicionesIniciales[2]) {
	for (int i = 0; i < 2; i++) {
		if (ficha[i] != posicionesIniciales[i])return false;
	}
	return true;
}
void salirDeBase(int ficha[], int jugador, int cantidadJugadores, int jugadores[], int posicionJugadores[][4][2], int posicionesIniciales[][4][2]) {
	Console::SetCursorPosition(ficha[0], ficha[1]);
	Console::BackgroundColor = ConsoleColor::White;
	Console::ForegroundColor = ConsoleColor::Black;
	cout << "   ";
	switch (jugador) {
	case 0:
		ficha[0] = 48; ficha[1] = 16;
		break;
	case 1:
		ficha[0] = 77; ficha[1] = 6;
		break;
	case 2:
		ficha[0] = 98; ficha[1] = 20;
		break;
	case 3:
		ficha[0] = 69; ficha[1] = 30;
		break;

	}

	for (int i = 0; i < cantidadJugadores; i++) {//comer rival en la posicion de salida
		if (jugadores[i] != jugador) {
			for (int j = 0; j < 4; j++) {
				if (posicionJugadores[jugadores[i]][j][0] == ficha[0] && posicionJugadores[jugadores[i]][j][1] == ficha[1]) {
					posicionJugadores[jugadores[i]][j][0] = posicionesIniciales[jugadores[i]][j][0];
					posicionJugadores[jugadores[i]][j][1] = posicionesIniciales[jugadores[i]][j][1];
					Console::SetCursorPosition(posicionJugadores[jugadores[i]][j][0], posicionJugadores[jugadores[i]][j][1]);
					switch (jugadores[i]) {
					case 0:
						Console::BackgroundColor = ConsoleColor::Green;
						cout << "GGG";
						break;
					case 1:
						Console::BackgroundColor = ConsoleColor::Red;
						cout << "RRR";
						break;
					case 2:
						Console::BackgroundColor = ConsoleColor::Blue;
						cout << "BBB";
						break;
					case 3:
						Console::BackgroundColor = ConsoleColor::Yellow;
						cout << "YYY";
						break;
					}
					break;
				}
			}
		}
	}


	Console::SetCursorPosition(ficha[0], ficha[1]);
	switch (jugador) {
	case 0:
		Console::BackgroundColor = ConsoleColor::Green;
		cout << "GGG";
		break;
	case 1:
		Console::BackgroundColor = ConsoleColor::Red;
		cout << "RRR";
		break;
	case 2:
		Console::BackgroundColor = ConsoleColor::Blue;
		cout << "BBB";
		break;
	case 3:
		Console::BackgroundColor = ConsoleColor::Yellow;
		cout << "YYY";
		break;
	}
	Console::ResetColor();
}

//struct {
//	int fichas[4][2];
//	string nombre;
//	int posicionInicial[4][2];
//	int lanzamientos;
//};
bool posicionInicialOcupada(int jugador, int fichas[4][2]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			switch (jugador) {
			case 0:
				if (fichas[i][0] == 48 && fichas[i][1] == 16)return true;
				break;
			case 1:
				if (fichas[i][0] == 77 && fichas[i][1] == 6)return true;
				break;
			case 2:
				if (fichas[i][0] == 98 && fichas[i][1] == 20)return true;
				break;
			case 3:
				if (fichas[i][0] == 69 && fichas[i][1] == 30)return true;
				break;
			}
		}
	}
	return false;
}
bool fueraDeBase(int fichas[4][2], int posicionesIniciales[4][2]) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {

			if (!((fichas[i][1] == 14 && (fichas[i][0] <= 64 || fichas[i][0] >= 85)) ||
				(fichas[i][1] == 22 && (fichas[i][0] <= 64 || fichas[i][0] >= 85)))) {
				if (fichas[i][j] != posicionesIniciales[i][j])return true;
			}
		}
	}
	return false;
}
bool jugar(int cantidadJugadores, int* jugadores, string nombres[], int posicionNombres[][2], string& ganador) {
	bool gameOver = false;
	int iterador = 0;
	int* lanzamientos = new int[cantidadJugadores];
	for (int i = 0; i < cantidadJugadores; i++) {
		lanzamientos[i] = 0;
	}
	int pasos = 0;
	int posicionJugadores[4][4][2];//[Jugadores][Fichas][posiciones(x,y)]
	int seisSeguidos = 0;
	int posicionesIniciales[4][4][2];
	int fichaElegida = 0;
	llenarPosicionJugadores(posicionJugadores, posicionesIniciales);

	while (!gameOver) {

		imprimirTurno(nombres[iterador]);

		do {
			pasos = lanzarDado();
			lanzamientos[iterador]++;
			imprimirCantidadLanzamientos(jugadores[iterador], posicionNombres, lanzamientos[iterador]);
			if (pasos == 6) {
				seisSeguidos++;
				if (seisSeguidos == 3) {
					system("pause>nul");
					break;
				}
				//si se quisiera seguir jugando despues de haber un ganador
				//se debe validar el caso en que un player tenga sus 4 fichas en meta y hacer un break

				fichaElegida = elegirFicha(posicionJugadores[jugadores[iterador]], jugadores[iterador], posicionesIniciales[jugadores[iterador]], true);

				if (estaEnBase(posicionJugadores[jugadores[iterador]][fichaElegida], posicionesIniciales[jugadores[iterador]][fichaElegida])) {
					if (!posicionInicialOcupada(jugadores[iterador], posicionJugadores[jugadores[iterador]])) {
						salirDeBase(posicionJugadores[jugadores[iterador]][fichaElegida], jugadores[iterador], cantidadJugadores, jugadores, posicionJugadores, posicionesIniciales);
					}
					else {
						break;
					}
				}
				else {
					if (mover(pasos, posicionJugadores[jugadores[iterador]][fichaElegida], jugadores[iterador], gameOver, posicionJugadores[jugadores[iterador]], posicionJugadores, fichaElegida, cantidadJugadores, jugadores, posicionesIniciales)) {
						break;
					}
				}
			}
			else {
				if (fueraDeBase(posicionJugadores[jugadores[iterador]], posicionesIniciales[jugadores[iterador]])) {
					fichaElegida = elegirFicha(posicionJugadores[jugadores[iterador]], jugadores[iterador], posicionesIniciales[jugadores[iterador]], false);
					if (mover(pasos, posicionJugadores[jugadores[iterador]][fichaElegida], jugadores[iterador], gameOver, posicionJugadores[jugadores[iterador]], posicionJugadores, fichaElegida, cantidadJugadores, jugadores, posicionesIniciales)) {
						break;
					}
				}
				else {
					system("pause>nul");
				}
			}

		} while (pasos == 6&&!gameOver);
		seisSeguidos = 0;
		if (gameOver) {
			ganador = nombres[iterador];
		}
		iterador++;
		if (iterador >= cantidadJugadores) {
			iterador = 0;
		}
	}
	return gameOver;
}

void comoJugar() {
	imprimirCuadro(94, 30, 33, 5);
	Console::SetCursorPosition(72, 7);
	cout << "Como jugar";
	Console::SetCursorPosition(36, 9);
	cout << "- Antes de iniciar la partida debera elegir la cantidad de jugadores(2 o 4)";
	Console::SetCursorPosition(36, 11);
	cout << "- Luego debe ingresar los nombres de los jugadores";
	Console::SetCursorPosition(36, 13);
	cout << "- Al iniciar la partida todos los jugadores tienen 4 fichas";
	Console::SetCursorPosition(36, 15);
	cout << "- Cada jugador en su turno debe lanzar el dado, el 6 indica la salida";
	Console::SetCursorPosition(36, 17);
	cout << "- Cuando pueda elegir una ficha para jugar, debera presionar la barra espaciadora para";
	Console::SetCursorPosition(36, 18);
	cout << "  alternar entre las disponibles para jugar en ese momento(enter para seleccionarla)";
	Console::SetCursorPosition(36, 20);
	cout << "- Un jugador no puede tener mas de una ficha en una misma casilla,";
	Console::SetCursorPosition(36, 21);
	cout << "  si un turno obtiene un numero que da como destino una casilla con una ficha propia";
	Console::SetCursorPosition(36, 22);
	cout << "  no se puede mover y se pierde el turno";
	Console::SetCursorPosition(36, 24);
	cout << "- Un jugador puede comer(regresar a su base) una ficha rival, si ocupa la misma casilla";
	Console::SetCursorPosition(36, 26);
	cout << "- Cuando una ficha llega a la vertical de su color esta segura(no puede ser comida)";
	Console::SetCursorPosition(36, 28);
	cout << "- El juego termina cuando un jugador consigue llevar sus 4 fichas a la meta";

	Console::SetCursorPosition(60, 31);
	cout << "Presione cualquier tecla para continuar";
	system("pause>nul");
	system("cls");
}
void creditos() {
	imprimirCuadro(60, 18, 45, 11);
	Console::SetCursorPosition(71, 13);
	cout << "Creditos";
	Console::SetCursorPosition(51, 15);
	cout << "- Proyecto realizado en el lenguaje C++/CLI";
	Console::SetCursorPosition(51, 17);
	cout << "- El IDE utilizado fue Visual Studio 2022";
	Console::SetCursorPosition(51, 19);
	cout << "- Tipo de proyecto: Proyecto vacio de CLR";
	Console::SetCursorPosition(51, 20);
	cout << "  (.NET Framework)";
	Console::SetCursorPosition(51, 22);
	cout << "- Proyecto realizado en su totalidad por ZeuCode";

	Console::SetCursorPosition(56, 25);
	cout << "Presione cualquier tecla para continuar";
	system("pause>nul");
	system("cls");
}
void despedida() {
	imprimirCuadro(50, 12, 49, 12);
	Console::SetCursorPosition(62, 15);
	cout << "Gracias por jugar LUDO" << endl;
	Console::SetCursorPosition(55, 19);
	cout << "Presione cualquier tecla para continuar";
	system("pause>nul");
	system("cls");
}
void imprimirGanador(string nombre) {
	system("cls");
	imprimirCuadro(40, 11, 54, 13);
	Console::SetCursorPosition(64, 17);
	cout << "Felicidades " << nombre;
	Console::SetCursorPosition(67, 19);
	cout << "Has ganado!!!";
	system("pause>nul");
}
int main() {
	srand(time(NULL));
	Console::CursorVisible = false;
	Console::SetWindowSize(150, 42);
	presentacionJuego();
	int opcion = 0;
	int cantidadJugadores = 0;
	string* nombres;
	int posicionNombres[4][2];//[x][y]
	posicionNombres[0][0] = 22;
	posicionNombres[0][1] = 8;
	posicionNombres[1][0] = 110;
	posicionNombres[1][1] = 8;
	posicionNombres[2][0] = 110;
	posicionNombres[2][1] = 25;
	posicionNombres[3][0] = 22;
	posicionNombres[3][1] = 25;
	int* jugadores = nullptr;
	bool salir = false;

	string ganador;


	while (!salir) {
		opcion = menuOpciones();
		system("cls");
		switch (opcion)
		{
		case 1:
			cantidadJugadores = elegirCantidadJugadores();
			nombres = ingresarNombres(cantidadJugadores);
			imprimirTablero();
			jugadores = imprimirDevolverPosicionesIniciales(cantidadJugadores, nombres, posicionNombres);
			salir = jugar(cantidadJugadores, jugadores, nombres, posicionNombres, ganador);
			imprimirGanador(ganador);
			break;
		case 2:
			comoJugar();
			break;
		case 3:
			creditos();
			break;
		case 4:
			despedida();
			return 0;
			break;
		}
	}
	return 0;
}