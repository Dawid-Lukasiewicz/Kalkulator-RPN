/* Dawid Łukasiewicz 06.01.2020 */
/* Kalkulator RPN z dodatkowymi funkcjami matematycznymi: Potęgowanie, pierwiastkowanie 2-stopnia. Funkcja usuwająca element z końca listy. */
/* Kalkulator liczy poprawnie tylko do 10 rzędów wielkości */
/* Do skompilowania programu proszę użyć pliku Makefile. Komenda "make all" lub "make", a następnie uruchomić "./kalkus" */

#include"struct_stos.h"
#include"dzialania.h"
#define MAX 1024


int main(){
int last, pre_last;
element *head = NULL;
char napis[MAX];	

	do{
		fgets(napis, MAX, stdin);	    /*Czytanie z klawiatury*/
		
		if(atoi(napis) != 0){	        /*Czy jest to liczba*/
			push(&head, atoi(napis));
		}
        
        else if(napis[0] == '0' && napis[1] == '\n')    /*Czy jest to 0?*/
            push(&head, 0);
        
		else if((napis[0] == 'P' || napis[0] == 'c' || napis[0] == 'r' || napis[0] == 'd' ||
            napis[0] == 'p' || napis[0] == 'f' ||napis[0] == 'q' || napis[0] == 'U' ||
            napis[0] == '+' || napis[0] == '-' || napis[0] == '*' || napis[0] == '/' ||
            napis[0] == '^' || napis[0] == 's') && napis[1] == '\n'){		/*Jeśli jest, to działanie lub inna opcja*/
			switch(napis[0]){
				case 'P': /*Wyświetlenie ostatnio dodanej liczby*/
					pop_top(&head);
				break;
				
				case 'c': /*Czyszczenie listy*/
					clear(&head);
				break;
				
				case 'r': /*Zamiana miejsc dwóch ostatnio dodanych liczb*/
				    reverse(&head);
				break;
				
				case 'd': /*Zduplikowanie ostatnio dodanej liczby*/
					duplicate(&head);
				break;
				
				case 'p': /*Wyświetlenie ostatnio dodanej liczby*/
					printf("\nWyświetlenie ostatnio dodanej\n");
					print(head);
				break;
				
				case 'f': /*Wyświetlenie całej zawartości listy*/
					printf("\nWyświetlenie całej zawartości\n\n");
					full_print(head);
				break;
                    
                case 's': /*Pierwiastkowanie, bardzo przybliżone*/
                    if(head != NULL){                       /*UWAGA WARUNEK KONIECZNY*/
                        last = zapamietaj(&head);           /*ASSERT w funkcji zapamietaj*/
                        pop_top(&head);
                        //printf("\nWynik pieriastkowania 2-stopnia: %d\n", (int)sqrt(last));
                        push(&head, (int)sqrt(last));
                    }
                    else
                        printf("\nWZa mało liczb do wykonania żądanego działania\n");
                break;
                    
                case '^': /*Potegowanie*/
                    if(head->nastepny != NULL){             /*UWAGA WARUNEK KONIECZNY*/
                        last = zapamietaj(&head);           /*ASSERT w funkcji zapamietaj*/
                        pop_top(&head);
                        pre_last = zapamietaj(&head);
                        pop_top(&head);
                        //printf("\nWynik potegowania: %d\n", (int)pow(last, pre_last));
                        push(&head, (int)pow(last, pre_last));
                    }
                    else
                        printf("\nZa mało liczb do wykonania żądanego działania\n");
                break;
                    
                case '-': /*Odejmowanie*/
                    if(head->nastepny != NULL){             /*UWAGA WARUNEK KONIECZNY*/
                        last = zapamietaj(&head);           /*ASSERT w funkcji zapamietaj*/
                        pop_top(&head);
                        pre_last = zapamietaj(&head);
                        pop_top(&head);
                        //printf("\nWynik odejmowania: %d\n", last-pre_last);
                        push(&head, last-pre_last);
                    }
                    else
                        printf("\nZa mało liczb do wykonania żądanego działania\n");
                break;
                    
                case '*': /*Mnożenie*/
                    if(head->nastepny != NULL){             /*UWAGA WARUNEK KONIECZNY*/
                        last = zapamietaj(&head);           /*ASSERT w funkcji zapamietaj*/
                        pop_top(&head);
                        pre_last = zapamietaj(&head);
                        pop_top(&head);
                        //printf("\nWynik mnożenia: %d\n", last*pre_last);
                        push(&head, last*pre_last);
                    }
                    else
                        printf("\nZa mało liczb do wykonania żądanego działania\n");
                break;
                    
                case '+': /*Dodawanie*/
                    if(head->nastepny != NULL){             /*UWAGA WARUNEK KONIECZNY*/
                        last = zapamietaj(&head);           /*ASSERT w funkcji zapamietaj*/
                        pop_top(&head);
                        pre_last = zapamietaj(&head);
                        pop_top(&head);
                        //printf("\nWynik dodawania: %d\n", last+pre_last);
                        push(&head, last+pre_last);
                    }
                    else
                        printf("\nZa mało liczb do wykonania żądanego działania\n");
                break;
                    
                case '/': /*Dzielenie*/
                    if(head->nastepny != NULL){             /*UWAGA WARUNEK KONIECZNY*/
                        last = zapamietaj(&head);           /*ASSERT w funkcji zapamietaj*/
                        pop_top(&head);
                        pre_last = zapamietaj(&head);
                        pop_top(&head);
                        if(pre_last != 0){
                            //printf("\nWynik dzielenia: %d\n", last/pre_last);
                            push(&head, last/pre_last);
                        }
                        else
                            printf("\nDzielenie przez '0'\n");      /*Dzielenie przez zero*/
                    }
                    else
                        printf("\nZa mało liczb do wykonania żądanego działania\n");
                break;
                    
                case 'U': /*Usunięcie z końca listy*/
                    pop_under(&head);
                break;
					
				case 'q': /*Wyjście*/
                    printf("\nWyłączenie kalkulatora\n");
				break;
			}
		}
        else
            printf("\nBłędnie wprowadzony parametr\n");
	}while(napis[0] != 'q');
}

/*
DOKUMENTACJA

TEST 1: Wprowadzanie nie poprawnych parametrów.

    próba.1 324tfs
    Wynik: Wprowadzenie do pamięci liczby 324.
    
    próba.2 tf344
    Wynik: Wyświetlenie komunikatu "Błędnie wprowadzony parametr", dana nie została wprowadzona do pamięci.
    
    próba.3 Px
    Wynik: Wyświetlenie komunikatu "Błędnie wprowadzony parametr"
    
    próba.4 f    qwdsd
    Wynik: Wyświetlenie komunikatu "Błędnie wprowadzony parametr"
    
WNIOSKI: Program poprawnie obsługuje błędy użytkownika, jedyne wątpliwości zostawia pierwsza próba.

TEST 2: Wprowadzanie poprawnych danych.

    próba.1 645
    Wynik: Wprowadzenie liczby do pamięci.
    
    próba.2 50
    Wynik: Wprowadzenie liczby do pamięci.
    
    próba.3 10
    Wynik: Wprowadzenie liczby do pamięci.
    
    próba.4 25
    Wynik: Wprowadzenie liczby do pamięci.
    
    próba.5 f
    Wynik: Wypisanie wszystkich liczb
    25
    10
    50
    645
    
WNIOSKI: Poprawne działanie listy i operacji f (full_print).

TEST 2: Działanie operacji 'p', 'P', 'U'(usunięcie z końca listy), 'f', 'd', 'r', 'c', '+', '-', '/', '*', 's'(pierwiastkowanie 2-stopnia), '^'(potęgowanie).

W każdym przypadku w pamięci znajdują się liczby: 3, 4, 5 wprowadzone w kolejności od lewej.
    
    próba.1 f
    Wynik: Wyświetlenie 5, 4, 3
    
    próba.2 p 
    Wynik: Wyświetlenie 5
    
    próba.3 P 
    Wynik: Usunięcie 5. Sprawdzone f
    
    próba.4 U
    Wynik: Usunięcie 3. Sprawdzone f
    
    próba.5 d
    Wynik: Dodanie do listy jeszcze jednej 5. Sprawdzone f
    
    próba.6 r
    Wynik: Zmiana kolejności dwóch liczb z początku listy, 4 i 5. Sprawdzone f
    
    próba.7 c
    Wynik: Usunięcie wszystkich liczb z pamięci. Sprawdzone f, wyświetla "Stos jest pusty".
    
    próba.8 +
    Wynik: Dodanie 4 do 5 i wynik jest nową pierwszą liczbą na liście. Sprawdzone f
    
    próba.9 -
    Wynik: Odjęcie 4 od 5 a wynik jest jako nowa liczba na początku listy. Sprawdzone f
    
    próba.10 /
    Wynik: 5 podzielone przez 4 i na całkowite to 1, a ten wynik na liste. Sporawdzone f
    Inne dane: 4 80
    Wynik: 80/4 to 20
    
    próba.11 *
    Wynik: Pomnożenie 5 prze 4 to 20, a ten wynik na liste jako nowy element. Sprawdzone f
    
    próba.12 s
    Wynik: Spierwiastkowanie 5 i przekonwertowanie wyniku na integer daje 2
    Dla liczby: 900
    Wynik: Wynikiem jest już poprawna liczba 30. Sprawdzone kalkulatorem prostym. Nowa liczba idzie na liste
    
    próba.13 ^
    Wynik: 5 do potęgi 4 to 625. Sprawdzone kalkulatorem prostym. Nowa liczba idzie na liste.
    
WNIOSKI: Poprawnie działające funkcje.

TEST 3: Gdy za mało liczb do wykonania operacji.

Każda z funckji ma zapewnione odpowiednie zabezpieczenia na wypadek gdy na liście brakuje liczb potrzebnych do wykonania operacji
W takich wypadkach kalkulator tylko wyświetla komunikat:
"Stos jest pusty", lub "Za mało liczb do wykonania żądanego działania"
Następnie czeka na użytkownika.

WNIOSKI: Program nie pozwala uzytkownikowi wprowadzić błędów, ale komunikuje go o tym i nie karze właściwie w ogóle. Jeśli w pamięci były liczby zostają one tam gdzie były a program nie przerywa dalszego działania.
*/