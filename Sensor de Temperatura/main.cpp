#include "sensor.hpp"

int main()
{
    SensorTemperatura sensor1(1);
    SensorTemperatura sensor2(2);
    SensorTemperatura sensor3(5);

    sensor1.ligar();
    sensor2.ligar();
    sensor3.ligar();

    sensor1.efetuaMedicao();
    sensor2.efetuaMedicao();
    sensor3.efetuaMedicao();

    sensor1.imprimir();
    sensor2.imprimir();
    sensor3.imprimir();

    cout << "\n" << SensorTemperatura::CelsiusToKelvin(24)
         << "\n" << SensorTemperatura::CelsiusToFahrenheit(24)
         << "\n" << SensorTemperatura::KelvinToCelsius(297)
         << "\n" << SensorTemperatura::KelvinToFahrenheit(297)
         << "\n" << SensorTemperatura::FahrenheitToCelsius(75.2)
         << "\n" << SensorTemperatura::FahrenheitToKelvin(75.2);

    return 0;
}