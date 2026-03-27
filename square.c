/*
                        Stochastic-gradient-descent
                        For a single input Data-set
*/

#include <stdio.h>
#include <stdlib.h>

#define epoch 1800
#define data_set 6
int data[][2] = {{1, 1},{2,2},{3,3},{4,4},{5,5},{6,6}};


typedef struct para {
  float input;
  float weight;
  float baise;
  float learn_rate;
} para;
float baise_sum=0, weight_sum=0;
float rand_float() { return (float)rand() / (float)RAND_MAX; }

void perceptron(para *parameter) {
   

}

int main() {
  para para1;
  para *parameter = &para1;

  srand(69);
  parameter->baise = 1.0;
  parameter->weight = rand_float() * 10.0f;
  parameter->learn_rate = 1e-2;
  /* large the learning rate like 1e-2 = 10^-2 = 0.01 ; 1e-3=10^-3= 0.001
   * Change weght by large amount
   * since largere will be the cost*l_rate vaule
   * small learning rate change weight by very small amount
   * like 1e-5 = 0.0005 very small chnage in weight
   */
    printf("\n sno.\texpected\tpredicted\t weight\t weight_gradient\t");    
   float weight_gradient=0;
  for (int j = 0; j < epoch; j++) {
   
  
     baise_sum=0;
     weight_sum=0;
     float y_cap=0;
  for (int i = 0; i < data_set; i++) {
     y_cap = (data[i][0] * parameter->weight) + parameter->baise;
    baise_sum+=data[i][1] - y_cap;
    weight_sum += baise_sum*data[i][0];
    printf("%d\t%d\t%f\t%f\t%f\n",j, data[i][1], y_cap, parameter->weight, weight_gradient);
  }
    //baise cost
    float baise_gradient = (baise_sum*2)/data_set;
    // baise update
    parameter->baise -= parameter->learn_rate*baise_gradient;
    
      //weight cost
    weight_gradient = (weight_sum*-2)/data_set;
    parameter->weight-= parameter->learn_rate*weight_gradient;  
   
     

   }


 /* float n = 0;
  printf("\n Enter number");
  scanf("%f", &n);
  printf("\n %f is answer", n * parameter->weight);
  */
  return 0;
}
