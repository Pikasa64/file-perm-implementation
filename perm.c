#include <stdio.h>
#include <stdint.h>
#include <string.h>

//read = 0, write = 1, rw = 2

void read(uint8_t *perm){
    *perm = (1<<0);
}

void write(uint8_t *perm){
    *perm = (1<<1);
}

void readwrite(uint8_t *perm){
    *perm = (1<<2);
}

void revoke(uint8_t *perm){
    *perm = 0;
    printf("all your permissions have been revoked\n");
}

void see(uint8_t *perm){
    if (*perm&(1<<0)) printf("you only have read permission\n");
    else if (*perm&(1<<1)) printf("you only have write permission\n");
    else if (*perm&(1<<2)) printf("you have both read and write permission\n");
    else printf("you have no permission enabled\n");
}


int main(){
    uint8_t perm = 0b00000000;
    while (true){
        char ch[6];
        printf("choose your option (read/write/rw/revoke/see/q): ");
        scanf("%s",ch);
        if (strcasecmp(ch,"read")==0) read(&perm);
        if (strcasecmp(ch,"write")==0) write(&perm);
        if (strcasecmp(ch,"see")==0) see(&perm);
        if (strcasecmp(ch,"rw")==0) readwrite(&perm);
        if (strcasecmp(ch,"revoke")==0) revoke(&perm);
        if (strcasecmp(ch,"q")==0) break;
    }

    return 0;
}
