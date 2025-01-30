#include "../include/storage/Storage.h"
#include "../include/exception/DataBaseException.h"

bool Storage::create_bucket(const std::string& bucket_name) {
    if (bucket_list_.find(bucket_name) != bucket_list_.end())
         throw DataBaseException("bucket with same name already exist");

    bucket_list_[bucket_name] = std::make_unique<Bucket>();
    logger_.log("Bucket created: ", bucket_name);
    return true;

}
bool Storage::delete_bucket(const std::string& bucket_name) {
    if (bucket_list_.find(bucket_name) == bucket_list_.end())
        throw DataBaseException("bucket with same name not found");

    logger_.log("Deleting bucket: " + bucket_name);
    bucket_list_.erase(bucket_name);
    return true;
}

bool Storage::use_bucket(const std::string& bucket_name) {
    if (bucket_list_.find(bucket_name) == bucket_list_.end())
        throw DataBaseException("bucket with same name not found");

    current_bucket_name_ = bucket_name;
    logger_.log("Current bucket name: ", current_bucket_name_);
    return true;
}

void Storage::bucket_list() {
    for (auto it = bucket_list_.begin(); it != bucket_list_.end(); it++) {
        std::cout  << "\tBucket: " << (*it).first << "\n";
    }
}

bool Storage::set(const long& id, const std::string& value) {
    if (current_bucket_name_.empty()) throw DataBaseException("bucket not selected");

    auto bucket_it = bucket_list_.find(current_bucket_name_);
    if (bucket_it == bucket_list_.end()) {
        throw DataBaseException("Current bucket does not exist");
    }

    auto& bucket = *(bucket_it->second);
    auto [it, inserted] = bucket.insert_or_assign(id, value);

    logger_.log("Value set for id " + std::to_string(id) + " in bucket " + current_bucket_name_);
    return inserted;
}

std::optional<std::string> Storage::get(const long& id) const{
    if (current_bucket_name_.empty()) throw DataBaseException("bucket not selected");

    auto it = bucket_list_.find(current_bucket_name_);
    if (it == bucket_list_.end()) {
        throw DataBaseException("Current bucket does not exist");
    }

    auto& bucket = *(it->second);
    auto value =  bucket.find(id);
    if (value == bucket.end()) {
        logger_.log("GET VALUE: ", "null");
        return std::nullopt;
    }
    logger_.log("GET VALUE: ", value->second);
    return value->second;
}

bool Storage::del(const long& id) {
    if (current_bucket_name_.empty()) {
        logger_.log("Error: Attempt to delete from unselected bucket");
        throw DataBaseException("bucket not selected");
    }

    auto it = bucket_list_.find(current_bucket_name_);
    if (it == bucket_list_.end()) {
        logger_.log("Error: Current bucket does not exist: ", current_bucket_name_);
        throw DataBaseException("Current bucket does not exist");
    }

    auto& bucket = *(it->second);
    auto result = bucket.erase(id);

    if (result > 0) {
        logger_.log("Key " + std::to_string(id) + " deleted from bucket " + current_bucket_name_);
        return true;
    } else {
        logger_.log("Key " + std::to_string(id) + " not found in bucket " + current_bucket_name_);
        return false;
    }
}