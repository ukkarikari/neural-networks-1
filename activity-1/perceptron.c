#include <stdio.h>

#define NUM_INPUTS 2
#define NUM_SAMPLES 4
#define THRESH 0.5
#define LEARNING_RATE 0.1
#define EPOCHS 100

int activate(float sum) {

  if (sum >= THRESH) {
    return 1;
  } else {
    return 0;
  }
}

void train(float weights[NUM_INPUTS], float *bias,
           int inputs[NUM_SAMPLES][NUM_INPUTS], int targets[NUM_SAMPLES]) {
  int epoch;

  for (epoch = 0; epoch < EPOCHS; epoch++) {
    int total_error = 0;

    for (int i = 0; i < NUM_SAMPLES; i++) {
      float sum = *bias;

      for (int j = 0; j < NUM_INPUTS; j++) {
        sum += weights[j] * inputs[i][j];
        printf("sum = %f \n", sum);
      }

      int output = activate(sum);
      int error = targets[i] - output;
      total_error += (error < 0) ? -error : error;
      printf("output: %d \nerror: %d\ntotal_error: %d\n", output, error,
             total_error);

      for (int j = 0; j < NUM_INPUTS; j++) {
        weights[j] += LEARNING_RATE * error * inputs[i][j];
      }
      *bias += LEARNING_RATE * error;
    }
    printf("---\nEPOCH %d\n\n", epoch);
    if (total_error == 0) {
      break;
    }
  }
}

int main() {
  int inputs[NUM_SAMPLES][NUM_INPUTS] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

  int targets[NUM_SAMPLES] = {0, 0, 0, 1};

  float weights[NUM_INPUTS] = {0.0, 0.0};

  float bias = 0.0;

  train(weights, &bias, inputs, targets);

  return 0;
}
