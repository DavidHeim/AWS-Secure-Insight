/**
 *
 * \file
 *
 * \brief AWS IoT Demo kit.
 *
 * Copyright (c) 2014-2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef AWS_KIT_TIMER_H_
#define AWS_KIT_TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/time.h>

#define	timeradd(tvp, uvp, vvp)								\
	do {													\
		(vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;		\
		(vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;	\
		if ((vvp)->tv_usec >= 1000000) {						\
			(vvp)->tv_sec++;								\
			(vvp)->tv_usec -= 1000000;						\
		}													\
	} while (0)
#define	timersub(tvp, uvp, vvp)								\
	do {													\
		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\
		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;	\
		if ((vvp)->tv_usec < 0) {							\
			(vvp)->tv_sec--;								\
			(vvp)->tv_usec += 1000000;						\
		}													\
	} while (0)

typedef struct RTT_Timer {
	struct timeval end_time;
} Timer;


void configure_rtt(void);
/**
 * @brief Check if a timer is expired
 *
 * Call this function passing in a timer to check if that timer has expired.
 *
 * @param Timer - pointer to the timer to be checked for expiration
 * @return bool - true = timer expired, false = timer not expired
 */
bool aws_kit_timer_expired(Timer *);

/**
 * @brief Create a timer (milliseconds)
 *
 * Sets the timer to expire in a specified number of milliseconds.
 *
 * @param Timer - pointer to the timer to be set to expire in milliseconds
 * @param uint32_t - set the timer to expire in this number of milliseconds
 */
void aws_kit_countdown_ms(Timer *, uint32_t);

/**
 * @brief Create a timer (seconds)
 *
 * Sets the timer to expire in a specified number of seconds.
 *
 * @param Timer - pointer to the timer to be set to expire in seconds
 * @param uint32_t - set the timer to expire in this number of seconds
 */
void aws_kit_countdown_sec(Timer *, uint32_t);

/**
 * @brief Check the time remaining on a given timer
 *
 * Checks the input timer and returns the number of milliseconds remaining on the timer.
 *
 * @param Timer - pointer to the timer to be set to checked
 * @return int - milliseconds left on the countdown timer
 */
uint32_t aws_kit_left_ms(Timer *);

/**
 * @brief Initialize a timer
 *
 * Performs any initialization required to the timer passed in.
 *
 * @param Timer - pointer to the timer to be initialized
 */
void aws_kit_init_timer(Timer *);

#ifdef __cplusplus
}
#endif

#endif //AWS_KIT_TIMER_H_

