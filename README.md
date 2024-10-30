# Lab3-Projeto-Final
UPF::EngenhariaDeComputacao::LaboratorioDeProgramacaoIII&lt;Projeto_Final_Arduino> Arduino_e_Qt;

---

# Objetivo do Trabalho  

Desenvolver um sistema completo que integre Software e Hardware, que realize uma tarefa específica e útil por meio de um software com interface gráfica feito em C++ com o uso do Qt Creator que se comunique via serial com um Arduino ou outro tipo de kit de desenvolvimento desempenhando a função de um Sistema Embarcado.

---

## Ideia inicial  

* Com um sketch de testes de um Arduino Uno, enviar constantemente dados do estado dos periféricos da placa (pinos analógicos e digitais, valores na EEPROM e outras regiões de memória, verificar eventualmente o funcionamento da I²C ou SPI, caso o modelo do Arduino suporte e for possível efetuar os testes dadas eventuais limitações técnicas de quem desenvolve o programa).
* A aplicação em C++ deverá receber os dados do Arduino via serial (utilizando bibliotecas do framework do Arduino e do Qt) e exibi-las ao usuário de maneira intuitiva, além de (talvez) escrever na EEPROM e executar determinadas funções de hardware. (Avaliar).
* O software verificará a integridade dos dados recebidos via serial e retornará ao usuário via interface gráfica se a placa está ou não em condições de uso.
