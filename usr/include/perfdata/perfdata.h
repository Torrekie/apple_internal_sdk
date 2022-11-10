/* perfdata.h - Created by Nick Chan on 11/11/2022 */

#ifndef PERFDATA_PERFDATA_H
#define PERFDATA_PERFDATA_H
#include <stdint.h>

#define PDUNIT_CUSTOM(x) "#\"" x "\""

typedef void* pdwriter_t;
extern char* pdunit_B;

void pdwriter_new_value(pdwriter_t pdWriter, const char* nameBuffer, char* pdUnit, double numd);
void pdwriter_close(pdwriter_t pdWriter);
pdwriter_t pdwriter_open(const char* pdFile, const char* pdName, int param_3, int param_4);
void pdwriter_record_variable_str(pdwriter_t pdWriter, char *key, const char *valueBuf);
#endif
