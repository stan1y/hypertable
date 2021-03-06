/** -*- c++ -*-
 * Copyright (C) 2008 Doug Judd (Zvents, Inc.)
 *
 * This file is part of Hypertable.
 *
 * Hypertable is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of the
 * License, or any later version.
 *
 * Hypertable is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef HYPERTABLE_EVENTHANDLERMASTERCONNECTION_H
#define HYPERTABLE_EVENTHANDLERMASTERCONNECTION_H

#include "Common/InetAddr.h"

#include "AsyncComm/ApplicationHandler.h"


namespace Hypertable {

  class MasterClient;

  class EventHandlerMasterConnection : public ApplicationHandler {
  public:
    EventHandlerMasterConnection(MasterClientPtr &master_client, EventPtr &event_ptr);

    virtual void run();

  private:
    MasterClientPtr m_master;
    String m_location_file;
    bool m_location_persisted;
    InetAddr m_inet_addr;
  };

}

#endif // HYPERTABLE_EVENTHANDLERMASTERCONNECTION_H

