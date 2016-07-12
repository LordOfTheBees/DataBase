#include "deleteValue.h"

int deleteVal(VALUE* toDelete) {
	
	if (toDelete->NextValue ==  NULL || toDelete == NULL) {
		free(toDelete);
		return 0;
	}
	VALUE *tmp = toDelete->NextValue;
	toDelete->Value = tmp->Value;
	toDelete->NextValue = tmp->NextValue;
	toDelete->Specificator = tmp->Specificator;
	free(tmp);
	return 1;
}