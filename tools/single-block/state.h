#ifndef STATE_H
#define STATE_H

#include "grid.h"
#include "problem.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	double *jc;
	double *phi;
	double *rhs;
	double *eps;
	double *debye;
	double *sol;
} state;

state *state_create(grid*, problem*);

void state_destroy(state*);

#ifdef __cplusplus
}
#endif

#endif
