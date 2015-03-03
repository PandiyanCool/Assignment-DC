/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rdictionary.h"

bool_t
xdr_example (XDR *xdrs, example *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->exfield1))
		 return FALSE;
	 if (!xdr_char (xdrs, &objp->exfield2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_wordwithmeaning_t (XDR *xdrs, wordwithmeaning_t *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->word, 128))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->meaning, 128))
		 return FALSE;
	return TRUE;
}