/*
 * Generated by asn1c-0.9.21 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-extended.asn"
 * 	`asn1c -fskeletons-copy`
 */

#ifndef	_GetNameListResponse_H_
#define	_GetNameListResponse_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include "Identifier.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

struct GetNameListResponse__listOfIdentifier 
{
	A_SEQUENCE_OF(Identifier_t) list;

	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
};

/* GetNameListResponse */
typedef struct GetNameListResponse 
{
	struct GetNameListResponse__listOfIdentifier listOfIdentifier;
	BOOLEAN_t	*moreFollows	/* DEFAULT TRUE */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetNameListResponse_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GetNameListResponse;

#ifdef __cplusplus
}
#endif

#endif	/* _GetNameListResponse_H_ */