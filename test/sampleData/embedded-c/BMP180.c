/*
* Copyright (C) 2020 Google Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* Auto-generated file for BMP180 v0.1.0.
* Generated from peripherals/BMP180.yaml using Cyanobyte Codegen v0.0.2
* Class for BMP180
* Bosch Digital Temperature / Pressure Sensor

*/




#include "BMP180.h"
#define DEVICE_ADDRESS 119

#define REGISTER_CONTROL 244
#define REGISTER_PRESSURECALAC1 170
#define REGISTER_PRESSURECALAC2 172
#define REGISTER_PRESSURECALVB1 182
#define REGISTER_PRESSURECALVB2 184
#define REGISTER_RESULT 246
#define REGISTER_TEMPCAL3 174
#define REGISTER_TEMPCAL4 176
#define REGISTER_TEMPCAL5 178
#define REGISTER_TEMPCAL6 180
#define REGISTER_TEMPCALMC 188
#define REGISTER_TEMPCALMD 190

// Provide an I2C connect function, return status
int bmp180_init(int (*connect)(uint8_t)) {
    // Initialize bus
    if (connect(DEVICE_ADDRESS) != 0) {
        return -1;
    }
}


int bmp180_writeControl(
    uint8_t* data,
    int (*write)(uint8_t, uint8_t, uint8_t*, uint8_t)
) {
    if (write(DEVICE_ADDRESS, REGISTER_CONTROL, data, 1) != 0) {
        return -1;
    }
    return 0;
}int bmp180_readPressureCalAC1(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_PRESSURECALAC1, val, 2) != 0) {
        return -2;
    }
    return 0;
}

int bmp180_readPressureCalAC2(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_PRESSURECALAC2, val, 2) != 0) {
        return -2;
    }
    return 0;
}

int bmp180_readPressureCalVB1(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_PRESSURECALVB1, val, 2) != 0) {
        return -2;
    }
    return 0;
}

int bmp180_readPressureCalVB2(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_PRESSURECALVB2, val, 2) != 0) {
        return -2;
    }
    return 0;
}

int bmp180_readResult(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_RESULT, val, 2) != 0) {
        return -2;
    }
    return 0;
}

int bmp180_readTempCal3(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_TEMPCAL3, val, 2) != 0) {
        return -2;
    }
    return 0;
}

int bmp180_readTempCal4(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_TEMPCAL4, val, 2) != 0) {
        return -2;
    }
    return 0;
}

int bmp180_readTempCal5(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_TEMPCAL5, val, 2) != 0) {
        return -2;
    }
    return 0;
}

int bmp180_readTempCal6(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_TEMPCAL6, val, 2) != 0) {
        return -2;
    }
    return 0;
}

int bmp180_readTempCalMC(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_TEMPCALMC, val, 2) != 0) {
        return -2;
    }
    return 0;
}

int bmp180_readTempCalMD(
    uint16_t* val,
    int (*read)(uint8_t, uint8_t, uint16_t*, uint8_t)
) {
    if (val == NULL) {
        return -1; // Need to provide a valid value pointer
    }
    if (read(DEVICE_ADDRESS, REGISTER_TEMPCALMD, val, 2) != 0) {
        return -2;
    }
    return 0;
}




celsiusCallback bmp180_pressure_asmbars(
    int (*read)(uint8_t, uint8_t, int*, uint8_t),
    int (*write)(uint8_t, uint8_t, int*, uint8_t)
) {
    short ac1; // Variable declaration
    short ac2; // Variable declaration
    short ac3; // Variable declaration
    uint16_t ac4; // Variable declaration
    float b1; // Variable declaration
    float c3; // Variable declaration
    float c4; // Variable declaration
    float p0; // Variable declaration
    float p1; // Variable declaration
    float p2; // Variable declaration
    float pressure; // Variable declaration
    float rawComp; // Variable declaration
    float temperature; // Variable declaration
    short vb1; // Variable declaration
    short vb2; // Variable declaration
    float x; // Variable declaration
    float x1; // Variable declaration
    float x2; // Variable declaration
    float y; // Variable declaration
    float y0; // Variable declaration
    float y1; // Variable declaration
    float y2; // Variable declaration
    float z; // Variable declaration


    bmp180_writeControl(52, write);
    bmp180_readResult(&pressure, read);
    bmp180_temperature_ascelsius(&temperature, read, write);
    struct celsiusCallback callbackState;
    // Point to the callback state
    callbackState.callback = _callback_celsius;
    // Save all of our variables
    callbackState.ac1 = ac1
    callbackState.ac2 = ac2
    callbackState.ac3 = ac3
    callbackState.ac4 = ac4
    callbackState.b1 = b1
    callbackState.c3 = c3
    callbackState.c4 = c4
    callbackState.p0 = p0
    callbackState.p1 = p1
    callbackState.p2 = p2
    callbackState.pressure = pressure
    callbackState.rawComp = rawComp
    callbackState.temperature = temperature
    callbackState.vb1 = vb1
    callbackState.vb2 = vb2
    callbackState.x = x
    callbackState.x1 = x1
    callbackState.x2 = x2
    callbackState.y = y
    callbackState.y0 = y0
    callbackState.y1 = y1
    callbackState.y2 = y2
    callbackState.z = z
    // Delay `callbackState.callback` execution for 10 ms.
    return callbackState;


}
// Occurs after 10 ms
void _callback_celsius(
    celsiusCallback callbackState,
    float* val,
    int (*read)(uint8_t, uint8_t, int*, uint8_t),
    int (*write)(uint8_t, uint8_t, int*, uint8_t),
) {
    // Re-import all of our variables
    short ac1 = celsiusCallback.ac1;
    short ac2 = celsiusCallback.ac2;
    short ac3 = celsiusCallback.ac3;
    uint16_t ac4 = celsiusCallback.ac4;
    float b1 = celsiusCallback.b1;
    float c3 = celsiusCallback.c3;
    float c4 = celsiusCallback.c4;
    float p0 = celsiusCallback.p0;
    float p1 = celsiusCallback.p1;
    float p2 = celsiusCallback.p2;
    float pressure = celsiusCallback.pressure;
    float rawComp = celsiusCallback.rawComp;
    float temperature = celsiusCallback.temperature;
    short vb1 = celsiusCallback.vb1;
    short vb2 = celsiusCallback.vb2;
    float x = celsiusCallback.x;
    float x1 = celsiusCallback.x1;
    float x2 = celsiusCallback.x2;
    float y = celsiusCallback.y;
    float y0 = celsiusCallback.y0;
    float y1 = celsiusCallback.y1;
    float y2 = celsiusCallback.y2;
    float z = celsiusCallback.z;
    rawComp = (temperature-25);
    bmp180_readPressureCalAC1(&ac1, read);
    bmp180_readPressureCalAC2(&ac2, read);
    x1 = (160*pow(2, -13)*ac2);
    bmp180_readPressureCalVB2(&vb2, read);
    x2 = (pow(160, 2)*pow(2, -25)*vb2);
    x = ((x2*pow(rawComp, 2))+(x1*rawComp)+ac1);
    bmp180_readTempCal3(&ac3, read);
    c3 = (160*pow(2, -15)*ac3);
    bmp180_readTempCal4(&ac4, read);
    c4 = (pow(10, -3)*pow(2, -15)*ac4);
    bmp180_readPressureCalVB1(&vb1, read);
    b1 = (pow(160, 2)*pow(2, -30)*vb1);
    y0 = (c4*pow(2, 15));
    y1 = (c4*c3);
    y2 = (c4*b1);
    y = ((y2*pow(rawComp, 2))+(y1*rawComp)+y0);
    z = ((pressure-x)/y);
    p0 = ((3791-8)/1600);
    p1 = (1-(7357*pow(2, -30)));
    p2 = (3038*100*pow(2, -36));
    pressure = ((p2*pow(z, 2))+(p1*z)+p0);

    *val = pressure;
}

void bmp180_temperature_ascelsius(
    float* val,
    int (*read)(uint8_t, uint8_t, int*, uint8_t),
    int (*write)(uint8_t, uint8_t, int*, uint8_t)
) {
    short rawComp; // Variable declaration
    short rawMc; // Variable declaration
    short rawMd; // Variable declaration
    float temperature; // Variable declaration
    uint16_t varAc5; // Variable declaration
    uint16_t varAc6; // Variable declaration
    float varC5; // Variable declaration
    float varMc; // Variable declaration
    float varMd; // Variable declaration


    bmp180_writeControl(46, write);
    bmp180_readResult(&temperature, read);
    bmp180_readTempCal5(&varAc5, read);
    bmp180_readTempCal6(&varAc6, read);
    varC5 = ((pow(2, -15)/160)*varAc5);
    rawComp = (varC5*(temperature-varAc6));
    bmp180_readTempCalMC(&rawMc, read);
    varMc = ((pow(2, 11)/pow(160, 2))*rawMc);
    bmp180_readTempCalMD(&rawMd, read);
    varMd = (rawMd/160);
    temperature = (rawComp+(varMc/(rawComp+varMd)));


    *val = temperature;
}

