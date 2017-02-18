#include<stdio.h>
#include<string.h>
#define MAX_FILE_NAME_CHARS 255
int main(int argc, char *argv[])
{
 FILE *fp;
 char file_name[MAX_FILE_NAME_CHARS], ch;
 int i;

 /*
  * after creating a.out, rename it as mycat for our own cat command
  * and it usage is same as standard cat command
  */
 if(argc<1){
    printf("Usage mycat <filename> \n");
    return 0;
 }

 /*
  * cat handles more than one file
  * so we need this loop to handle all the files provided
  * on command line
  */
 for(i=1; i<=argc;i++){
    /* no need of copy but for understanding purpose, i have created
     * string for each file name
     */
    strncpy(file_name, argv[i], MAX_FILE_NAME_CHARS);

    fp=fopen(file_name, "r");
    if(fp == NULL) {
       printf("%s: No such file or directory\n", file_name);
       return 0;
    }

    /*
     * read file and feed contents to STDIO
     */
    while((ch=fgetc(fp)) != EOF){
         putchar(ch);
    }
    fclose(fp);
 }
return 0;
}
