#include <glib.h>
#include <gdbus/gdbus.h>

#include <cstdlib>
#include <iostream>

int main(int argc, char** argv)
{
  std::cout << "Before DBusConnection..." << std::endl;
  DBusConnection *dbus = g_dbus_setup_bus(DBUS_BUS_SYSTEM, NULL, NULL);

  std::cout << "Before g_dbus_attach_object_manager()..." << std::endl;
  g_dbus_attach_object_manager(dbus);

  std::cout << "Before g_dbus_client_new()" << std::endl;
  GDBusClient *client = g_dbus_client_new(dbus_conn, "org.bluez", "/org/bluez");

  std::cout << "Before unrefs" << std::endl;
  g_dbus_client_unref(client);
  dbus_connection_unref(dbus);

  return EXIT_SUCCESS;
}
