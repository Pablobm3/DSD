/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calcul.h"

bool_t
xdr_inputs (XDR *xdrs, inputs *objp)
{
	register int32_t *buf;

	 if (!xdr_float (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->b))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->c))
		 return FALSE;
	return TRUE;
}
