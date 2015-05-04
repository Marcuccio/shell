#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

const char* D_LEVEL = "middle"; // variabile di stato del livello di default
const char* D_PROMPT = "your-shell: ";
const char* D_LOGFILE = "log.txt";

char* level = "middle" //variabile di stato del livello scelto dall'utente |LOW|MIDDLE|HIGH
char* prompt = "your-shell";
char* logfile = "log.txt";
char** comandi;

void internalCommand(char*);

int main(int argc, char *argv[]){
	char* line = NULL;
	int len;
	//controllo dei parametri in input
	if(argc!=1 && argc!=4){ //si accettano 0 o 3 parametri
		system("cat argumenterror"); //file di testo contenente messaggio di help per l'utente
		exit(0);
	}
	if(argc==4){
		prompt = (char*)malloc(strlen(argv[1]) * sizeof(char));
		if(strcpy(prompt,argv[1])==NULL){
			printf("errore");
		}
		if((strcmp(argv[2],"low")==0)||(strcmp(argv[2],"middle")==0)||(strcmp(argv[2],"high")==0)){		
			level = (char*)malloc(strlen(argv[2]) * sizeof(char));
			if(strcpy(level,argv[2])==NULL){
				printf("errore");
				exit(1);
			}
		}else{
			printf("errore: selezionare un opportuno livello di log \n");
			exit(1);
		}
		logfile = (char*)malloc(strlen(argv[3]) * sizeof(char));
		if(strcpy(prompt,argv[3])==NULL){
			printf("errore");
		}
		
	}

	for(;;){ //loop del terminale
		printf("shell@%s: ",prompt);
		getline(&line, (size_t*)&len, stdin);

		if (line[strlen(line) - 1] == '\n') //si controlla se l'utlimo carattere della stringa è uno \n
		  line[strlen(line) - 1] = '\0'; // se lo è lo si sostiuisce con il terminatore di stringa \0

		switch(line[0]){
			case '!': internalCommand(line); break;
			default : system(line);break;
		}

	} 

	fflush(stdout);
	free(line);

	return 0;
}

void internalCommand(char* line){
	if (strcmp(line,"!quit") == 0) //Comando "!quit"
		exit(0);
	else if (strcmp(line,"!showlevel") == 0) //comando "!showlevel"
		printf("Il levello attuale di log è: %s \n",level);
	else if (strcmp(line,"!logon") == 0) //comando "!logon"
		printf("1 \n");
	else if (strcmp(line,"!logoff") == 0) //comando "!logoff"
		printf("1 \n");
	else if (strcmp(line,"!logshow") == 0)//comando "!logshow"
		printf("1 \n");
	else if (strcmp(line,"!setlevel") == 0)//comando "!setlevel"
		printf("1 \n");
	else if (strcmp(line,"!setpromp") == 0)//comando "!setpromp"
		printf("1 \n");
}
