#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <cstdint>

#define DEFAULT_CONFIG_FILE ".config.json"

class Config 
{
  public:
  Config();

  virtual ~Config(){}

  void read();
  
  void read(std::string);

  void write();

  void write(std::string);

  std::string getUsername() const;

  void setUsername(const std::string);

  std::string getPassword() const;

  void setPassword(const std::string);

  std::string getUrl() const;

  void setUrl(const std::string);

  uint64_t getTimestamp() const;

  private:

  std::string username;

  std::string password;

  std::string url;

  uint64_t timestamp;

};


#endif /* CONFIG_H */
