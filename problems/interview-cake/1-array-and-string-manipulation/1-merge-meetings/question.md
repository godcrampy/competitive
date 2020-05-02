Your company built an in-house calendar tool called HiCal. You want to add a feature to see the times in a day when *everyone* is available.

To do this, you'll need to know when *any* team is having a meeting. In HiCal, a meeting is stored as an instance of a Meeting class with integer member variables startTime and endTime. These integers represent the number of 30-minute blocks past 9:00am.

```c++
class Meeting {
 private:
  // number of 30 min blocks past 9:00 am
  unsigned int startTime*;
  unsigned int endTime*;

 public:
  Meeting() : startTime * (0),
  endTime * (0) {
  }

  Meeting(unsigned int startTime, unsigned int endTime) : startTime_(startTime),
                                                          endTime_(endTime) {
  }

  unsigned int getStartTime() const {
    return startTime_;
  }

  void setStartTime(unsigned int startTime) {
    startTime_ = startTime;
  }

  unsigned int getEndTime() const {
    return endTime_;
  }

  void setEndTime(unsigned int endTime) {
    endTime_ = endTime;
  }

  bool operator==(const Meeting& other) const {
    return startTime_ == other.startTime_ && endTime_ == other.endTime_;
  }
};
```

For example:

`Meeting meeting1(2, 3); // meeting from 10:00 -- 10:30 am Meeting meeting2(6, 9); // meeting from 12:00 -- 1:30 pm`

Write a function mergeRanges() that takes a vector of multiple meeting time ranges and returns a vector of condensed ranges.

For example, given:

`[Meeting(0, 1), Meeting(3, 5), Meeting(4, 8), Meeting(10, 12), Meeting(9, 10)]`

your function would return:

`[Meeting(0, 1), Meeting(3, 8), Meeting(9, 12)]`

Do not assume the meetings are in order. The meeting times are coming from multiple teams.

Write a solution that's efficient even when we can't put a nice upper bound on the numbers representing our time ranges. Here we've simplified our times down to the number of 30-minute slots past 9:00 am. But we want the function to work even for very large numbers, like Unix timestamps. In any case, the spirit of the challenge is to merge meetings where startTime and endTime don't have an upper bound.
