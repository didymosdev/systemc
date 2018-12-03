/*****************************************************************************

  Licensed to Accellera Systems Initiative Inc. (Accellera) under one or
  more contributor license agreements.  See the NOTICE file distributed
  with this work for additional information regarding copyright ownership.
  Accellera licenses this file to you under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with the
  License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
  implied.  See the License for the specific language governing
  permissions and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  sc_object_int.h -- For inline definitions of some utility functions.
                     DO NOT EXPORT THIS INCLUDE FILE.

  Original Author: Philipp A. Hartmann, OFFIS, 2013-02-10

 *****************************************************************************/

#ifndef SC_OBJECT_INT_H_INCLUDED_
#define SC_OBJECT_INT_H_INCLUDED_

#include "sysc/kernel/sc_object.h"
#include "sysc/kernel/sc_module.h"
#include "sysc/kernel/sc_simcontext_int.h"
#include "sysc/kernel/sc_phase_callback_registry.h"

namespace sc_core {

inline void
sc_object::do_simulation_phase_callback()
{
    simulation_phase_callback();
}

} // namespace sc_core

#endif // SC_OBJECT_INT_H_INCLUDED_
// Taf!
