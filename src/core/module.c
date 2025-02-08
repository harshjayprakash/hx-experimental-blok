#include "module.h"

Context *BlokContextGet(void)
{
    static Context context;
    return &context;
}