/*
    MIT License

    Copyright (c) 2018 PS
    GitHub: https://github.com/ClnViewer/Code-Blocks-Android-NDK

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sub license, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
 */

#ifndef __CBP2NDK_LOCAL_H__
#define __CBP2NDK_LOCAL_H__

#if !defined(_WIN32_WINNT)
#   define _WIN32_WINNT 0x0501
#endif

#if (defined(_WIN32) || defined(__WIN32__) || \
     defined(_WIN64) || defined(__WIN64__) || \
     defined(__WINNT) || defined(__WINNT__) || defined(WINNT) || \
     defined(_Windows) || defined(_MSC_VER) || \
     defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__))
#   define __OS_IS_WIN 1
#   define __SEPARATOR_PATH "\\"
#else
#   define __SEPARATOR_PATH "/"
#endif

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iostream>
#include <sstream>
#include "extern/tixml2ex.h"
#include "../version.h"
#include <windows.h>
#include <stdio.h>
#include <io.h>

#define __CSZ(a)  static_cast<size_t>(sizeof(a)-1)
#define __NELE(a) (sizeof(a) / sizeof(a[0]))
#define __AUTO(x) __attribute__((cleanup(x)))

static inline void __attribute__((always_inline)) __autofree(void *v)
{
    if (v)
    {
#       if defined(__cplusplus)
        void *x = static_cast<void*>(*static_cast<void**>(v));
#       else
        void *x = (void*)(*(void**)v);
#       endif
        if (x)
        {
            free(x);
        }
    }
}

static inline void __attribute__((always_inline)) __autofile(void *v)
{
    if (v)
    {
#       if defined(__cplusplus)
        void *x = static_cast<void*>(*static_cast<void**>(v));
#       else
        void *x = (void*)(*(void**)v);
#       endif
        if (x)
        {
#           if defined(__cplusplus)
            fclose(static_cast<FILE*>(x));
#           else
            fclose((FILE*)x);
#           endif
            x = NULL;
        }
    }
}

#if defined(__cplusplus)

inline bool string_end(std::string const & val, std::string const & ending)
{
    if (ending.size() > val.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), val.rbegin());
}

inline bool string_begin(std::string const & val, std::string const & start)
{
    if (start.size() > val.size()) return false;
    return std::equal(start.begin(), start.end(), val.begin());
}

inline void string_trim(std::string & str)
{
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ')+1);
}

#endif

enum elabels
{
    LBL_CEXT,
    LBL_CSRC,
    LBL_CFLAG,
    LBL_CPPFLAG,
    LBL_LDFLAG,
    LBL_LDLIBS,
    LBL_HINC,
    LBL_CMDL,
    LBL_NAME,
    LBL_END
};

#define _END_FOR_ARRAY elabels::LBL_NAME
#include "cbp2ndk-CbConf.h"

const char * get_label(int32_t);
PBYTE        get_resource(LPCSTR, size_t*);

void dump_CbConf(CbConf*);
bool if_section(CbConf*, int32_t);
bool write_label(FILE*, int32_t, bool);
bool write_section(FILE*, CbConf*, int32_t);
void write_appmk_custom(CbConf*);
void write_appmk(CbConf*);
void write_andmk(CbConf*);
void write_makef(CbConf*);
void write_makefcb(CbConf*);

void parse_cflag(
        CbConf*,
        std::string&);

void parse_ldflag(
        CbConf*,
        std::string&);

void parse_srclist(
        CbConf*,
        std::string&);

void parse_prjname(
        CbConf*,
        std::string&);

void parse_section(
        CbConf*,
        const tinyxml2::XMLDocument&,
        std::string const&,
        std::string const&,
        std::function<void(CbConf*, std::string&)>);

void parse_section(
        CbConf*,
        const tinyxml2::XMLElement*,
        std::string const&,
        std::string const&,
        std::function<void(CbConf*, std::string&)>);

#endif
