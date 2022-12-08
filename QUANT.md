# Quantization Maths

## Quantization Formulas

Mapping Function:

	Q = round(F/S + Z)

Notice that:

	f = (Q - Z) * S
	leadsto: f != F

with:

	F = Float value
	Q = Quantized value
	f = Reconstructed float value

Scaling Factor: S
Zero-Point: Z

	S = (B - A) / (Bq - Aq)
	Z = - ( (A / S) - Aq)

with:

	A,B = Clipping Range
	and, |Bq - Aq| <= (2**bitwidth - 1)

A, B are determined during `Calibration` which are by default the Max-Min, but could be obtained in several ways (e.g., Entropy Minimization, mean-square-error minimization, ...).

## Quantized Matrix Multiplication

Given the floating matrices `If`, `Wf`, `Of` with `Of = If x Wf` and their corresponding integer version `Ii`, `Wi`, `Oi`.
Given the respective Scale Factors `si`, `sw`, `so` and the respective Zero Points `zi`, `zw`, `zo`.

The GEMM can be computed as:

	Of = If x Wf

	so*(Oi - zi) = si*sw*((Ii x Wi) - zi*Wi - zw*Ii)

However, in case of Symmetric Quantization (Zero Points are null):

	Of = si*sw*(Ii x Wi)
