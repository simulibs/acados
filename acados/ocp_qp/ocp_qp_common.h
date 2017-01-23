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

#ifndef ACADOS_OCP_QP_OCP_QP_COMMON_H_
#define ACADOS_OCP_QP_OCP_QP_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "acados/utils/types.h"

typedef struct ocp_qp_in_ {
    int_t N;
    const int_t *nx;
    const int_t *nu;
    const int_t *nb;
    const int_t *nc;
    const real_t **A;
    const real_t **B;
    const real_t **b;
    const real_t **Q;
    const real_t **S;
    const real_t **R;
    const real_t **q;
    const real_t **r;
    const int_t **idxb;
    const real_t **lb;
    const real_t **ub;
    const real_t **Cx;
    const real_t **Cu;
    const real_t **lc;
    const real_t **uc;
} ocp_qp_in;

typedef struct ocp_qp_out_ {
    real_t **x;
    real_t **u;
    real_t **pi;
    real_t **lam;
} ocp_qp_out;

typedef struct qp_solver_ {
    int_t (*fun)(ocp_qp_in*, ocp_qp_out*, void*, void*);
    ocp_qp_in *in;
    ocp_qp_out *out;
    void *mem;
    void *work;
} qp_solver;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // ACADOS_OCP_QP_OCP_QP_COMMON_H_
