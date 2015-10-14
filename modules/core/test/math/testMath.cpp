/****************************************************************************
 *
 * $Id: testMath.cpp 4658 2014-02-09 09:50:14Z fspindle $
 *
 * This file is part of the ViSP software.
 * Copyright (C) 2005 - 2014 by INRIA. All rights reserved.
 * 
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * ("GPL") version 2 as published by the Free Software Foundation.
 * See the file LICENSE.txt at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * For using ViSP with software that can not be combined with the GNU
 * GPL, please contact INRIA about acquiring a ViSP Professional 
 * Edition License.
 *
 * See http://www.irisa.fr/lagadic/visp/visp.html for more information.
 * 
 * This software was developed at:
 * INRIA Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 * http://www.irisa.fr/lagadic
 *
 * If you have questions regarding the use of this file, please contact
 * INRIA at visp@inria.fr
 * 
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * Description:
 * Test some vpColVector functionalities.
 *
 * Authors:
 * Souriya Trinh
 *
 *****************************************************************************/

/*!
  \example testMath.cpp

  Test some vpMath functionalities.
*/

#include <iostream>
#include <limits>
#include <cfloat>

#include <visp3/core/vpMath.h>

#if defined _MSC_VER && _MSC_VER >= 1200
  #pragma warning( disable: 4723 )

// 4723 : potential divide by 0
#endif

int main() {
  //Test isNaN
  if(vpMath::isNaN(0.0)) {
    std::cerr << "Fail: IsNaN(0.0)=" << vpMath::isNaN(0.0) << " / should be false" << std::endl;
    return -1;
  }

  double num = 1.0, den = 0.0;
  if(vpMath::isNaN(num/den)) {
    std::cerr << "Fail: IsNaN(1.0/0.0)=" << vpMath::isNaN(num/den) << " / should be false" << std::endl;
    return -1;
  }

  if(!vpMath::isNaN(sqrt(-1.0))) {
    std::cerr << "Fail: IsNaN(sqrt(-1.0))=" << vpMath::isNaN(sqrt(-1.0)) << " / should be true" << std::endl;
    return -1;
  }

  num = 0.0;
  if(!vpMath::isNaN(num/den)) {
    std::cerr << "Fail: IsNaN(0.0/0.0)=" << vpMath::isNaN(num/den) << " / should be true" << std::endl;
    return -1;
  }

  if(!vpMath::isNaN(std::numeric_limits<double>::quiet_NaN())) {
    std::cerr << "Fail: IsNaN(quiet_NaN)=" << vpMath::isNaN(std::numeric_limits<double>::quiet_NaN())
      << " / should be true" << std::endl;
    return -1;
  }

  if(!vpMath::isNaN(std::numeric_limits<double>::signaling_NaN())) {
    std::cerr << "Fail: IsNaN(signaling_NaN)=" << vpMath::isNaN(std::numeric_limits<double>::signaling_NaN())
      << " / should be true" << std::endl;
    return -1;
  }

  if(vpMath::isNaN(std::numeric_limits<double>::infinity())) {
    std::cerr << "Fail: IsNaN(infinity)=" << vpMath::isNaN(std::numeric_limits<double>::infinity())
      << " / should be false" << std::endl;
    return -1;
  }

  if(vpMath::isNaN(1.0 / std::numeric_limits<double>::epsilon())) {
    std::cerr << "Fail: IsNaN(1.0/epsilon)=" << vpMath::isNaN(1.0/std::numeric_limits<double>::epsilon())
      << " / should be false" << std::endl;
    return -1;
  }

  if(!vpMath::isNaN(std::numeric_limits<double>::infinity() - std::numeric_limits<double>::infinity())) {
    std::cerr << "Fail: IsNaN(1.0/epsilon)=" << vpMath::isNaN(1.0/std::numeric_limits<double>::epsilon())
      << " / should be true" << std::endl;
    return -1;
  }

  float a = 0.0f, b = 0.0f;
  if(!vpMath::isNaN(a/b)) {
    std::cerr << "Fail: IsNaN(0.0f/0.0f)=" << vpMath::isNaN(a/b) << " / should be true" << std::endl;
    return -1;
  }
  std::cout << "vpMath::isNaN is Ok !" << std::endl;


  //Test isInf
  if(vpMath::isInf(sqrt(-1.0))) {
    std::cerr << "Fail: vpMath::isInf(sqrt(-1.0))=" << vpMath::isInf(sqrt(-1.0)) << " / should be false" << std::endl;
    return -1;
  }

  if(!vpMath::isInf(1.0/0.0)) {
    std::cerr << "Fail: vpMath::isInf(1.0/0.0)=" << vpMath::isInf(1.0/0.0) << " / should be true" << std::endl;
    return -1;
  }

  if(vpMath::isInf(0.0)) {
    std::cerr << "Fail: vpMath::isInf(0.0)=" << vpMath::isInf(0.0) << " / should be false" << std::endl;
    return -1;
  }

  if(!vpMath::isInf(exp(800))) {
    std::cerr << "Fail: vpMath::isInf(exp(800))=" << vpMath::isInf(exp(800)) << " / should be true" << std::endl;
    return -1;
  }

  if(vpMath::isInf(DBL_MIN/2.0)) {
    std::cerr << "Fail: vpMath::isInf(DBL_MIN/2.0)=" << vpMath::isInf(DBL_MIN/2.0) << " / should be false" << std::endl;
    return -1;
  }
  std::cout << "vpMath::isInf is Ok !" << std::endl;


  //Test round
  if(vpMath::round(2.3) != 2) {
    std::cerr << "Fail: vpMath::round(2.3)=" << vpMath::round(2.3) << " / should be 2" << std::endl;
    return -1;
  }

  if(vpMath::round(3.8) != 4) {
    std::cerr << "Fail: vpMath::round(3.8)=" << vpMath::round(3.8) << " / should be 4" << std::endl;
    return -1;
  }

  if(vpMath::round(5.5) != 6) {
    std::cerr << "Fail: vpMath::round(5.5)=" << vpMath::round(5.5) << " / should be 6" << std::endl;
    return -1;
  }

  if(vpMath::round(-2.3) != -2) {
    std::cerr << "Fail: vpMath::round(-2.3)=" << vpMath::round(-2.3) << " / should be -2" << std::endl;
    return -1;
  }

  if(vpMath::round(-3.8) != -4) {
    std::cerr << "Fail: vpMath::round(-3.8)=" << vpMath::round(-3.8) << " / should be -4" << std::endl;
    return -1;
  }

  if(vpMath::round(-5.5) != -6) {
    std::cerr << "Fail: vpMath::round(-5.5)=" << vpMath::round(-5.5) << " / should be -6" << std::endl;
    return -1;
  }

  if(vpMath::round(0.0) != 0) {
    std::cerr << "Fail: vpMath::round(0.0)=" << vpMath::round(0.0) << " / should be 0" << std::endl;
    return -1;
  }
  std::cout << "vpMath::round is Ok !" << std::endl;

  std::cout << "OK !" << std::endl;

  return 0;
}
