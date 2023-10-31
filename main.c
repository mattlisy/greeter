#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "List.h"
#include <dirent.h>
#include <string.h>

#define MAX_QUOTE_LENGTH 1024
#define ART_LINE_LENGTH 255
/* === Todo ===

- ascii art 

--------------------
*/

		
void print_art() {
	List art_bank = create_List();
	DIR* dir = opendir("art/");
	assert(dir != NULL);
	struct dirent* file;

	while ((file = readdir(dir)) != NULL) {
		if (file->d_type == DT_REG) {
			append_List(&art_bank, file->d_name); 
		}
	}
	
	closedir(dir);

	char filename[64] = "art/";
	strcat(filename, get_random_List(art_bank));
	FILE* art = fopen(filename, "r");
	assert(art != NULL);
	char line[ART_LINE_LENGTH];
	
		
	while (fgets(line, ART_LINE_LENGTH, art) != NULL) {	
		 printf("%s\n", line);
	}
	fclose(art);

	
	
	
}



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
	
	print_art();
	
	// get user
	char* user = getenv("USER");
	assert(user != NULL);

	// time
	time_t now = time(&now);

	printf("  Hello, %s\n\n\tit is %s\n\n\t", user, ctime(&now));
	
	
	// unique quote
	grab_quote();
}
