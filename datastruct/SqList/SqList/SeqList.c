#include "SepList.h"

void SLInit(SL* ps) {
	assert(ps); // assert为真通过，为假报错
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}
void SLDestory(SL* ps) {
	assert(ps);
	free(ps->arr);
	ps->capacity = ps->size = 0;
}

