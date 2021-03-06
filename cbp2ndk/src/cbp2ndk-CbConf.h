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

#ifndef __CBCONF_LOCAL_H__
#define __CBCONF_LOCAL_H__

class CbConf
{
    private:
        void path();
        void cmdl(const char**, int);
        bool findcbp();

    public:
        std::vector<std::string> v[_END_FOR_ARRAY];
        std::map<std::string, int32_t> m[2];
        std::string fname[5];
        std::string prjname;
        std::string tag;
        std::string abi[3];
        /// configuration
        bool isarg;
        bool isverb;
        bool isquiet;
        bool isdump;
        bool isnodef;
        bool isabi;
        bool iscbtmpl;
        /// files found
        bool isapp;
        bool isand;
        bool ismkf;

    CbConf(const char**, int);
    ~CbConf();
};

#endif
