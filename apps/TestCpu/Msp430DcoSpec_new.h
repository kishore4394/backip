/* -*- mode:c++; indent-tabs-mode: nil -*-
 * Copyright (c) 2007, Technische Universitaet Berlin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of the Technische Universitaet Berlin nor the names
 *   of its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES {} LOSS OF USE, DATA,
 * OR PROFITS {} OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * Specify the target cpu clock speed of your platform by overriding this file.
 *
 * Be aware that tinyos relies on binary 4MHz, that is 4096 binary kHz.  Some
 * platforms have an external high frequency oscilator to generate the SMCLK
 * (e.g. eyesIFX, and possibly future ZigBee compliant nodes). These
 * oscillators provide metric frequencies, but may not run in power down
 * modes. Here, we need to switch the SMCLK source, which is easier if
 * the external and thd DCO source frequency are the same.
 * 
 * @author: Andreas Koepke (koepke@tkn.tu-berlin.de)
 */


#ifndef MS430DCOSPEC_H
#define MS430DCOSPEC_H

#ifdef ENABLE_SPI0_DMA
#warning "Using 2**22 Hz DCO for DMA SpiPacket"
#define TARGET_DCO_KHZ 4096 // the target DCO clock rate in binary kHz
#else
#warning "Using 2**23 Hz DCO for software SpiPacket"
#define MHZ_8
#define TARGET_DCO_KHZ 8192 // the target DCO clock rate in binary kHz
#endif
#define ACLK_KHZ 32 // the ACLK rate in binary kHz
#endif
