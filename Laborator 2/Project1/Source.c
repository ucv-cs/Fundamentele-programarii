#include<stdio.h>
#include<conio.h>
#include<math.h>
#pragma warning(disable: 4996 6031) //suprima avertizarile VS: "deprecation" si "scanf not used return value"

//prototipuri de functii
void equation1_solution();
void equation2_solution();
int check_power2();
void sort_3ints();

void main() {
	equation1_solution();
	equation2_solution();
	check_power2();
	sort_3ints();

	//...
	printf("\n\nApasa orice tasta pentru a inchide aplicatia...");
	_getch();
}

/**
 * Calculeaza si afiseaza solutia ecuatiei de gradul I, folosind datele introduse de la tastatura.
 **/
void equation1_solution() {
	//algoritm: ax + b = 0 => x = - b/a

	//notifica utilizatorul despre tema
	printf("Tema 1: Calculati solutia ecuatiei de gradul I, folosind datele introduse de la tastatura.\n");

	//declara variabilele pentru coeficienti
	float a, b;

	//obtine coeficientii ecuatiei
	while (1) {
		printf("Scrie coeficientii ecuatiei (a nu poate fi 0):\na = ");
		scanf("%f", &a); //a
		printf("b = ");
		scanf("%f", &b); //b
		if (a == 0) {
			printf("\na nu poate fi 0. Mai incearca o data!\n\n");
		} else {
			break;
		}
	}

	//declara si initializeaza solutia ecuatiei
	float x = -b / a;

	//afiseaza rezultatul
	printf("\nSolutia ecuatiei %gx + %g = 0 este:\nx = %g", a, b, x); //%g afiseaza zecimalele unui float numai daca ele exista (cea mai scurta reprezentare a numarului)
}

/**
 * Calculeaza si afiseaza solutia ecuatiei de gradul II, folosind datele introduse de la tastatura.
 **/
void equation2_solution() {
	/*algoritm: ax^2 + bx + c = 0 =>
		x1 = (- b + sqrt(b^2 - 4ac))/2a
		x2 = (- b - sqrt(b^2 - 4ac))/2a
	*/

	//notifica utilizatorul despre tema
	printf("\n\n------------------\nTema 2: Calculati solutia ecuatiei de gradul II, folosind datele introduse de la tastatura.\n");

	//declara variabilele pentru coeficienti
	float a, b, c;

	//obtine coeficientii ecuatiei
	while (1) {
		printf("Scrie coeficientii ecuatiei (a nu poate fi 0):\na = ");
		scanf("%f", &a); //a
		printf("b = ");
		scanf("%f", &b); //b
		printf("c = ");
		scanf("%f", &c); //c
		if (a == 0) {
			printf("\na nu poate fi 0. Mai incearca o data!\n\n");
		} else {
			break;
		}
	}

	//calculeaza discriminantul
	float delta = pow(b, 2) - 4 * a * c;

	//afiseaza rezultatul
	if (delta < 0) { //daca delta este negativ, solutiile ecuatiei sunt complexe; se putea folosi si isnan(sqrt(delta))
		printf("\nEcuatia %gx^2 + %gx + %g = 0 nu are solutii in R", a, b, c);
	} else {
		float x1 = (-b + sqrt(delta)) / 2 * a;
		float x2 = (-b - sqrt(delta)) / 2 * a;
		if (x1 != x2) {
			printf("\nSolutiile ecuatiei %gx^2 + %gx + %g = 0 sunt: \nx1 = %g\nx2 = %g", a, b, c, x1, x2);
		} else {
			printf("\nSolutiile ecuatiei %gx^2 + %gx + %g = 0 sunt: \nx1 = x2 = %g", a, b, c, x1);
		}
	}
}

/**
 * Verifica daca un numar introdus de la tastatura este putere a lui 2, folosind operatii pe biti.
 **/
int check_power2() {
	/*algoritm:
	- observam:
	0000 0000 = 0
	0000 0001 = 1 //2^0
	0000 0010 = 2 //2^1
	0000 0011 = 3
	0000 0100 = 4 //2^2
	0000 0101 = 5
	0000 0110 = 6
	0000 0111 = 7
	0000 1000 = 8 //2^3
	0000 1001 = 9
	0000 1010 = 10
	0000 1011 = 11
	0000 1100 = 12
	0000 1101 = 13
	0000 1110 = 14
	0000 1111 = 15
	0001 0000 = 16 //2^4 ...

	- puterile lui 2 sunt de forma 00...100...0, deci contin un singur bit 1, restul 0
	- numerele impare au ca ultim bit 1 (toate puterile lui 2, fiind pare, trebuie sa aiba ca ultim bit 0);
		- verificarea s-ar face cu & 1 (par, deci ...0, numai daca rezultatul operatiei este 0)
	- a >> 1 are ca rezultat catul impartirii a / 2; ex. 13 / 2 = 6
	- deci putem folosi >> 1 pentru a reduce numarul prin impartiri succesive la 2 (numai impartirile de numere pare vor conta)
	- calculul se opreste cand ajungem la 1 = 2^0
	v. https://www.exploringbinary.com/ten-ways-to-check-if-an-integer-is-a-power-of-two-in-c/
	*/

	//notifica utilizatorul despre tema
	printf("\n\n------------------\nTema 3: Verificati daca un numar introdus de la tastatura este putere a lui 2, folosind operatii pe biti.\n");

	//declara variabila
	unsigned int number, temp, exponent;
	exponent = 0;

	//obtine numarul
	printf("Scrie un numar natural:\na = ");
	scanf("%d", &number); //number
	temp = number; //pastram number pentru a fi folosit la afisarea rezultatului

	//verificare: cat timp numarul este par si mai mare de 1, executa >> 1 si creste exponentul cu 1
	while (((temp & 1) == 0) && (temp > 1)) {
		temp >>= 1; //temp = temp >> 1;
		exponent++;
	}

	//afiseaza rezultatul verificarii
	if (temp == 1) {
		printf("\n%d este o putere a lui 2: %d = 2^%d.\n\n", number, number, exponent);
	} else {
		printf("\n%d nu este o putere a lui 2.\n\n", number);
	}

}

/**
 * Citeste trei numere introduse de la tastatura si le afiseaza in ordine crescatoare (folosind if).
 **/
void sort_3ints() {
	/*algoritm: v. https://pages.mtu.edu/~shene/COURSES/cs201/NOTES/chap03/sort.html
	*/

	//notifica utilizatorul despre tema
	printf("\n\n------------------\nTema 4: Cititi trei numere introduse de la tastatura si afisati-le in ordine crescatoare (folosind if).\n");

	//declara variabilele
	float a, b, c;
	float x, y, z; //in loc de array, folosesc un numar de variabile egal cu inputul, a caror ordine este data (x <= y <= z)...

	//obtine numerele
	while (1) {
		printf("Scrie numerele de sortat:\na = ");
		scanf("%f", &a); //a
		printf("b = ");
		scanf("%f", &b); //b
		printf("c = ");
		scanf("%f", &c); //c

		//asociere implicita care va fi modificata dupa if-uri
		// a b c
		x = a;
		y = b;
		z = c;

		/* combinatii posibile:
		a b c * implicita
		a c b *
		b a c **
		b c a *
		c a b *
		c b a **
		*/

		//verificari
		// a b c
		if (a < b) {
			if (a < c) {
				if (b > c) { // a c b
					y = c;
					z = b;
				}
			} else {
				// c a b
				x = c;
				y = a;
				z = b;
			}
		} else {
			if (b < c) {
				if (a < c) {
					// b a c
					x = b;
					y = a;
				} else {
					// b c a
					x = b;
					y = c;
					z = a;
				}
			} else {
				// c b a
				x = c;
				z = a;
			}
		}

		printf("\nNumerele sortate sunt: %g %g %g\n----------\n", x, y, z);
	}
}

/*
N.B.: atentie la felul cum C face calculele cu intregi:
	int a = 2;
	int b = 3;
	float c = -b / a;
	printf("%g\n", c); //-1.0

	c = -(float)b / (float)a;
	printf("%g\n", c); //-1.5
*/
