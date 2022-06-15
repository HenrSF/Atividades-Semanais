#include "sensor.hpp"

SensorTemperatura::SensorTemperatura(int u)
{
    ligado = false;
    defeito = false;

    switch (u)                                  //Kelvin = 1 ; Fahrenheit = 2 ; Celsius = 3;
    {
    case 1:
        setunidade(1);
        break;
    
    case 2:
        setunidade(2);
        break;

    default:
        setunidade(3);
        break;
    }
}

void SensorTemperatura::ligar()

{
    ligado = true;
}

void SensorTemperatura::desligar()

{
    ligado = false;
}

void SensorTemperatura::setunidade(int u)
{
    unidade = u;
}

void SensorTemperatura::setdefeito(int d)
{
    srand(time(NULL));
    rand()%100 + 1;
    if (d < 5)
    {
        defeito = true;
        cerr << "O sensor apresenta problemas.";
        exit(EXIT_FAILURE);
    }
    
}

/*static*/float SensorTemperatura::CelsiusToFahrenheit()

{
    F = (1.8*C) + 32;
}

/*static*/float SensorTemperatura::CelsiusToKelvin()

{
    K = C + 273;
}

/*static*/float SensorTemperatura::KelvinToCelsius()

{
    C = K - 273;
}

/*static*/float SensorTemperatura::KelvinToFahrenheit()

{
    F = ((K - 273)*1.8) + 32;
}

/*static*/float SensorTemperatura::FahrenheitToCelsius()

{
    F = (F - 32)/1.8;
}

/*static*/float SensorTemperatura::FahrenheitToKelvin()

{
    K = ((F-32)*(5/9)) + 273;
}
