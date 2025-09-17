# Module 3: Buck and Boost Converters

## 3.1 INTRODUCTION

In modern industrial and electronic applications, it is often necessary to convert a fixed DC voltage source into a variable DC voltage source. A **DC–DC converter** is the circuit that performs this task by directly processing the DC power, and it is therefore simply referred to as a **DC converter**. From a theoretical perspective, a DC–DC converter can be regarded as the DC counterpart of an AC transformer with a continuously variable turns ratio. In the same way that a transformer can either step up or step down an AC voltage, a DC–DC converter can step up (**boost**) or step down (**buck**) a DC voltage.  

These converters find wide application in traction motor control for electric vehicles, trolley cars, hoists, and forklifts, as well as in renewable energy systems. Their advantages include smooth acceleration control, high efficiency, and fast dynamic response. In transportation systems, DC–DC converters are also crucial because they enable regenerative braking of DC motors, feeding energy back to the supply and achieving significant energy savings. Furthermore, they are used in DC voltage regulation and in conjunction with inductors to generate current sources for inverters. As such, DC–DC converters are integral to modern energy conversion, especially in renewable and sustainable power systems.  

<p align="center">
  <img width="852" height="437" alt="General block diagram of a DC–DC converter" src="https://github.com/user-attachments/assets/036606ca-2a51-4d0f-b483-35b62f3cab01" />
</p>  

<p align="center"><em>Figure 1. General block diagram of a DC–DC converter, illustrating the main power processing stage between input and output.</em></p>

The performance of a practical DC–DC converter can be described in terms of its input and output voltages and currents. Ideally, both should be pure DC; however, due to switching, they include harmonics and ripples. These fluctuations are inherent to the converter’s operation and appear both at the input and the output.  

<p align="center">
  <img src="https://github.com/user-attachments/assets/9f967c6d-abf6-4b22-8074-6cda4efb5291" alt="Typical output voltage waveform of a DC–DC converter" width="800"/>
</p>  

<p align="center"><em>Figure 2. Typical output voltage of a DC–DC converter, showing the average value with a superimposed ripple due to switching operation.</em></p>  

<p align="center">
  <img src="https://github.com/user-attachments/assets/1b6d6c42-004a-40f6-b1ec-40c8b0557dd6" alt="Typical input current waveform of a DC–DC converter" width="800"/>
</p>  

<p align="center"><em>Figure 3. Typical input current of a DC–DC converter, showing the average value and the ripple component introduced by switching.</em></p>
  

La potencia promedio de salida de un convertidor DC-DC es:

$$P_{dc} = V_a \cdot I_a$$

donde $V_a$ es el voltaje promedio de salida y $I_a$ es la corriente promedio de carga (Rashid, 2017).

This general theory sets the foundation for analyzing two of the most basic and fundamental converters: the **buck converter**, which reduces the voltage, and the **boost converter**, which increases it. In the following sections, their operation will be explained in detail, starting from the inductor and capacitor equations, applying the volt–second balance, and deriving the steady-state relations for each case.

---

## 3.2 BUCK CONVERTER

The buck converter is a DC–DC power electronic circuit whose function is to reduce an input voltage $V_{in}$ to a lower output voltage $V_o$. The basic circuit consists of a controlled switch $S$, a diode $D$, an inductor $L$, an output capacitor $C$, and a resistive load $R$. The theoretical development of its operation is based on the inductor voltage law $v_L = L \frac{di_L}{dt}$, Kirchhoff's laws, and the periodic steady-state condition, which requires volt–second balance on the inductor and charge balance on the capacitor.

[Insert Figure: Buck converter schematic]

When the switch is ON for a duration $DT$, where $D$ is the duty cycle and $T = \frac{1}{f_s}$ is the switching period, the input source is directly applied to the inductor and load. The inductor voltage is:

$$
v_{L(on)} = V_{in} - V_o
$$

Thus, the inductor current increases linearly:

$$
\Delta i_{L(on)} = \frac{(V_{in} - V_o) D}{L f_s}
$$

When the switch is OFF for a duration \( (1-D)T \), the inductor releases energy through the diode to the load. The inductor voltage becomes:

$$
v_{L(off)} = -V_o
$$

and the inductor current decreases:

$$
\Delta i_{L(off)} = - \frac{V_o (1-D)}{L f_s}
$$

In steady state, the current ripple cancels over one period, i.e.,

$$
\Delta i_{L(on)} + \Delta i_{L(off)} = 0
$$

Substituting gives:

$$
(V_{in} - V_o)D - V_o(1-D) = 0
$$

which simplifies to the **buck voltage conversion ratio**:

$$
V_o = D \, V_{in}
$$

---

### Inductor Ripple and CCM Condition

The peak-to-peak ripple of the inductor current is:

$$
\Delta I_L = \frac{(V_{in} - V_o) D}{L f_s}
$$

To limit ripple below a maximum desired value, the minimum inductance is:

$$
L = \frac{(V_{in} - V_o) D}{\Delta I_{L(max)} f_s}
$$

For continuous conduction mode (CCM), the average inductor current, equal to the load current \( I_o = \tfrac{V_o}{R} \), must exceed half the ripple:

$$
I_o > \frac{\Delta I_L}{2}
$$

From this, the **critical inductance** is obtained:

$$
L_{crit} = \frac{(1-D)R}{2 f_s}
$$

---

### Output Capacitor and Voltage Ripple

The capacitor current is:

$$
i_C(t) = i_L(t) - I_o
$$

Approximating \( i_L(t) \) as a triangular waveform and applying charge balance, the peak-to-peak output voltage ripple is approximately:

$$
\Delta V_{o(pp)} \approx \frac{\Delta I_L}{8 f_s C}
$$

From this, the required capacitance is:

$$
C = \frac{\Delta I_L}{8 f_s \Delta V_o}
$$

---

## 3.3 BOOST CONVERTER

The boost converter increases the input voltage \( V_{in} \) to a higher output voltage \( V_o > V_{in} \). The circuit consists of a controlled switch, a diode, an inductor, a capacitor, and a resistive load. The analysis again applies the inductor voltage law and periodic steady-state condition.

[Insert Figure: Boost converter schematic]

During the ON interval \( DT \), the switch is closed and the diode blocks. The inductor voltage is:

$$
v_{L(on)} = V_{in}
$$

and the inductor current increases:

$$
\Delta i_{L(on)} = \frac{V_{in} D}{L f_s}
$$

During the OFF interval \( (1-D)T \), the switch opens and the inductor transfers energy to the load through the diode. The inductor voltage is:

$$
v_{L(off)} = V_{in} - V_o
$$

The current variation is:

$$
\Delta i_{L(off)} = \frac{(V_{in} - V_o)(1-D)}{L f_s}
$$

Applying volt–second balance:

$$
V_{in} D + (V_{in} - V_o)(1-D) = 0
$$

which simplifies to the **boost conversion ratio**:

$$
V_o = \frac{V_{in}}{1-D}
$$

---

### Inductor Ripple and CCM Condition

The inductor current ripple is:

$$
\Delta I_L = \frac{V_{in} D}{L f_s}
$$

The average inductor current equals the input current:

$$
I_{in} = \frac{I_o}{1-D}
$$

At the CCM boundary, the minimum inductor current reaches zero, i.e.,

$$
I_{in} = \frac{\Delta I_L}{2}
$$

Solving leads to the **critical inductance**:

$$
L_{crit} = \frac{D R (1-D)^2}{2 f_s}
$$

---

### Output Capacitor and Voltage Ripple

During the ON interval, the load is supplied only by the capacitor. The charge balance gives the output ripple:

$$
\Delta V_{o(pp)} \approx \frac{I_o D}{C f_s}
$$

Thus, the minimum required capacitance is:

$$
C = \frac{I_o D}{f_s \Delta V_o}
$$

---

## Practical Considerations

The above relations assume ideal components. In practice, the switch and diode have voltage drops, the inductor has winding resistance, and the capacitor has equivalent series resistance (ESR). These nonidealities reduce efficiency and modify the exact values of ripple and output voltage. The analysis with nonidealities follows the same laws but includes additional resistive and semiconductor voltage terms.

[Insert Figure: Buck waveforms]  
[Insert Figure: Boost waveforms]  

---

### Reference

Muhammad H. Rashid, *Power Electronics: Circuits, Devices, and Applications*. Pearson.

