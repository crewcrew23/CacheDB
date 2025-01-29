#ifndef STORAGE_H
#define STORAGE_H

#include <memory>
#include <optional>
#include <unordered_map>
#include <string>
#include <logger/Logger.h>

using Bucket = std::unordered_map<long, std::string>;

class Storage {
private:
  Logger logger_;
  std::string current_bucket_name_;
  std::unordered_map<std::string, std::unique_ptr<Bucket>> bucket_list_;

public:
  Storage(){};
  ~Storage(){};

  bool create_bucket(const std::string& bucket_name);
  bool delete_bucket(const std::string& bucket_name);
  bool use_bucket(const std::string& bucket_name);
  void bucket_list();

  bool set(const long& id, const std::string& value);
  std::optional<std::string> get(const long& id) const;
  bool del(const long& id);
};

#endif //STORAGE_H
