/**
 * \file result.c
 * \date 13-08-2014
 * \brief Implementation of the result module.
 *
 * This file contains the implementation of the creating a result.
 */

#include "result.h"
#include <wchar.h>

BlokResult BlokCreateResult(BlokResultCode code, wchar_t *pMessage)
{
    BlokResult result = {0};
    result.code = code;

    if (pMessage)
    {
        (void)wcsncpy(result.message, pMessage, 260);
    }

    return result;
}