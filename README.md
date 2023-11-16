# RandomNumber-Generator <img src="https://cdn.iconscout.com/icon/premium/png-256-thumb/random-number-generate-2302894-1951461.png" width="60" height="60" />

## <img src="https://github.com/YaraHisham61/OS_Scheduler/assets/88517271/34402b46-ead8-415c-96f6-a21dce7fa14d" width="30" height="30" /> Table of Contents

- [Overview](#Overview)
- [System Description](#sysdes) 
- [Components](#comp)
- [Methodology](#run)
- [Algorithm](#algo)
- [Demo Video](#vid)


<hr style="background-color: #4b4c60"></hr>

## <img src="https://cdn-icons-png.flaticon.com/512/8632/8632710.png" width="30" height="30" /> Overview <a name = "Overview"></a>
This project aims to develop a digital device that randomizes 5-digit integer numbers using an ATmega328P microcontroller without any built-in functions.

## <img src="https://github.com/YaraHisham61/OS_Scheduler/assets/88517271/d8e6c9f3-9ba5-4d9e-a108-7d9a95989812" width="30" height="30" /> System Description <a name = "sysdes"></a>
There are 2 MCUs, one is the processing device (Proc MCU) which is responsible for the random number generation, and the other
one is the human interface (HMI MCU) which is responsible for controlling the processing device according to the user input.

## <img src="https://cdn2.iconfinder.com/data/icons/advertisement-marketing/512/puzzle-512.png" width="30" height="30" /> Components <a name = "comp"></a>

| Component 	| Role | Connected MCU|
|:----------------------|:-------------------|:-------------------|
| 7-segment	| Displays the current digit | HMI |
| 5 LEDs | The remaining time (initially it’s the process runtime)| HMI |
| 3 push buttons |	controls the digital Randomizer (generate - next - previous) | HMI |
| Servo Motor |	Provides angular feedback | HMI  |
| Buzzer |	Provides audible feedback | HMI |
| 3 LEDs |	Shows the state of the processing MCU | Proc  |

## <img src="https://cdn-icons-png.flaticon.com/512/6289/6289238.png" width="30" height="30" /> Methodology <a name = "meth"></a>
* The user should press the “Generate” push button, then the HMI MCU sends to the processing MCU to generate a random number.
* Once the processing MCU receives the request and validates it, the 1st connected LED to the processing MCU should turn ON, and after one second, the second LED should be turned on, which indicates the random number is generated and ready to be sent, then
after one second, the processing MCU should respond to the HMI MCU with the random number and turn on the 3rd LED. Turn off all the LEDs after one second. If there is something wrong with the synchronization between the 2 MCUs, let the 3 LEDs toggle for 5 seconds (toggle every 500 ms).
* After the HMI receives the generated number, it should be represented in 5 digits so show digit by digit and turn on the LED corresponding to the order of the digit in the number from the 5 LEDs and each digit should last for one second. The buzzer should release a sound with duty cycle equal to the ratio of the digit value / 10 and after 5 seconds,
the duty cycle should be the random number / 65535.
* HMI should also move the servo to position (random number % 180) in a time period of 5 seconds.
* If the user presses the “Next” push button, then the HMI MCU should ignore the current task and then show the next digit quickly. The same if the user presses the “Previous” push button.
* If the user presses the “Generate” push button before the MCU finishes the previous task, ignore the current task and start the new task immediately.

## <img src="https://cdn-icons-png.flaticon.com/512/7690/7690595.png" width="30" height="30" /> Algorithm <a name = "algo"></a>
* Initialization:
  - The Timer1 counter value (TCNT1) is used to seed the initial value of randomDigit.
    ```
    // Use Timer1 value as seed to update randomDigit
      randomDigit += TCNT1;
    ```

* Number Generation Loop:
  - A loop runs five times, populating the randomNumber array with random single-digit numbers.
The random numbers are generated using the formula ((randomDigit ^ TCNT1) % 10).
    ```
     for (uint8 i = 0 ; i<5 ; i++ ){
    randomNumber[i] = ((randomDigit ^ TCNT1) % 10);
    }
    ```
* Interrupt Service Routine (ISR):
  - An ISR is triggered on ADC conversion completion.
The ADC result is XORed with randomDigit to further update the randomness.
A new ADC conversion is started to continue the process.

    ```
    // ADC conversion complete interrupt service routine
    ISR(ADC_vect) {
      // Read ADC result
      uint16 adcValue = ADC;
      
      // Use ADC value to further update randomDigit
      randomDigit ^= adcValue;
      
      // Start new ADC conversion
      ADCSRA |= (1 << 6);
    }
    ```
## <img src="https://github.com/YaraHisham61/AYKN-Search-Engine/assets/88517271/2783fa4c-1371-45d2-bbfa-7682bbc4b65d" width="30" height="30" /> Demo Video <a name = "vid"></a>


https://github.com/YaraHisham61/RandomNumber-Generator/assets/88517271/f7acb804-db72-4580-8586-e139fda43f46

