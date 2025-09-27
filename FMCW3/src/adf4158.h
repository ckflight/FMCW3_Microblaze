#ifndef ADF4158_H
#define ADF4158_H

#include "xspi.h"
#include "xgpio.h"
#include "xil_types.h"

// External SPI instance (from spi.c)
extern XSpi SPI0;

// GPIO pin mapping (adapt as needed)
#define ADF_CE_PIN     0   // GPIO[0] -> CE
#define ADF_LE_PIN     1   // GPIO[1] -> LE

#define FREQ_PFD       30000000U

typedef enum {
    SAWTOOTH_WAVEFORM = 0,
    TRIANGULAR_WAVEFORM = 1
} WAVEFORM_TYPE;

int  ADF4158_Init(WAVEFORM_TYPE wf);
void ADF4158_DeviceEnable(void);
void ADF4158_WriteRegister(u32 data);
void ADF4158_Configure_Sweep(WAVEFORM_TYPE wf, double startFreq, double bw, double rampTime, int rampDel);

#endif
