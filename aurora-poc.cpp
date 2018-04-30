#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>



int main(){
	
	int pipefd[2];
	//int write_pipefd[2];
	pid_t cpid;
	char buf;
	
	char * argv[3] = {(char*)"Command-line", (char*)".", NULL};
	
	pipe(pipefd);
	//pipe(parent_pipefd);
	cpid = fork();
	
	
	//child
	if(cpid == 0){
		//set child side of pipe to stdin of zork to pass it commands
		dup2(pipefd[0],0);
		
		execv("./zork", argv);
	}
	else{
		while(true){
			
			
			
			 
			write(pipefd[1],"open mailbox\n",13);
			//std::cout << "hi there" <<std::endl;
			
			sleep(5);
		}
	}



}
