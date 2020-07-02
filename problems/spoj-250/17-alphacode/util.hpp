#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <map>
#include <string>

int char_to_int(char c) { return c - '0'; }

long long get_number_of_decodings(const std::string &message) {
  static std::map<std::string, long long> cache;
  long long final;
  if (message.length() == 0) return 1;
  if (message.at(0) == '0') return 0;
  if (message.length() == 1) return 1;
  if (cache.count(message)) {
    // there is cache
    return cache[message];
  }
  int number = char_to_int(message.at(0)) * 10 + char_to_int(message.at(1));
  if (number > 26) {
    final = get_number_of_decodings(message.substr(1, message.length() - 1));
    cache.insert({message, final});
    return final;
  }
  final = get_number_of_decodings(message.substr(2, message.length() - 2)) +
          get_number_of_decodings(message.substr(1, message.length() - 1));
  cache.insert({message, final});
  return final;
}

#endif