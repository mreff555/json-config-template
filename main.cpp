#include "config.h"
#include <iostream>

// Very simple config file template and demo
// read and write calls are overloaded with string
// parameters, otherwise the default location defined
// in the header is used.  A timestamp is set when writing
// the file.  It does not seem to be saving off the full
// 64 bits of information.  I'll have to look into this later
// but this still should be good down to seconds, which is fine
// for most config file timestamps.
//
// compile with -lboost_system

int main()
{
  Config cfg;

  cfg.setUsername("dan");
  cfg.setPassword("secret");
  cfg.setUrl("http://google.com");
  cfg.write();

  cfg.read();

  std::cout << "username: " << cfg.getUsername() << "\n";
  std::cout << "password: " << cfg.getPassword() << "\n";
  std::cout << "url: " << cfg.getUrl() << "\n";
  std::cout << "timestamp: " << cfg.getTimestamp() << "\n";

  return 0;
}
