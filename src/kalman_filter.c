
#include <kalman_filter.h>

#ifdef __cplusplus
extern "C"
{
#endif

	void KalmanFilter_init(KalmanFilter_Handle* handle)
	{
		// Nothing to do
	}
	void KalmanFilter_filter(KalmanFilter_Handle* handle, float input, float* output)
	{
		if(handle->bufferLength < handle->bufferMaxSize)
		{
			handle->bufferLength++;
		}
		handle->gain = 1 / handle->bufferLength;
		handle->estimated += (input - handle->estimated) / handle->bufferLength;
		*output = handle->estimated;
	}
	void KalmanFilter_reset(KalmanFilter_Handle* handle)
	{
		handle->bufferLength = 0;
		handle->estimated = 0;
	}

#ifdef __cplusplus
}
#endif