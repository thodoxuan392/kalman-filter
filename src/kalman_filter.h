/**
 * @file kalman_filter.h
 * @author Xuan Tho Do (tho.dok17@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

	typedef float KalmanFilter_Data;

	typedef struct
	{
		KalmanFilter_Data* bufferPtr;
		uint32_t bufferMaxSize;
		uint32_t bufferLength;

		float gain;
		KalmanFilter_Data estimated;
	} KalmanFilter_Handle;

	void KalmanFilter_init(KalmanFilter_Handle* handle);
	void KalmanFilter_filter(KalmanFilter_Handle* handle, float input, float* output);

#ifdef __cplusplus
}
#endif

#endif // KALMAN_FILTER_H