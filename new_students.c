#include <stdio.h>
int main(int argc, char const *argv[]) {
  char first_name[64];
  char last_name[64];
  int age;

  printf("First Name: ");
  scanf("%s", first_name);

  printf("Last Name: ");
  scanf("%s", last_name);

  printf("Age: ");
  scanf("%d",&age);

  FILE* fd=fopen("student.dat","r+");
  int id;

  fseek(fd,0,SEEK_SET);
  fread(&id,sizeof(id),1,fd);

  //printf("The id is: %d\n",id);

  fseek(fd,0,SEEK_END);
  fwrite(&id,sizeof(id),1,fd);
  fwrite(first_name,sizeof(first_name),1,fd);
  fwrite(last_name,sizeof(last_name),1,fd);
  fwrite(&age,sizeof(age),1,fd);

  fseek(fd,0,SEEK_SET);
  id++;
  fwrite(&id,sizeof(id),1,fd);
  fclose(fd);

  return 0;
}
