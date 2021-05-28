#ifndef STOS
#define STOS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct e
{

  int dana;
  struct e *nastepny;

};

typedef struct e element;

#endif
