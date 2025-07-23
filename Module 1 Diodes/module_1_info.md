# Module 1: Diodes

# DIODE CHARACTERISTICS

It´s a two-terminal pn-junctions device. When the potential between anode and cathode is positive taking the anode like the reference point, the diode is forward biased and conducts, in this moment the diode has a relatively small forward voltage drop across it. In other case, when the potential between anode and cathode is negative taking the anode like the reference point, the diode is reverse biased, in this situation a small reverse current (leakage current) flows and that current increases slowly in magnitude with the reverse voltage. This behavior can be observed in this image

<img src="./images/behaviorDiode.png" alt="Diode behavior" />


And can be describe by the equation knows as Shockley diode equation

$$
I_D = I_S \left( e^{\frac{V_D}{n V_T}} - 1 \right)
$$

Where:

$I_D$ = Current through the diode, A

$V_D$ = Diode voltage with anode positive with respect to cathode, V

$I_S$ = Leakage current, typically in the range $10^{-6}$ A to $10^{-15}$ A

$n$ = empirical constant knowns as emission coefficient,  usually whose value varies from 1 to 2

The diode characteristic can be divided into three regions : 

- Forward-biased	region,	where	$V_D > 0$
- Reverse-biased	region,	where	$V_D < 0$
- Breakdown region,	where	$V_D < -V_BR$


# DIODE TYPES 
|Diode|Voltage range|Current range|Reverse recovery time|Applications| 
|---|---|---|---|---|
|General-purpose|50 V to 5 kV|0A to several thousands|25 $\mu\text{S}$ |Diode rectifier, converters for a low-input frequency up to 1 kHz, line-commutated converters|
|Fast-recovery|50 V to 3 kV|0A to hundreds of amperes|5 $\mu\text{S}$|DC-DC and DC-AC converter circuits|
|Schottky|0 V to 100 V| 1 A to 400 A|10 $n\text{S}$|High-current and low-voltage DC power supplies|

# FREEWHEELING

the freewheeling diode (Dm) provides a safe path for the inductive current when the switch opens, preventing high voltage spikes and protecting the switch from damage

<img src="./images/FreeWheelingDiode.png" alt="FreeWheeling diode" />

# RECTIFIERS WITH DIODES

## single-phase (full wave)

<img src="./images/single-phase.png" alt="Single Phase rectifier" />

A single-phase full-wave rectifier converts both the positive and negative halves of an AC voltage into a pulsating DC voltage. It uses a center-tapped transformer and two diodes. During the positive half-cycle, one diode conducts; during the negative half-cycle, the other does. This allows current to flow through the load in the same direction during both halves of the cycle. The result is a more efficient and smoother DC output compared to a half-wave rectifier.

## Three phases

<img src="./images/Three-phases.png" alt="Three Phases rectifier" />

A three-phase bridge rectifier uses six diodes to convert AC to DC in high-power applications. Two diodes conduct at a time, based on the highest line-to-line voltage, and each diode conducts for 120°. It produces a six-pulse DC output with lower ripple and works with or without a transformer

# PERFORMANCE PARAMETERS

- The average value of the output (load) voltage, $ V_dc $
- The average value of the output (load) current, $I_dc$
- The output dc power: $P_dc = V_dc I_dc$
- The root-mean-square (rms) value of the output voltage, $ V_rms $
- The rms value of the output current, $I_rms$
- The output AC power: $P_ac = V_rms * I_rms$
- The efficiency of a rectifier: $ n = P_dc/P_ac$


# DESIGN OF A RECTIFIER CIRCUIT


