#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main(){
  DIR * dirstream;
  struct dirent *curr;
  int total_size = 0;
  dirstream = opendir("./");
  
  curr = readdir(dirstream);
  printf("Printing files...\n");
  while(curr){
    if(curr->d_type & DT_REG){
      printf("\t%s\n", curr -> d_name);
      total_size+=curr->d_reclen;
    }
    curr = readdir(dirstream);
    
  }
  printf("Printing directories...\n");
  closedir(dirstream);
  dirstream = opendir("./");
  curr = readdir(dirstream);
  while(curr){
    if(curr->d_type & DT_DIR){
      printf("\t%d - %s\n", curr -> d_type , curr -> d_name);
      total_size+=curr->d_reclen;
    }
    curr = readdir(dirstream);

  }
  closedir(dirstream);
  printf("Size of Directory: %d\n",total_size);
  printf("End of Directory");
  return 0;
}
