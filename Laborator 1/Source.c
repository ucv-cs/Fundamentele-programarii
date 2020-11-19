#include<stdio.h>
#include<conio.h>
#include<math.h>
#pragma warning(disable: 4996 6031) //suprima avertizarile VS: "deprecation" si "scanf not used return value"

//prototipuri de functii...
void deg2rad();
void distance();

void main() {
	//Tema 1
	deg2rad(); //vulnerabil la date de tip invalid; nu validam inputul...

	//Tema 2
	distance(); //idem

	//...
	printf("\n\nApasa ENTER pentru a inchide aplicatia...");
	_getch();
}

/**
 * Tema 1: calculati si afisati transformarea unui unghi din grade in radiani, 
 * cu valoarea in grade a unghiului introdusa de la tasatatura.
 **/
void deg2rad() {
	//notifica utilizatorul ca incepe tema
	printf("Tema 1:\n");

	//defineste constanta pi si declara variabila pentru valoarea gradelor de convertit
	const float PI = 3.14159265358979f;
	float degrees;

	//obtine unghiul in grade de la utilizator
	printf("Scrie unghiul in grade: ");
	scanf("%f", &degrees);

	//converteste gradele in radiani
	//v. https://en.wikipedia.org/wiki/Radian
	float radians = degrees * PI / 180;

	//afiseaza valoarea in radiani
	printf("Rezultatul conversiei este: %.2f grade = %.4f radiani", degrees, radians);
}

/**
 * Tema 2: calculati si afisati distanta dintre doua puncte in plan, A si B, 
 * cu coordonatele punctelor introduse de la tastatura.
 **/
void distance() {
	//notifica utilizatorul ca incepe tema
	printf("\n\nTema 2:\n");

	//defineste variabilele pentru coordonate
	float ax, ay, bx, by;

	//obtine coordonatele punctului A din tastatura
	printf("Scrie coordonatele lui A:\n");
	printf("\tx = ");
	scanf("%f", &ax);
	printf("\ty = ");
	scanf("%f", &ay);

	//obtine coordonatele punctului B din tastatura
	printf("Scrie coordonatele lui B:\n");
	printf("\tx = ");
	scanf("%f", &bx);
	printf("\ty = ");
	scanf("%f", &by);

	//calculeaza catetele triunghiului dreptunghic format de coordonate
	//v. https://en.wikipedia.org/wiki/Euclidean_distance#Two_dimensions
	float dx = bx - ax; //delta x
	float dy = by - ay; //delta y

	//calculeaza ipotenuza triunghiului, date fiind catetele - cf. teoremei lui Pitagora
	float ab = sqrt(pow(dx, 2) + pow(dy, 2));

	//afisam distanta
	printf("Distanta dintre A(%.2f, %.2f) si B(%.2f, %.2f) este %.4f", ax, ay, bx, by, ab);
}
