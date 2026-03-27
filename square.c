/*
                            predict a square                
                        trained weight	1.000000
                                bais  -0.000000
                        
                                hypothesis
                        (y=weight*input^2+bais)
*/

#include <stdio.h>
#include <stdlib.h>

#define epoch 180000
#define data_set 6
int data[][2] = {{1, 1},{2,4},{3,9},{4,16},{5,25},{6,36}};


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
 
    printf("\n sno.\texpected\tpredicted\t weight\t weight_gradient\tBias gradient\n");    
   float weight_gradient=0, baise_gradient=0 ;
  for (int j = 0; j < epoch; j++) {
   
  
     baise_sum=0;
     weight_sum=0;
     float y_cap=0;
  for (int i = 0; i < data_set; i++) {
      // y = wx+c -> for lnear output
      //  y = wx^2+c -> for quadratic output
      //  since y or prediation depdens on x 
     y_cap = (data[i][0] * data[i][0] * parameter->weight) + parameter->baise;
    baise_sum+=data[i][1] - y_cap; 
    weight_sum += (data[i][1] - y_cap)*data[i][0];
    printf("%d\t%d\t%f\t%f\t%f\t%f\n",j, data[i][1], y_cap, parameter->weight, weight_gradient,baise_gradient);
  }
    //baise cost
 baise_gradient   = (baise_sum*-2)/data_set;
    // baise update
    parameter->baise -= parameter->learn_rate*baise_gradient;
    
      //weight cost
    weight_gradient = (weight_sum*-2)/data_set;
    parameter->weight-= parameter->learn_rate*weight_gradient;  
   
     

   }

 printf("\n final output\n weight\t%f\nbais\t%f",parameter->weight,parameter->baise);
  float n = 0;
  printf("\n Enter number");
  scanf("%f", &n);
  printf("\n %f is answer\n\n", (n*n* parameter->weight)+parameter->baise);
  
  return 0;
}
