#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a helper function.
// Takes in an array of c-strings, the length of that array, and a c-string tok.
// if tok is found, outputs the index in that array of tok
// else, outputs -1
int findName(char dictionary[][20], unsigned int dictionary_length, char* tok) {
  // iterate through all the strings in dictionary
  for(int i = 0; i < dictionary_length+1; i++) {
    // if we find the token in the dictionary, return the index position of that element
    if(strcmp(dictionary[i],tok) == 0)
      return i;
  }
  // If we exit this loop normally, we did not find the token in dictionary
  return -1;
}

int compare(const void *p1, const void *p2)
{
	const int (*a)[2] = p1;
    const int (*b)[2] = p2;
    if ( (*a)[0] < (*b)[0] ) return -1;
    if ( (*a)[0] > (*b)[0] ) return +1;
    return 0;
}

// main
int main(int argc, char *argv[]){
  // printf("%s","*******************************************************\n");
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
  
  char filename[length_filename+1];
  strcpy(filename, argv[1]);
  
  //variable for data processing and limiting
  int MAX_TWEETERS = 20000;
  int MAX_TWEETER_NAME_LENGTH = 50;
  char dictionary[MAX_TWEETERS][MAX_TWEETER_NAME_LENGTH];

  int count[MAX_TWEETERS][2]; 
  //count[x][0] holds the actual count while [x][1] holds the index of associated dictionary entry

  int last_valid_tweeter_index = -1;
  
  // initialise the tweeter counts to zero
  for(int i = 0; i < MAX_TWEETERS; i++) {
    count[i][0] = 0;
    count[i][1] = -1;
  }

  //open file for reading
  FILE * f = fopen(filename, "r");
  if(f == NULL) {
    printf("Invalid Input CSV Filename\n");
    return 0;
  }
  
  //variable for file parsing
  int MAX_LINE_LENGTH = 2000; // line is at max 400 characters, I think
  int MAX_TOKEN_LENGTH = 1000; //EDIT: shorter or longer? (longer :D
  char lin[MAX_LINE_LENGTH];
  char * line = lin;
  char toke[MAX_TOKEN_LENGTH];
  char * token = toke;
  int numHeaders = 0;
  int name_index = -1; // we want the name index to be initially invalid.
  
  //file parsing
  if(fgets(line, MAX_LINE_LENGTH,f) != NULL) {
    token = strtok(line,",");

    while(token != NULL) {
      if (strcmp(token, "name") == 0 || strcmp(token,"\"name\"") == 0
          || strcmp(token, "name\n") == 0 || strcmp(token,"\"name\"\n") == 0)
        name_index = numHeaders;
      numHeaders++;
      token = strtok(NULL,","); // keep going thorugh line until we hit the null character
    }
  
    // Check that we actually have columns in the CSV file
    if(numHeaders == 0) {
      printf("Invalid: CSV file has no headers\n");
      return 1; //no rows (i.e. headers) at all
    }

    // Check that there is a column called "name"
    if(name_index < 0) {
      printf("Invalid: No \'Name\' attribute in CSV file\n");
      return 1; // no column called "name"
     } 
   }
  
  // parse the rest of the file.
  // jumpstart the loop
  // Loop thorugh file
  while(fgets(line,MAX_LINE_LENGTH,f) != NULL) {
    // read in a token
    token = strtok(line, ",");
    int num_tok = 0;
  
    // while there's still tokens available, and there aren't too many tokens
    while(token != NULL && num_tok < numHeaders) { 
      if(num_tok == name_index) { // i.e. we've hit the right column
        // try to find name in dictionary
        int found = findName(dictionary, last_valid_tweeter_index, token); // not found = -1, found = num >= 0.  IMPLEMENT THIS, THIS IS PSEUDOCODE
        if(found >= 0) {
          // if in dictionary, increment matching index of count array
          count[found][0]++;
        }
        else {
          // else add to dictionary at last_valid_tweeter_index+1
          strcpy(dictionary[last_valid_tweeter_index+1],token);
	  count[last_valid_tweeter_index+1][1] = last_valid_tweeter_index+1;
          count[last_valid_tweeter_index+1][0]++;
          last_valid_tweeter_index++;
        } // end else
      } // end if
    
      // Move on to next token
      // check if token is second-to-last
      if(num_tok == numHeaders - 2) {
        token = strtok(NULL,"\n");
        }
      else {
        token = strtok(NULL, ",");
        }

      num_tok++;
    
    } // end inner while
    
    // check that the there are the right number of tokens in the line
    // the current token should be null, and numTok should be equal to the number of headers
    if(token != NULL || num_tok != numHeaders) {
        printf("columns don't match up with the number of headers\n");
	      return 1;
    }
  } // end outer while

  // Check if the file has headers but no data, last_valid_tweeter_index should be -1.  if so, return.
  if(last_valid_tweeter_index == -1) {
    printf("Invalid: no data rows\n");
    return 1;
  }

  qsort(count, last_valid_tweeter_index*2, sizeof count[0], compare);
  
  // for loop for testing 
	//EDIT: printing for the new version of count
  for(int i = 0; i < 20; i++) {
    if(count[i][1] != -1) {
      printf("Name: %s\n",dictionary[count[i][1]]);
      printf("Count: %d\n",count[i][0]);
    }
  }
  return 0;
}
