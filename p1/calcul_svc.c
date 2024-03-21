/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calcul.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
calculate_prog1_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		inputs sum_1_arg;
		inputs res_1_arg;
		inputs mult_1_arg;
		inputs div_1_arg;
		inputs pot_1_arg;
		vectores vector_sum_1_arg;
		vectores vector_res_1_arg;
		vectores vector_mult_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case sum:
		_xdr_argument = (xdrproc_t) xdr_inputs;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) sum_1_svc;
		break;

	case res:
		_xdr_argument = (xdrproc_t) xdr_inputs;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) res_1_svc;
		break;

	case mult:
		_xdr_argument = (xdrproc_t) xdr_inputs;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) mult_1_svc;
		break;

	case div:
		_xdr_argument = (xdrproc_t) xdr_inputs;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) div_1_svc;
		break;

	case pot:
		_xdr_argument = (xdrproc_t) xdr_inputs;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) pot_1_svc;
		break;

	case vector_sum:
		_xdr_argument = (xdrproc_t) xdr_vectores;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) vector_sum_1_svc;
		break;

	case vector_res:
		_xdr_argument = (xdrproc_t) xdr_vectores;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) vector_res_1_svc;
		break;

	case vector_mult:
		_xdr_argument = (xdrproc_t) xdr_vectores;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) vector_mult_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (CALCULATE_PROG1, CALCULATE_VER1);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, CALCULATE_PROG1, CALCULATE_VER1, calculate_prog1_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALCULATE_PROG1, CALCULATE_VER1, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, CALCULATE_PROG1, CALCULATE_VER1, calculate_prog1_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALCULATE_PROG1, CALCULATE_VER1, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
