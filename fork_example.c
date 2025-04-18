#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();  // Create child process

    if (pid < 0) {
        // Error occurred
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("👶 Child Process:\n");
        printf("   PID: %d\n", getpid());
        printf("   Parent PID: %d\n", getppid());
    }
    else {
        // Parent process
        printf("🧓 Parent Process:\n");
        printf("   PID: %d\n", getpid());
        printf("   Child PID: %d\n", pid);
    }

    return 0;
}
