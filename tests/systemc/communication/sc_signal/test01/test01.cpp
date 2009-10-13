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

  test01.cpp -- 

  Original Author: Ucar Aziz, Synopsys, Inc., 2002-02-15
                   Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

// test of sc_signal<sc_logic> channel

#include "systemc.h"

SC_MODULE( mod_a )
{
  sc_signal<sc_logic> channel;

  sc_in_clk clk;

    void main_action1()
    {
      sc_logic a;
      a = '1';

      cout<<"current value of channel  ";
      channel.print(cout);
      cout<<endl;

      channel.write(a);
      channel.dump(cout);
      cout<<endl;

    }

    void main_action2()
    {
      sc_logic b;
      b = 'Z';
      cout<<"current value of channel  "<<channel.get_data_ref()<<endl;
      channel.write(b);
      channel.dump(cout);
      cout<<endl;
 
    }

    SC_CTOR( mod_a )
    {
        SC_METHOD( main_action1 );
        sensitive << clk.pos();
        SC_METHOD( main_action2 );
        sensitive << clk.neg();
    }
};


int
sc_main( int, char*[] )
{
    sc_clock clk;
    mod_a a("a");

    a.clk(clk);

    cout<<"type of channel : "<<a.channel.kind()<<endl;

    if(a.channel.event() == 1)
      cout<<"there was event on channel\n\n";
    else
      cout<<"there was no event on channel\n\n";

    sc_start( 3 );

    return 0;
}
