/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2005 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License Version 2.4 (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.systemc.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  main.cpp -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

// Main routine

#include "testbench.h"
#include "adder_sub.h"

int sc_main(int ac, char *av[])
{
  sc_signal<int> a;
  sc_signal<int> b;
  sc_signal<int> c;
  sc_signal<int> d;
  sc_signal<int> sum;
  sc_signal<bool> ready;
  sc_signal<bool> done;
  sc_clock clock("Clock", 10, 0.5, 0);

  testbench T("TB", clock, sum, d, done, a, b, c, ready);
  adder_sub AS("AS", clock, a, b, c, ready, d, sum, done);

  sc_clock::start(-1);
  return 0;
}
