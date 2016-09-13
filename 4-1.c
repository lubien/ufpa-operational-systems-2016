#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *runner(void *param); /* the thread */

int main(int argc, char *argv[]) {
   if(argc < 2) {
      fprintf(stderr, "USO: ./primos <inteiro>\n");
      exit(1);
   }

   if(atoi(argv[1]) < 2) {
      fprintf(stderr, "USO: %d deve ser >= 2\n", atoi(argv[1]));
      exit(1);
   }

   pthread_t tid;       //Thread ID
   pthread_attr_t attr; //Atributos

   pthread_attr_init(&attr);
   pthread_create(&tid,&attr,runner,argv[1]);
   pthread_join(tid,NULL);
   printf("\n");
}

void *runner(void *param) {
   int i,j,upper = atoi(param);
   for(i = 2; i < upper; i++) {
   int trap = 0;
      for(j = 2; j < i; j++) {
         int result = i % j;
         if(result == 0) {
            trap = 1;
            break;
         }
      }
      if(trap == 0) {
         printf("%d, ", i);
      }
   }
   pthread_exit(0);
}
