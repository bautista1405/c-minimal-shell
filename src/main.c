int main(int argc, char **argv)
{
    // call our loop fn to be executed while terminal is being used
    lsh_loop();
    return 0;
}

void lsh_loop(void)
{
    char *line;
    char **args;
    int status;

    // here the loop fns are pretty self-explanatory
    do
    {

        printf("> ");                // print command
        line = lsh_read_line();      // read command
        args = lsh_split_line(line); // splint command into args
        status = lsh_execute(args);  // execute args

        // free memory
        free(line);
        free(args);

    } while (status);
}

#define LSH_RL_BUFSIZE 1024
char *lsh_read_line(void)
{
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // read a character
        c = getchar();

        // if we hit EOF replace it with a null character and return
        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        // if exceeding the buffer we reallocate
        if (position >= bufsize)
        {
            bufsize += LSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer)
            {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}