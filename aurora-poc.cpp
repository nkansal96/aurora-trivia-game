#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>



int main(){
	
	int pipefd[2];
	pid_t cpid;
	char * argv[3] = {(char*)"Command-line", (char*)".", NULL};
	pipe(pipefd);
	cpid = fork();
	
	
	//child
	if(cpid == 0){
		//set child side of pipe to stdin of zork to pass it commands
		dup2(pipefd[0],0);
		//start zork
		execv("./zork", argv);
	}
	else{
		//used while true as an easy way to keep the parent process running
		while(true){
			//send command 'open mailbox' to child game
			write(pipefd[1],"open mailbox\n",13);
			
			sleep(5);
		}
	}



}
