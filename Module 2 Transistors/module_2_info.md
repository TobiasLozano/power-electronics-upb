# Module 2: Power Transistor

Power transistors are semiconductor devices designed to handle high levels of voltage and current, mainly used as electronic switches in power conversion systems such as dc–dc and dc–ac converters. They operate in saturation mode to minimize on-state voltage drop and provide fast switching, although their ratings are generally lower than those of thyristors

In this module, the emphasis is:

- Power MOSFETs.
- Power BJTs 

## Power MOSFETs

A power MOSFET is a voltage-controlled device that requires little input current and offers very high switching speeds (nanoseconds), making it ideal for low-power, high-frequency converters. Unlike BJTs, it is free from second breakdown issues but is sensitive to electrostatic discharge and harder to protect under short-circuit conditions.

There are two main types:

- Depletion MOSFETs: Already conductive at zero gate voltage. A negative gate-to-source voltage depletes the channel, - increasing resistance and eventually stopping current (at pinch-off voltage). A positive voltage widens the channel, lowering resistance.

<img src="./images/Channel_depletion.png" alt="Channel depletion">



- Enhancement MOSFETs: Non-conductive at zero gate voltage. A positive gate-to-source voltage above the threshold voltage creates a channel that allows current flow.

<img src="./images/Channel_enhancement.png" alt="Channel enhancement">

Since depletion MOSFETs are normally ON and enhancement MOSFETs are normally OFF, enhancement-type MOSFETs are preferred in power electronics switching applications. To reduce resistance and allow higher current conduction, vertical (V-type) MOSFET structures are commonly used

## Power BJTs

A BJT (Bipolar Junction Transistor) is formed by combining two pn-junctions, creating NPN or PNP types. It has three terminals: collector, emitter, and base. With a wide emitter, narrow base, and doped collector, it provides efficient current conduction and a low on-state resistance, making it useful in power applications.

<img src="./images/BJT.png" alt="BJTs">

Simulation.

<p align="center">
  <img width="1435" height="485" src="https://github.com/user-attachments/assets/27058c3a-b57c-4ec6-88c5-6f06211bf5cb" />
</p>

<p align="center"><em>Figure 1. BJT Circuit.</em></p>

<p align="justify">
This circuit represents a typical example of a power electronic stage that converts AC into a regulated DC output while providing control over the power delivered to the load. Let us carefully describe each part of the circuit and explain why every component is included.
</p>

<p align="justify">
The circuit begins with an AC voltage source, represented by V2, which provides a sinusoidal input signal at 120 V and 60 Hz. Because the system is designed to operate at a lower voltage level, a transformer is used. The transformer steps down the AC voltage to a more convenient level, indicated by the primary-to-secondary ratio shown in the schematic. Without this step, the downstream rectification and regulation stage would be forced to handle excessively high voltages, which would not be practical for power control at the load.
</p>

<p align="justify">
Following the transformer, the AC signal is rectified using a full-wave bridge rectifier formed by four diodes (D1 through D4). The purpose of this bridge is to convert the AC input, which alternates polarity every cycle, into a unidirectional current. Instead of wasting half of the waveform as in half-wave rectification, the full-wave bridge makes use of both halves of the input cycle, thereby doubling the frequency of the rectified pulses and improving efficiency.
</p>

<p align="justify">
The rectified output, however, is still a pulsating DC voltage. To smooth this ripple, a large filter capacitor (C1 = 14700 µF) is placed across the rectifier output. This capacitor charges up when the rectifier voltage rises and discharges into the load when the rectifier voltage falls, thereby filling in the gaps between pulses. The result is a much smoother DC voltage that can now be used as a source for the power stage. The size of this capacitor is deliberately large because the circuit is intended to supply significant current to the load, and a smaller capacitor would not be able to effectively maintain a stable voltage under such conditions.
</p>

<p align="justify">
Next, we encounter the control and switching stage, which uses two transistors. The control signal is provided by source V1, defined as a pulse generator. This represents a square-wave control input, similar to a PWM (Pulse Width Modulation) signal. The purpose of this signal is to turn the power transistor on and off at controlled intervals, regulating the amount of energy delivered to the load. However, the power transistor (Q1, a TIP35C) requires a significant base current to switch properly. Directly driving such a large transistor from the control signal would not be efficient or even feasible.
</p>

<p align="justify">
To solve this, the circuit includes a smaller transistor, Q2 (a 2N2222), which acts as a driver stage. The control pulse is applied to the base of Q2 through a resistor (R1 = 470 Ω), which limits the current and protects the transistor. When Q2 turns on, it provides a stronger current to the base of the TIP35C through resistor R5 (100 Ω). In this way, the 2N2222 amplifies the control signal, ensuring that the TIP35C receives the necessary base current to operate correctly. This arrangement, where a small transistor drives a larger one, is very common in power electronics and prevents the control circuit from being overloaded.
</p>

<p align="justify">
The TIP35C itself is a high-power BJT transistor capable of handling large collector currents, up to tens of amperes. In this circuit, it acts as the main switch that connects the DC supply to the load. The load is represented by resistor R3 (5.56 Ω), which consumes the regulated power. To further enhance the design, resistor R2 (10 kΩ) is included as a pull-down resistor to keep Q2 off when the control signal is not active, ensuring stable operation and preventing false triggering.
</p>

<p align="justify">
Finally, resistor R4 (0.1 Ω) is placed in series with the emitter of the TIP35C. This is a very low-value resistor known as a current-sensing resistor. Its role is to provide a small voltage proportional to the current flowing through the load. This voltage can be used for monitoring, feedback, or even for implementing overcurrent protection in a more advanced version of the circuit. Because the resistor is very small, it introduces minimal power loss while still providing useful information about the current.
</p>

<p align="justify">
In summary, the circuit works as follows: the AC source is stepped down, rectified, and filtered to provide a stable DC voltage. A PWM-like pulse signal controls a small transistor (2N2222), which drives the base of a large power transistor (TIP35C). This transistor then regulates the current delivered to the load, allowing control over power delivery. Each resistor and capacitor in the design serves a protective or functional role: limiting currents, stabilizing signals, or smoothing voltage. The result is a robust power stage suitable for supplying significant current to a load while allowing external control through the pulse generator.
</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/e2d63c08-45ef-43a8-81d0-49e760a5c092" />
</p>

<p align="center"><em>Figure 2. Current through resistor R5.</em></p>

<p align="justify">
Figure 2 shows the simulated current waveform across resistor R5, which is part of the driver stage connected to the 2N2222 transistor. The horizontal axis represents time, ranging from 0 to 2 seconds, while the vertical axis indicates the current in milliamperes. This analysis is crucial because R5 is directly tied to the base of the power transistor TIP35C, meaning its behavior reflects the demand placed on the control stage.
</p>

<p align="justify">
The waveform exhibits alternating periods of zero current followed by sharp current pulses synchronized with the control signal generated by V1. During the "ON" state of the 2N2222 transistor, the current through R5 increases up to approximately 8–9 mA. This level of current is more than sufficient to drive the TIP35C transistor into conduction, ensuring that it can switch effectively without saturating the control stage or overloading the microcontroller that would provide the input signal.
</p>

<p align="justify">
It is important to note that the ripple observed during the ON interval arises from the residual voltage variations in the rectified and filtered DC supply. The filter capacitor (C1) reduces most of the ripple, but a small oscillatory component remains and propagates into the base drive path. This ripple does not compromise circuit functionality, as the average current supplied through R5 remains stable and adequate for switching purposes.
</p>

<p align="justify">
From a design standpoint, the current drawn by R5 confirms that the driver stage isolates the microcontroller from the high-current requirements of the TIP35C. The microcontroller would only need to supply a small logic-level signal to the base of the 2N2222 through R1 (470 Ω). The 2N2222 then amplifies this control current and delivers the necessary base drive through R5. Therefore, the microcontroller is protected from excessive current draw, and the switching operation of the power stage remains reliable.
</p>

<p align="justify">
In summary, the waveform of Figure 2 demonstrates that resistor R5 carries short-duration pulses of approximately 8–9 mA, aligned with the PWM control signal. This ensures proper activation of the TIP35C without directly burdening the control electronics, validating the effectiveness of including the 2N2222 as a driver stage in the circuit.
</p>
<p align="center">
  <img width="1919" height="896" alt="image" src="https://github.com/user-attachments/assets/913957a5-2393-4400-b011-196ed556914e" />
</p>

<p align="center"><em>Figure 3. Current through resistor R3 (load).</em></p>

<p align="justify">
Figure 3 illustrates the current waveform across resistor R3, which represents the main load connected to the collector of the TIP35C transistor. The horizontal axis corresponds to time, ranging from 0 to 2 seconds, while the vertical axis indicates the current in amperes. Since R3 has a resistance of 5.56 Ω, its current directly reflects the effective power delivered to the load when the transistor is switched on.
</p>

<p align="justify">
The waveform shows two clear states: intervals of nearly zero current (when the TIP35C is in the cutoff region and no power is delivered to the load) and intervals where the current rises to approximately 1.6 A. This amplitude can be explained by Ohm’s law: 
</p>

<p align="center">
  <em>I = V / R</em>
</p>

<p align="justify">
Considering the filtered DC bus voltage of around 9 V and the load resistance of 5.56 Ω, the expected current is:
</p>

<p align="center">
  <em>I = 9 V / 5.56 Ω ≈ 1.62 A</em>
</p>

<p align="justify">
This calculation aligns well with the peak values observed in the simulation. The waveform also presents a small ripple during the ON state, which originates from the incomplete smoothing of the rectified voltage by the capacitor C1. Although the capacitor significantly reduces variations, residual oscillations remain and are mirrored in the current waveform. However, these fluctuations are minor compared to the average load current and do not compromise stability.
</p>

<p align="justify">
The periodic ON and OFF behavior corresponds to the control signal applied to the base of the 2N2222 transistor, which ultimately drives the TIP35C. During the ON state, the TIP35C provides the full current demanded by the load, while during the OFF state, the current through R3 drops to zero, effectively disconnecting the load from the DC supply. This demonstrates how the system controls power delivery by means of a pulse-width-modulated (PWM) input.
</p>

<p align="justify">
In conclusion, the current through R3 confirms the correct operation of the circuit: the load receives approximately 1.6 A in controlled pulses, consistent with the theoretical value predicted by Ohm’s law. This validates the effectiveness of the rectification, filtering, and switching stages, ensuring that the circuit can reliably deliver regulated current to the load while responding to the external control signal.
</p>
