/* 
3.17 Consumo de gasolina. Os motoristas se preocupam
com o consumo de combustível de seus automóveis.
Um motorista manteve um registro do número de abas-
tecimentos que fez, registrando também o número de
quilômetros rodados e de litros obtidos a cada abasteci-
mento. Desenvolva um programa que peça o (número de
quilômetros dirigidos) e a (quantidade de litros obtidos a
cada abastecimento). O programa deverá calcular e exibir
a quantidade de quilômetros rodados por litros usados.
Depois de processar toda a informação, o programa de-
verá calcular e exibir o total combinado de quilômetros
por litro para todos os abastecimentos. Veja um exemplo
do diálogo de entrada/saída:
*/

#include <stdio.h>

int main() {
  float kilometers_driven, liters_to_fuel; 
  float current_consumption, total_consumption;
  float counter_total_consumption = 0;
  int counter = 0;
  

  printf("inform how many liters you filled (-1 to exit): ");
  scanf("%f", &liters_to_fuel);

  if (liters_to_fuel == -1) {
    return 0;
  }

  printf("inform how many km you drove: ");
  scanf("%f", &kilometers_driven);


  while(liters_to_fuel != -1) {

    current_consumption = kilometers_driven / liters_to_fuel;
    counter += 1;
    counter_total_consumption += current_consumption;
    
    printf("The current consumption is %f km/l\n", current_consumption);

    printf("inform how many liters you filled (-1 to exit): ");
    scanf("%f", &liters_to_fuel);

    if (liters_to_fuel == -1) {
      break;
    }

    printf("inform how many km you drove: ");
    scanf("%f", &kilometers_driven);

  }

  total_consumption = counter_total_consumption / counter;

  printf("overall consumption was %f km/l", total_consumption);
  
  return 0;
}

