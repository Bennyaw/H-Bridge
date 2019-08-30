H-Bridge DC-DC Converter (In progress)
========================
This repository is a project about **SMPS H-Bridge DC-DC converter**, it is going to step down from high voltage 360V to low voltage 50V for driving load. The circuit will be constructed on a prototype board and later on will be move on to PCB board.  
The overall system works as the block diagram shows below. The microcontroller is to generate pulse to MOSFET driver to switch the MOSFET in H-Bridge during the operation. Feedback circuit is always watching the load voltage and current and feedback status to microcontroller, if any over-voltage or over-current condition occurs, the microcontroller immediately compensate the pulse proper operating load voltage or current.
![h-bridge block diagram](https://github.com/Bennyaw/H-Bridge/blob/master/images/h%20bridge%20block%20diagram.png)  

Table of Content
================
1. [Requirement](#req)  
2. [H-Bridge](#hbridge)  //will be including Rsense signal result  
3. [IR2113](#ir2113)  
    1. [Bootstrap Capacitor](#bootcap)  
4. [Protection Circuit](#protectcircuit)
    1. [Over Current Protection](#ocp)  
    1. [Over Voltage Protection](#ovp)  
5. [STM32F103C8T6](#uc)  
    1. [Setting Up Microcontroller](#setup)  //will be including steps to configure timer  
    2. [DeadTime Insertion](#deadtime)  
    
# <a name = req></a> Requirement  
Software
--------
-STM32CubeMX  
-Eclipse  
-Ceedling  
-NI Multisim  

Equipmemt
-----------
-STM32F103C8T6 Blue pill  
-STM32F103 Smart V2  
-30V/3A power supply test bench  
-4x STP80NF70 N-Channel MOSFET  
-2x IR2113 MOSFET Driver  
-2x C106D SCR  
-2x LDO LM1117 voltage regulator  
-2x LDO LM7805 voltage regulator  
-2x 2k Trimpot  
-2X LM311N Comparator  
-perf board  
-GD74LS00 NAND Gate  

## <a name = hbridge></a> H-Bridge   
![](https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/h%20bridge%20sch.png)  
<div align="center">
  Figure 0. Schematic of H-Bridge DC-DC converter without subcircuit
</div>  
  
H-Bridge is a DC-DC converter topology which has four switching components in the system, which here are N-Channel MOSFETs, across a transformer. During the operation, a pair of MOSFETs is switched on 1 side of the driver at the same time.  
When "a pair of MOSFETs is switched" means that either 1 MOSFET is turn **OFF** and another 1 is **ON**, from the schmatic below, M1, M2 is a pair and drove by 1 MOSFET Driver, M3,M4 will be another one.
The arrow shows how the current go through the MOSFET during the operation.
In order let current flow, either M1 M4 turn **ON** , or either M2 M3 turn **ON**.  
![](https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/4%20mosfets.PNG)

## <a name = ir2113></a> IR2113 MOSFET Driver  
![](https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/IR2113%20with%20h-bridge.png)
<div align="center">
  Figure 1. Schematic of IR2113 Mosfet Driver in Multisim
</div>  

### <a name = bootcap></a> Bootstrap Capacitor  
The reason we want to have a driver is because there is the Highside MOSFET, which is M1 and M3 from the circuit above, do not have sufficient Vgs value to turn **ON** fully, therefore it cannot deliver full power to the load. So, the driver is used here.  
In the circuit of IR2113 below, the bootstrap capacitor will be charged up to VCC voltage when to highside MOSFET is OFF, source voltage of MOSFET is floating. When the transistor is turn ON, the bootstrap capacitor will make sure the gate-source voltage is enough to fully turn on the transistor. Suggested VCC supply to IR2113 is 15V. [Link](https://www.infineon.com/dgdl/ir2110.pdf?fileId=5546d462533600a4015355c80333167e.) to IR2113 Datasheet      
![](https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/IR2113%20datasheet%20sch.PNG)  
<div align="center">
  Figure 2. Suggested construction of IR2113 in datasheet
</div>  

To calculate the bootstrap capacitor value, can refer to the application note [here](https://www.infineon.com/dgdl/Infineon-HV_Floating_MOS_Gate_Drivers-ApplicationNotes-v01_00-EN.pdf?fileId=5546d4626c1f3dc3016c47de609d140a&redirId=114085) , page 5&6.  

![](https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/equation%20for%20bootstrap%20capacitance.PNG)
  <div align="center">
  Figure 3. Equation to calculate minimun bootstrap capacitance 
</div>  

## <a name = protectcircuit></a> Protection Circuit  
The **LDO**, low-dropout voltage regulator, is there to give a maximum 3.3V voltage input to compartor, and we also want to reduce the number power supply in the circuit system. So, we have a supply of 12V-15V(Depends on the VCC voltage for IR2113) for the LM7805 supply a 5V output voltage to LM311N comparator. Then LM1117-3.3 will take 5V input and geenrate 3.3V to trimpot to set a voltage reference at the inverting pin of comparator.  

The **SCR**, silicon controlled rectifier, is to act as a memory or latching component. Whenever there is a over current or voltage happen on the *current sense resistor* or *load* respectively, it will triggered the SCR and pull the voltage at **OCP** and **OVP** until is it reset. The LED is a indicator to indicates the SCR is triggered.  
<img src ="https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/scr%20ocp.png" width="220"><img src ="https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/scr%20ovp.png" width="220">  

To **reset** SCR  
-remove power supply for SCR,stop the current flowing through SCR  
-give negative voltage on the gate  
When SCR is triggered here means that the circuit is at risk of damage,either over current on the primary side or over voltage on the load, we want the driver to stop immediately before any further damage on the system. So to do that, we connect the OCP and OVP to a NAND gate, output of NAND gate is connected to the SD(shutdown) pin on the IR2113 to stop the system.  
<img src ="https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/Nand%20gate%20to%20SD.png" width="220">  

### <a name = ocp></a> Over Current Protection 
R8 resistor (in figure 1) is the **current sense resistor**, this resistor is to constantly watch the amount of current in the system. Usually having very small resistance, below 1Ohm. To make sure the current does not exceed and damage the transistors, **over protection circuit** is introduced.  
![](https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/over%20protection%20circuit.png)  
<div align="center">
  Figure 4. Schematic of Over Current Protection on current sense resistor
</div>  

```
Vsense = I x Rsense
I : Current flowing in the primary side,(A)
```  

The comparator non-inverting input(+) voltage  is comparing with the Vref at the inverting input(-),which is controlled by the trimpot.   
When V(+) > V(-) : Vout=5V, SCR trigger  
When V(+) < V(-) : Vout=0V, SCR is not trigger  

### <a name = ovp></a> Over Voltage Protection 
R1 resistor (in figure 0) is the **load**, this load is to constantly to have a fixed voltage,here we limit it to 50V. To make sure the voltage does not exceed and damage the load, **over voltage circuit** is introduced.  
![](https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/over%20voltage%20protection.png)  
<div align="center">
  Figure 5. Schematic of Over Voltage Protection on load
</div>  

The comparator non-inverting input(+) voltage  is comparing with the Vref at the inverting input(-),which is controlled by the trimpot.   
When V(+) > V(-) : Vout=5V, SCR trigger  
When V(+) < V(-) : Vout=0V, SCR is not trigger  

//will add a combined schematic circuit of OCP and OVP
## <a name = uc></a> STM32F103C8T6  
Both the microcontroller is using the same ARM processor, but blue pill has the debug feature, so it is the programme board and smart V2 board is the target board. Download the program on the blue pill and runs on smart V2 board.
<img src ="https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/circuit%20stm32.jpg" width="220">  

### <a name = setup></a> Setting Up Microcontroller  
1. Find the swd pins on the smart v2.  
<img src ="https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/connection%20between%20blue%20pill%20and%20smart%20v2.jpg" width="500">  

2. Constructs the connections between blue pill and smart V2 as below diagram  
<img src ="https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/blue%20pill%20to%20smart%20v2.jpg" width="270">  

3. Plug in USB cable to blue pill. Make sure both the MCU have sufficient voltage power supply.   
4. Run simple program to test whether is working or not.  

### <a name = deadtime></a> DeadTime Insertion  
Dead time is the time frame that both complementary signals is low. These signals are usually used to switch **ON** and **OFF** transistors like MOSFETs. Signal high, transistor **ON**, signal low, transistor **OFF**. In H-bridge here, we do not want to have both transistors to turn ON at the same time on the same driver, this will cause a very large current to shoot through both transistor and deals damage to the whole system. Even though MOSFET has a fast switching characteristic, but it is still not enough to prevent shoot through condition. So deadtime is to make sure that 1 transistor fully turn OFF before another transistor turns ON.  
<img src ="https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/deadtime%20datasheet.PNG" width="330">  

To configure it, just follow the equation provided by the [datasheet](https://www.st.com/content/ccc/resource/technical/document/reference_manual/59/b9/ba/7f/11/af/43/d5/CD00171190.pdf/files/CD00171190.pdf/jcr:content/translations/en.CD00171190.pdf) in STM32F103C8T6.  
These 8 bits is the configuration for the duration of the deadtime. It is ***only available in Advanced Timer, which is Timer1 and Timer8***, located inside ***BDTR register***.  
<img src ="https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/dtgbits.PNG" width="435">  


## Will be adding in future  
-Timer1 configurations  
-timer1 output waveform result  
-discuss DMA request  

 













Reference
==========
[1] H-Bridge Drivers  
http://www.modularcircuits.com/blog/articles/h-bridge-secrets/h-bridge_drivers/  
[2] Design of a 2.5kW DC/DC Fullbridge Converter, Christian Andersson,  
http://publications.lib.chalmers.se/records/fulltext/173958/173958.pdf  
[3] Using the high-low side driver IR2110 - explanation and plenty of example circuits, Tahmid’s blog,  
http://tahmidmc.blogspot.com/2013/01/using-high-low-side-driver-ir2110-with.html  
[4] IR2110(S)PbF/IR2113(S)PbF  
https://www.infineon.com/dgdl/ir2110.pdf?fileId=5546d462533600a4015355c80333167e  
[5] Application Note AN-978, Intertional Rectifier,  
https://www.infineon.com/dgdl/Infineon-HV_Floating_MOS_Gate_Drivers-ApplicationNotes-v01_00-EN.pdf?fileId=5546d4626c1f3dc3016c47de609d140a&redirId=114085  
[6] J-LINK,  
https://docs.platformio.org/en/latest/plus/debug-tools/jlink.html
[7] RM0008,
https://www.st.com/content/ccc/resource/technical/document/reference_manual/59/b9/ba/7f/11/af/43/d5/CD00171190.pdf/files/CD00171190.pdf/jcr:content/translations/en.CD00171190.pdf
