#include "sensor.hpp"

SensorTemperatura::SensorTemperatura(){
    //falta a unidade de medicao que o construtor recebera
    ligado = false;
    defeito = false;
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
    
}

void SensorTemperatura::setdefeito(int d)
{
    srand(time(NULL));
    rand()%101;
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
