/* -*- c++ -*- */

#define OSCILLOSCOPE_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "oscilloscope_swig_doc.i"

%{
#include "oscilloscope/oscilloscope.h"
%}

%include "oscilloscope/oscilloscope.h"
GR_SWIG_BLOCK_MAGIC2(oscilloscope, oscilloscope);
