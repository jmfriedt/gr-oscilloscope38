/* -*- c++ -*- */
/*
 * Copyright 2019 gr-oscilloscope author.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_OSCILLOSCOPE_OSCILLOSCOPE_H
#define INCLUDED_OSCILLOSCOPE_OSCILLOSCOPE_H

#include <oscilloscope/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace oscilloscope {

    /*!
     * \brief <+description of block+>
     * \ingroup oscilloscope
     *
     */
    class OSCILLOSCOPE_API oscilloscope : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<oscilloscope> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of oscilloscope::oscilloscope.
       *
       * To avoid accidental use of raw pointers, oscilloscope::oscilloscope's
       * constructor is in a private implementation
       * class. oscilloscope::oscilloscope::make is the public interface for
       * creating new instances.
       */
      static sptr make(std::string ip, float range, float rate, float duration, int channels);
      virtual void set_range(float) = 0;
      virtual void set_rate(float) = 0;
      virtual void set_duration(float) = 0;
//      virtual void set_ip(std::string);
//      virtual void set_channels(int);
    };

  } // namespace oscilloscope
} // namespace gr

#endif /* INCLUDED_OSCILLOSCOPE_OSCILLOSCOPE_H */

