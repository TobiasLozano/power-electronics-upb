# Module 4: Thyristors

A thyristor is a solid-state semiconductor device widely used in power electronics to control and convert electrical energy. It operates as a bistable switch, meaning it stays off until a gate signal triggers it on, and then remains conducting until the current naturally drops to zero or is externally forced off. Conventional thyristors are mainly used for rectification and power control in high-voltage and high-current applications, while advanced types like Gate Turn-Off Thyristors (GTOs) allow both turn-on and turn-off through gate control. Thyristors are valued for their high power-handling capability and low conduction losses, making them especially useful in industrial drives, HVDC transmission, and other high-power systems.

## Thyristors characteristics 

The main characteristics of thyristors are: 

- Four-layer PNPN structure: consists of three PN junctions (J1, J2, J3) and three terminals: anode, cathode, gate
<img src="./Images/Thyristors.png" alt="Thyristor symbol">
<p align="center"><em>Figure 1. Thyristor symbol.</em></p>

- Operating states: Forward blocking (off-state), Forward conducting (on-state), Reverse blocking state
- Latching current (IL): minimum anode current required to keep the thyristor conducting immediately after it has been turned on
- Holding current (IH): minimum anode current needed to sustain conduction. If current falls below IH, the device switches back to the blocking state (IH < IL)

<img src="./Images/V_I_characteristics.png" alt="V_I_Characteristics">
<p align="center"><em>Figure 2. V-I Characteristics.</em></p>

- Voltage and current ratings: designed for high voltage blocking (hundreds to thousands of volts) and high current carrying capability

## Thyristor types

- Phase-controlled thyristors (or SCRs)
- Bidirectional phase-controlled thyristors (BCTs)
- Fast switching asymmetrical thyristors (or ASCRs)
- Light-activated silicon-controlled rectifiers (LASCRs)
- Bidirectional triode thyristors (TRIACs)
- Reverse-conducting thyristors (RCTs)
- Gate turn-off thyristors (GTOs)
- FET-controlled thyristors (FET-CTHs)
- MOS turn-off thyristors (MTOs)
- Emitter turn-off (control) thyristors (ETOs)
- Integrated gate-commutated thyristors (IGCTs)
- MOS-controlled thyristors (MCTs)
- Static induction thyristors (SITHs)

A comparation table between the previous thyristors:


| **Type of Thyristor** | **Control / Structure** | **Key Features** | **Typical Applications** |
|-------------------------|--------------------------|------------------|--------------------------|
| **Phase-controlled thyristor (SCR)** | 3 terminals (Anode, Cathode, Gate) | Classical thyristor, gate-controlled turn-on only, turn-off by current zero crossing | Power rectifiers, AC/DC converters, motor drives |
| **Bidirectional phase-controlled thyristor (BCT)** | Combines two SCRs in anti-parallel on one chip | Conducts in both directions, reduces device count | AC power control, induction heating |
| **Fast switching asymmetrical thyristor (ASCR)** | Asymmetrical voltage blocking capability | High-speed switching, optimized for low switching losses | High-frequency inverters, choppers |
| **Light-activated SCR (LASCR)** | Triggered by light instead of gate current | Optical isolation, suitable for high-voltage applications | HVDC transmission, pulsed power systems |
| **Bidirectional triode thyristor (TRIAC)** | Equivalent to two SCRs in anti-parallel with one gate | Can switch both half-cycles of AC with one gate | Lamp dimmers, AC motor control, household appliances |
| **Reverse-conducting thyristor (RCT)** | SCR with built-in anti-parallel diode | Eliminates need for external diode, saves space | Inverters, motor drives |
| **Gate turn-off thyristor (GTO)** | Gate controls both turn-on and turn-off | High power capability, requires large gate current for turn-off | Traction, industrial drives, HVDC systems |
| **FET-controlled thyristor (FET-CTH)** | Combines FET and thyristor | Easier gate control, voltage-controlled operation | Power electronics where simpler control is needed |
| **MOS turn-off thyristor (MTO)** | Combines MOSFET with thyristor | MOSFET helps in controlled turn-off, improved efficiency | Medium-to-high power converters |
| **Emitter turn-off thyristor (ETO)** | Uses auxiliary MOSFETs in the emitter path | Very fast turn-off, low switching losses | Pulsed power, high-frequency power converters |
| **Integrated gate-commutated thyristor (IGCT)** | Improved GTO with integrated gate drive | Very high power, fast turn-off, low conduction losses | FACTS, HVDC, medium-voltage drives |
| **MOS-controlled thyristor (MCT)** | MOSFET structure embedded in thyristor | Full gate-controlled turn-on and turn-off, low gate power | Motor drives, inverters, DC/DC converters |
| **Static induction thyristor (SITH)** | Vertical-channel FET-like structure | Very fast switching, low on-state voltage, high-frequency | RF amplifiers, pulsed power, high-speed inverters |

Simulation

To analyze the switching characteristics and control behavior of the thyristor, different simulations were carried out using LTspice and Proteus. Each environment provided complementary insights: LTspice was used for waveform and component-level analysis, while Proteus allowed microcontroller-based control implementation.

1. Basic Thyristor Circuit

The initial setup represents a simple thyristor rectifier circuit. It consists of an SCR (Silicon Controlled Rectifier), a resistive load, and a basic RC triggering network. The purpose of this configuration is to observe the natural conduction of the thyristor when the gate receives a pulse and to analyze how it maintains conduction until the current falls below the holding current threshold.
![Tiristor_Circuit](https://github.com/user-attachments/assets/33fd4518-804a-4508-85fc-cd0c4c117869)


<p align="center"><em>Figure 3. Basic thyristor circuit schematic.</em></p>

In this circuit:

The AC voltage source provides a sinusoidal input that feeds the SCR and load.

The resistor-capacitor (RC) network determines the phase delay before triggering the gate.

Once the gate voltage exceeds the threshold, the SCR switches from its forward blocking state to forward conduction.

When the anode current drops below the holding current, the SCR naturally turns off at the next zero crossing.

This fundamental configuration helps to understand the latching and holding characteristics of the thyristor in open-loop conditions.

2. LTSpice Simulation – Uncontrolled Thyristor

The following circuit was simulated in LTspice to observe the uncontrolled behavior of the thyristor. It uses an MCR100-03 SCR model and a standard sinusoidal source. The gate is connected through a resistor network to provide a fixed triggering pulse without external modulation.
![Tiristor_Circuit_SIM](https://github.com/user-attachments/assets/3c5882f5-8421-4e11-8d95-141034260e29)

<p align="center"><em>Figure 4. LTspice simulation of the uncontrolled thyristor circuit.</em></p>

The waveform generated in the simulation shows a typical phase-controlled rectified output:

At each positive half-cycle, the SCR turns on once the gate receives a sufficient pulse, allowing current flow through the load.

The output voltage waveform presents the characteristic ramp-up and decay pattern, showing conduction only during the part of the input cycle where the SCR is triggered and current remains above the holding threshold.

When the current reaches zero, the SCR returns to the blocking state, awaiting the next gate pulse.

This simulation validates the basic operation of the SCR and demonstrates how it can be used for power control in AC applications such as dimmers, controlled rectifiers, and motor speed control systems.

3. Proteus Simulation – Arduino Controlled Thyristor

Since LTspice does not natively support microcontroller integration, the control part of the system was implemented in Proteus using an Arduino Uno. The Arduino generates the gate signal according to a variable input (simulated via a potentiometer connected to an analog pin), allowing real-time adjustment of the thyristor’s firing angle.
![Tiristor_Circuit_SIM_Proteus](https://github.com/user-attachments/assets/4b6aea46-f37a-4db0-9af0-798db304776a)

<p align="center"><em>Figure 5. Proteus simulation with Arduino-based thyristor control.</em></p>

In this configuration:

The Arduino reads the voltage level from the potentiometer and converts it into a delay time for the gate trigger.

Two optocouplers (PC817) provide electrical isolation between the low-voltage Arduino control circuit and the high-voltage thyristor section.

The SCR is triggered at different points of the AC cycle depending on the analog input value, effectively adjusting the average output voltage across the load.

This setup demonstrates phase-angle control using a microcontroller, a key concept in industrial power electronics, used in systems like dimmers, temperature controllers, and AC voltage regulators.


