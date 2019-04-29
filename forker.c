#include <stdio.h>

#include <unistd.h>

#include <sys/types.h>

int main()

{

pid_t pid, pid2;

int n;

printf("Select a number [1-5]: ") ;

scanf("%d", &n);

printf("\n\n");

switch(n)

{

case 1:

fork();

printf("This is process %d\n", getpid());

break;

  

case 2:

fork(); fork();

printf("This is process %d\n", getpid());

break;

  

case 3:

fork(); fork(); fork();

printf("This is process %d\n", getpid());

break;

  

case 4:

if((pid=fork()) && (pid2 = fork())) {fork();}

if((pid=fork()) && (pid2 = fork())) {fork();}

if ((pid=fork()) && (pid2 = fork())) {fork();}

printf("This is process %d\n", getpid());

break;

case 5:

for (int i=1; i<=5; i++)

{

fork();

}

printf("This is process %d\n", getpid());

break;

default:

printf("Number not in range [1-5] !\n");

}

}
