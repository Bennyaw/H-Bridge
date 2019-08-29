H-Bridge DC-DC Converter (In progress)
========================
This repository is a project about **SMPS H-Bridge DC-DC converter**, it is going to step down from high voltage 360V to low voltage 50V for driving load. The circuit will be constructed on a prototype board and later on will be move on to PCB board.  
The overall system works as the block diagram shows below. The microcontroller is to generate pulse to MOSFET driver to switch the MOSFET in H-Bridge during the operation. Feedback circuit is always watching the load voltage and current and feedback status to microcontroller, if any over-voltage or over-current condition occurs, the microcontroller immediately compensate the pulse proper operating load voltage or current.
![h-bridge block diagram](https://github.com/Bennyaw/H-Bridge/blob/master/images/h%20bridge%20block%20diagram.png)  

Table of Content
================
1. [Requirement](#req)  

# <a name = req></a> Requirement  
Software
--------
-STM32CubeMX  
-Eclipse  
-Ceedling  

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

Introduction
============
H-Bridge is a DC-DC converter topology which has four switching components in the system, which here are N-Channel MOSFETs, across a transformer. During the operation, a pair of MOSFETs is switched on 1 side of the driver at the same time.  
When "a pair of MOSFETs is switched" means that either 1 MOSFET is turn **OFF** and another 1 is **ON**, from the schmatic below, M1, M2 is a pair and drove by 1 MOSFET Driver, M3,M4 will be another one.
The arrow shows how the current go through the MOSFET during the operation.
In order let current flow, either M1 M4 turn **ON** , or either M2 M3 turn **ON**.  
![](https://github.com/Bennyaw/H-Bridge/blob/Bennyaw-readme/images/4%20mosfets.PNG)






Reference
==========
[1] H-Bridge Drivers  
http://www.modularcircuits.com/blog/articles/h-bridge-secrets/h-bridge_drivers/  
[2] Design of a 2.5kW DC/DC Fullbridge Converter, Christian Andersson,  
http://publications.lib.chalmers.se/records/fulltext/173958/173958.pdf  
[3] Using the high-low side driver IR2110 - explanation and plenty of example circuits, Tahmid’s blog,  
http://tahmidmc.blogspot.com/2013/01/using-high-low-side-driver-ir2110-with.html  
