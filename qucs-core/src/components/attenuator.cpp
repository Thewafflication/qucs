/*
 * attenuator.cpp - attenuator class implementation
 *
 * Copyright (C) 2003 Stefan Jahn <stefan@lkcc.org>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this package; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.  
 *
 * $Id: attenuator.cpp,v 1.1 2003/12/20 19:03:28 ela Exp $
 *
 */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"
#include "object.h"
#include "node.h"
#include "circuit.h"
#include "attenuator.h"

attenuator::attenuator () : circuit (2) {
}

void attenuator::calc (nr_double_t frequency) {
  nr_double_t a = pow (10.0, - getPropertyDouble ("L") / 20.0);
  setS (1, 1, 0.0);
  setS (2, 2, 0.0);
  setS (1, 2, a);
  setS (2, 1, a);
}
