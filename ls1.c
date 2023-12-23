// rev1 22-Dec-2018
// rev2 23-Dec-2019
// rev 3 22-Dec-2023
//  ls1.c
//  UNIX advance Programming , p#4
//  The Program immitates ls

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

static void lookup(const char *arg)
{
    DIR *dirp;
    struct dirent *dp;

    if ((dirp = opendir(".")) == NULL) {
        perror("couldn't open '.'");
        return;
    }
    do {
        errno = 0;
        if ((dp = readdir(dirp)) != NULL) {
            if (strcmp(dp->d_name, arg) != 0)
                continue;

            (void) printf("found %s\n", arg);
            (void) closedir(dirp);
                return;
        }
    } while (dp != NULL);}


int main(int argc, const char *argv[]) {
   
    DIR *dirp;
    struct dirent *dp;
    int i;
  /* if (argc !=2)
        err_quit("err");
    if ((dp = opendir(argv[1])) == EOF)
        err_sys("can't open",argv[1]);
    
    while(( dp = readdir(dirp)) != NULL){
        printf("found =%s\n", dp->d_name);}
   closedir(dirp);
 */
    

  //  for (i = 1; i < argc; i++)
        lookup(argv[i]);
//
    return 0;
}

