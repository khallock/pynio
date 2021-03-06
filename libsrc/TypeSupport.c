
/*
 *      $Id: TypeSupport.c.sed,v 1.7 2010-04-14 21:29:48 huangwei Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:29:40 MST 1995
 *
 *	Description:	
 */
#ifdef NIO_LIB_ONLY
#include "niohlu.h"
#include "nioNresDB.h"
#else
#include <ncarg/hlu/hlu.h>
#include <ncarg/hlu/NresDB.h>
#endif
#include "defs.h"
#include "NclType.h"
#include "TypeSupport.h"
#include "NclMdInc.h"
#include "NclTypelist.h"
#include <ctype.h>


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclmultiply
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.multiply!= NULL) {
		return((*(the_type->type_class.multiply))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.multiply != NULL) {
				return((*(tmp->type_class.multiply))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclmultiply_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.multiply_type!= NULL) {
		return((*(the_type->type_class.multiply_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.multiply_type != NULL) {
				return((*(tmp->type_class.multiply_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Ncldivide
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.divide!= NULL) {
		return((*(the_type->type_class.divide))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.divide != NULL) {
				return((*(tmp->type_class.divide))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Ncldivide_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.divide_type!= NULL) {
		return((*(the_type->type_class.divide_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.divide_type != NULL) {
				return((*(tmp->type_class.divide_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclplus
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.plus!= NULL) {
		return((*(the_type->type_class.plus))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.plus != NULL) {
				return((*(tmp->type_class.plus))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclplus_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.plus_type!= NULL) {
		return((*(the_type->type_class.plus_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.plus_type != NULL) {
				return((*(tmp->type_class.plus_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclminus
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.minus!= NULL) {
		return((*(the_type->type_class.minus))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.minus != NULL) {
				return((*(tmp->type_class.minus))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclminus_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.minus_type!= NULL) {
		return((*(the_type->type_class.minus_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.minus_type != NULL) {
				return((*(tmp->type_class.minus_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclexponent
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.exponent!= NULL) {
		return((*(the_type->type_class.exponent))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.exponent != NULL) {
				return((*(tmp->type_class.exponent))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclexponent_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.exponent_type!= NULL) {
		return((*(the_type->type_class.exponent_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.exponent_type != NULL) {
				return((*(tmp->type_class.exponent_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclmod
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.mod!= NULL) {
		return((*(the_type->type_class.mod))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.mod != NULL) {
				return((*(tmp->type_class.mod))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclmod_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.mod_type!= NULL) {
		return((*(the_type->type_class.mod_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.mod_type != NULL) {
				return((*(tmp->type_class.mod_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclsel_lt
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.sel_lt!= NULL) {
		return((*(the_type->type_class.sel_lt))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.sel_lt != NULL) {
				return((*(tmp->type_class.sel_lt))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclsel_lt_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.sel_lt_type!= NULL) {
		return((*(the_type->type_class.sel_lt_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.sel_lt_type != NULL) {
				return((*(tmp->type_class.sel_lt_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclsel_gt
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.sel_gt!= NULL) {
		return((*(the_type->type_class.sel_gt))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.sel_gt != NULL) {
				return((*(tmp->type_class.sel_gt))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclsel_gt_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.sel_gt_type!= NULL) {
		return((*(the_type->type_class.sel_gt_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.sel_gt_type != NULL) {
				return((*(tmp->type_class.sel_gt_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclgt
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.gt!= NULL) {
		return((*(the_type->type_class.gt))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.gt != NULL) {
				return((*(tmp->type_class.gt))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclgt_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.gt_type!= NULL) {
		return((*(the_type->type_class.gt_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.gt_type != NULL) {
				return((*(tmp->type_class.gt_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Ncllt
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.lt!= NULL) {
		return((*(the_type->type_class.lt))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.lt != NULL) {
				return((*(tmp->type_class.lt))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Ncllt_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.lt_type!= NULL) {
		return((*(the_type->type_class.lt_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.lt_type != NULL) {
				return((*(tmp->type_class.lt_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclge
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.ge!= NULL) {
		return((*(the_type->type_class.ge))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.ge != NULL) {
				return((*(tmp->type_class.ge))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclge_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.ge_type!= NULL) {
		return((*(the_type->type_class.ge_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.ge_type != NULL) {
				return((*(tmp->type_class.ge_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclle
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.le!= NULL) {
		return((*(the_type->type_class.le))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.le != NULL) {
				return((*(tmp->type_class.le))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclle_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.le_type!= NULL) {
		return((*(the_type->type_class.le_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.le_type != NULL) {
				return((*(tmp->type_class.le_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclne
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.ne!= NULL) {
		return((*(the_type->type_class.ne))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.ne != NULL) {
				return((*(tmp->type_class.ne))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclne_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.ne_type!= NULL) {
		return((*(the_type->type_class.ne_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.ne_type != NULL) {
				return((*(tmp->type_class.ne_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Ncleq
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.eq!= NULL) {
		return((*(the_type->type_class.eq))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.eq != NULL) {
				return((*(tmp->type_class.eq))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Ncleq_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.eq_type!= NULL) {
		return((*(the_type->type_class.eq_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.eq_type != NULL) {
				return((*(tmp->type_class.eq_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclncl_and
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.ncl_and!= NULL) {
		return((*(the_type->type_class.ncl_and))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.ncl_and != NULL) {
				return((*(tmp->type_class.ncl_and))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Ncland_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.and_type!= NULL) {
		return((*(the_type->type_class.and_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.and_type != NULL) {
				return((*(tmp->type_class.and_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclncl_or
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.ncl_or!= NULL) {
		return((*(the_type->type_class.ncl_or))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.ncl_or != NULL) {
				return((*(tmp->type_class.ncl_or))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclor_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.or_type!= NULL) {
		return((*(the_type->type_class.or_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.or_type != NULL) {
				return((*(tmp->type_class.or_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportOpTemplate.c.sed,v 1.1 1995-01-28 01:53:13 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclncl_xor
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, ng_size_t nlhs, ng_size_t nrhs)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
ng_size_t nlhs;
ng_size_t nrhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.ncl_xor!= NULL) {
		return((*(the_type->type_class.ncl_xor))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.ncl_xor != NULL) {
				return((*(tmp->type_class.ncl_xor))(result, lhs, rhs, lhs_m, rhs_m, nlhs, nrhs));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclxor_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.xor_type!= NULL) {
		return((*(the_type->type_class.xor_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.xor_type != NULL) {
				return((*(tmp->type_class.xor_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportMonoOpTemplate.c.sed,v 1.1 1995-01-28 01:53:09 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:05 MST 1995
 *
 *	Description:	
 */






NhlErrorTypes _Nclncl_not
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, NclScalar* lhs_m, ng_size_t nlhs)
#else
(the_type, result, lhs, lhs_m, nlhs)
NclTypeClass the_type;
void * result;
void* lhs;
NclScalar* lhs_m;
ng_size_t nlhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.ncl_not!= NULL) {
		return((*(the_type->type_class.ncl_not))(result, lhs, NULL, lhs_m, NULL, nlhs, 0));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.ncl_not != NULL) {
				return((*(tmp->type_class.ncl_not))(result, lhs, NULL, lhs_m, NULL, nlhs, 0));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclnot_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.not_type!= NULL) {
		return((*(the_type->type_class.not_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.not_type != NULL) {
				return((*(tmp->type_class.not_type))());
			} else {
				tmp =(NclTypeClass) tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportMonoOpTemplate.c.sed,v 1.1 1995-01-28 01:53:09 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:05 MST 1995
 *
 *	Description:	
 */






NhlErrorTypes _Nclneg
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, NclScalar* lhs_m, ng_size_t nlhs)
#else
(the_type, result, lhs, lhs_m, nlhs)
NclTypeClass the_type;
void * result;
void* lhs;
NclScalar* lhs_m;
ng_size_t nlhs;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.neg!= NULL) {
		return((*(the_type->type_class.neg))(result, lhs, NULL, lhs_m, NULL, nlhs, 0));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.neg != NULL) {
				return((*(tmp->type_class.neg))(result, lhs, NULL, lhs_m, NULL, nlhs, 0));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclneg_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.neg_type!= NULL) {
		return((*(the_type->type_class.neg_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.neg_type != NULL) {
				return((*(tmp->type_class.neg_type))());
			} else {
				tmp =(NclTypeClass) tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


/*
 *      $Id: TypeSupportMatTemplate.c.sed,v 1.1.4.1 2008-03-28 20:37:53 grubin Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:30:15 MST 1995
 *
 *	Description:	
 */





NhlErrorTypes _Nclmat
#if	NhlNeedProto
(NclTypeClass the_type, void * result, void* lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m, int nlhs_dims,ng_size_t* lhs_dimsizes, int nrhs_dims, ng_size_t* rhs_dimsizes)
#else
(the_type, result, lhs, rhs, lhs_m, rhs_m, nlhs_dims,lhs_dimsizes, nrhs_dims,rhs_dimsizes)
NclTypeClass the_type;
void * result;
void* lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
int nlhs_dims;
ng_size_t *lhs_dimsizes;
int nrhs_dims;
ng_size_t *rhs_dimsizes;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.mat!= NULL) {
		return((*(the_type->type_class.mat))(result, lhs, rhs, lhs_m, rhs_m, nlhs_dims,lhs_dimsizes, nrhs_dims,rhs_dimsizes));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.mat != NULL) {
				return((*(the_type->type_class.mat))(result, lhs, rhs, lhs_m, rhs_m, nlhs_dims,lhs_dimsizes, nrhs_dims,rhs_dimsizes));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}


NclTypeClass _Nclmat_type
#if	NhlNeedProto
(NclTypeClass the_type)
#else
(the_type)
NclTypeClass the_type;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.mat_type!= NULL) {
		return((*(the_type->type_class.mat_type))());
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.mat_type != NULL) {
				return((*(tmp->type_class.mat_type))());
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NULL);
	}
}


NhlErrorTypes _NclInitTypeClasses
#if	NhlNeedProto
(void)
#else
()
#endif
{
	_NclInitClass(nclTypedoubleClass);
	_NclInitClass(nclTypefloatClass);
	_NclInitClass(nclTypelongClass);
	_NclInitClass(nclTypeintClass);
	_NclInitClass(nclTypeshortClass);
	_NclInitClass(nclTypelogicalClass);
	_NclInitClass(nclTypebyteClass);
	_NclInitClass(nclTypecharClass);
	_NclInitClass(nclTypestringClass);
	_NclInitClass(nclTypeobjClass);
	_NclInitClass(nclTypeint64Class);
	_NclInitClass(nclTypeushortClass);
	_NclInitClass(nclTypeuintClass);
	_NclInitClass(nclTypeulongClass);
	_NclInitClass(nclTypeuint64Class);
	_NclInitClass(nclTypeubyteClass);
	_NclInitClass(nclTypelistClass);
	return(NhlNOERROR);
}

NhlErrorTypes _Nclcmpf
#if	NhlNeedProto
(NclTypeClass the_type, void *lhs, void* rhs, NclScalar* lhs_m, NclScalar* rhs_m,int digits,double *result)
#else
(the_type,lhs,rhs,lhs_m,rhs_m,digits,result)
NclTypeClass the_type;
void *lhs;
void* rhs;
NclScalar* lhs_m;
NclScalar* rhs_m;
int digits;
double *result;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.cmpf!= NULL) {
		return((*(the_type->type_class.cmpf))(lhs,rhs,lhs_m,rhs_m,digits,result));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.cmpf != NULL) {
				return((*(tmp->type_class.cmpf))(lhs,rhs,lhs_m,rhs_m,digits,result));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
	}
	return NhlFATAL;
}

NclTypeClass _NclTypeEnumToTypeClass
#if	NhlNeedProto
(NclObjTypes obj_type_enum)
#else
(obj_type_enum)
NclObjTypes obj_type_enum;
#endif
{
	switch(obj_type_enum) {
	case Ncl_Typedouble:
		return((NclTypeClass)nclTypedoubleClass);
	case Ncl_Typefloat:
		return((NclTypeClass)nclTypefloatClass);
	case Ncl_Typelong:
		return((NclTypeClass)nclTypelongClass);
	case Ncl_Typeint:
		return((NclTypeClass)nclTypeintClass);
	case Ncl_Typeshort:
		return((NclTypeClass)nclTypeshortClass);
	case Ncl_Typebyte:
		return((NclTypeClass)nclTypebyteClass);
	case Ncl_Typestring:
		return((NclTypeClass)nclTypestringClass);
	case Ncl_Typechar:
		return((NclTypeClass)nclTypecharClass);
	case Ncl_Typelogical:
		return((NclTypeClass)nclTypelogicalClass);
	case Ncl_Typeint64:
		return((NclTypeClass)nclTypeint64Class);
	case Ncl_Typeushort:
		return((NclTypeClass)nclTypeushortClass);
	case Ncl_Typeuint:
		return((NclTypeClass)nclTypeuintClass);
	case Ncl_Typeulong:
		return((NclTypeClass)nclTypeulongClass);
	case Ncl_Typeuint64:
		return((NclTypeClass)nclTypeuint64Class);
	case Ncl_Typeubyte:
		return((NclTypeClass)nclTypeubyteClass);
	case Ncl_Typeobj:
		return((NclTypeClass)nclTypeobjClass);
	case Ncl_Typelist:
		return((NclTypeClass)nclTypelistClass);
	default:
		return((NclTypeClass)nclTypeClass);
	}
}

NhlErrorTypes _Nclprint
#if	NhlNeedProto
(NclTypeClass the_type,FILE *fp,void* val)
#else
(the_type,fp,val)
NclTypeClass the_type;
FILE *fp;
void* val;
#endif
{
	NclTypeClass tmp;

	if(the_type->type_class.print != NULL) {
		return((*(the_type->type_class.print))(fp,val));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.print!= NULL) {
				return((*(tmp->type_class.print))(fp,val));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
	}
	return NhlFATAL;

}

NhlErrorTypes _Nclcoerce
#if	NhlNeedProto
(NclTypeClass to_type, void * result, void* from, ng_size_t n, NclScalar* from_m, NclScalar* to_m, NclTypeClass from_type)
#else
(t0_type, result, from, n, from_m, to_m, from_type)
NclTypeClass to_type;
void * result;
void* from;
ng_size_t n;
NclScalar* from_m;
NclScalar* to_m;
NclTypeClass from_type;
#endif
{
	NclTypeClass tmp;

	if(to_type->type_class.coerce != NULL) {
		return((*(to_type->type_class.coerce))(result,from,n,from_m,to_m,from_type));
	} else {
		tmp = (NclTypeClass)to_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.coerce != NULL) {
				return((*(tmp->type_class.coerce))(result,from,n,from_m,to_m,from_type));
			} else {
				tmp =(NclTypeClass) tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}

NhlErrorTypes _Nclreset_mis
#if	NhlNeedProto
(NclTypeClass the_type,void *val, NclScalar* old_m, NclScalar * new_m,ng_size_t nval)
#else
(the_type,val, old_m, new_m,nval)
NclTypeClass the_type;
void *val;
NclScalar* old_m;
NclScalar* new_m;
ng_size_t nval;
#endif
{
	NclTypeClass tmp;
	if(the_type->type_class.reset_mis != NULL) {
		return((*(the_type->type_class.reset_mis))(val,old_m,new_m,nval));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.reset_mis != NULL) {
				return((*(tmp->type_class.reset_mis))(val,old_m,new_m,nval));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}
}

NclMonoTypes _Nclis_mono
#if	NhlNeedProto
(NclTypeClass the_type, void *val, NclScalar* val_m, ng_size_t nval)
#else
(the_type, val, val_m, nval)
NclTypeClass the_type;
void *val;
NclScalar* val_m;
ng_size_t nval;
#endif
{
	NclTypeClass tmp;
	if(the_type->type_class.is_mono != NULL) {
		return((*(the_type->type_class.is_mono))(val, val_m, nval));
	} else {
		tmp = (NclTypeClass)the_type->obj_class.super_class;
		while(tmp != (NclTypeClass)nclTypeClass) {
			if(tmp->type_class.is_mono != NULL) {
				return((*(tmp->type_class.is_mono))(val, val_m, nval));
			} else {
				tmp = (NclTypeClass)tmp->obj_class.super_class;
			}
		}
		return(NhlFATAL);
	}

}

NclQuark _NclGetLower
(
	NclQuark qstr
	)
{
	char *buf;
	char buffer[256];
	char *cp;
	char *instr = NrmQuarkToString(qstr);
	int size;
	NrmQuark outq;
	
	if (! instr) {
	        return NrmNULLQUARK;
        }
        size  = strlen(instr);
	if (size < 256) {
		buf = buffer;
	}
	else {
		buf = NclMalloc(size + 1);
	}
	strncpy(buf,instr,size);
	buf[size] = '\0';
	for (cp = buf; *cp != '\0'; cp++) {
		*cp = tolower(*cp);
	}
	outq = NrmStringToQuark(buffer);

	if (buf != buffer)
		NclFree(buf);

	return outq;
}

NhlErrorTypes _NclSetDefaultFillValues
(
	int default_type
)
{
	if (default_type == NCL_5_DEFAULT_FILLVALUES) {
		((NclTypeClass)nclTypeshortClass)->type_class.default_mis.shortval = -99;
		((NclTypeClass)nclTypeintClass)->type_class.default_mis.intval = -999;
		((NclTypeClass)nclTypelongClass)->type_class.default_mis.longval = -9999;
		((NclTypeClass)nclTypeint64Class)->type_class.default_mis.int64val = -99999999;
		((NclTypeClass)nclTypeushortClass)->type_class.default_mis.ushortval = 0;
		((NclTypeClass)nclTypeuintClass)->type_class.default_mis.uintval = 0;
		((NclTypeClass)nclTypeulongClass)->type_class.default_mis.ulongval = 0;
		((NclTypeClass)nclTypeuint64Class)->type_class.default_mis.uint64val = 0;
		((NclTypeClass)nclTypeubyteClass)->type_class.default_mis.ubyteval = 0;
		((NclTypeClass)nclTypefloatClass)->type_class.default_mis.floatval = -999.0;
		((NclTypeClass)nclTypedoubleClass)->type_class.default_mis.doubleval = -9999.0;
		((NclTypeClass)nclTypecharClass)->type_class.default_mis.charval = 0;
		((NclTypeClass)nclTypebyteClass)->type_class.default_mis.byteval = (char) 0xff;
		((NclTypeClass)nclTypestringClass)->type_class.default_mis.stringval = NrmStringToQuark("missing");
		((NclTypeClass)nclTypelogicalClass)->type_class.default_mis.logicalval = -1;
	}
	else if (default_type == NCL_6_DEFAULT_FILLVALUES) {
		((NclTypeClass)nclTypeshortClass)->type_class.default_mis.shortval = -32767;
		((NclTypeClass)nclTypeintClass)->type_class.default_mis.intval = -2147483647;
		((NclTypeClass)nclTypelongClass)->type_class.default_mis.longval = -2147483647;
		((NclTypeClass)nclTypeint64Class)->type_class.default_mis.int64val = (long long)-9223372036854775806LL;
		((NclTypeClass)nclTypeushortClass)->type_class.default_mis.ushortval = 65535;
		((NclTypeClass)nclTypeuintClass)->type_class.default_mis.uintval = 4294967295U;
		((NclTypeClass)nclTypeulongClass)->type_class.default_mis.ulongval = 4294967295U;
		((NclTypeClass)nclTypeuint64Class)->type_class.default_mis.uint64val = (unsigned long long)18446744073709551614ULL;
		((NclTypeClass)nclTypeubyteClass)->type_class.default_mis.ubyteval = 255;
		((NclTypeClass)nclTypefloatClass)->type_class.default_mis.floatval = 9.9692099683868690e+36f;
		((NclTypeClass)nclTypedoubleClass)->type_class.default_mis.doubleval = 9.9692099683868690e+36;
		((NclTypeClass)nclTypecharClass)->type_class.default_mis.charval = 0;
		((NclTypeClass)nclTypebyteClass)->type_class.default_mis.byteval = -127;
		((NclTypeClass)nclTypestringClass)->type_class.default_mis.stringval = NrmStringToQuark("missing");
		((NclTypeClass)nclTypelogicalClass)->type_class.default_mis.logicalval = -1;
	}
	return NhlNOERROR;
}

NhlErrorTypes _NclGetDefaultFillValue
(NclBasicDataTypes type,
 NclScalar *def_val)
{
	char *ctype = NULL;
	NclTypeClass class = NULL;

	ctype = _NclBasicDataTypeToName(type);
	if (ctype) {
		class = _NclNameToTypeClass(NrmStringToQuark(ctype));
		if (class) {
				*def_val = class->type_class.default_mis;
				return NhlNOERROR;
                }
        }
	return NhlFATAL;
}
