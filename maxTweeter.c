#include stdio.h;
#include stdlib.h;
#include string.h;


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
  int name_index = 0;
  
  //file parsing
  if(fgets(line, MAX_LINE_LENGTH,f) != NULL);
  token = strtok(line,",");

  while(token != NULL) {
    if (strcmp(token, "name") == 1)
      name_index = numHeaders;
    numHeaders++;
    token = strtok(NULL,","); // keep going thorugh line until we hit the null character
  }
  
  
  
  return 0;
}
