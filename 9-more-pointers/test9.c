#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SIZE 2000
int count = 0;

void process(char *s1,char *s2,char *ans,int *state);
void print(const char *ans,int *state);

int main(){
  char *s1 = malloc(SIZE * sizeof *s1);
  char *s2 = malloc(SIZE * sizeof *s2);
  char *ans = malloc(SIZE * sizeof *ans);

  scanf("%s",s1);
  getchar();
  scanf("%s",s2);
  printf("%s",s2);

  int state = 0;

  while (scanf("%s",s2) != EOF){
	process(s1,s2,ans,&state);
  }

  print(ans,&state);



  free(s1);
  free(s2);
  free(ans);
}

void process(char *s1,char *s2,char *ans,int *state){


  if (*state == 1) {
	int i = 0;
	*state = 0;
	*(ans+count) ='3';
	count++;
	*(ans + count) = '=';
	count++;
	while (*(s2 + i) != 0) {
	  *(ans + count) = *(s2 + i);
	  count++;
	  i++;
	}
	*(ans+count) ='3';
	count++;
	return;

  }

  if(*s2 == '-'){


	for(int i = 0;i< strlen(s1);i++){
	  if(*(s1+i) == *(s2+1) && *(s1+i+1) != ':'){
		*(ans + count) = *(s2+1);
		count++;
		return;
	  }else if(*(s1+i) == *(s2+1) && *(s1+i+1) == ':'){
		*state = 1;
		*(ans + count) = *(s2+1);
		count++;
		return;
	  }
	}
	//找遍了s1还是没找到
	*(ans + count) = '2';
	count++;
	*(ans + count) = *(s2+1);
	count++;
	return;

  }



}

void print(const char *ans,int *state){
  for(int i = 0;i<count;i++){
	if(*(ans+i) == '2'){
	  printf(": invalid option -- '%c'",*(ans+i+1));
	  return;
	}
  }

  if(*state == 1){
	printf(": option requires an argument -- '%c'",*(ans + strlen(ans)-1));
	return;
  }




  for (int i = 0; i < count; ++i) {
	if(*(ans + i) == '3'){
	  int temp_count = 0;
	  int j = 1;
	  while (*(ans+i+j)!='3'){
		printf("%c",*(ans + i + j));
		temp_count++;
		j++;
	  }

	  i +=j;
	  continue;
	}


	if(*(ans+i)!='='){
	  printf("\n%c",*(ans+i));
	}
  }


}