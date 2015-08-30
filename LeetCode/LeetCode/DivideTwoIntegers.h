#pragma once
class DivideTwoIntegers
{
public:
	DivideTwoIntegers();
	int divide(int dividend, int divisor) {
		long long ans = 0;
		if (divisor == 0) return INT_MAX;
		if (dividend == INT_MIN&&divisor == INT_MIN) return 1;
		if (dividend == INT_MIN&&divisor == 1) return INT_MIN;
		if (dividend == INT_MIN&&abs(divisor)>abs(INT_MIN>> 1)) return 1;
		if (divisor == INT_MIN) return 0;
		if (dividend == INT_MIN){
			if (divisor > 0)
				dividend += divisor;
			else
				dividend -= divisor;
		}
		int sign = dividend>0 && divisor>0 ? 1 : (dividend<0 && divisor<0 ? 1 : -1);

		dividend = abs(dividend);
		divisor = abs(divisor);
		int bit = 0, i = divisor, quotient = 1;
		while (true){
			while (abs(dividend) >= abs(i) && i <= (INT_MAX >> 1))
			{
				i = i << 1;
				bit++;
			}
			if (i >(INT_MAX >> 1)){
				if (dividend <divisor) break;
				dividend -= i;
				for (int j = 0; j<bit; j++)
					quotient = quotient << 1;

				ans += quotient;
				bit = 0;
				i = divisor;
				quotient = 1;
			}			
			else if (abs(dividend)< abs(i) ){
				i = (i >> 1);
				if (dividend<divisor) break;
				dividend -= i;
				for (int j = 0; j<bit - 1; j++)
					quotient = quotient << 1;

				ans += quotient;
				bit = 0;
				i = divisor;
				quotient = 1;
			}
		}
		return  sign>0 ? ((ans>INT_MAX) ? INT_MAX : ans) : -ans;
	}
	~DivideTwoIntegers();
};

