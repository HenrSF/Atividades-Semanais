#include "sensor.hpp"

int main()
{
    srand(time(NULL));
    
    SensorTemperatura sensor1(1);
    sensor1.ligar();
    sensor1.efetuaMedicao();
    sensor1.imprimir();

    SensorTemperatura sensor2(2);
    sensor2.ligar();
    sensor2.efetuaMedicao();
    sensor2.imprimir();

    SensorTemperatura sensor3(5);
    sensor3.ligar();
    sensor3.efetuaMedicao();
    sensor3.imprimir();
    

    cout << "\n" << SensorTemperatura::CelsiusToKelvin(24)
         << "\n" << SensorTemperatura::CelsiusToFahrenheit(24)
         << "\n" << SensorTemperatura::KelvinToCelsius(297)
         << "\n" << SensorTemperatura::KelvinToFahrenheit(297)
         << "\n" << SensorTemperatura::FahrenheitToCelsius(75.2)
         << "\n" << SensorTemperatura::FahrenheitToKelvin(75.2);

    return 0;
}