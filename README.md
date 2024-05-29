# c-minimal-shell

A minimal shell written in C. This repository follows [Stephen Brennan's blog article](https://brennan.io/2015/01/16/write-a-shell-in-c/)

It's a single `main.c` file with the corresponding functions for a very basic shell. It has the `cd`, `help` and `exit` commands.

#### Run it

1. Clone repository
2. Make sure you are in a Unix-like environment (any Linux distro will do)
3. In the command console: `gcc -o main ./src/main.c`
4. And then: `./main`