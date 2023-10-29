#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "List.h"

#define MAX_QUOTE_LENGTH 1024

/* === Todo ===

- ascii art 

--------------------
*/

		


void grab_quote() {
	List quote_bank = create_List();
	FILE* quotes_file = fopen("quotes.txt", "r");
	char quote[MAX_QUOTE_LENGTH]; 	
	assert(quotes_file != NULL); 
	while(fgets(quote, MAX_QUOTE_LENGTH, quotes_file)) {
		append_List(&quote_bank, quote);	
	}	
	
	fclose(quotes_file);		
	printf("\n  %s\n", get_random_List(quote_bank));
	destory_List(&quote_bank);
}


int main () {

	// hello user
	char* user = getenv("USER");
	assert(user != NULL);

	// time
	time_t now = time(&now);

	// unique quote


	printf("  Hello, %s\n\n\tit is %s\n\n\t", user, ctime(&now));
	
	grab_quote();
}
