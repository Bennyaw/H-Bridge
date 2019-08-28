H-Bridge DC-DC Converter (In progress)
========================
This repository is a project about DC-DC converter, it is going to step down from high voltage 360V to low voltage 50V for driving load. The circuit will be constructed on a prototype board and later on will be move on to PCB board.

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
-2x LDO //need to be confirm
-2x LDO //need to be confirm
-2x 2k Trimpot
-2X LM311N Comparator
-perf board

Introduction
============
H-Bridge is a DC-DC converter topology which has four switching components in the system, which here are N-Channel MOSFETs, across a transformer. During the operation, a pair of MOSFETs is switched




Reference
==========
[1] H-Bridge Drivers
http://www.modularcircuits.com/blog/articles/h-bridge-secrets/h-bridge_drivers/
[2] Design of a 2.5kW DC/DC Fullbridge Converter, Christian Andersson,
http://publications.lib.chalmers.se/records/fulltext/173958/173958.pdf
[3] Using the high-low side driver IR2110 - explanation and plenty of example circuits, Tahmid’s blog,
http://tahmidmc.blogspot.com/2013/01/using-high-low-side-driver-ir2110-with.html
