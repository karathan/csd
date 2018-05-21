/* Καραθανάσης Δημήτρης
Άσκηση1
translate.c */

#include <stdio.h>

#define CAP_M 204
#define CAP_N 205
#define CAP_P 208
#define CAP_T 212
#define SMALL_M 236
#define SMALL_N 237
#define SMALL_P 240
#define SMALL_T 244



void GrToLatin(int c){                                     /*Συναρτηση αντικαταστασης ολων των χαρακτηρων*/
	if (c==193){
	putchar('A');
	}
	else if (c==194){
	putchar('V');
	}
	else if (c==195){
	putchar('G');
	}
	else if (c==196){
	putchar('D');
	}
	else if (c==197){
	putchar('E');
	}
	else if (c==198){
	putchar('Z');
	}
	else if (c==199){
	putchar('H');
	}
	else if (c==200){
	putchar('8');
	}
	else if (c==201){
	putchar('I');
	}
	else if (c==202){
	putchar('K');
	}
	else if (c==203){
	putchar('L');
	}
	else if (c==204){
	putchar('M');
	}
	else if (c==205){
	putchar('N');
	}
	else if (c==206){
	printf("KS");
	}
	else if (c==207){
	putchar('O');
	}
	else if (c==208){
	putchar('P');
	}
	else if (c==209){
	putchar('R');
	}
	else if (c==211){
	putchar('S');
	}
	else if (c==212){
	putchar('T');
	}
	else if (c==213){
	putchar('Y');
	}
	else if (c==214){
	putchar('F');
	}
	else if (c==215){
	putchar('X');
	}
	else if (c==216){
	printf("PS");
	}
	else if (c==217){
	putchar('W');
	}
	else if (c==225){
	putchar('a');
	}
	else if (c==226){
	putchar('v');
	}
	else if (c==227){
	putchar('g');
	}
	else if (c==228){
	putchar('d');
	}
	else if (c==229){
	putchar('e');
	}
	else if (c==230){
	putchar('z');
	}
	else if (c==231){
	putchar('h');
	}
	else if (c==232){
	putchar('8');
	}
	else if (c==233){
	putchar('i');
	}
	else if (c==234){
	putchar('k');
	}
	else if (c==235){
	putchar('l');
	}
	else if (c==236){
	putchar('m');
	}
	else if (c==237){
	putchar('n');
	}
	else if (c==238){
	printf("ks");
	}
	else if (c==239){
	putchar('o');
	}
	else if (c==240){
	putchar('p');
	}
	else if (c==241){
	putchar('r');
	}
	else if (c==242){
	putchar('s');
	}
	else if (c==243){
	putchar('s');
	}
	else if (c==244){
	putchar('t');
	}
	else if (c==245){
	putchar('y');
	}
	else if (c==246){
	putchar('f');
	}
	else if (c==247){
	putchar('x');
	}
	else if (c==248){
	printf("ps");
	}
	else if (c==249){
	putchar('w');
	}
	else if (c==182){
	printf("‘A");
	}
	else if (c==184){
	printf("‘E");
	}
	else if (c==185){
	printf("‘H");
	}
	else if (c==186){
	printf("‘I");
	}
	else if (c==188){
	printf("‘O");
	}
	else if (c==190){
	printf("‘W");
	}
	else if (c==191){
	printf("‘Y");
	}
	else if (c==220){                  
	printf("a'");                                     
	}
	else if (c==221){
	printf("e'");
	}
	else if (c==222){
	printf("h'");
	}
	else if (c==223){
	printf("i'");
	}
	else if (c==252){
	printf("o'");
	}
	else if (c==254){
	printf("w'");
	}
	else if (c==253){
	printf("y'");
	}
	else if (c==250){
	printf("i”");
	}
	else if (c==251){
	printf("y”");
	}
	else if (c==192){
	printf("i’”");
	}
	else if (c==224){
	printf("y’”");
	}
	else if (c==218){
	printf("I”");
	}
	else if (c==219){
	printf("Y”");
	}
	else if (c==192){
	printf("I’”");
	}
	else if (c==224){
	printf("Y’”");
	}
	else
		putchar(c);                                        /*Εαν το c δεν συμπεριλαμβανεται στους κανοντες τοτε παραμενει ιδιο*/
}



int main(){

	enum states {                                         
		INITIAL,
		KEFALAIO_M,
		MIKRO_M,
		KEFALAIO_N,
		MIKRO_N
	};
	enum states state = INITIAL;
	int c;

	while ((c=getchar())!=EOF) {                           /*Διαβασμα του Input*/
		switch(state) {                                    /*Αναλογα με το Input πηγαινει και στο αντιστοιχο state*/
			case INITIAL:
				if (c==CAP_M){							   /*Οι 4 αυτες if τσεκαρουν αν το Input Ειναι Μ,μ,Ν,ν */ 
					state = KEFALAIO_M;					   /*Αν ισχυει τοτε αλλαζει το state αναλογα με την περιπτωση*/
					break;								   
				}

				if (c==SMALL_M){
					state = MIKRO_M;
					break;	
				}

				if (c==CAP_N){
					state = KEFALAIO_N;
					break;	
				}

				if (c==SMALL_N){
					state = MIKRO_N;
					break;	
				}
				else {									   /*Διαφορετικά παει στην συναρτηση αντικαταστασης*/
				     GrToLatin(c);
					break;

				}
			case KEFALAIO_M:						       /*Τα 4 cases ελεγχουν το επομενο input σε περιπτωση που το πρωτο input*/
				if (c==CAP_P || c==SMALL_P){			   /*ειναι Μ,μ,Ν,ν ια να δει αν θα βαλει B,D,b,d Κλπ*/	
					putchar('B');						   
				}
				else{
					putchar('M');
					GrToLatin(c);
				}
                state = INITIAL;
				break;
			case MIKRO_M:
				if (c==CAP_P || c==SMALL_P){
					putchar('b');
				}
				else{
					putchar('m');
					GrToLatin(c);
				}
				state = INITIAL;
				break;
			case KEFALAIO_N:
				if (c==CAP_T || c==SMALL_T){
					putchar('D');
				}
				else{
					putchar('N');
					GrToLatin(c);
				}
				state = INITIAL;
				break;
		    case MIKRO_N:
				if (c==CAP_T || c==SMALL_T){
					putchar('d');
				}
				else {
					putchar('n');
					GrToLatin(c);
				}
				state = INITIAL;
				break;
		}
	}
	return 0;
}