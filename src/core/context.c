#include "context.h"

Context *BlokContextGet()
{
    static Context context;
    return &context;
}