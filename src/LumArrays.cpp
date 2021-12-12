#include "LumArrays.h"

/// <summary>
/// Sum the first numElements in an array.
/// </summary>
/// <param name="vec"></param>
/// <param name="numElements"></param>
/// <returns></returns>
int sum(int* vec, unsigned int numElements) {
  int sumVec = 0;
  for(int k=0;k<numElements;k++)
  {
    sumVec += vec[k];
  }

  return sumVec;
}

float sum(float* vec, unsigned int numElements) {
  float sumVec = 0;
  for(int k=0;k<numElements;k++)
  {
    sumVec += vec[k];
  }

  return sumVec;
}

int average(int* vec, unsigned int numElements) {
  int sumVec = sum(vec,numElements);
  return sumVec/numElements;
}

float average(float* vec, unsigned int numElements) {
  float sumVec = sum(vec,numElements);
  return sumVec/numElements;
}