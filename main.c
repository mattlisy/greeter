#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>



/* === Todo ===

- say hello to user
- give time and say 
- give unique quote 

--------------------
*/



int main () {

	// hello user
	char* user = getenv("USER");
	assert(user != NULL);

	// time
	time_t now = time(&now);

	// unique quote
	char* quote = grab_quote();

	printf("Hello, %s\n\n\tit is %s", user, ctime(&now));
}
