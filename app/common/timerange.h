#ifndef TIMERANGE_H
#define TIMERANGE_H

#include "rational.h"

class TimeRange {
public:
  TimeRange() = default;
  TimeRange(const rational& in, const rational& out);

  const rational& in() const;
  const rational& out() const;
  const rational& length() const;

  void set_in(const rational& in);
  void set_out(const rational& out);
  void set_range(const rational& in, const rational& out);

  bool operator==(const TimeRange& r) const;

  bool OverlapsWith(const TimeRange& a) const;
  TimeRange CombineWith(const TimeRange& a) const;
  bool Contains(const TimeRange& a, bool inout_inclusive = true) const;

  static bool Overlap(const TimeRange& a, const TimeRange& b);
  static TimeRange Combine(const TimeRange &a, const TimeRange &b);

private:
  void normalize();

  rational in_;
  rational out_;
  rational length_;
};

uint qHash(const TimeRange& r, uint seed);

class TimeRangeList : public QList<TimeRange> {
public:
  TimeRangeList() = default;

  void InsertTimeRange(const TimeRange& range);

  void RemoveTimeRange(const TimeRange& range);

  bool ContainsTimeRange(const TimeRange& range) const;

  TimeRangeList Intersects(const TimeRange& range);

};

#endif // TIMERANGE_H
