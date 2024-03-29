#include "config.h"
#include <fstream>
#include <sys/time.h>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

Config::Config()
{

}

void Config::read()
{
  this->read(DEFAULT_CONFIG_FILE);
}

void Config::read(std::string filename)
{
  boost::property_tree::ptree root;
  boost::property_tree::read_json(filename, root);
  this->username = root.get<std::string>("username");
  this->password = root.get<std::string>("password");
  this->url = root.get<std::string>("url");
  this->timestamp = root.get<uint64_t>("timestamp");
}

void Config::write()
{
  this->write(DEFAULT_CONFIG_FILE);
}

void Config::write(std::string filename)
{
  boost::property_tree::ptree root;
  root.put("username", this->username);
  root.put("password", this->password);
  root.put("url", this->url);
  std::fstream fs(filename, std::fstream::out);
  if(fs.is_open())
  {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    this->timestamp = ts.tv_sec * 1000 + ts.tv_nsec / 1000;
    root.put("timestamp", this->timestamp);
    boost::property_tree::write_json(fs, root);
    fs.close();
  }
  else
  {
    std::cout << "Error opening file: " << filename << ".\n";
  }
}
  
std::string Config::getUsername() const
{
  return this->username;
};

void Config::setUsername(const std::string value)
{
  this->username = value;
};

std::string Config::getPassword() const
{
  return this->password;
};

void Config::setPassword(const std::string value)
{
  this->password = value;
};

std::string Config::getUrl() const
{
  return this->url;
};

void Config::setUrl(const std::string value)
{
  this->url = value;
};

uint64_t Config::getTimestamp() const
{
  return this->timestamp;
};
