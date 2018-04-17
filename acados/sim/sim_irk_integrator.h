/*
 *    This file is part of acados.
 *
 *    acados is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    acados is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with acados; if not, write to the Free Software Foundation,
 *    Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef ACADOS_SIM_SIM_IRK_INTEGRATOR_H_
#define ACADOS_SIM_SIM_IRK_INTEGRATOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "acados/sim/sim_common.h"
#include "acados/utils/types.h"



typedef struct
{
	/* external functions */
	// implicit ode
	external_function_generic *impl_ode_fun;
	// jac_x implicit ode
	external_function_generic *impl_ode_jac_x;
	// jac_xdot implicit ode
	external_function_generic *impl_ode_jac_xdot;
	// jac_u implicit ode
	external_function_generic *impl_ode_jac_u;
    // implicit ode (included) & jac_x & jax_xdot
    external_function_generic *impl_ode_fun_jac_x_xdot;
	// jax_x & jac_u implicit ode
    external_function_generic *impl_ode_jac_x_u;
	// jax_x & jac_xdot & jac_u implicit ode
    external_function_generic *impl_ode_jac_x_xdot_u;

} irk_model;




typedef struct
{

    struct blasfeo_dmat *JGK; // jacobian of G over K (nx*ns, nx*ns)
    struct blasfeo_dmat *JGf; // jacobian of G over x and u (nx*ns, nx+nu);
    struct blasfeo_dmat *JKf; // jacobian of K over x and u (nx*ns, nx+nu);
    struct blasfeo_dmat *S_forw; // forward sensitivities

    struct blasfeo_dvec *rG; // residuals of G (nx*ns)
    struct blasfeo_dvec *K; // internal variables (nx*ns)
    struct blasfeo_dvec *xt; // temporary x
    struct blasfeo_dvec *xn; // x at each integration step

    struct blasfeo_dvec *lambda; // adjoint seed (nx+nu)
    struct blasfeo_dvec *lambdaK; // auxiliary variable (nx*ns)

    double *rGt; // temporary residuals of G (nx, 1)
    double *jac_out; // temporary Jacobian of ode (nx, 2*nx+nu)
    double *Jt; // temporary Jacobian of ode (nx, nx)
    double *S_adj_w;
    int *ipiv; // index of pivot vector

    struct blasfeo_dvec *xn_traj; // xn trajectory
    struct blasfeo_dvec *K_traj;  // K trajectory
    struct blasfeo_dmat *JG_traj; // JGK trajectory

} sim_irk_workspace;



//
int sim_irk_model_calculate_size(void *config, sim_dims *dims);
//
void *sim_irk_model_assign(void *config, sim_dims *dims, void *raw_memory);
//
int sim_irk_model_set_function(void *model_, sim_function_t fun_type, void *fun);
//
int sim_irk_opts_calculate_size(void *config, sim_dims *dims);
//
void *sim_irk_opts_assign(void *config, sim_dims *dims, void *raw_memory);
//
void sim_irk_opts_initialize_default(void *config, sim_dims *dims, void *opts_);
//
void sim_irk_opts_update(void *config_, sim_dims *dims, void *opts_);
//
int sim_irk_memory_calculate_size(void *config, sim_dims *dims, void *opts_);
//
void *sim_irk_memory_assign(void *config, sim_dims *dims, void *opts_, void *raw_memory);
//
int sim_irk(void *config, sim_in *in, sim_out *out, void *opts_, void *mem_, void *work_);
//
int sim_irk_workspace_calculate_size(void *config, sim_dims *dims, void *opts_);
//
void sim_irk_config_initialize_default(void *config);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // ACADOS_SIM_SIM_IRK_INTEGRATOR_H_
