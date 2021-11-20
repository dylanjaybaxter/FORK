/*
CPE 357 Lab07
Author: Dylan Baxter (dybaxter)
File: tryit.c
Description: This file contains a demonstration of fork() and exec together.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*Define some macros*/
#define PARENT 1
#define CHILD 0

int main(int argc, char const *argv[]) {
    int pid;
    int forkVal;
    int childStat;

    /*Ensure 1 command*/
    if(argc != 2){
        printf("usage: tryit command\n");
        exit(EXIT_FAILURE);
    }

    /*Fork*/
    if(-1 == (forkVal = fork())){
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }

    /*If child, execute program*/
    if(forkVal == CHILD){
        if(-1 == execl(argv[1], argv[1], NULL)){
            perror(argv[1]);
            return -1;
        }
        return 0;
    }

    /*If parent wait for the child to exit and record exit value*/
    if(-1 == (pid = wait(&childStat))){
        perror("Wait failed");
        exit(EXIT_FAILURE);
    }

    /*Print exit status and return*/
    if(childStat){
        printf("Process %d exited with an error value.\n", pid);
    }
    else{
        printf("Process %d suceeded.\n", pid);
    }

    return 0;
}