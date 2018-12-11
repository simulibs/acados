// system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// acados
#include "acados/sim/sim_common.h"
#include "acados_c/sim_interface.h"
// mex
#include "mex.h"



void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
	{

//	mexPrintf("\nin sim_set\n");

	long long *ptr;

	/* RHS */

	// C_sim

	// config
	ptr = (long long *) mxGetData( mxGetField( prhs[0], 0, "config" ) );
	sim_solver_config *config = (sim_solver_config *) ptr[0];
	// dims
	ptr = (long long *) mxGetData( mxGetField( prhs[0], 0, "dims" ) );
	void *dims = (void *) ptr[0];
	// out
	ptr = (long long *) mxGetData( mxGetField( prhs[0], 0, "out" ) );
	sim_out *out = (sim_out *) ptr[0];

	// field
	char *field = mxArrayToString( prhs[1] );
//	mexPrintf("\n%s\n", field);


	// TODO implement with LHS !!!!!
	// value
	if(!strcmp(field, "xn"))
		{
		double *xn = mxGetPr( prhs[2] );
		sim_out_get(config, dims, out, "xn", xn);
		}
	else
		{
		mexPrintf("\nsim_get: field not supported: %s\n", field);
		return;
		}



	/* return */

	return;

	}

