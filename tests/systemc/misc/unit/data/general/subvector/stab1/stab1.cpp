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

  stab1.cpp -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

#include "systemc.h"

int
sc_main( int argc, char* argv[] )
{
    int i;
    sc_bv<325> x;
    sc_lv<142> y;

    sc_signed z(103);
    sc_unsigned w(291);

    for (i = 0; i < 325; ++i) {
        x[i] = ((i & 1) ^ ((i >> 1) & 1));
    };
    for (i = 0; i < 325; ++i) {
        assert( x[i] == ((i & 1) ^ ((i >> 1) & 1)) );
    };
    for (i = 0; i < 142; ++i) {
        y[i] = ((i & 1) ^ ((i >> 2) & 1));
    }
    for (i = 0; i < 142; ++i) {
        // assert( y[i] == char((i & 1) ^ ((i >> 2) & 1)) );
        assert( y[i] == ((i & 1) ^ ((i >> 2) & 1)) );
    }
    for (i = 0; i < 103; ++i) {
        z[i] = (((i >> 2) & 1) ^ ((i >> 1) & 1));
    }
    for (i = 0; i < 103; ++i) {
        assert( (bool) z[i] == (((i >> 2) & 1) ^ ((i >> 1) & 1)) );
    }
    for (i = 0; i < 291; ++i) {
        w[i] = (((i >> 3) & 1) ^ ((i >> 1) & 1));
    }
    for (i = 0; i < 291; ++i) {
        assert( (bool) w[i] == (((i >> 3) & 1) ^ ((i >> 1) & 1)) );
    }

    cout << x << endl;
    cout << x.to_string() << endl;
    cout << y << endl;
    cout << y.to_string() << endl;
    cout << z << endl;
    cout << w << endl;

    for (int k = 0; k < 100; ++k) {
        cerr << "k = " << k << endl;

        for (i = 0; i < 100; ++i) {
            int j;

            if (k == 0) {
                cout << "i = " << i << endl;
                cout << x.range(i + 224, i) << endl;
                cout << x.range(i + 224, i).to_string() << endl;
                cout << y.range(i + 41, i) << endl;
                cout << y.range(i + 41, i).to_string() << endl;
                cout << sc_signed(z.range(i+2,i)) << endl;
                cout << sc_unsigned(w.range(i + 190, i)) << endl;
                cout << x.range(i, i + 224) << endl;
                cout << x.range(i, i + 224).to_string() << endl;
                cout << y.range(i, i + 41) << endl;
                cout << y.range(i, i + 41).to_string() << endl;
                cout << sc_signed(z.range(i,i+2)) << endl;
                cout << sc_unsigned(w.range(i, i + 190)) << endl;
            } else {
                (void) x.range(i + 224, i);
                (void) y.range(i + 41, i);
                (void) sc_signed(z.range(i + 2, i));
                (void) sc_unsigned(w.range(i + 190, i));
            }

            sc_bv<225> foo;
            sc_bv<225> foo1;
            foo = x.range(i + 224, i);
            foo1 = x.range(i, i + 224);
            for (j = 0; j < 225; ++j) {
                assert( foo[j] == x[i + j] );
                assert( foo1[224 - j] == x[i + j] );
            }

            sc_lv<42> bar;
            sc_lv<42> bar1;
            bar = y.range(i + 41, i);
            bar1 = y.range(i, i + 41);
            for (j = 0; j < 42; ++j) {
                assert( bar[j] == y[i + j] );
                assert( bar1[41 - j] == y[i + j] );
            }

            sc_signed baz(3);
            sc_signed baz1(3);
            baz = z.range(i + 2, i);
            baz1 = z.range(i, i + 2);
            for (j = 0; j < 3; ++j) {
                assert( baz[j] == z[i + j] );
                assert( baz1[2 - j] == z[i + j] );
            }

            sc_unsigned quux(191);
            sc_unsigned quux1(191);
            quux = w.range(i + 190, i);
            quux1 = w.range(i, i + 190);
            for (j = 0; j < 191; ++j) {
                assert( quux[j] == w[i + j] );
                assert( quux1[190 - j] == w[i + j] );
            }
        }
    }
    return 0;
}
