#!/usr/bin/env bash
#
# Copyright 2008 Doug Judd (Zvents, Inc.)
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# The installation directory
export HYPERTABLE_HOME=$(cd `dirname "$0"`/.. && pwd)
if [ ! -f $HYPERTABLE_HOME/bin/ThriftBroker ]; then
  echo "ThriftBroker not installed";
  exit 1; #Can't stop nothing
fi

. $HYPERTABLE_HOME/bin/ht-env.sh

usage() {
  echo ""
  echo "usage: stop-thriftbroker.sh [OPTIONS] [<global-args>]"
  echo ""
  echo "OPTIONS:"
  echo "  --all  try to stop all running instances of thrift broker"
  echo ""
}

while [ "$1" != "${1##[-+]}" ]; do
  case $1 in
    --all)
      for pid in `ps aux | grep -v grep | grep $HYPERTABLE_HOME/bin/ThriftBroker  |  awk '{print $2}'`
      do
	    echo "stoping thrift broker with pid $pid"
	    kill -9 $pid
      done
      break;;
    *)
      stop_server thriftbroker
      wait_for_server_shutdown thriftbroker "thrift broker" "$@" &
      break;;
  esac
done
