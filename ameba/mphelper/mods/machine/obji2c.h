/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Chester Tseng
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef OBJI2C_H_
#define OBJI2C_H_

#include "i2c_api.h"
#include "py/mpstate.h"
#include "py/runtime.h"
#include "py/mphal.h"

#include "exception.h"

#include "bufhelper.h"

#include "objpin.h"

#define I2C_MASTER                (0)
#define I2C_SLAVE                 (1)
#define I2C_MIN_BAUD_RATE_HZ      (50000)
#define I2C_DEFAULT_BAUD_RATE_HZ  (100000)
#define I2C_MAX_BAUD_RATE_HZ      (400000)

extern const mp_obj_type_t i2c_type;
extern const PinMap PinMap_I2C_SDA[];
extern const PinMap PinMap_I2C_SCL[];

typedef struct {
    mp_obj_base_t base;
    i2c_t     obj;
    uint8_t   unit;
    uint8_t   mode;
    uint32_t  baudrate;
    pin_obj_t *scl;
    pin_obj_t *sda;
} i2c_obj_t;

#endif  // OBJPIN_H_
