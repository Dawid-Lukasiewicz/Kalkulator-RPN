#include"struct_stos.h"
//#include"dzialania.h"

void push(element **head, int dana) {   /*Dodanie elementu na liste*/

  element *nowy = (element*)malloc(sizeof(element*));
  nowy->dana = dana;
  nowy->nastepny = *head;
  *head = nowy;

}

void duplicate(element **head){ /*Duplikowanie*/
	if(*head == NULL)
		printf("\nStos jest pusty\n");

	else{
		element *nowy = (element*)malloc(sizeof(element*));
		nowy->dana = (*head)->dana;
		nowy->nastepny = *head;
		*head = nowy;
	}
}

void pop_top(element **head){   /*Usuwanie elementu z początku listy*/

	if(*head == NULL)
		printf("\nStos jest pusty\n");

	else{
		element *usuwany = *head;
		*head = (*head)->nastepny;
		free(usuwany);

	}
}

int zapamietaj(element **head){ /*Zapamiętuje liczbę*/
    assert(*head != NULL);  /*POTRZEBNY WARUNEK PRZED FUNKCJĄ, ABY TO NIE NASTĄPIŁO*/
        return (*head)->dana;;       
}

void pop_under(element **head){ /*Usuwanie elementu z końca listy*/
	/*if((*head)->nastepny == NULL)*/
	if(*head == NULL)
		printf("\nStos jest pusty\n");
	
	else if((*head)->nastepny == NULL){
        free(*head);
		*head = NULL;
	}
	
	else{
		element *usuwany = *head;
		while(usuwany->nastepny->nastepny != NULL){
			usuwany = usuwany->nastepny;
		}
		free(usuwany->nastepny);
		usuwany->nastepny = NULL;

	}
}

void clear(element **head){/*Czyszczenie listy*/
	if(*head == NULL)
		printf("\nStos jest pusty\n");
	
	else{
		element *usuwany = NULL;
		while(*head != NULL){
			usuwany = *head;
			*head = (*head)->nastepny;
			free(usuwany);
		}
	}
}

void print(element *head){  /*Wypisanie pierwszego elementu*/

	if(head == NULL)
		printf("\nStos jest pusty\n");
	
	else
		printf("\n%d\n", head->dana);
}

void full_print(element *head){ /*Wypisanie wszystkich elementów*/

	if(head == NULL)
		printf("\nStos jest pusty\n");

	else{
		element *show = head;
		do{
		printf("%d\n", show->dana);
		show = show->nastepny;
		}while (show != NULL);
	}
}

int poj_stosu(element *head){ /*Jednak niepotrzebne*/
	int licznik = 0;
	
	if(head == NULL)
		return licznik;
	
	else{
		element *teraz = head;
		do{
			licznik++;
			teraz = teraz->nastepny;
		}while(teraz != NULL);
	}
	return licznik;
}

void reverse(element **head){ /*Podmiana kolejności 2 liczb z początku listy*/
	
	if(*head == NULL)
		printf("\nStos jest pusty\n");

	else{
		element *tmp_1 = *head;
		*head = (*head)->nastepny;
		tmp_1->nastepny = tmp_1->nastepny->nastepny;
		(*head)->nastepny = tmp_1;
	}
}

