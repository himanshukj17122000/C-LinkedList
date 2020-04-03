#include <stdlib.h>
#include <stdio.h>
int fn(int x);


int main(int argc, char *argv[]) {
int num=atoi(argv[1]);
int ans= fn(num);

printf("%d \n",ans);
return EXIT_SUCCESS;
}

int fn(int x){
if(x==0){
  return x;
}
if(x==1){
  return x;
}
return fn(x-1)+ 2*fn(x-2)+3;
}
