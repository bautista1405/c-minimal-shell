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