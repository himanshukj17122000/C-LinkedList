#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265358979323846

typedef struct pizza {
  char name[64];
  float diameter;
  float price;
  float area;
  float avg;
  struct pizza *next;
} pizza_t;

void bubbleSort(pizza_t *pizzas);
void swap(pizza_t *pizza, pizza_t *pizza1);

int main(int argc, char *argv[]) {
    pizza_t *pizzas = NULL;
    pizza_t *temp = NULL;
    FILE *file = fopen(argv[1], "r");
    char line[64];
    fseek(file, 0L, SEEK_END);
    int sz = ftell(file);
    if(sz==0){
      printf("%s\n","PIZZA FILE IS EMPTY" );
      fclose(file);
      return 0;
      }
    else if(sz>0){
    rewind(file);
    while (true) {
        pizza_t *pizza = (pizza_t*) malloc(sizeof(pizza_t));
        strcpy(pizza->name, fgets(line,64,file));
        strtok(pizza->name, "\n");
        if (strcmp(pizza->name, "DONE") == 0) {
            free(pizza);
            break;
        }
        pizza->diameter = atof(fgets(line, sizeof(line), file));
        pizza->price = atof(fgets(line, sizeof(line), file));
        if(pizza->diameter!=(float)0){
        pizza->area= (PI*((*pizza).diameter)*((*pizza).diameter))/4;
        pizza->avg =((*pizza).price/(*pizza).area);
      }else {
        pizza->avg=(float) 0;
      }
        pizza->next = NULL;
        if (pizzas == NULL) {
            pizzas = pizza;
            temp = pizza;
        }
        else {
            temp->next = pizza;
            temp = temp->next;
        }
    }
    fclose(file);
    bubbleSort(pizzas);
    while (pizzas != NULL) {
        printf("%s %f \n", pizzas->name, pizzas->avg);
        pizza_t *temp = pizzas;
        pizzas = pizzas->next;
        free(temp);
    }
     return EXIT_SUCCESS;
  }}

  void bubbleSort(pizza_t *pizzas) {
    int check=1;
    int counter=0;
    while (check>counter) {
          pizza_t *top = pizzas;

          while (top->next != NULL) {
              if (top->avg < top->next->avg) {
                  swap(top, top->next);
                  counter++;
              }
              else if (top->avg == top->next->avg) {
                  if (strcmp(top->name, top->next->name) > 0) {
                      swap(top, top->next);
                      counter++;
                  }
              }
              top = top->next;

            }
            check=counter;
            counter=0;
      }
  }

void swap(pizza_t *pizza, pizza_t *pizza1) {
    char naam[64];
    strcpy(naam, pizza->name);
    float naamnum = pizza->avg;
    strcpy(pizza->name, pizza1->name);
    pizza->avg = pizza1->avg;
    strcpy(pizza1->name, naam);
    pizza1->avg = naamnum;

}
