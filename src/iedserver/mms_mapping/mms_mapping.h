/*
 *  mms_mapping.h
 *
 *  Copyright 2013 Michael Zillgith
 *
 *  This file is part of libIEC61850.
 *
 *  libIEC61850 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libIEC61850 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libIEC61850.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  See COPYING file for the complete license text.
 */

#ifndef MMS_MAPPING_H_
#define MMS_MAPPING_H_

#include "model.h"
#include "mms_server_connection.h"
#include "mms_device_model.h"
#include "control.h"

typedef enum {
    REPORT_CONTROL_NONE,
    REPORT_CONTROL_VALUE_UPDATE,
    REPORT_CONTROL_VALUE_CHANGED,
    REPORT_CONTROL_QUALITY_CHANGED
} ReportInclusionFlag;

typedef struct sMmsMapping MmsMapping;

MmsMapping*
MmsMapping_create(IedModel* model);

MmsDevice*
MmsMapping_getMmsDeviceModel(MmsMapping* mapping);

void
MmsMapping_setMmsServer(MmsMapping* self, MmsServer server);

void
MmsMapping_installHandlers(MmsMapping* self);

void
MmsMapping_destroy(MmsMapping* mapping);

void
MmsMapping_startEventWorkerThread(MmsMapping* self);

void
MmsMapping_triggerReportObservers(MmsMapping* self, MmsValue* value, ReportInclusionFlag flag);

void
MmsMapping_triggerGooseObservers(MmsMapping* self, MmsValue* value);

void
MmsMapping_enableGoosePublishing(MmsMapping* self);

char*
MmsMapping_getMmsDomainFromObjectReference(char* objectReference, char* buffer);

void
MmsMapping_addControlObject(MmsMapping* self, ControlObject* controlObject);

char*
MmsMapping_createMmsVariableNameFromObjectReference(char* objectReference, FunctionalConstraint fc, char* buffer);

void
MmsMapping_addObservedAttribute(MmsMapping* self, DataAttribute* dataAttribute,
        void* handler);

char*
MmsMapping_getNextNameElement(char* name);

void /* Create PHYCOMADDR ACSI type instance */
MmsMapping_createPhyComAddrStructure(MmsTypeSpecification* namedVariable);

ControlObject*
MmsMapping_getControlObject(MmsMapping* self, MmsDomain* domain, char* lnName, char* coName);

#endif /* MMS_MAPPING_H_ */
