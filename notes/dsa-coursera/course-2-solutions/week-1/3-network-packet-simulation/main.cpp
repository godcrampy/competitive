#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

const std::string PROCESSING_TIME = "PROCESSING_TIME";
const std::string ARRIVAL_TIME = "ARRIVAL_TIME";
const std::string POSITION = "POSITION";

typedef std::map<std::string, int> Packet;
/*
Packet: {
  "arrival_time": int,
  "processing_time": int,
  "position": int
}
*/

void process_packets(std::queue<Packet> &stream, int size, int stream_size) {
  std::queue<Packet> Buffer;
  // auto stream_size = stream.size();
  std::vector<int> status(stream_size, 0);
  int buffer_size = 0;
  // int time = 0;
  int process_finishing_time = -1;
  for (int time = 0; !(stream.empty() && Buffer.empty()); ++time) {
    while (!stream.empty() && stream.front()[ARRIVAL_TIME] == time) {
      if (buffer_size < size) {
        Buffer.push(stream.front());
        ++buffer_size;
        stream.pop();
      } else {
        status[stream.front()[POSITION]] = -1;
        stream.pop();
      }
    }
    if (time >= process_finishing_time && !Buffer.empty()) {
      auto new_process = Buffer.front();
      Buffer.pop();
      --buffer_size;
      process_finishing_time = time + new_process[PROCESSING_TIME];
      status[new_process[POSITION]] = process_finishing_time;
    }
  }
  // for (auto i = 0; i < stream_size; ++i)
  // {
  //   Packet packet = stream[i];
  //   if (queue_size < size)
  //   {
  //     // there is space in queue
  //     Buffer.push(packet);
  //     ++queue_size;
  //   }
  //   else
  //   {
  //     status[i] = -1;
  //   }
  //   time = Buffer.front()[ARRIVAL_TIME];
  //   if (time >= process_finishing_time)
  //   {
  //     // previous process is over
  //     auto new_process = Buffer.front();
  //     Buffer.pop();
  //     --queue_size;
  //     process_finishing_time = time + new_process[PROCESSING_TIME];
  //     status[new_process[POSITION]] = process_finishing_time;
  //   }
  // }
  for (auto time : status)
    std::cout << time << std::endl;
}

int main(int argc, char const *argv[]) {
  int n, s;
  std::cin >> s >> n;
  std::queue<Packet> stream;
  for (auto i = 0; i < n; ++i) {
    int a, p;
    std::cin >> a >> p;
    Packet temp = {{PROCESSING_TIME, p}, {ARRIVAL_TIME, a}, {POSITION, p}};
    stream.push(temp);
  }
  process_packets(stream, s, n);
  return 0;
}