#include "pch.h"
#include "board_overrides.h"



Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::D15;
}

// =============================================
// CONFIGURACIÓN DE TU PLACA
// =============================================
static void customBoardDefaultConfiguration() {

    // 1. INYECCIÓN (Puerto E Alto)
    // -----------------------------------------
    engineConfiguration->injectionPins[0] = Gpio::E0;  // Cilindro 1
    engineConfiguration->injectionPins[1] = Gpio::E1;  // Cilindro 2
    engineConfiguration->injectionPins[2] = Gpio::E2;  // Cilindro 3
    engineConfiguration->injectionPins[3] = Gpio::E3; // Cilindro 4

    // 2. IGNICIÓN (Puerto D Medio)
    // -----------------------------------------
    // Usamos D10-D13. Esto deja libres D8 y D9 para Bluetooth.
    engineConfiguration->ignitionPins[0] = Gpio::E4; // Bobina 1
    engineConfiguration->ignitionPins[1] = Gpio::E5; // Bobina 2
    engineConfiguration->ignitionPins[2] = Gpio::E6; // Bobina 3
    engineConfiguration->ignitionPins[3] = Gpio::E7; // Bobina 4

    // 3. TRIGGER (Sensor de Posición)
    // -----------------------------------------
    // 120-2 en Arbol de Levas (Camshaft) en C6.
    engineConfiguration->triggerInputPins[0] = Gpio::C6;       
    engineConfiguration->triggerInputPins[1] = Gpio::Unassigned; 

    // 4. BOMBA Y RELÉS (Puerto B)
    // -----------------------------------------
    engineConfiguration->mainRelayPin  = Gpio::B10;
    engineConfiguration->fuelPumpPin   = Gpio::B11;
    engineConfiguration->tachOutputPin = Gpio::B13;
    engineConfiguration->fanPin        = Gpio::B14;
    engineConfiguration->fan2Pin       = Gpio::B15;

    // 5. ENTRADAS DIGITALES (Switches)
    // -----------------------------------------
    engineConfiguration->clutchUpPin   = Gpio::E13;
    engineConfiguration->clutchDownPin = Gpio::E12;
    engineConfiguration->brakePedalPin = Gpio::E14;

    // 6. SENSORES ANALÓGICOS
    // -----------------------------------------
    // Mapeo estándar del STM32F407
    engineConfiguration->tps1.adcChannel      = EFI_ADC_1;  // PA1
    //engineConfiguration->knock.adcChannel       = EFI_ADC_3;  // PA3
    engineConfiguration->map.sensor.hwChannel   = EFI_ADC_5;  // PA5
    engineConfiguration->vbattAdcChannel        = EFI_ADC_0;  // PA0
    engineConfiguration->clt.adcChannel         = EFI_ADC_6;  // PA6
    engineConfiguration->iat.adcChannel         = EFI_ADC_7;  // PA7

    // Resistencias y calibración estándar
    engineConfiguration->analogInputDividerCoefficient = 1.56f;
    engineConfiguration->vbattDividerCoeff = (6.34 + 1) / 1;
    engineConfiguration->adcVcc = 3.3f;
    engineConfiguration->clt.config.bias_resistor = 2490;
    engineConfiguration->iat.config.bias_resistor = 2490;

    // 7. COMUNICACIÓN
    // -----------------------------------------
    // Dejamos CAN sin asignar para ahorrar recursos y pines
    engineConfiguration->canTxPin = Gpio::Unassigned;
    engineConfiguration->canRxPin = Gpio::Unassigned;
    
    // NOTA: Los pines D8 y D9 NO se tocan aquí.
    // Se activarán automáticamente como Serial 3 en el Makefile.
}

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
