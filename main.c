#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
	int fd[2];
	char text[50];
	char text2[50];

	pipe(fd);
	pid_t pid = fork();
	if (pid == 0) {
		close(fd[0]);
		printf("enter text: ");
		scanf("%s", text);
		write(fd[1], text, strlen(text)+1);
		close(fd[1]);
	}
	else {
		close(fd[1]);
		read(fd[0], text2, 20);
		text2[0]='X';
		close(fd[0]);
		printf("%s\n", text2);
	}
	return 0;
}
