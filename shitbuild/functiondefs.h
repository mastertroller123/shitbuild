#include <stdio.h>
#include <string.h>
#include <process.h>
#include <sys/stat.h>
/* function to check if file exists */
int file_exists(char *filename);
/* function to execute a command*/
int execute_command(char *cmd);
/* read commands from a file and execute them */
int run_commands_from_file(char *filename);
