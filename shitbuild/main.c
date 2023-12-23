#include "functiondefs.h"

int file_exists(char *filename)
{
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

int execute_command(char *cmd)
{
    int result = system(cmd);
    if (result != 0)
    {
        perror("system failed\n");
        return 1;
    }
    return 0;
}


int run_commands_from_file(char *filename)
{
    if (!file_exists(filename))
    {
        perror("File does not exist\n");
        return 1;
    }
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Failed to open file\n");
        return 1;
    }
    char line[1000000000];
    while (fgets(line, sizeof line, file))
    {
// Remove trailing newline character
        line[strcspn(line, "\n")] = 0;
        execute_command(line);
    }
    fclose(file);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        perror("No command specified\n");
        return 1;
    }
    if (strcmp(argv[1], "build") == 0)
    {
        printf("Building\n");
        if (run_commands_from_file("BUILD.SB") == 1)
        {
            return 1;
        }
    }
    if (strcmp(argv[1], "run") == 0)
    {
        printf("Running\n");
        if (run_commands_from_file("RUN.SB") == 1)
        {
            return 1;
        }
    }
    return 0;
}
