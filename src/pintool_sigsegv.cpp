/*-
 * Copyright (c) 2010, 2011, 2012, 2013, Columbia University
 * All rights reserved.
 *
 * This software was developed by Vasileios P. Kemerlis <vpk@cs.columbia.edu>
 * at Columbia University, New York, NY, USA, in June 2010.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Columbia University nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "pin.H"

/*
 * trace inspection (instrumentation function)
 *
 * traverse the basic blocks (BBLs) on the trace and
 * inspect every instruction for instrumenting it
 * accordingly --- dummy version; simply counts the
 * number of instructions inside the trace
 *
 * @trace:      instructions trace; given by PIN
 */
/* static void trace_inspect(TRACE trace, VOID *v) { */
/*     /1* iterators *1/ */
/*     BBL bbl; */
/*     INS ins; */

/*     /1* instruction counter *1/ */
/*     size_t ins_ct = 0; */

/*     /1* traverse all the BBLs in the trace *1/ */
/*     for (bbl = TRACE_BblHead(trace); BBL_Valid(bbl); bbl = BBL_Next(bbl)) { */
/*         /1* traverse all the instructions in the BBL *1/ */
/*         for (ins = BBL_InsHead(bbl); INS_Valid(ins); ins = INS_Next(ins)) */
/*             /1* analyze the instruction; dummy *1/ */
/*             ins_ct++; */
/*     } */
/* } */

static BOOL sig_handler(THREADID, INT32, CONTEXT *, BOOL,
                        const EXCEPTION_INFO *, void *) {
    std::cerr << "catched sigsegv" << std::endl;
    return TRUE;
}

/*
 * NullPin
 *
 * used for estimating the overhead of Pin
 */
int main(int argc, char **argv) {
    /* initialize symbol processing */
    PIN_InitSymbols();

    /* initialize PIN */
    if (PIN_Init(argc, argv)) {
        std::cerr
            << "Sth error in PIN_Init. Plz use the right command line options."
            << std::endl;
        return -1;
    }

    PIN_InterceptSignal(SIGSEGV, sig_handler, 0);
    /* PIN_UnblockSignal(SIGSEGV, TRUE); */

    PIN_StartProgram();

    return 0;
}
