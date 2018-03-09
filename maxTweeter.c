#include stdio.h;
#include stdlib.h;
#include string.h;

// This is a helper function.
// Takes in an array of c-strings, the length of that array, and a c-string tok.
// if tok is found, outputs the index in that array of tok
// else, outputs -1
int findName(char **dictionary, unsigned int dictionary_length, char* tok) {
  // iterate through all the strings in dictionary
  for(int i = 0; i < dictionary_length+1; i++) {
    // if we find the token in the dictionary, return the index position of that element
    if(strcmp(dictionary[i],tok) == 0)
      return i;
  }
  // If we exit this loop normally, we did not find the token in dictionary
  return -1;
}

void sort_ten(int *highest, int max_index)
{
  //FILL IN PSEUDOCODE
}

// main
int main(int argc, char *argv[]){
  //read file
  if(argc != 2){
    printf("Invalid Command Line Args\n");
    return 1; //no filename
  }
  
  int length_filename = strlen(argv[1]);
  
  if(length_filename > 50){
    printf("Invalid Filename Length\n");
    return 1; //filename too long
  }
  
  char filename[length_filename+1]; //EDIT: should the be plus one in order to add a end of line character?
  strcpy(filename, argv[1]);
  
  //variable for data processing and limiting
  int MAX_TWEETERS = 20000;
  int MAX_TWEETER_NAME_LENGTH = 20;
  char dictionary[MAX_TWEETERS][MAX_TWEETER_NAME_LENGTH];
  int count[MAX_TWEETERS];
  int last_valid_tweeter_index = 0;
  
  // initialise the tweeter counts to zero
  for(int i = 0; i < MAX_TWEETERS; i++) {
    count[i] = 0;
  }

  //open file for reading
  FILE * f = fopen(filename, 'r');
  if(f == NULL) {
    printf("Invalid Input CSV Filename\n");
    return 0;
  }
  
  //variable for file parsing
  int MAX_LINE_LENGTH = 2000 //EDIT: instead of using length of the tweeter name, should this be shorter or longer?
  int MAX_TOKEN_LENGTH = 100 //EDIT: shorter or longer?
  char line[MAX_LINE_LENGTH] = "";
  char token[MAX_TOKEN_LENGTH] = "";
  int numHeaders = 0;
  //int name_index = 0;
  int name_index = -1; //K_CHANGE - we want the name index to be initially invalid.
  
  //file parsing
  if(fgets(line, MAX_LINE_LENGTH,f) != NULL);
  token = strtok(line,",");

  while(token != NULL) {
    if (strcmp(token, "name") == 1)
      name_index = numHeaders;
    numHeaders++;
    token = strtok(NULL,","); // keep going thorugh line until we hit the null character
  }
  
  //K_ADD: Check that we actually have columns in the CSV file
  if(numHeaders == 0) {
    printf("Invalid: CSV file has no headers\n");
    return 1; //no rows (i.e. headers) at all
  }

  //K_ADD: Check that there is a column called "name"
  if(name_index < 0) {
    printf("Invalid: No \'Name\' attribute in CSV file");
    return 1; // no column called "name"
   } 
  
  // parse the rest of the file.
  // jumpstart the loop
  fgets(line,MAX_TWEETER_NAME_LENGTH,f);

  // Loop thorugh file
  while(line != NULL) {
    // read in a token
    token = strtok(line, ",");
    //int num_toks_in_line = numHeaders; // Unnecessary
    int num_tok = numHeaders;
  
    // while there's still tokens available, and there aren't too many tokens
    // K_ADD: num_toks_in_line needs to be decremented
    while(token != NULL && num_tok > 0) { 
      if(num_tok == nameHeader) { // i.e. we've hit the right column
        // try to find name in dictionary
        int found = findName(dictionary, last_valid_tweeter_index, token); // not found = -1, found = num >= 0.  IMPLEMENT THIS, THIS IS PSEUDOCODE
      
        if(found >= 0) {
          // if in dictionary, increment matching index of count array
          count[found]++;
        }
        else {
          // else add to dictionary at last_valid_tweeter_index+1
          dictionary[last_valid_tweeter_index+1] = token;
          last_valid_tweeter_index++;
        } // end else
      } // end if
    
      //K_ADD: move on to next token
      token = strtok(NULL, ",");
      num_tok--;
    
    } // end inner while
    
    // check that the there are the right number of tokens in the line
    // the current token should be null, and numTok should be 0
    if(!token && numTok != 0) {
        printf("columns don't match up with the number of headers");
	return 1;
    }
	  
    // Read in next line
    fgets(line,MAX_TWEETER_NAME_LENGTH,f);
  } // end outer while

  // K_ADD: if the file has headers but no data, last_valid_tweeter_index should be -1.  if so, return.
  if(last_valid_tweeter_index == -1) {
    printf("Invalid: no data rows\n");
    return 1;
  }
  
  // part 4
  int highest[10] = {-1}; //this holds the index not the count
	int curr_index = 0
	int i = 0;

	highest[0] = 0
	for(i = 1, i < 9, i++)//check bounds
	{
		if(counts[highest[curr_index]] < counts[i])
    {
      highest[curr_index+1] = i
			sort_ten(highest, counts, i); //EDIT: POINTERS?
    }
		else 
			highest[curr_index+1] = i
		curr_index++;
	}

	for(i = 9, i < last_valid_tweeter_index, i++)//check bounds
	{
		if(counts[highest[9]] < counts[i])
    {
      highest[9] = i;
      sort_ten(highest, counts, i);
    }
		else
			continue;
	}
 
  //part 5
  for(i = 1, i < 10, i++)//check bounds
	{
    printf("%s, %d", dictionary[highest[i]], counts[highest[i]]);
  }
  return 0;
}
