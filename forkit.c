/*
CPE 357 Lab07
Author: Dylan Baxter (dybaxter)
File: forkit.c
Description: This file demonstartes functionality of fork()
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
    /*Define some variables*/
    int forkVal;

    /*Announce to world*/
    printf("Hello world!\n");

    /*Fork*/
    if(-1 == (forkVal = fork())){
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }

    /*Split parent and child*/
    if(forkVal){
        /*Print parent pid*/
        printf("This is the parent, pid %d.\n", getpid());
    }
    else{
        /*Print child pid and return*/
        printf("This is the child, pid %d.\n", getpid());
        return 0;
    }

    /*Wait for child to exit*/
    if(-1 == wait(NULL)){
        perror("Wait Failed");
        exit(EXIT_FAILURE);
    }

    /*Say goodbye and exit*/
    printf("This is the parent, pid %d, signing off.\n", getpid());
    return 0;
}