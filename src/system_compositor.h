/*
 * Copyright © 2013-2014 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Robert Ancell <robert.ancell@canonical.com>
 *              Alexandros Frantzis <alexandros.frantzis@canonical.com>
 */

#ifndef USC_SYSTEM_COMPOSITOR_H_
#define USC_SYSTEM_COMPOSITOR_H_

#include <memory>

#include "system_impl.h"

class ScreenStateHandler;
class DBusScreen;

namespace usc
{

class ServerConfiguration;
class PowerKeyMediator;
class PowerKeyHandler;
class DMConnection;
class Spinner;

class SystemCompositor
{
public:
    SystemCompositor(std::shared_ptr<ServerConfiguration> const& config);
    ~SystemCompositor();
    void run();

private:
    void main();
    void qt_main();

    std::shared_ptr<ServerConfiguration> const config;
    std::shared_ptr<DMConnection> const dm_connection;
    std::shared_ptr<Spinner> const spinner;
    std::unique_ptr<DBusScreen> dbus_screen;
    std::shared_ptr<ScreenStateHandler> screen_state_handler;
    std::shared_ptr<PowerKeyMediator> power_key_mediator;
    std::shared_ptr<PowerKeyHandler> power_key_handler;
    SystemImpl system_impl;
};

}

#endif /* USC_SYSTEM_COMPOSITOR_H_ */
