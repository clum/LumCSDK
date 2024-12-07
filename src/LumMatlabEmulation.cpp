#include "LumMatlabEmulation.h"

/// <summary>
/// Emulate the 'linspace' command but only returns an array of length 10.
/// </summary>
/// <param name="X1"></param>
/// <param name="X2"></param>
/// <param name="N"></param>
/// <returns></returns>
float* linspace10(float X1, float X2)
{
	//Version History
	//??/??/??: Created
	//12/06/24: Changed to only output a 10 element array

	float ret[10];
	unsigned int N = 10;
	double delta = (X2 - X1) / (N+1);
	for (unsigned int k = 0; k < N; k++) 
	{
		ret[k] = X1 + k * delta;
	}

	return ret;
}