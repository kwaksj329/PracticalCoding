#include "fx_head.h"
#include "fx_s15_16.h"

//extern fixed fxAdd_float(), fxAdd_precision(), fxAdd_fair(), fxAdd_performance(); 
//extern fixed fxSub_float(), fxSub_precision(), fxSub_fair(), fxSub_performance(); 
//extern fixed fxMul_float(), fxMul_precision(), fxMul_fair(), fxMul_performance(); 
//extern fixed fxDiv_float(), fxDiv_precision(), fxDiv_fair(), fxDiv_performance(); 

#define fxADD(a, b) ((a)+(b))

fixed fx_Add_float(fixed a, fixed b)
{
	return fxADD(a, b);
}

fixed fx_Add_precision(fixed a, fixed b)
{
	return fxADD(a, b);
}
fixed fx_Add_fair(fixed a, fixed b)
{
	return fxADD(a, b);
}
fixed fx_Add_performance(fixed a, fixed b)
{
	return fxADD(a, b);
}
fixed fxMul_float(fixed a, fixed b) 
{
	return fromFloat(toFloat(a) * toFloat(b)); 
}
fixed fxMul_precision(fixed a, fixed b) 
{
	long long la = a, lb = b, lc;
	lc = la * lb;		// 장점: 오버플로우가 발생하지 않는다.
	lc >>= FX_Q_NUM;
	return (fixed) lc;
}

// 16 --> 8, 8
// 15 --> 8, 7
#define FX_Q_NUM_B (FX_Q_NUM/2)
#define FX_Q_NUM_A (FX_Q_NUM - (FX_Q_NUM/2))

fixed fxMul_fair(fixed a, fixed b)
{
	return ((a>>4) * (b>>4)) >> 8;
}

fixed fxMul_performance(fixed a, fixed b)
{
	return (a>>FX_Q_NUM) * (b>>FX_Q_NUM_B);
	return (a>>8) * (b>>8);
	return (a*b)>>16;		//1.0 * 1.0 overflow
}
