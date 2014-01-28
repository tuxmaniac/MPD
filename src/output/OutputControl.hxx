/*
 * Copyright (C) 2003-2014 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef MPD_OUTPUT_CONTROL_HXX
#define MPD_OUTPUT_CONTROL_HXX

#include "ReplayGainInfo.hxx"

#include <stddef.h>

struct AudioOutput;
struct AudioFormat;
struct config_param;
class MusicPipe;

void
audio_output_set_replay_gain_mode(AudioOutput *ao,
				  ReplayGainMode mode);

/**
 * Enables the device.
 */
void
audio_output_enable(AudioOutput *ao);

/**
 * Disables the device.
 */
void
audio_output_disable(AudioOutput *ao);

/**
 * Opens or closes the device, depending on the "enabled" flag.
 *
 * @return true if the device is open
 */
bool
audio_output_update(AudioOutput *ao,
		    AudioFormat audio_format,
		    const MusicPipe &mp);

void
audio_output_play(AudioOutput *ao);

void
audio_output_pause(AudioOutput *ao);

void
audio_output_drain_async(AudioOutput *ao);

/**
 * Clear the "allow_play" flag and send the "CANCEL" command
 * asynchronously.  To finish the operation, the caller has to call
 * audio_output_allow_play().
 */
void
audio_output_cancel(AudioOutput *ao);

/**
 * Set the "allow_play" and signal the thread.
 */
void
audio_output_allow_play(AudioOutput *ao);

void
audio_output_close(AudioOutput *ao);

/**
 * Closes the audio output, but if the "always_on" flag is set, put it
 * into pause mode instead.
 */
void
audio_output_release(AudioOutput *ao);

void
audio_output_finish(AudioOutput *ao);

#endif
