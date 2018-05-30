#include "stella_mat.h"
#include "stella_pc.h"


#undef __FUNCT__
#define __FUNCT__ "stella_pc_create"
PetscErrorCode stella_pc_create(stella_pc **pc)
{
	stella_pc *ctx;

	ctx = (stella_pc*) malloc(sizeof(stella_pc));
	*pc = ctx;

	return 0;
}


#undef __FUNCT__
#define __FUNCT__ "stella_pc_setup"
PetscErrorCode stella_pc_setup(PC pc)
{
	#ifdef WITH_BOXMG
	PetscErrorCode ierr;
	Mat pmat;
	stella_pc *pc_ctx;
	stella_bmg_mat *mat_ctx;

	ierr = PCGetOperators(pc,PETSC_NULL,&pmat);CHKERRQ(ierr);
	ierr = PCShellGetContext(pc, (void**)&pc_ctx);CHKERRQ(ierr);
	ierr = MatShellGetContext(pmat, (void**)&mat_ctx);CHKERRQ(ierr);

	pc_ctx->nd = mat_ctx->nd;
	if (pc_ctx->nd == 2)
		pc_ctx->solver2 = bmg2_solver_create(&mat_ctx->op2);
	else
		pc_ctx->solver3 = bmg3_solver_create(&mat_ctx->op3);
	#endif

	return 0;
}


#undef __FUNCT__
#define __FUNCT__ "stella_pc_apply"
PetscErrorCode stella_pc_apply(PC pc, Vec x, Vec y)
{
	#ifdef WITH_BOXMG
	PetscErrorCode ierr;
	stella_pc *pc_ctx;
	double *yarr;
	const double *xarr;

	ierr = PCShellGetContext(pc, (void**)&pc_ctx);CHKERRQ(ierr);
	ierr = VecGetArrayRead(x, &xarr);CHKERRQ(ierr);
	ierr = VecGetArray(y, &yarr);CHKERRQ(ierr);

	if (pc_ctx->nd == 2)
		bmg2_solver_run(pc_ctx->solver2, yarr, xarr);
	else
		bmg3_solver_run(pc_ctx->solver3, yarr, xarr);

	ierr = VecRestoreArrayRead(x, &xarr);CHKERRQ(ierr);
	ierr = VecRestoreArray(y, &yarr);CHKERRQ(ierr);
	#endif

	return 0;
}



#undef __FUNCT__
#define __FUNCT__ "stella_pc_destroy"
PetscErrorCode stella_pc_destroy(PC pc)
{
	PetscErrorCode ierr;
	stella_pc *pc_ctx;

	ierr = PCShellGetContext(pc, (void**)&pc_ctx);CHKERRQ(ierr);
	free(pc_ctx);

	return 0;
}
