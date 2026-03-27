/*
                        Stochastic-gradient-descent
                        For a single input Data-set
*/

#include <stdio.h>
#include <stdlib.h>

#define epoch 300

int data[][2] = {{2, 4}};

typedef struct para {
  float input;
  float weight;
  float learn_rate;
} para;

float rand_float() { return (float)rand() / (float)RAND_MAX; }

void perceptron(para *parameter) {

  for (int i = 0; i < 1; i++) {
    float z = data[i][0] * parameter->weight;
    //  float err = z-data[i][1];
    float cost = (2 * data[i][0]) * (z - data[i][1]);
    parameter->weight -= parameter->learn_rate * cost;

    printf("\t%d\t%f\t%f\t%f\n", data[i][1], z, parameter->weight, cost);
  }
}

int main() {
  para para1;
  para *parameter = &para1;

  srand(69);
  parameter->weight = rand_float() * 10.0f;
  parameter->learn_rate = 1e-2;
  /* large the learning rate like 1e-2 = 10^-2 = 0.01 ; 1e-3=10^-3= 0.001
   * Change weght by large amount
   * since largere will be the cost*l_rate vaule
   * small learning rate change weight by very small amount
   * like 1e-5 = 0.0005 very small chnage in weight
   */
  printf("\n sno.\texpected\tpredicted\t weight\t cost\t");
  for (int j = 0; j < epoch; j++) {
    printf("%d", j);
    perceptron(parameter);
  }
  float n = 0;
  printf("\n Enter number");
  scanf("%f", &n);
  printf("\n %f is answer", n * parameter->weight);
  return 0;
}
