

/*
                                 And Gate neural netwrok 
                      compile it with gcc and_gate.c -o and-gate -lm
*/

#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#define epoch 300000
#define data_set 4
int data[][3] = {{1, 1, 1}, {1, 0, 0}, {0, 0, 0}, {0, 1, 0}};

typedef struct para {
  float input;
  float weight_1;
  float weight_2;
  float bias;
  float learn_rate;
} para;
float bias_sum = 0, weight1_sum = 0, weight2_sum = 0;
float rand_float() { return (float)rand() / (float)RAND_MAX; }



float sigmoid(float x) { return 1.0 / (1.0 + exp(-x)); }

int main() {
  para para1;
  para *parameter = &para1;

  srand(69);
  parameter->bias = 1.0;
  parameter->weight_1 = rand_float() * 10.0f;
  parameter->weight_2 = rand_float() * 10.0f;
  parameter->learn_rate = 1e-1;
 
  printf("\n sno.\texpected\tpredicted\t weight\t weight_gradient\t");
  float weight_gradient_1 = 0;
  float weight_gradient_2 = 0;
  for (int j = 0; j < epoch; j++) {

    bias_sum = 0;
    weight1_sum = 0;
    weight2_sum = 0;
    float y_cap = 0;
    for (int i = 0; i < data_set; i++) {
      y_cap = sigmoid((data[i][0] * parameter->weight_1) +
                      (data[i][1] * parameter->weight_2) + parameter->bias);
      bias_sum += data[i][2] - y_cap;
      weight1_sum += (data[i][2] - y_cap) * data[i][0];
      weight2_sum += (data[i][2] - y_cap) * data[i][1];
      printf("%d\t%d\t%d\t%f\t%f\t%f\n", j, data[i][0], data[i][1], y_cap,
             weight_gradient_1, weight_gradient_2);
    }
    // bias cost
    float bias_gradient = (bias_sum * -2) / data_set;
    // bias update
    parameter->bias -= parameter->learn_rate * bias_gradient;

    // weight cost
    weight_gradient_1 = (weight1_sum * -2) / data_set;
    weight_gradient_2 = (weight2_sum * -2) / data_set;
    parameter->weight_1 -= parameter->learn_rate * weight_gradient_1;
    parameter->weight_2 -= parameter->learn_rate * weight_gradient_2;
  }

  float x1 = 0, x2 = 0;
    int ch=1;
  while (ch!=0) {


  printf("\n Enter two  number");
  scanf("%f %f", &x1, &x2);
  printf("\n %f is answer",
         sigmoid((x1 * parameter->weight_1) + (x2 * parameter->weight_2) +
                 parameter->bias));

  printf("\n\nDo u want to exit? 0 for yes and 1 for no\t\n");
  scanf("%d",&ch);

}
  return 0;
}
