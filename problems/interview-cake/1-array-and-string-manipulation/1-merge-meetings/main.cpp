#include <algorithm>
#include <iostream>
#include <vector>

// ! IMP

using namespace std;

class Meeting {
 private:
  // number of 30 min blocks past 9:00 am
  unsigned int startTime_;
  unsigned int endTime_;

 public:
  Meeting() : startTime_(0), endTime_(0) {}

  Meeting(unsigned int startTime, unsigned int endTime)
      : startTime_(startTime), endTime_(endTime) {}

  unsigned int getStartTime() const { return startTime_; }

  void setStartTime(unsigned int startTime) { startTime_ = startTime; }

  unsigned int getEndTime() const { return endTime_; }

  void setEndTime(unsigned int endTime) { endTime_ = endTime; }

  bool operator==(const Meeting& other) const {
    return startTime_ == other.startTime_ && endTime_ == other.endTime_;
  }
};

vector<Meeting> mergeRanges(const vector<Meeting>& meetings) {
  // merge meeting ranges
  // sort meetings
  vector<Meeting> sortedMeetings(meetings);
  sort(sortedMeetings.begin(), sortedMeetings.end(),
       [](auto a, auto b) { return a.getStartTime() < b.getStartTime(); });

  vector<Meeting> mergedMeetings;
  mergedMeetings.push_back(sortedMeetings.front());

  for (const auto& meeting : sortedMeetings) {
    auto& lastMeeting = mergedMeetings.back();
    if (lastMeeting.getEndTime() >= meeting.getStartTime()) {
      lastMeeting.setEndTime(
          max(meeting.getEndTime(), lastMeeting.getEndTime()));
    } else {
      mergedMeetings.push_back(meeting);
    }
  }
  return mergedMeetings;
}

// tests

// const lest::test tests[] = {
//     {CASE("meetings overlap"){
//         const auto meetings = vector<Meeting>{Meeting(1, 3), Meeting(2, 4)};
// const auto actual = mergeRanges(meetings);
// const auto expected = vector<Meeting>{Meeting(1, 4)};
// EXPECT(actual == expected);
// }
// }
// ,

//     {CASE("meetings touch"){
//         const auto meetings = vector<Meeting>{Meeting(5, 6), Meeting(6, 8)};
// const auto actual = mergeRanges(meetings);
// const auto expected = vector<Meeting>{Meeting(5, 8)};
// EXPECT(actual == expected);
// }
// }
// ,

//     {CASE("meeting contains other meeting"){
//         const auto meetings = vector<Meeting>{Meeting(1, 8), Meeting(2, 5)};
// const auto actual = mergeRanges(meetings);
// const auto expected = vector<Meeting>{Meeting(1, 8)};
// EXPECT(actual == expected);
// }
// }
// ,

//     {CASE("meetings stay separate"){
//         const auto meetings = vector<Meeting>{Meeting(1, 3), Meeting(4, 8)};
// const auto actual = mergeRanges(meetings);
// const auto expected = vector<Meeting>{Meeting(1, 3), Meeting(4, 8)};
// EXPECT(actual == expected);
// }
// }
// ,

//     {CASE("multiple merged meetings"){
//         const auto meetings = vector<Meeting>{Meeting(1, 4), Meeting(2, 5),
//         Meeting(5, 8)};
// const auto actual = mergeRanges(meetings);
// const auto expected = vector<Meeting>{Meeting(1, 8)};
// EXPECT(actual == expected);
// }
// }
// ,

//     {CASE("meetings not sorted"){
//         const auto meetings = vector<Meeting>{Meeting(5, 8), Meeting(1, 4),
//         Meeting(6, 8)};
// const auto actual = mergeRanges(meetings);
// const auto expected = vector<Meeting>{Meeting(1, 4), Meeting(5, 8)};
// EXPECT(actual == expected);
// }
// }
// ,

//     {CASE("one long meeting contains smaller meetings"){
//         const auto meetings = vector<Meeting>{Meeting(1, 10), Meeting(2, 5),
//         Meeting(6, 8),
//                                               Meeting(9, 10), Meeting(10,
//                                               12)};
// const auto actual = mergeRanges(meetings);
// const auto expected = vector<Meeting>{Meeting(1, 12)};
// EXPECT(actual == expected);
// }
// }
// ,

//     {CASE("sample input"){
//         const auto meetings = vector<Meeting>{Meeting(0, 1), Meeting(3, 5),
//         Meeting(4, 8),
//                                               Meeting(10, 12), Meeting(9,
//                                               10)};
// const auto actual = mergeRanges(meetings);
// const auto expected = vector<Meeting>{Meeting(0, 1), Meeting(3, 8),
// Meeting(9, 12)}; EXPECT(actual == expected);
// }
// }
// ,
// }
// ;

// int main(int argc, char** argv) {
//   return lest::run(tests, argc, argv);
// }