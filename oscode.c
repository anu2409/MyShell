/**
 * ---------------------------------------
 * 
 *	NAME 	 : SHASHANK SHEKHAR
 *	ID	 	 : 1001767592
 *  CSE 3320 : OPERATING SYSTEMS
 * 
 * ---------------------------------------
*/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <curses.h>
#include <sys/stat.h>

#define MAX_LEN 256
#define BIG_MAX_LEN 1024

void init_WelcomePage();
void list_Directories();
void list_FilesInDirectory();
void getAllOperations();
void edit_Directory();
void run_File();
void remove_File();
void move_Directory();

pid_t child;
DIR *d;
struct dirent *de;
int i, c, k;
char s[MAX_LEN], cmd[MAX_LEN],file[MAX_LEN][BIG_MAX_LEN],dir[MAX_LEN][BIG_MAX_LEN*2];
int num;
int choice;

void init_WelcomePage(){
	time_t my_time;
	my_time = time(NULL);

	printf("\t ------------------------------------------------ \n \t\t This is my shell \n\t ------------------------------------------------\n\n\t Your current time : %s\n", ctime(&my_time));
	list_Directories();
	list_FilesInDirectory();

}

/**
 * list_Directories()
 * ------------------
 * 
 * 1. Print the path for the current working directory.
 * 2. List down all the available directories.
 * 
*/

void list_Directories(){
	
	getcwd(s, 200);
	printf("\t Current Working Directory: %s \n", s);

	d = opendir(".");
	c = 0;

	printf("\t ------------------ \n\t Available Directories\n\t ------------------ \n");
	printf("\t Sno. \t\t Name \n\t ------------------------------\n\n");


	while ((de = readdir(d)))
	{
        if ((de -> d_type) & DT_DIR)
		{
            printf("\t %d \t\t %s \n", c++, de->d_name);
		    strcpy(dir[c], de -> d_name);
            }

		}
		closedir(d);
}

/**
 * list_FilesInDirectory()
 * -----------------------
 * 
 * 1. Print all the files in my working directory.
*/

void list_FilesInDirectory(){
	
	d = opendir(".");
	c = 0;
	
	printf("\t ------------------ \n\t Available Files\n\t ------------------ \n");
	printf("\t Sno. \t\t Name \n\t ------------------------------\n\n");

	while ((de = readdir(d))){

		if (((de -> d_type) & DT_REG)){

            printf("\t %d \t\t %s \n", c++, de->d_name);
			strcpy(file[c], de -> d_name);
        }

	}
	closedir(d);
}

/**
 * getAllOperations()
 * --------------------
 * 
 * 1. List the available commands.
*/

void getAllOperations(){

	printf("\n\t ------------------------------ \n\t Available Operations\n\t ------------------------------ \n\n");
	printf("\t Sno. \t\t Command \t\t Purpose \n\t ------------------------------------------------------------\n\n");
	printf("\t 1. \t\t d \t\t Display \n \t 2. \t\t e \t\t Edit \n \t 3. \t\t r \t\t Run \n \t 4. \t\t c \t\t Change Directory \n \t 5. \t\t m \t\t Move Directory \n \t 6. \t\t f \t\t Remove File \n \t 7. \t\t q \t\t Quit\n\n");


}

/**
 * edit_Directory()
 * -----------------
 * 
 * 1. Open the file in text editor.
 * 2. Default editor : gedit.
 * 3. Available alternatives : pico, source, vim, nano, code(VS Code).
*/

void edit_Directory(){
	
	printf("which file you want to edit with?: ");		
	scanf("%d", &num);
	strcpy(s,file[num]);
	strcpy(cmd, "gedit ");
	strcat(cmd, s);
	system(cmd);
}

/**
 * run_File()
 * ----------
 * 
 * 1. Run the exexcutable file.
 * 2. Usage : ./filname
*/

void run_File(){

	printf(" (Hint : ./filename) : ");
	scanf("%s",cmd);
	system(cmd);
}

/**
 * change_Directory()
 * ------------------
 * 
 * 1. Change the current directory.
*/

void change_Directory(){

	printf("Which directory you want to Change?: ");
	scanf("%d", &num);
	strcpy(cmd, dir[num]);
	chdir(cmd);
}

/**
 * remove_File()
 * -------------
 * 
 * 1. Remove the file from the directory.
*/

void remove_File(){
	printf("Directory to remove  : ");
	scanf("%s", cmd);
	rmdir(cmd);
}

/**
 * move_Directory()
 * -----------------
 * 
 * 1. Move the file from one directory to another.
 * 2. USAGE : source_directory, destination_directory.
*/

void move_Directory(){
	
	char src_folder[BIG_MAX_LEN];
    char dest_folder[BIG_MAX_LEN];

	printf("Source File/Directory : ");
	scanf("%s", src_folder);

	printf("Destination File/Directory  : ");
	scanf("%s", dest_folder);

	if (rename(src_folder, dest_folder) ){
		perror( NULL );
		printf("%s moved to : %s . DONE.",src_folder, dest_folder);
	}else{
		printf("Error in moving the file/directory.");
	}

}
			

int main(void)
{
	

	while (1)
	{

		init_WelcomePage();
		getAllOperations();

		d = opendir(".");
		choice = 0;

		printf(" > ");
		choice = getchar();

		strcpy(cmd, "");

		switch(choice)
		{

			case 'd' :  list_Directories();
						break;

			case 'e' : edit_Directory();
						break;

			case 'r' : run_File();
						break;
			
			case 'c':	change_Directory();
						break;

			case 'm' : move_Directory();
						break;

			case 'f' : remove_File();
						break;
				
			case 'h' : getAllOperations();
			break;

			case 'q' :	exit(0);
			break;
		}

	}
}

