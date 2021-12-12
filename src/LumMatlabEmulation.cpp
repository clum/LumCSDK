#include "LumMatlabEmulation.h"

/// <summary>
/// Emulate the 'linspace' command.
/// </summary>
/// <param name="X1"></param>
/// <param name="X2"></param>
/// <param name="N"></param>
/// <returns></returns>
float* linspace(float X1, float X2, unsigned int N = 100)
{
	float ret[N];

	double delta = (X2 - X1) / (N+1);
	for (unsigned int k = 0; k < N; k++) 
	{
		ret[k] = X1 + k * delta;
	}

	return ret;
}