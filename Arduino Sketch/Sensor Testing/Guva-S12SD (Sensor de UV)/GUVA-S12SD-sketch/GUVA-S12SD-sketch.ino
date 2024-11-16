/*

                Explicando a lógica do Sensor UV GUVA-S12SD
    Esse é um sensor que basicamente mede níveis de radiação ultravioleta vinda do sol.
    A radiação UV é o tipo de radiação solar que causa queimaduras à pela humana, então, é importante ser cauteloso com a intensidade dessa radiação
    O sensor em questão é um sensor analógico, que mede o índice UV que está incidindo sobre ele e converte esse valor para valores de tensão em mV
    A curva do sensor pode ser conferida no seguinte link: https://www.usinainfo.com.br/blog/projeto-sensor-uv-guva-s12sd-com-arduino/
    Comparando a tabela UV (que varia de 0 a 11+) com os valores de saída do sensor, temos o seguinte:
    
    Índice UV                 Valor de Saída do Sensor(mV)              Valor Analógico
    0                                       <50                               <10
    1                                       227                                46
    2                                       318                                65
    3                                       408                                83
    4                                       503                               103
    5                                       606                               124                                
    6                                       696                               142
    7                                       795                               162
    8                                       881                               180
    9                                       972                               200
    10                                     1079                               221
    11+                                   1170+                               240


*/

int pinoUV = A4;
float TensaoSaida;
float valorSensor;

void setup() {
  Serial.begin(9600);
  pinMode(pinoUV, INPUT);
}

void loop() {


  valorSensor = analogRead(pinoUV);
  TensaoSaida = valorSensor / (1024.0*5.0) * 1000;   // Convertendo o valor para mili Volts. A saída do sensor varia entre 0 e 1 V;
  Serial.print("Valor lido pelo sensor: ");
  Serial.println(valorSensor);
  Serial.print("Tensão de Saída: ");
  Serial.println(TensaoSaida, 6);

  delay(1000);

}
